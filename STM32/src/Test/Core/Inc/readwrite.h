/* USER CODE BEGIN Includes */
/*
 * readwrite.h
 *
 *  Created on: Feb 1, 2019
 *      Author: vbele
 */

#ifndef INC_READWRITE_H_
#define INC_READWRITE_H_

#include <stdint.h>
#include "stdbool.h"
#include "i2c.h"
#include "MagConfig.h"

int write_register8(uint8_t addr, uint8_t value);
int read_data(uint8_t addr, uint8_t *value, uint8_t len);

#endif /* INC_READWRITE_H_ */

/* USER CODE END Includes */
