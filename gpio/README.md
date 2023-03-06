# GPIO
This section details the use of the GPIO pins for input, output, and interrupts

## Operation
The pins of the Spresense can be set to one of three modes. Mode 0 is always GPIO, and modes 1, 2, and 3 are connected to various hardware features,
such as UART and PWM drivers. A full table showing the names of the pins and their state in each mode is given below. Pins are connected together into
groups, so changing the mode of one pin in that group will change the mode of all pins in that group to be the same.  

WLCSP is the reduced 100-pin package, with fewer pins, whereas FCBGA is the full 185-pin package.  
<table>
<colgroup>
<col>
<col>
<col>
<col>
<col>
<col>
<col>
<col>
<col>
</colgroup>
<thead>
<tr>
<th class="tableblock halign-left valign-top">Pin Name</th>
<th class="tableblock halign-left valign-top">Arduino<br>
                compatible<br>
                Pin Name</th>
<th class="tableblock halign-left valign-top">WLCSP</th>
<th class="tableblock halign-left valign-top">FCBGA</th>
<th class="tableblock halign-left valign-top"></th>
<th class="tableblock halign-left valign-top">Mode0</th>
<th class="tableblock halign-left valign-top">Mode1</th>
<th class="tableblock halign-left valign-top">Mode2</th>
<th class="tableblock halign-left valign-top">Mode3</th>
</tr>
</thead>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2C4_BCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">I2C#4<br>
                                                           (CXD5247)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2C4_BDT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PMIC_INT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">PMIC<br>
                                                            Interrupt</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">PMIC Interrupt<br>
                                                                            (OpenDrain)</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">RTC_IRQ_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D41</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">RTC_IRQ_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">RTC_IRQ_OUT<br>
                                                                            (OpenDrain)</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">AP_CLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D40</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">AP_CLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">PMU_WDT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">PMU_WDT<br>
                                                                                              (OpenDrain)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">GNSS_1PPS_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D44</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GNSS_1PPS_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">CPU_WDT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">CPU_WDT<br>
                                                                                              (OpenDrain)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI0_CS_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">UART#1<br>
                                                           (Console)</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">SPI#0</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI0_SCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI0_MOSI</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">I2C#2</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI0_MISO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI1_CS_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="6"><p class="tableblock">SPI#1<br>
                                                           (SPI-Flash)</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">SPI#0</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI1_SCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI1_IO0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI1_IO1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI1_IO2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI1_IO3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI2_CS_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D42</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">SPI#2<br>
                                                           (HostIF)</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">UART#0<br>
                                                                            (HostIF)</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">I2C#3<br>
                                                                                              (HostIF)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI2_SCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D43</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI2_MOSI</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D04</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI2_MISO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D08</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">HIF_IRQ_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D02</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">HIF_IRQ_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">HIF_IRQ_OUT<br>
                                                                            (OpenDrain)</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GNSS_1PPS_OUT</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">HIF_GPIO0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D39</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPS_EXTLD</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SEN_IRQ_IN</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D22</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">SEN_IRQ_IN</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_CS0_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D32</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_CS0_X</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_CS1_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D07</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_CS1_X</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_CS2_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_CS2_X</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_SCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D29</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="3"></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">SPI#3<br>
                                                           (Sensor)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_MOSI</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D31</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI3_MISO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D30</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2C0_BCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D15</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">I2C#0<br>
                                                           (Sensor)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2C0_BDT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D14</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PWM0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D06</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">PWM#0,1</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PWM1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D05</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PWM2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D09</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">PWM#2,3</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">I2C#1<br>
                                                                            (Sensor)</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PWM3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D03</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_CLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="11"></td>
