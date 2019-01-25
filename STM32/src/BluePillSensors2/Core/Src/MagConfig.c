/* USER CODE BEGIN Includes */
/*
 * MagConfig.c
 *
 *  Created on: Jan 25, 2019
 *      Author: Caustic_Zinc
 */
#include "MagConfig.h"
#include "i2c.h"
unsigned char buffer[6];
void config() {
	/* SetUp measurement mode -------------------------------------------*/
	buffer[0] = 0x11; // Select mode register
	buffer[1] = 0x80; //Continuous measurement mode
	HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, buffer, 2, 100);

	HAL_Delay(15);
	buffer[0] = 0x10; // Select mode register
	buffer[1] = 1; //Continuous measurement mode
	HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, buffer, 2, 100);

	buffer[0] = 0x11; // Select mode register
	buffer[1] = 0x80; //Continuous measurement mode
	HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, buffer, 2, 100);

	HAL_Delay(15);
	buffer[0] = 0x10; // Select mode register
	buffer[1] = 1; //Continuous measurement mode
	HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, buffer, 2, 100);

}

/* USER CODE END Includes */
