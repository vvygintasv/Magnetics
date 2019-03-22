/* USER CODE BEGIN Includes */
/*
 * magnetmath.h
 *
 *  Created on: Feb 12, 2019
 *      Author: vbele
 */

#ifndef INC_MAGNETMATH_H_
#define INC_MAGNETMATH_H_

#include "Magnet.h"
#include "stdlib.h"
#include "math.h"

void CreateTable(double table[21][21][3], double z, double Br, double magnet_radius, double magnet_height); //Creates a table of expected sensor data, based on relative location of magnet and sensor

void CalculateMagnetEquation(double Br, double x, double y, double z, double magnet_radius, double magnet_height, double answer[]);
void CompareSensorValue(double Br, double magnet_radius, double magnet_height, volatile int field[], int min_ind[], double table[21][21][3]);  //Finds table point with smallest difference from sensor data

#endif /* INC_MAGNETMATH_H_ */
/* USER CODE END Includes */
