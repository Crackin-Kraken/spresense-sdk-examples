#include <arch/board/board.h>
#include <arch/chip/pin.h>

#include <nuttx/config.h>
#include <stdio.h>

int main(int argc, FAR char *argv[])
{
	board_gpio_config(PIN_I2S0_BCK, 0, true, false, PIN_PULLDOWN);

	for(int i=0;i<6;i++)
	{
		printf("%fs: %d\n", i*0.5, board_gpio_read(PIN_I2S0_BCK));
		usleep(500000);
	}

	return 0;
}
