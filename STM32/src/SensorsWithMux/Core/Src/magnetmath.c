/* USER CODE BEGIN Includes */
/*
 * magnetmath.c
 *
 *  Created on: Feb 12, 2019
 *      Author: vbele
 */

#include "magnetmath.h"

void CalculateMagnetEquation(double Br, double x, double y, double z, double magnet_radius, double magnet_height, double answer[])
{
	double u0 = 4 * M_PI * 0.0000001;
	double V = pow(magnet_radius, 2) * M_PI * magnet_height;
	double moment = (1 / u0) * Br * V;
	double e1 = u0 / (4 * M_PI);

	double e2_x = 3 * (moment * z) * x;
	double e2_y = 3 * (moment * z) * y;
	double e2_z = 3 * (moment * z) * z;

	double e3 = pow(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)), 5);

	double e4_x = 0;
	double e4_y = 0;
	double e4_z = moment;

	double e5 = pow(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)), 3);

	answer[0] = e1 * ((e2_x / e3) - (e4_x / e5)) * 10000000;
	answer[1] = e1 * ((e2_y / e3) - (e4_y / e5)) * 10000000;
	answer[2] = e1 * ((e2_z / e3) - (e4_z / e5)) * 10000000;
	//int i;
}

void CompareSensorValue(double Br, double magnet_radius, double magnet_height, int field[], int min_ind[], double table[21][21][3]) //Finds table point with smallest difference from sensor data
{
	double min_diff = 99999999;
	for(int x = -10; x < 11; x++)
	{
		for(int y = -10; y < 11; y++)
		{
			// Uses Pythagorean equation to calculate the distance between sensor and magnet
			double difference = sqrt(pow(table[x+10][y+10][0] - field[0], 2) + pow(table[x+10][y+10][1] - field[1], 2) + pow(table[x+10][y+10][2] - field[2], 2));
			if(difference < min_diff)
			{
				// The point with the smallest distance / difference is assumed to be the magnet
				min_diff = difference;
				min_ind[0] = x;
				min_ind[1] = y;
			}
		}
	}
}

void CreateTable(double table[21][21][3], double z, double Br, double magnet_radius, double magnet_height) //Creates a table of expected sensor data, based on relative location of magnet and sensor
{
	double eq_res[3];
	for(double x = -10; x < 11; x++)
	{
		for(double y = -10; y < 11; y++)
		{
			//Total size of table is constrained due to low RAM of micro-controller, current table uses approx. 60% of available board RAM.
			CalculateMagnetEquation(Br, x/100, y/100, z, magnet_radius, magnet_height, eq_res); //Adjust the denominator of x and y to determine accuracy, higher number means more accuracy but smaller max distance checked
			table[(int)x+10][(int)y+10][0] = eq_res[0];
			table[(int)x+10][(int)y+10][1] = eq_res[1];
			table[(int)x+10][(int)y+10][2] = eq_res[2];
		}
	}
}

/*
void CompareSensorValue(double Br, double magnet_radius, double magnet_height, int field[], double min_ind[], double equation_result[])
{
	double min_diff = 99999999;
	for(double x = -25; x < 26; x++)
	{
		for(double y = -25; y < 26; y++)
		{
			CalculateMagnetEquation(Br, x/200, y/200, 0.05, magnet_radius, magnet_height, equation_result);
			double difference = sqrt(pow(equation_result[0] - field[0], 2) + pow(equation_result[1] - field[1], 2) + pow(equation_result[2] - field[2], 2));
			if(difference < min_diff)
			{
				min_diff = difference;
				min_ind[0] = x;
				min_ind[1] = y;
			}
		}
	}
}
*/

/*
int CheckGrid(int grid_x[], int grid_y[], int grid_z[], int field[])
{
	int min_diff = 999999;
	float str_field = sqrt(pow(field[0], 2) + pow(field[1], 2) + pow(field[2], 2));
	int i = 0;
	int grid_index = 0;
	for(int x = 0; x < 21; x++)
	{
		for(int y = 0; y < 21; y++)
		{
			float str_grid = sqrt(pow(grid_x[i], 2) + pow(grid_y[i], 2) + pow(grid_z[i], 2));
			if(abs(str_grid - str_field) < min_diff)
			{
				min_diff = abs(str_grid - str_field);
				grid_index = i;
			}
			i++;
		}
	}
	return grid_index;
}
*/
/* USER CODE END Includes */
