/*
 * PCA9539.cpp
 *
 *  Created on: 08.06.2021
 *      Author: kai-s
 */

#include "PCA9539.h"

namespace Portexpander {

PCA9539::PCA9539() {
	// TODO Auto-generated constructor stub

}

PCA9539::~PCA9539() {
	// TODO Auto-generated destructor stub
}

PCA9539::PCA9539(uint8_t addr, I2C_HandleTypeDef i2c_port)
{
	address = addr;
	hi2c = i2c_port;
}

/*
 * @ brief:  Configures Port
 * @ param: Selected IO Port, Bitmask for setting IO-Direction
 * @ return: none
 */

void PCA9539::ConfigurePort(IOPort port,uint8_t config)
{
	uint8_t data[] ={0x6+port,config};
	HAL_I2C_Master_Transmit(&hi2c, address, (uint8_t*)data, 2, 10);
}

/*
 * @ brief:  Writes byte to Port
 * @ param: Selected IO Port, Byte to write
 * @ return: none
 */

void PCA9539::WritePort(IOPort port, uint8_t data)
{
	uint8_t tx_data[] ={2+port,data};
	HAL_I2C_Master_Transmit(&hi2c, address, tx_data, 2, 10);
}

/*
 * @ brief:  Reads byte from Port
 * @ param: Selected IO Port
 * @ return: Readen Byte
 */
uint8_t PCA9539::ReadPort(IOPort port)
{
	uint8_t rx_data;
	HAL_I2C_Master_Transmit(&hi2c, address, (uint8_t*)port, 1, 10);
	HAL_I2C_Master_Receive(&hi2c, address, &rx_data, 1, 10);
	return rx_data;
}

/*
 * @ brief: Inverts Input Register
 * @ param: Bitmask: Set Bits are inverted, Cleared Bits remain
 * @ return: none
 */
void PCA9539::InvertPort(IOPort port,uint8_t bitmask)
{
	uint8_t data[] ={4+port,bitmask};
	HAL_I2C_Master_Transmit(&hi2c, address, data, 2, 10);
}

} /* namespace Portexpander */
