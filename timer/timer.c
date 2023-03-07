#include <sys/ioctl.h>
#include <fcntl.h>
#include <nuttx/config.h>
#include <stdio.h>

#include <arch/board/board.h>
#include <arch/chip/pin.h>
#include <nuttx/timers/rtc.h>

// CONFIG_EXAMPLES_ALARM_SIGNO 1
// CONFIG_EXAMPLES_ALARM_PRIORITY 100
// CONFIG_EXAMPLES_ALARM_STACKSIZE 2048

static bool g_alarm_daemon_started;
volatile bool cont = 0;

static void alarm_handler(int signo, FAR siginfo_t *info, FAR void *ucontext)
{
	cont = 1;
}

static int alarm_daemon(int argc, FAR char *argv[])
{
	struct sigaction act;
	sigset_t set;
	int ret;

	g_alarm_daemon_started = true;
	printf("Running\n");

	// Make sure alarm signal is unmasked
	sigemptyset(&set);
	sigaddset(&set, 1);
	ret = sigprocmask(SIG_UNBLOCK, &set, NULL);
	if(ret != OK)
	{
		printf("Error: sigprocmask failed\n");
	}

	//Register alarm signal handler
	act.sa_sigaction = alarm_handler;
	act.sa_flags = SA_SIGINFO;

	sigfillset(&act.sa_mask);
	sigdelset(&act.sa_mask, 1);

	ret = sigaction(1, &act, NULL);
	if(ret < 0) 
	{
		printf("Error: sigaction failed\n");
	}

	for(;;) { //Task must be running to catch alarm interrupt
		if(cont) break; //End task when no longer needed
	}
}

int main(int argc, FAR char *argv[])
{
	int ret;
	board_gpio_config(PIN_I2S0_BCK, 0, false, false, PIN_FLOAT);
	board_gpio_write(PIN_I2S0_BCK, 1); //Turn on this pin

	pid_t g_alarm_daemon_pid = task_create("alarm_daemon", 100, 2048, alarm_daemon, NULL); //Launch alarm_daemon function as separate task in os
	if(g_alarm_daemon_pid < 0)
	{
		printf("Failed to start alarm_daemon\n");
	} else printf("Started\n");

	int fd = open("/dev/rtc0", O_WRONLY);
	if(fd < 0) {
		printf("Failed to open rtc0");
		return -1;
	}

	struct rtc_setrelative_s setrel;
	setrel.id = 0; //alarm id
	setrel.pid = g_alarm_daemon_pid;
	setrel.reltime = (time_t) 5; //seconds before expire
	setrel.event.sigev_notify = SIGEV_SIGNAL;
	setrel.event.sigev_signo = 1;
	setrel.event.sigev_value.sival_int = 0; // alarmid, same as setrel.id

	ret = ioctl(fd, RTC_SET_RELATIVE, (unsigned long)((uintptr_t)&setrel));
	if(ret < 0)
	{
		printf("Error: RTC_SET_RELATIVE ioctl failed\n");
	}
	close(fd);

	printf("Waiting\n");
	while(!cont) {} //Busy wait for alarm to return
	board_gpio_write(PIN_I2S0_BCK, 0); //Turn off this pin
	printf("Finished\n");

	return 0;
}
