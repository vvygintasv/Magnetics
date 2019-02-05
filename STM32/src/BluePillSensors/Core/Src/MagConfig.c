/* USER CODE BEGIN Includes */
/*
 * MagConfig.c
 *
 *  Created on: Jan 25, 2019
 *      Author: Caustic_Zinc
 */
#include "MagConfig.h"
#include "i2c.h"
unsigned char bufferconf[6];
uint8_t config_regadd;
uint8_t config_data;

void config(void) {
	/* SetUp measurement mode -------------------------------------------*/

	HAL_Delay(15);
	bufferconf[0] = 0x11; // Select mode register
	bufferconf[1] = 0x80; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR<<1, bufferconf, 2, 100);
    HAL_Delay(15);

    bufferconf[0] = 0x10; // Select mode register
	bufferconf[1] = 0x11; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR<<1, bufferconf, 2, 100);
    HAL_Delay(15);

    bufferconf[0] = 0x11; // Select mode register
	bufferconf[1] = 0x80; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR<<1, bufferconf, 2, 100);
    HAL_Delay(15);

    bufferconf[0] = 0x10; // Select mode register
	bufferconf[1] = 0x11; //Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR<<1, bufferconf, 2, 100);
    HAL_Delay(15);
}

/* USER CODE END Includes */
