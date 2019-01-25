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

void read_values_to_arrays(int koord_L[], int koord_R[])
{
	koord_L[0] = read_xL();
	koord_L[1] = read_yL();
	koord_L[2] = read_zL();
	koord_R[0] = read_xR();
	koord_R[1] = read_yR();
	koord_R[2] = read_zR();
}

void make_unit_vectors(int coord[], float unit_vect[])
{
	float sum = 0;
	for(int i = 0; i < 3; i++) sum += pow(coord[i], 2);

	sum = sqrt(sum);

	for(int i = 0; i < 3; i++) unit_vect[i] = coord[i] / sum;
}

int mag_read_registerL(int reg)
{
	int reg_val;

	buffer[0] = reg;
	HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, buffer, 1, 100);
	HAL_Delay(15);
	HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, &buffer[1], 1, 100);
	reg_val = buffer[1];

	return reg_val;
}

int mag_read_registerR(int reg)
{
	int reg_val;

	buffer[0] = reg;
	HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, buffer, 1, 100);
	HAL_Delay(15);
	HAL_I2C_Master_Receive(&hi2c2, MAG_ADDR, &buffer[1], 1, 100);
	reg_val = buffer[1];

	return reg_val;
}

int mag_read_valueL(int msb_reg, int lsb_reg)
{
  int val_low, val_high;  //define the MSB and LSB
  val_high = mag_read_registerL(msb_reg);
  HAL_Delay(2);
  val_low = mag_read_registerL(lsb_reg);
  int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
  return out;
}
int mag_read_valueR(int msb_reg, int lsb_reg)
{
  int val_low, val_high;  //define the MSB and LSB
  val_high = mag_read_registerR(msb_reg);
  HAL_Delay(2);
  val_low = mag_read_registerR(lsb_reg);
  int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
  return out;
}

int read_xL(void)
{
  return mag_read_valueL(0x01, 0x02);
}
int read_xR(void)
{
  return mag_read_valueR(0x01, 0x02);
}
int read_yL(void)
{
  return mag_read_valueL(0x03, 0x04);
}
int read_yR(void)
{
  return mag_read_valueR(0x03, 0x04);
}
int read_zL(void)
{
  return mag_read_valueL(0x05, 0x06);
}
int read_zR(void)
{
  return mag_read_valueR(0x05, 0x06);
}

/* USER CODE END Includes */
