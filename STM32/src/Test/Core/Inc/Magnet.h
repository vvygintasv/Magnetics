/* USER CODE BEGIN Includes */
/*
 * Magnet.h
 *
 *  Created on: Jan 25, 2019
 *      Author: vbele
 */

#ifndef INC_MAGNET_H_
#define INC_MAGNET_H_
#include <stdint.h>

int coord_L[3];
float unit_vect_L[3];
unsigned char buffer[6];
uint8_t reg_ptr;
uint8_t buffr[2];

void read_values_to_arrays(int koord_L[]);
void make_unit_vectors(int coord[], float unit_vect[]);
void read_register(uint8_t register_pointer, uint8_t* receive_buffer);
void mag_read_valueL(int koord_L[]);

#endif /* INC_MAGNET_H_ */
/* USER CODE END Includes */
