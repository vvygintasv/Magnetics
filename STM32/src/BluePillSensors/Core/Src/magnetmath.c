/* USER CODE BEGIN Includes */
/*
 * magnetmath.c
 *
 *  Created on: Feb 12, 2019
 *      Author: vbele
 */

#include "magnetmath.h"

void CreateGrid(int grid[21][21][3], float height, float Br, float radius, float magnet_height)
{
	float u0 = 4 * M_PI * 0.0000001;
	float V = radius * radius * M_PI * magnet_height;
	float moment = (1 / u0) * Br * V;
	float e1 = u0 / (4 * M_PI);
	int i = 0;

	for(int x = -20; x < 20; x++)
	{
		for(int y = -20; y < 20; y++)
		{
			float e2_x = 3 * (moment * height) * (x / 100);
			float e2_y = 3 * (moment * height) * (y / 100);
			float e2_z = 3 * (moment * height) * height;
			float e3 = powf(sqrtf(pow(x, 2) + pow(y, 2) + pow(height, 2)), 5);
			float e4_x = 0;
			float e4_y = 0;
			float e4_z = moment;
			float e5 = powf(sqrtf(pow(x, 2) + pow(y, 2) + pow(height, 2)), 3);

			grid[x+20][y+20][0] = e1 * ((e2_x / e3) - (e4_x / e5));
			grid[x+20][y+20][1] = e1 * ((e2_y / e3) - (e4_y / e5));
			grid[x+20][y+20][2] = e1 * ((e2_z / e3) - (e4_z / e5));
		    i++;
		}
	}
}


void CheckGrid(int grid[21][21][3], int field[], int grid_index[])
{
	int min_diff = 999999;
	float str_field = sqrt(pow(field[0], 2) + pow(field[1], 2) + pow(field[2], 2));
	for(int i = 0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			float str_grid = sqrt(pow(grid[i][j][0], 2) + pow(grid[i][j][1], 2) + pow(grid[i][j][2], 2));
			if(abs(str_grid - str_field) < min_diff)
			{
				min_diff = abs(str_grid - str_field);
				grid_index[0] = i;
				grid_index[1] = j;
			}
		}
	}
}

/* USER CODE END Includes */
