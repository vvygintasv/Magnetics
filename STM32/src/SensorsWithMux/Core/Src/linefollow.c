/* USER CODE BEGIN Includes */
/*
 * linefollow.c
 *
 *  Created on: Feb 27, 2019
 *      Author: vbele
 */

#include "linefollow.h"

double CalcPID(int current_magnet[][2], int expected_magnet[][2], double Kp, double Ki, double Kd, double error_integ, double error_last, int sensor)
{
	int i = sensor - 1;
	int error_x = current_magnet[i][0] - expected_magnet[i][0];
	int error_y = current_magnet[i][1] - expected_magnet[i][1];
	double error = error_x;
	double error_diff = error - error_last;
	error_integ = error_integ + error;
	if(error_integ > 10) error_integ = 10;
	if(error_integ < -10) error_integ = -10;

	double output = Kp * error + Kd * error_diff + Ki * error_integ;
	error_last = error;

	return output;
}

/* USER CODE END Includes */
