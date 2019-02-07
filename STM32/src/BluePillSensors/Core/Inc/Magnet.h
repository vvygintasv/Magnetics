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
#include <stdio.h>

int field_L[3], field_R[3];
float unit_vect_L[3], unit_vect_R[3];;
float str_L, str_R;
int bg_L[3], bg_R[3];
unsigned char buffer[6];

void read_values_to_arrays(int field_L[], int field_R[]);
float make_unit_vectors(int field[], float unit_vect[]);

void reset_background(int field_L[], int field_R[], int bg_L[], int bg_R[], int end_of_startup);

void mag_read_valueL(int field[]);
void mag_read_valueR(int field[]);

#endif /* INC_MAGNET_H_ */
/* USER CODE END Includes */
