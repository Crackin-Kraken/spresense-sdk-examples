# PWM
The pwm functionality is accessed as files through the /dev directory. There are 4 potential pwm devices, /dev/pwm0 through /dev/pwm3, each of which
must be turned on through configuration tool under "System Type/CXD56xx Package Configuration/Peripheral Support".  
Pins PWM0 and PWM1 are grouped together, as are pins PWM2 and PWM3, so both pins are set to the same mode. When using the hardware features pins are
automatically configured, so when utilising one of the pins in a pair as PWM the other must also be used as PWM.

The PWM frequency depends on the SCU clock mode, also set using the configuration tool. The clock frequency when the clock is set to each mode is
given below:
| Clock type | Frequency |
| --- | --- |
| Same with SCU32K | 32.768 kHz |
| RCOSC | 8.2 MHz |
| XOSC | 13 MHz |

Based upon this, the frequency range that the PWM can be set to is 1 ≤ f ≤ SCU Clock / 2.

