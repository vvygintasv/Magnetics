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

void CreateGrid(int grid_x[], int grid_y[], int grid_z[], float height, float Br, float radius, float magnet_height);
int CheckGrid(int grid_x[], int grid_y[], int grid_z[], int field[]);

#endif /* INC_MAGNETMATH_H_ */
/* USER CODE END Includes */
