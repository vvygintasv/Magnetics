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
uint8_t config_regadd;
uint8_t config_data;
void config(void) {
	/* SetUp measurement mode -------------------------------------------*/

	config_regadd = 0x10; // Select mode register
	config_data = 0x01; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c1, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 0xFFFF);

	HAL_Delay(15);
	config_regadd = 0x11; // Select mode register
	config_data = 0x80; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c1, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 0xFFFF);

	config_regadd = 0x10; // Select mode register
	config_data = 0x01; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c2, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 0xFFFF);

	HAL_Delay(15);
	config_regadd = 0x11; // Select mode register
	config_data = 0x80; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c2, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 0xFFFF);
}

/* USER CODE END Includes */
