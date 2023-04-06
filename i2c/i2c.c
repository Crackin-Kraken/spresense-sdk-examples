#include <nuttx/config.h>
#include <nuttx/i2c/i2c_master.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>

#define I2C_SLAVE_ADDR 	0x08
#define I2C_SPEED 		I2C_SPEED_STANDARD

static int send(int fd, FAR uint8_t *buffer, size_t len)
{
	struct i2c_msg_s msg[1];
	struct i2c_transfer_s xfer;

	//I2C Packets
	msg[0].frequency = I2C_SPEED;
	msg[0].addr = I2C_SLAVE_ADDR;
	msg[0].buffer = buffer;
	msg[0].length = len;
	msg[0].flags = 0;

	xfer.msgv = msg;
	xfer.msgc = 1;

	int ret = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)((uintptr_t)&xfer));
	if(ret < 0)	return -1; //Failed to set buffer
	return 0;
}

static int receive(int fd, FAR uint8_t *buffer, size_t len)
{
	struct i2c_msg_s msg;
	struct i2c_transfer_s xfer;

	//I2C Packets
	msg.frequency = I2C_SPEED;
	msg.addr = I2C_SLAVE_ADDR;
	msg.buffer = buffer;
	msg.length = len;
	msg.flags = I2C_M_READ;

	xfer.msgv = &msg;
	xfer.msgc = 1;

	int ret = ioctl(fd, I2CIOC_TRANSFER, (unsigned long)((uintptr_t)&xfer));
	if((ret < 0) || (buffer[0] != 0)) return -1; //Failed to get buffer
	return 0;
}


int main(int argc, char* argv[])
{
	int fd = open("/dev/i2c0", O_WRONLY);
	if(fd<0) return -1; //Failed open

	//Write 8 bytes
	size_t sz = 8;
	uint8_t* buffer = (uint8_t*)malloc(sz);
	if(!buffer) return -1;

	for(int i=0;i<sz;i++)
	{
		buffer[i] = (i+1) & 0xff;
	}
	int ret = send(fd, buffer, sz);
	if(ret < 0) return -1; //Error
	free(buffer);
	
	//Read 2 bytes
	sz = 2;
	buffer = (uint8_t*)malloc(sz);
	receive(fd, buffer, sz);
	/* Data placed into buffer */
	
	close(fd);
	return 0;
}
