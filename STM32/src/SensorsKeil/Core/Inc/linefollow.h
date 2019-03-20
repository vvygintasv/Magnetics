/* USER CODE BEGIN Includes */
/*
 * linefollow.h
 *
 *  Created on: Feb 27, 2019
 *      Author: vbele
 */

#ifndef INC_LINEFOLLOW_H_
#define INC_LINEFOLLOW_H_

#include <stdint.h>
#include <stdio.h>
#include "math.h"
#include "stdlib.h"

double CalcPID(int current_magnet[][2], int expected_magnet[][2], double Kp, double Ki, double Kd, double error_integ, double error_last, int sensor);

#endif /* INC_LINEFOLLOW_H_ */

/* USER CODE END Includes */
