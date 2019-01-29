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
	mag_read_valueL(koord_L, koord_R);
	mag_read_valueR(koord_L, koord_R);
}

void make_unit_vectors(int coord[], float unit_vect[])
{
	float sum = 0;
	for(int i = 0; i < 3; i++) sum += pow(coord[i], 2);

	sum = sqrt(sum);

	for(int i = 0; i < 3; i++) unit_vect[i] = coord[i] / sum;
}

void mag_read_register_all_L(uint8_t *receive_buffer[6])
{

    HAL_I2C_Master_Transmit_IT(&hi2c1, MAG_ADDR, MAG3110_OUT_X_MSB, 1);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    //HAL_I2C_Master_Receive_IT(&hi2c1, (MAG_ADDR<<1), receive_buffer, 6);
    HAL_I2C_Master_Sequential_Receive_IT(&hi2c1, MAG_ADDR, receive_buffer, 6, I2C_LAST_FRAME);
}

void mag_read_register_all_R(uint8_t *receive_buffer[6])
{
    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit_IT(&hi2c2, MAG_ADDR, MAG3110_OUT_X_MSB, 1);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    //HAL_I2C_Master_Receive_IT(&hi2c1, (MAG_ADDR<<1), receive_buffer, 6);
    HAL_I2C_Master_Sequential_Receive_IT(&hi2c2, MAG_ADDR, receive_buffer, 6, I2C_LAST_FRAME);
}


void mag_read_valueL(int koord_L[], int koord_R[])
{
	uint8_t whoami_answer[1];
	uint8_t whoami_address = 0x07;
    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, &whoami_address, 1, 100);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    //HAL_I2C_Master_Receive_IT(&hi2c1, (MAG_ADDR<<1), receive_buffer, 6);
    HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, whoami_answer, 1, 100);

    uint8_t reg_value[6];

    //mag_read_register_all_L(reg_value);

    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, MAG3110_OUT_X_MSB, 1, 100);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    //HAL_I2C_Master_Receive_IT(&hi2c1, (MAG_ADDR<<1), receive_buffer, 6);
    HAL_I2C_Master_Sequential_Receive_IT(&hi2c1, MAG_ADDR, reg_value, 6, I2C_LAST_FRAME);

	koord_L[0] = (reg_value[1]|(reg_value[0] << 8));
	koord_L[1] = (reg_value[3]|(reg_value[2] << 8));
	koord_L[2] = (reg_value[5]|(reg_value[4] << 8));

  //uint8_t val_low = 0, val_high = 0;  //define the MSB and LSB
  //val_high = mag_read_registerL(msb_reg);
  //HAL_Delay(2);
  //val_low = mag_read_registerL(lsb_reg);
  //unsigned int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
  //return out;
}
void mag_read_valueR(int koord_L[], int koord_R[])
{
	uint8_t reg_value[6];
	//mag_read_register_all_R(reg_value);

    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit_IT(&hi2c2, MAG_ADDR, MAG3110_OUT_X_MSB, 1);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    //HAL_I2C_Master_Receive_IT(&hi2c1, (MAG_ADDR<<1), receive_buffer, 6);
    HAL_I2C_Master_Sequential_Receive_IT(&hi2c2, MAG_ADDR, reg_value, 6, I2C_LAST_FRAME);

	koord_R[0] = (reg_value[1]|(reg_value[0] << 8));
	koord_R[1] = (reg_value[3]|(reg_value[2] << 8));
	koord_R[2] = (reg_value[5]|(reg_value[4] << 8));

	//uint8_t val_low = 0, val_high = 0;  //define the MSB and LSB
	//val_high = mag_read_registerL(msb_reg);
	//HAL_Delay(2);
	//val_low = mag_read_registerL(lsb_reg);
	//unsigned int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
	//return out;
}


/* USER CODE END Includes */
