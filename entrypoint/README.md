# Entrypoint
Changing the entrypoint of the spresense changes the application which is automatically started when the Spresense is powered on. This also allows for
user control over the usb serial port connected to the main board, since normally the NuttX shell takes control of this.

## Configuration
In the configuration tool the Application Entry Point must be changed to the name of the program to serve as the new entrypoint. For example, if a
program is added using the `mkcmd.py` tool called `test`, then to use this program as the entrypoint this field should be changed to `test_main`.

## Code
For a program to act as the entrypoint there are a few additions which must be made to the code.

The first action in the main function must be to call
```c 
boardctl(BOARDIOC_INIT, 0);
```
For this, `boardctl.h` must be included:
```c 
#include <sys/boardctl.h>
```

Also, the definition of the main function must be altered to be as shown:
```c 
#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int test_main(int argc, FAR char* argv[])
#endif
{
	//Main function
```
Where `test_main` is replaced with the appropriate name for the program