<td class="tableblock halign-left valign-top" rowspan="11"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="11"><p class="tableblock">CMOS Image Sensor</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_VSYNC</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_HSYNC</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA5</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA6</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">IS_DATA7</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">UART2_TXD</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D01</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">UART#2</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">UART2_RXD</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D00</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">UART2_CTS</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D27</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">UART2_RTS</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D28</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI4_CS_X</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D10</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">SPI#4</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI4_SCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D13</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI4_MOSI</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D11</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SPI4_MISO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D12</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">EMMC_CLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D23</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="6"><p class="tableblock">eMMC</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">SPI#5</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">EMMC_CMD</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D24</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">EMMC_DATA0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D16</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">EMMC_DATA1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D17</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">EMMC_DATA2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D20</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">EMMC_DATA3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D21</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_CLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="6"></td>
<td class="tableblock halign-left valign-top" rowspan="6"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="6"><p class="tableblock">SDIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">SPI#5</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_CMD</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_DATA0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_DATA1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_DATA2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_DATA3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_CD</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D36</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">SDIO<br>
                                                           (Card)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_WP</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D37</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_CMDDIR</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D33</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="3"></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">SDIO</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_DIR0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D34</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_DIR1_3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D35</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO_CLKI</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D38</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">SDIO<br>
                                                           (Card)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S0_BCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D26</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">I2S#0</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S0_LRCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D25</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S0_DATA_IN</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D19</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S0_DATA_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">D18</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S1_BCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">LED0</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">I2S#1</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S1_LRCK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">LED1</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S1_DATA_IN</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">LED2</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">I2S1_DATA_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">LED3</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">MCLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">MCLK<br>
                                                           (Audio)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PDM_CLK</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top" rowspan="3"></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">PDM<br>
                                                           (Audio)</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PDM_IN</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">PDM_OUT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">USB_VBUSINT</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">-</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock">*</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">GPIO</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">USB VBUS Interrupt</p></td>
<td class="tableblock halign-left valign-top"></td>
<td class="tableblock halign-left valign-top"></td>
</tr>
</tbody>
</table>


## Configuration
Each pin can be configured using the `board_gpio_config` function, which takes five parameters:
- The pin name PIN_XXX, where XXX is one of the names listed in the table above
- The pin mode, as described in the table above
- Whether the pin is input enabled (true) or disabled (false)
- Whether the pin drive current is 4mA (true) or 2mA (false)
- The state of pull up/down resistors, from PIN_FLOAT, PIN_PULLUP, PIN_PULLDOWN, and PIN_BUSKEEPER  
For example, to have pin I2S0_BCK set as an input with an internal pulldown resistor:
```c
board_gpio_config(PIN_I2S0_BCK, 0, true, false, PIN_PULLDOWN);
```
Or, to have the same pin as an output with 2mA drive current:
```c
board_gpio_config(PIN_I2S0_BCK, 0, false, false, PIN_FLOAT);
```

To read an input into a variable:
```c
int status = board_gpio_read(PIN_I2S0_BCK);
```
And to set an output:
```c
board_gpio_write(PIN_I2S0_BCK, 1); //Write high
```
The output of an output pin can be disabled by writing -1 to it.

## Interrupts
A pin can be configured to trigger interrupts using the `board_gpio_intconfig` function, which takes four parameters:
- The pin name PIN_XXX, where XXX is one of the names listed in the table above
- The interrupt trigger, from INT_HIGH_LEVEL, INT_LOW_LEVEL, INT_RISING_EDGE, INT_FALLING_EDGE, and INT_BOTH_EDGE
- Whether the noise filter is enabled (true) or disabled (false)
- The name of the Interrupt Service Routine (ISR)
For example, to have pin I2S0_BCK trigger an ISR called `handler` when its state transitions from low to high:
```c
board_gpio_intconfig(PIN_I2S0_BCK, INT_RISING_EDGE, false, handler);
```
The interrupt must then be enabled by calling `board_gpio_int` as shown:
```c
board_gpio_int(PIN_I2S0_BCK, true);
```
To later disable the interrupt call:
```c
board_gpio_int(PIN_I2S0_BCK, false);
```

#### Interrupt Service Routine
The ISR must be in the format shown below:
```c
static int handler(int irq, FAR void *context, FAR void *arg)
{
	// Code
}
```


