#include <sys/boardctl.h>
#include <nuttx/config.h>
#include <stdio.h>


#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int entrypoint_main(int argc, FAR char* argv[])
#endif
{
	boardctl(BOARDIOC_INIT, 0);
	char c;

	while(1) {
		c = fgetc(stdin);
		if(c == 's') {
			printf("Yes\n");
		}
	}

	return 0;
}
