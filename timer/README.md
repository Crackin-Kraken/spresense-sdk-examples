# Timer
An interrupt can be triggered after a set amount of time using the realtime clock (RTC) alarm functionality.

## Configuration
Via the configuration tool the RTC alarm functionality may be turned on or off, and the number of alarms available may be set. Other options available
include the use of the RTC to provide date/time information, the enabling of a high resolution RTC mode, support for periodic interrupts in the RTC
driver, and the use of an external source for the RTC.

## Programming
As with the other hardware features, the RTC is accessed by a file in the /dev directory: /dev/rtc0. After opening this file, `ioctl` is used to send
instructions to the device, as shown below:

#### Opening device
```c
fd = open("/dev/rtc0", O_WRONLY);
```

#### Setting timer
```c
struct rtc_setrelative_s setrel;
setrel.id = alarm_id;
setrel.pid = g_alarm_daemon_pid;
setrel.reltime = (time_t) duration_seconds;
setrel.event.sigev_notify = SIGEV_SIGNAL;
setrel.event.sigev_signo = 1;
setrel.event.sigev_value.sival_int = alarm_id;

ret = ioctl(fd, RTC_SET_RELATIVE, (unsigned long)((uintptr_t)&setrel));
```

#### Cancelling timer
```c
ret = ioctl(fd, RTC_CANCEL_ALARM, (unsigned long)alarm_id);
```

#### Read timer
```c
struct rtc_rdalarm_s rd = 
{
	0
};
rd.id = alarm_id;

long timeleft;
time_t now;
time(&now);

ret = ioctl(fd, RTC_RD_ALARM, (unsigned long)((uintptr_t)&rd));

if (rd.time.tm_year > 0) // Normal case
{
	timeleft = mktime((struct tm*)&rd.time) - now;
}
else // Unfolding NuttX RTC alarms which do not support alarms longer than one month
{
	struct tm now_tm;

	gmtime_r(&now, &now_tm);
	rd.time.tm_mon = now_tm.tm_mon;
	rd.time.tm_year = now_tm.tm_year;

	do
	{
		timeleft = mktime((struct tm*)&rd.time) - now;
		if (timeleft < 0)
		{
			rd.time.tm_mon++;
		}
	}
	while (timeleft < 0);
}
```

