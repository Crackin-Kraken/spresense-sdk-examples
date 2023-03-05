#include <arch/board/board.h>
#include <arch/chip/pin.h>

#include <nuttx/config.h>

int main(int argc, FAR char *argv[])
{
	board_gpio_config(PIN_I2S0_BCK, 0, false, false, PIN_FLOAT);
	board_gpio_write(PIN_I2S0_BCK, 1);
	usleep(2000000);
	board_gpio_write(PIN_I2S0_BCK, 0);
	usleep(2000000);
	board_gpio_write(PIN_I2S0_BCK, 1);
	usleep(2000000);
	board_gpio_write(PIN_I2S0_BCK, -1);

	return 0;
}
