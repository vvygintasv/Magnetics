void readMagL(int *x, int *y, int *z)
{

  // Start readout at X MSB address
  SWireL.beginTransmission(MAG3110_I2C_ADDRESS);
  SWireL.write(MAG3110_OUT_X_MSB);
  SWireL.endTransmission();

  delayMicroseconds(2);

  // Read out data using multiple byte read mode
  SWireL.requestFrom(MAG3110_I2C_ADDRESS, 6);
  while (SWireL.available() != 6)
  {
  }

  // Combine registers
  uint16_t values[3];
  for (uint8_t idx = 0; idx <= 2; idx++)
  {
    values[idx] = SWireL.read() << 8; // MSB
    values[idx] |= SWireL.read();   // LSB
  }

  // Put data into referenced variables
  *x = (int)values[0];
  *y = (int)values[1];
  *z = (int)values[2];
}
void readMagR(int *x, int *y, int *z)
{

  // Start readout at X MSB address
  SWireR.beginTransmission(MAG3110_I2C_ADDRESS);
  SWireR.write(MAG3110_OUT_X_MSB);
  SWireR.endTransmission();

  delayMicroseconds(2);

  // Read out data using multiple byte read mode
  SWireR.requestFrom(MAG3110_I2C_ADDRESS, 6);
  while (SWireR.available() != 6)
  {
  }

  // Combine registers
  uint16_t values[3];
  for (uint8_t idx = 0; idx <= 2; idx++)
  {
    values[idx] = SWireR.read() << 8; // MSB
    values[idx] |= SWireR.read();   // LSB
  }

  // Put data into referenced variables
  *x = (int)values[0];
  *y = (int)values[1];
  *z = (int)values[2];
}
/*
void readMicroTeslas(float *x, float *y, float *z)
{

  // Using internal read function
  int x_int, y_int, z_int;
  //readMag(&x_int, &y_int, &z_int);

  //Read each axis and scale to Teslas
  *x = (float)x_int * 0.1f;
  *y = (float)y_int * 0.1f;
  *z = (float)z_int * 0.1f;
}
//Note: Must be calibrated to use readHeading!!!
float readHeading()
{

  int x, y, z;
  

  float xf = (float)x * 1.0f;
  float yf = (float)y * 1.0f;

  //Calculate the heading
  return (atan2(-y * y_scale, x * x_scale) * DEG_PER_RAD);
}
*/
