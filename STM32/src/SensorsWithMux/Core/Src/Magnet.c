/* USER CODE BEGIN Includes */
/*
 * Magnet.c
 *
 *  Created on: Jan 25, 2019
 *      Author: vbele
 */

#include "Magnet.h"

uint8_t bufferW[6];
uint8_t bufferR[6];

float make_unit_vectors(int field[], float unit_vect[])
{
	float vect_length = 0;

	for(int i = 0; i < 3; i++) vect_length += pow(field[i], 2);
	vect_length = sqrt(vect_length);
	for(int i = 0; i < 3; i++) unit_vect[i] = field[i] / vect_length;

	return vect_length;
}

void mag_read_value(int field[][3], int sensor)
{
	SelectSensor(sensor);
    bufferW[0] = 0x01; //address of registry containing the first measured value
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferW, 1, 100);  //writes the register address into the slave device
    HAL_Delay(1);
    HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, (uint8_t*)&bufferR, 6, 100); //reads 6 bytes of data from the slave device, starting at the registry which was previously written
    HAL_Delay(1);
    field[sensor-1][0] = (bufferR[1]|(bufferR[0] << 8)); //buffer[0] is MSB of x, buffer[1] is LSB of x
    field[sensor-1][1] = (bufferR[3]|(bufferR[2] << 8)); //buffer[2] is MSB of y, buffer[3] is LSB of y
    field[sensor-1][2] = (bufferR[5]|(bufferR[4] << 8)); //buffer[4] is MSB of z, buffer[5] is LSB of z
}

void reset_background(int field[][3], int bg[][3], int end_of_startup, int sensorcount)
{
	for(int j = 0; j <= end_of_startup; j++)
	{
		if(j == end_of_startup)
		{
			for(int i = 0; i < sensorcount; i++)
			{
				for(int k = 0; k < 3; k++)
				{
					bg[i][k] /= end_of_startup;
				}
			}
		}
		else
		{
			for(int i = 0; i < sensorcount; i++)
			{
				mag_read_value(field, i+1);
				for(int j = 0; j < 3; j++)
				{
					if(field[i][j] > 65536 / 2) field[i][j] -= 65536;
					bg[i][j] += field[i][j];
				}
			}
		}
	}
}

float average(int array[], int k)
{
	float sum = 0;
	for(int i = 0; i < k; i++)
	{
		if(array[i] > 0 && array[i] < 65535) sum += array[i];
	}
	sum = sum / k;
	return sum;
}

void SelectSensor(int sensor)
{
	HAL_GPIO_WritePin(SR_SIGNAL_GPIO_Port, SR_SIGNAL_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	for(int i = 0; i < 8; i++)
	{
		if(i == 7 - sensor) AddBit(1);
		else AddBit(0);
	}
	HAL_GPIO_WritePin(SR_RCK_GPIO_Port, SR_RCK_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(SR_RCK_GPIO_Port, SR_RCK_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void AddBit(int i)
{
	if(i == 1)
	{
		HAL_GPIO_WritePin(SR_SIGNAL_GPIO_Port, SR_SIGNAL_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
	}
	HAL_GPIO_WritePin(SR_SCK_GPIO_Port, SR_SCK_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(SR_SCK_GPIO_Port, SR_SCK_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	if(i == 1)
	{
		HAL_GPIO_WritePin(SR_SIGNAL_GPIO_Port, SR_SIGNAL_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}
}

/* USER CODE END Includes */