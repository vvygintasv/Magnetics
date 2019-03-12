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
#include "spi.h"

int field[8][3];
float vect[6][3];
float str[6];
int bg[6][3];
unsigned char buffer[6];

float make_unit_vectors(int field[], float unit_vect[]); //Turns the magnetic field readings into directional unit vectors and outputs the field strength

void reset_background(int field[][3], int bg[][3], int end_of_startup, int sensorcount); //Startup function which takes the first 100 values and takes their average as the new zero

void mag_read_value(int field[][3], int sensor); //Calls HAL functions to read the left sensor values

float average(int array[], int k); //Outputs the average of an array thats size k

void SelectSensor(int sensor);
void AddBit(int i);

#endif /* INC_MAGNET_H_ */
/* USER CODE END Includes */
