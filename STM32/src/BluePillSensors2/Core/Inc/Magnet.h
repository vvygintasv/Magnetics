/* USER CODE BEGIN Includes */
/*
 * Magnet.h
 *
 *  Created on: Jan 25, 2019
 *      Author: vbele
 */

#ifndef INC_MAGNET_H_
#define INC_MAGNET_H_

int coord_L[3];
int coord_R[3];
float unit_vect_L[3];
float unit_vect_R[3];
unsigned char buffer[6];
int bit16max = 65536;

void read_values_to_arrays(int koord_L[], int koord_R[]);
void make_unit_vectors(int coord[], float unit_vect[]);
int mag_read_registerL(int reg);
int mag_read_registerR(int reg);
int mag_read_valueL(int msb_reg, int lsb_reg);
int mag_read_valueR(int msb_reg, int lsb_reg);
int read_xL(void);
int read_xR(void);
int read_yL(void);
int read_yR(void);
int read_zL(void);
int read_zR(void);

#endif /* INC_MAGNET_H_ */
/* USER CODE END Includes */
