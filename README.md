# USB-C_Power_Monitor_Board
STM32 based board displays how much power your hardware draws over USB-C by utilizing INA260 with internal shunt resistor. 

INA260 shunt resistor is in series with the voltage source and the load and is polled by the STM once every second. STM converts raw data and displays to LCD1602 via I2C.

Includes custom lightweight library to initialize and output to LCD. Utilizes STM32 NUCLEO-F302R8, LCD Driven by PCF8574T (https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204) 
