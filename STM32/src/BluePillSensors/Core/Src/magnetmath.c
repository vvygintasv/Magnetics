/* USER CODE BEGIN Includes */
/*
 * magnetmath.c
 *
 *  Created on: Feb 12, 2019
 *      Author: vbele
 */

#include "magnetmath.h"

void CreateGrid(int grid_x[], int grid_y[], int grid_z[], float height, float Br, float radius, float magnet_height)
{
	float u0 = 4 * M_PI * 0.0000001;
	float V = radius * radius * M_PI * magnet_height;
	float moment = (1 / u0) * Br * V;
	float e1 = u0 / (4 * M_PI);
	int i = 0;

	for(int x = -10; x < 10; x++)
	{
		for(int y = -10; y < 10; y++)
		{
			float e2_x = 3 * (moment * height) * (x / 100);
			float e2_y = 3 * (moment * height) * (y / 100);
			float e2_z = 3 * (moment * height) * height;
			float e3 = pow(sqrt(pow((x / 100), 2) + pow((y / 100), 2) + pow(height, 2)), 5);
			float e4_x = 0;
			float e4_y = 0;
			float e4_z = moment;
			float e5 = pow(sqrt(pow((x / 100), 2) + pow((y / 100), 2) + pow(height, 2)), 3);

			grid_x[i] = (int)truncf(e1 * ((e2_x / e3) - (e4_x / e5)));
			grid_y[i] = (int)truncf(e1 * ((e2_y / e3) - (e4_y / e5)));
			grid_z[i] = (int)truncf(e1 * ((e2_z / e3) - (e4_z / e5)));
		    i++;
		}
	}
}


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

/* USER CODE END Includes */
