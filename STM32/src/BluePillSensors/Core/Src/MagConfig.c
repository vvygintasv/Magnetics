/* USER CODE BEGIN Includes */
/*
 * MagConfig.c
 *
 *  Created on: Jan 25, 2019
 *      Author: Caustic_Zinc
 */
#include "MagConfig.h"
#include "i2c.h"
uint8_t bufferconf[2];
uint8_t bufferread1[2];
uint8_t bufferread2[2];
uint8_t config_regadd;
uint8_t config_data;

void config(void) {
	/* SetUp measurement mode -------------------------------------------*/
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
	bufferconf[1] = 0x1; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferconf, 2, 100);
    HAL_Delay(15);

    bufferconf[0] = 0x11; // Select mode register
	bufferconf[1] = 0x80; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, bufferconf, 2, 100);
    HAL_Delay(15);

    bufferconf[0] = 0x10; // Select mode register
	bufferconf[1] = 0x1; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, bufferconf, 2, 100);
    HAL_Delay(15);

    bufferconf[0] = 0x07; // Select mode register
    bufferconf[1] = 0x00; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, bufferconf, 1, 100);
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferconf, 1, 100);

    HAL_Delay(10);
    HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, (uint8_t*)&bufferread1, 1, 100);
    HAL_I2C_Master_Receive(&hi2c2, MAG_ADDR, (uint8_t*)&bufferread2, 1, 100);
    HAL_Delay(15);

}

/* USER CODE END Includes */
