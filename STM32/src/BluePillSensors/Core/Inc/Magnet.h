/* USER CODE BEGIN Includes */
/*
 * Magnet.h
 *
 *  Created on: Jan 25, 2019
 *      Author: vbele
 */

#ifndef INC_MAGNET_H_
#define INC_MAGNET_H_
#include <stdint.h>

int coord_L[3];
int coord_R[3];
float unit_vect_L[3];
float unit_vect_R[3];
unsigned char buffer[6];

void read_values_to_arrays(int koord_L[], int koord_R[]);
void make_unit_vectors(int coord[], float unit_vect[]);
//uint16_t mag_read_registerL(uint8_t register_pointer);
//uint16_t mag_read_registerR(uint8_t register_pointer);
//void mag_read_register_all_L(uint8_t receive_buffer[6]);
//void mag_read_register_all_R(uint8_t receive_buffer[6]);
void mag_read_valueL(int koord_L[]);
void mag_read_valueR(int koord_R[]);
/*
unsigned int read_xL(void);
unsigned int read_xR(void);
unsigned int read_yL(void);
unsigned int read_yR(void);
unsigned int read_zL(void);
unsigned int read_zR(void);
*/
#endif /* INC_MAGNET_H_ */
/* USER CODE END Includes */
