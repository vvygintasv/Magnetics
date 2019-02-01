/* USER CODE BEGIN Includes */
/*
 * readwrite.c
 *
 *  Created on: Feb 1, 2019
 *      Author: vbele
 */
#include "readwrite.h"

int write_register8(uint8_t addr, uint8_t value)
{
	uint16_t tx_buff;
	tx_buff = MAG_ADDR << 1;
	if (HAL_I2C_Mem_Write(&hi2c1, tx_buff, addr, 1, &value, 1, 10000) == HAL_OK)
		return 0;
	else
		return 1;
}

int read_data(uint8_t addr, uint8_t *value, uint8_t len)
{
	uint16_t tx_buff;
	tx_buff = MAG_ADDR << 1;
	if (HAL_I2C_Mem_Read(&hi2c1, tx_buff, addr, 1, value, len, 5000) == HAL_OK)
		return 0;
	else
		return 1;
}


/* USER CODE END Includes */
