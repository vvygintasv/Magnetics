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
#include "math.h"
#include "i2c.h"
#include "MagConfig.h"

int field_L[3], field_R[3];
float vect_L[3], vect_R[3];;
float str_L, str_R;
int bg_L[3], bg_R[3];
unsigned char buffer[6];

void read_values_to_arrays(int field_L[], int field_R[]); //Calls reading functions for both left and right
float make_unit_vectors(int field[], float unit_vect[]); //Turns the magnetic field readings into directional unit vectors and outputs the field strength

void reset_background(int field_L[], int field_R[], int bg_L[], int bg_R[], int end_of_startup); //Startup function which takes the first 100 values and takes their average as the new zero

void mag_read_valueL(int field[]); //Calls HAL functions to read the left sensor values
void mag_read_valueR(int field[]); //Calls HAL functions to read the right sensor values

float average(int array[], int k); //Outputs the average of an array thats size k

#endif /* INC_MAGNET_H_ */
/* USER CODE END Includes */
