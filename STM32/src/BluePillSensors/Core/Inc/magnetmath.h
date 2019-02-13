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

void CreateGrid(int grid[21][21][3], float height, float Br, float radius, float magnet_height);
void CheckGrid(int grid[21][21][3], int field[], int grid_index[]);

#endif /* INC_MAGNETMATH_H_ */
/* USER CODE END Includes */
