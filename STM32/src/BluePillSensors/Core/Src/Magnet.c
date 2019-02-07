/* USER CODE BEGIN Includes */
/*
 * Magnet.c
 *
 *  Created on: Jan 25, 2019
 *      Author: vbele
 */
#include "MagConfig.h"
#include "Magnet.h"
#include "math.h"
#include "i2c.h"

uint8_t bufferW[6];
uint8_t bufferR[6];

void read_values_to_arrays(int field_L[], int field_R[])
{
	mag_read_valueL(field_L);
	mag_read_valueR(field_R);
}

float make_unit_vectors(int field[], float unit_vect[])
{
	float vect_length = 0;

	for(int i = 0; i < 3; i++) vect_length += pow(field[i], 2);
	vect_length = sqrt(vect_length);
	for(int i = 0; i < 3; i++) unit_vect[i] = field[i] / vect_length;

	return vect_length;
}

void mag_read_valueL(int field[])
{
	bufferW[0] = 0x01;
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, bufferW, 1, 100);  // note the & operator which gives us the address of the register_pointer variable
    HAL_Delay(5);
    // receive the 2 x 8bit data into the receive buffer
    HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, (uint8_t*)&bufferR, 6, 100);
    HAL_Delay(5);

    field[0] = (bufferR[1]|(bufferR[0] << 8));
    field[1] = (bufferR[3]|(bufferR[2] << 8));
    field[2] = (bufferR[5]|(bufferR[4] << 8));
}
void mag_read_valueR(int field[])
{
	bufferW[0] = 0x01;
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, bufferW, 1, 100);  // note the & operator which gives us the address of the register_pointer variable
    HAL_Delay(5);
    // receive the 2 x 8bit data into the receive buffer
    HAL_I2C_Master_Receive(&hi2c2, MAG_ADDR, (uint8_t*)&bufferR, 6, 100);
    HAL_Delay(5);

    field[0] = (bufferR[1]|(bufferR[0] << 8));
    field[1] = (bufferR[3]|(bufferR[2] << 8));
    field[2] = (bufferR[5]|(bufferR[4] << 8));
}

void reset_background(int field_L[], int field_R[], int bg_L[], int bg_R[], int end_of_startup)
{
  for(int j = 0; j <= end_of_startup; j++)
  {
    if(j == end_of_startup)
    {
      for(int i = 0; i < 3; i++)
      {
        bg_L[i] = bg_L[i] / end_of_startup;
        bg_R[i] = bg_R[i] / end_of_startup;
      }
    }
    else
    {
      read_values_to_arrays(field_L, field_R);
      for(int i = 0; i < 3; i++)
      {
        if(field_L[i] > 65536 / 2) field_L[i] = field_L[i] - 65536;
        if(field_R[i] > 65536 / 2) field_R[i] = field_R[i] - 65536;
        bg_L[i] += field_L[i];
        bg_R[i] += field_R[i];
      }
    }
  }
}

/* USER CODE END Includes */
