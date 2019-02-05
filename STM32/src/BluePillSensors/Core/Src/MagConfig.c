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
uint8_t whoami_answer[1];
uint8_t whoami_address = 0x07;
void config(void) {
	/* SetUp measurement mode -------------------------------------------*/

	HAL_Delay(15);
	config_regadd = 0x11; // Select mode register
	config_data = 0x80; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c1, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 100);

	HAL_I2C_Mem_Read(&hi2c1, MAG_ADDR, whoami_address, I2C_MEMADD_SIZE_8BIT, &whoami_answer[0], 1, 100);
    // first set the register pointer to the register wanted to be read
    //HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, &whoami_address, 1, 100);  // note the & operator which gives us the address of the register_pointer variable
    // receive the 2 x 8bit data into the receive buffer
    //HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, whoami_answer, 1, 100);

	config_regadd = 0x10; // Select mode register
	config_data = 0x11; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c1, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 100);

	HAL_Delay(15);
	config_regadd = 0x11; // Select mode register
	config_data = 0x80; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c2, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 100);

	HAL_I2C_Mem_Read(&hi2c2, MAG_ADDR, whoami_address, I2C_MEMADD_SIZE_8BIT, &whoami_answer[0], 1, 100);

	config_regadd = 0x10; // Select mode register
	config_data = 0x11; //Continuous measurement mode
	//HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR<<1, buffer, 2, 100);
	HAL_I2C_Mem_Write(&hi2c2, MAG_ADDR, config_regadd, I2C_MEMADD_SIZE_8BIT, &config_data, 1, 100);
}

/* USER CODE END Includes */
