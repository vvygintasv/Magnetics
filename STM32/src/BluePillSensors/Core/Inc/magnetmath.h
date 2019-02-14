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

void CreateTable(double table[25][25][3], double z, double Br, double magnet_radius, double magnet_height);

void CalculateMagnetEquation(double Br, double x, double y, double z, double magnet_radius, double magnet_height, double answer[]);
void CompareSensorValue(double Br, double magnet_radius, double magnet_height, int field[], int min_ind[], double table[25][25][3]);

//void CompareSensorValue(double Br, double magnet_radius, double magnet_height, int field[], double min_ind[], double equation_result[]);

//int CheckGrid(int grid_x[], int grid_y[], int grid_z[], int field[]);

#endif /* INC_MAGNETMATH_H_ */
/* USER CODE END Includes */
