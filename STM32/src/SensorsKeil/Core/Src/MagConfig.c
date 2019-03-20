/* USER CODE BEGIN Includes */
/*
 * MagConfig.c
 *
 *  Created on: Jan 25, 2019
 *      Author: Caustic_Zinc
 */
#include "MagConfig.h"
#include "i2c.h"
#include "Magnet.h"
uint8_t bufferconf[2];
uint8_t bufferread1[2];
uint8_t bufferread2[2];
uint8_t config_regadd;
uint8_t config_data;

void config(void) {
	/* SetUp measurement mode -------------------------------------------*/
	for(int i = 0; i < 6; i++)
	{
		SelectSensor(i+1);
		bufferread1[0] = 0;
		bufferread1[1] = 0;
		bufferread2[0] = 0;
		bufferread2[1] = 0;
		HAL_Delay(15);
		bufferconf[0] = 0x11; // Select mode register
		bufferconf[1] = 0x80; //Continuous measurement mode
		HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferconf, 2, 100);
		HAL_Delay(15);

		bufferconf[0] = 0x10; // Select mode register
		bufferconf[1] = 0xFF - 0x1; //Continuous measurement mode
		HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferconf, 2, 100);
		HAL_Delay(15);

		bufferconf[0] = 0x07; // Select mode register
		bufferconf[1] = 0x00; //Continuous measurement mode
		//writes the address of the WHO_AM_I register as a test
		HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferconf, 1, 100);

		HAL_Delay(10);
		HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, (uint8_t*)&bufferread1, 1, 100); //if I2C communication is working properly, the read byte must always be 0xC4
		HAL_Delay(15);
	}


}

/* USER CODE END Includes */
