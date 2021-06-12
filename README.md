# PCA9539
The library interfaces NXP's I2C Portexpander by a standard I2C Interface.
The functionality of the code is fully tested and supports the complete functionality of the IC.
The Library uses ST's HAL Layer for I2C Abstraction. For porting the library to other vendor devices,
the user must change the Handler ("hi2c") and its HAL-Functions (HAL_I2C_MasterTransmit/Receive).

The following example code shows the usage of the code.
The MCU configures Port0 as 8-bit Input and Port1 as 8-bit Output.
The Input Byte is readen and outputed,afterwards an Inverted Read is performed, and its output shifted out to 
the Output Register
```
uint8_t ret;
Portexpander::PCA9539 exp(0xee,hi2c1);
exp.ConfigurePort(Portexpander::Port0, 0xFF);
exp.ConfigurePort(Portexpander::Port1,0);
  while (1)
  {
	  exp.InvertPort(Portexpander::Port0, 0x00);
	  ret = exp.ReadPort(Portexpander::Port0);
	  exp.WritePort(Portexpander::Port1,ret);
	  HAL_Delay(1000);
    // Invert input reg and read again:
	  exp.InvertPort(Portexpander::Port0, 0xFF);
	  ret = exp.ReadPort(Portexpander::Port0);
	  exp.WritePort(Portexpander::Port1,ret);
	  HAL_Delay(1000);
  }
```
