# I2C
The i2c functionality is accessed as files through the /dev directory. There are 3 potential i2c devices, /dev/i2c0 through /dev/i2c2, each of which
must be turned on through configuration tool under "System Type/CXD56xx Package Configuration/Peripheral Support". Here, the I2C character device
driver must also be selected.  
To control the I2C as shown in i2c.c the Sensor Control Unit (SCU) must be disabled for the device, which can be done by deselecting the "SCU
Sequencer" option presented for I2C0 and I2C1. As the SCU cannot have control over I2C 2 this has no such option. The SCU does not have to be disabled
entirely, and doing such would interfere with other hardware features such as PWM or the ADC.

## Details
The maximum frequency of the clock for I2C is 1MHz. The main board operates at a voltage of 1.8V with a 4.7kΩ pull-up resistor, whereas the extension
board operates at either 5V or 3.3V (depending on jumper position) with a 1kΩ pull-up resistor.  
A 32 byte buffer is available for a single transfer operation. By default a 7 but address is used, which can be increased to 10 bits.

## Usage
The device should be opened in write only mode. Using /dev/i2c0 as an example:
```c
int file_descriptor = open("/dev/i2c0", O_WRONLY);
```

An `i2c_msg_s` struct is used to hold the information for each transfer. This can either be a single packet, or an array of sequential packets with
different information. Each packet holds:
- frequency: The frequency of communication. This can be one of the following values:
	| Value | Frequency (kHz) |
	| --- | --- |
	| I2C_SPEED_STANDARD | 100 |
	| I2C_SPEED_FAST 	 | 400 |
	| I2C_SPEED_FAST_PLUS | 1000 |
- addr: The I2C address of the device to receive the packet
- buffer: An array of data to transfer
- length: The length of the buffer in bytes
- flags: Flags to change operation. Possible values and their effects are:
	| Flag | Effect |
	| --- | --- |
	| I2C_M_READ 	| Read data from slave |
	| I2C_M_TEN 	| Use ten bit address |
	| I2C_M_NOSTOP 	| Do not end message with a STOP |
	| I2C_M_NOSTART | Do not begin message with a START |


An `i2c_transfer_s` struct is used in the transfer process. This takes two values:
- msgv: The i2c\_msg\_s array. If this is not an array, pass the address.
- msgc: The length of the array

Finally, the transfer is completed with the following command:
```c
ioctl(fd, I2CIOC_TRANSFER, (unsigned long)((uintptr_t)&xfer));
```
Where `fd` is the file descriptor for the i2c device returned by `open`, and `xfer` is the `i2c_transfer_s` struct.

