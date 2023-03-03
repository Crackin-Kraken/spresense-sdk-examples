# spresense-sdk-examples
Example code for programming Sony Spresense microcontroller via the SDK
All of these examples were created and tested on a Linux installation. I have no idea if they will translate smoothly to other systems.

## Setup
Follow [these instructions](https://developer.sony.com/develop/spresense/docs/sdk_set_up_en.html#_development_environment) for downloading and
installing the SDK and arm-none-eabi-gcc compiler on your system. On Linux systems, it may be possible to acquire the arm compiler through your
package manager. On gentoo, use the articles for [Crossdev](https://wiki.gentoo.org/wiki/Crossdev) and [ARM](https://wiki.gentoo.org/wiki/ARM).

Within the Spresense SDK, the configuration, compiling, and flashing is all done from the 'sdk' folder. From here, to add a folder to store your own
programs in, use:
```bash
./tools/mkappsdir.py directory_name "Directory Description"
```
This directory will be made in the root folder of the Spresense SDK, so it will be one level above the sdk folder which this command is executed in.
To add a program template to this directory, use the `mkcmd` command, making sure to specify the directory which was just created.
```bash
./tools/mkcmd.py -d directory_name program_name "Program Description"
```
After adding a new program with `mkcmd.py`, in the sdk directory `make clean` must be run. By doing this it is ensured that the configuration and
commpilation tools will be able to locate it. It is possible to check and select which programs will be compiled into the nuttx image with the
configuration tool.

##Configuration
Configuration is done by the `./tools/config.py` command. There are different interfaces for configuration, which can be accessed by passing different
flags to this command:
- `-m` or `--menuconfig` for an ncurses interface
- `-g` or `--gconfig` for a GTK based GUI
- `-q` or `--qconfig` for a QT based GUI

The config tool allows for the enabling and disabling of hardware features, many of which are disabled by default; the alteration of hardware and
software options; and the selection of which programs will be available in the compiled image. The directory and program descriptions specified in the
Setup section are used in these menus.

##Building
To build a nuttx.spk image suitable for flashing to the Spresense board, simply run `make` in the sdk directory. This will automatically descend into
directories which have been added using the `mkappsdir.py` and `mkcmd.py` tools. Every time after adding a new program with `mkcmd.py`, run `make
clean` to ensure that it is detected.
The resultant nuttx.spk image will also be in the sdk directory.

##Flashing
Flashing the Spresense board is done via the `tools/flash.sh` command. If when running this a warning regarding the bootloader is shown, follow either
the instructions printed in the terminal or the instruction [found
here](https://developer.sony.com/develop/spresense/docs/sdk_set_up_en.html#_flashing_bootloader) to update the firmware.
Run
```bash
./tools/flash.sh -c port nuttx.spk
```
to flash the nuttx.spk image to the board, where `port` is the serial port which the Spresense is attached to. For example, under Linux this may be
`/dev/ttyUSB0`, or in Windows it may be `COM9`. Ensure there are no other communications happening on this port whilst attempting to flash, such as
with minicom as described in the following section

##Running
To access the nuttx shell on the Spresense whilst it is running, a program such as
[minicom](https://www.poftut.com/install-use-linux-minicom-command-tutorial-examples/) can be used. For example, if the Spresense is connected to port
`/dev/ttyUSB0`, then running
```bash
minicom -b 115200 -D /dev/ttyUSB0
```
Will provide access to the shell. The `-b` flag specifies the baud rate of communication, which is 115200 bit/s in this case.

In this shell, some standard linux commands are provided, such as `ls`, `ps`, and `cd`. As well as this, any programs selected to be built during the
configuration stage will also be available as shell commands. For example, if a program is added by the user using the `mkcmd.py` tool with the name
helloworld, then it can be executed in the nuttx shell by typing `helloworld`.

