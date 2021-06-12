/*
 * PCA9539.h
 *
 *  Created on: 08.06.2021
 *      Author: kai-s
 */

#ifndef SRC_PCA9639_PCA9539_H_
#define SRC_PCA9639_PCA9539_H_
#include <stdint.h>
#include "stm32g4xx_hal.h"

namespace Portexpander {

enum IOPort
{
	Port0,
	Port1
};

class PCA9539 {

public:
	PCA9539();
	PCA9539(uint8_t addr, I2C_HandleTypeDef i2c_port); // Constructor
	void ConfigurePort(IOPort port,uint8_t config); // Set Port Direction
	void WritePort(IOPort port,uint8_t data); // Write
	uint8_t ReadPort(IOPort port); // Read byte from word
	void InvertPort(IOPort port,uint8_t bitmask); // Inverts bits from Input Register
	void Reset();
	virtual ~PCA9539();

private:
	uint8_t address;
	I2C_HandleTypeDef hi2c;

};

} /* namespace Portexpander */

#endif /* SRC_PCA9639_PCA9539_H_ */
