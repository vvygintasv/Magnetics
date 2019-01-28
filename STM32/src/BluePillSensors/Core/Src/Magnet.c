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
	/*
	koord_L[0] = read_xL();
	koord_L[1] = read_yL();
	koord_L[2] = read_zL();
	koord_R[0] = read_xR();
	koord_R[1] = read_yR();
	koord_R[2] = read_zR();
	*/
}

void make_unit_vectors(int coord[], float unit_vect[])
{
	float sum = 0;
	for(int i = 0; i < 3; i++) sum += pow(coord[i], 2);

	sum = sqrt(sum);

	for(int i = 0; i < 3; i++) unit_vect[i] = coord[i] / sum;
}

void mag_read_register_all_L(uint8_t receive_buffer[6])
{
    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, 0x01, 1, 100);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, (uint8_t*)&receive_buffer, 6, 100);
}

void mag_read_register_all_R(uint8_t receive_buffer[6])
{
    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, 0x01, 1, 100);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    HAL_I2C_Master_Receive(&hi2c2, MAG_ADDR, (uint8_t*)&receive_buffer, 1, 100);
}
/*
uint16_t mag_read_registerL(uint8_t register_pointer)
{
	uint16_t receive_buffer;
    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit(&hi2c1, MAG_ADDR, &register_pointer, 1, 100);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    HAL_I2C_Master_Receive(&hi2c1, MAG_ADDR, (uint8_t*)&receive_buffer, 1, 100);
    return receive_buffer;
}
*/
/*
uint16_t mag_read_registerR(uint8_t register_pointer)
{
	uint16_t receive_buffer;
    // first set the register pointer to the register wanted to be read
    HAL_I2C_Master_Transmit(&hi2c2, MAG_ADDR, &register_pointer, 1, 100);  // note the & operator which gives us the address of the register_pointer variable

    // receive the 2 x 8bit data into the receive buffer
    HAL_I2C_Master_Receive(&hi2c2, MAG_ADDR, (uint8_t*)&receive_buffer, 1, 100);
    return receive_buffer;
}
*/

/*
uint8_t mag_read_registerL(uint8_t register_pointer)
{
    HAL_StatusTypeDef status = HAL_OK;
    uint8_t return_value = 0;

    status = HAL_I2C_Mem_Read(&hi2c1,
    		MAG_ADDR<<1,
			(uint16_t)register_pointer,
			I2C_MEMADD_SIZE_8BIT,
			&return_value,
			1,
			100);

    if(status != HAL_OK)
    {
    	printf("Error Handler Activated\n");
    	//Error_Handler();
    }

    return return_value;
}

uint8_t mag_read_registerR(uint8_t register_pointer)
{
    HAL_StatusTypeDef status = HAL_OK;
    uint8_t return_value = 0;

    status = HAL_I2C_Mem_Read(&hi2c2,
    		MAG_ADDR<<1,
			(uint16_t)register_pointer,
			I2C_MEMADD_SIZE_8BIT,
			&return_value,
			1,
			100);

    if(status != HAL_OK)
    {
    	printf("Error Handler Activated\n");
    	//Error_Handler();
    }

    return return_value;
}
*/
void mag_read_valueL(int koord_L[], int koord_R[])
{
  uint8_t reg_value[6];
  reg_value[0] = 0;
  reg_value[1] = 0;
  reg_value[2] = 0;
  reg_value[3] = 0;
  reg_value[4] = 0;
  reg_value[5] = 0;
  mag_read_register_all_L(reg_value);



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
	mag_read_register_all_R(reg_value);

	koord_R[0] = (reg_value[1]|(reg_value[0] << 8));
	koord_R[1] = (reg_value[3]|(reg_value[2] << 8));
	koord_R[2] = (reg_value[5]|(reg_value[4] << 8));
	reg_value[0] = 0;
	reg_value[1] = 0;
	reg_value[2] = 0;
	reg_value[3] = 0;
	reg_value[4] = 0;
	reg_value[5] = 0;

	//uint8_t val_low = 0, val_high = 0;  //define the MSB and LSB
	//val_high = mag_read_registerL(msb_reg);
	//HAL_Delay(2);
	//val_low = mag_read_registerL(lsb_reg);
	//unsigned int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
	//return out;
}

/*
unsigned int read_xL(void)
{
  return mag_read_valueL(0x01, 0x02);
}
unsigned int read_xR(void)
{
  return mag_read_valueR(0x01, 0x02);
}
unsigned int read_yL(void)
{
  return mag_read_valueL(0x03, 0x04);
}
unsigned int read_yR(void)
{
  return mag_read_valueR(0x03, 0x04);
}
unsigned int read_zL(void)
{
  return mag_read_valueL(0x05, 0x06);
}
unsigned int read_zR(void)
{
  return mag_read_valueR(0x05, 0x06);
}
*/
/* USER CODE END Includes */
