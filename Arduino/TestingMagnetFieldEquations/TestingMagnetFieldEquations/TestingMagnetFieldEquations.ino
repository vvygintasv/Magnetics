#include <Wire.h>
#include <SoftWire.h>
 
#define MAG_ADDR  0x0E //7-bit address for the MAG3110, doesn't change

/////////////////////////////////////////
// MAG3110 Magnetometer Registers      //
/////////////////////////////////////////
#define MAG3110_DR_STATUS 0x00
#define MAG3110_OUT_X_MSB 0x01
#define MAG3110_OUT_X_LSB 0x02
#define MAG3110_OUT_Y_MSB 0x03
#define MAG3110_OUT_Y_LSB 0x04
#define MAG3110_OUT_Z_MSB 0x05
#define MAG3110_OUT_Z_LSB 0x06
#define MAG3110_WHO_AM_I 0x07
#define MAG3110_SYSMOD 0x08
#define MAG3110_OFF_X_MSB 0x09
#define MAG3110_OFF_X_LSB 0x0A
#define MAG3110_OFF_Y_MSB 0x0B
#define MAG3110_OFF_Y_LSB 0x0C
#define MAG3110_OFF_Z_MSB 0x0D
#define MAG3110_OFF_Z_LSB 0x0E
#define MAG3110_DIE_TEMP 0x0F
#define MAG3110_CTRL_REG1 0x10
#define MAG3110_CTRL_REG2 0x11

////////////////////////////////
// MAG3110 WHO_AM_I Response  //
////////////////////////////////
#define MAG3110_WHO_AM_I_RSP 0xC4

/////////////////////////////////////////
// MAG3110 Commands and Settings       //
/////////////////////////////////////////

//CTRL_REG1 Settings
//Output Data Rate/Oversample Settings
//DR_OS_80_16 -> Output Data Rate = 80Hz, Oversampling Ratio = 16

#define MAG3110_DR_OS_80_16 0x00
#define MAG3110_DR_OS_40_32 0x08
#define MAG3110_DR_OS_20_64 0x10
#define MAG3110_DR_OS_10_128 0x18
#define MAG3110_DR_OS_40_16 0x20
#define MAG3110_DR_OS_20_32 0x28
#define MAG3110_DR_OS_10_64 0x30
#define MAG3110_DR_OS_5_128 0x38
#define MAG3110_DR_OS_20_16 0x40
#define MAG3110_DR_OS_10_32 0x48
#define MAG3110_DR_OS_5_64 0x50
#define MAG3110_DR_OS_2_5_128 0x58
#define MAG3110_DR_OS_10_16 0x60
#define MAG3110_DR_OS_5_32 0x68
#define MAG3110_DR_OS_2_5_64 0x70
#define MAG3110_DR_OS_1_25_128 0x78
#define MAG3110_DR_OS_5_16 0x80
#define MAG3110_DR_OS_2_5_32 0x88
#define MAG3110_DR_OS_1_25_64 0x90
#define MAG3110_DR_OS_0_63_128 0x98
#define MAG3110_DR_OS_2_5_16 0xA0
#define MAG3110_DR_OS_1_25_32 0xA8
#define MAG3110_DR_OS_0_63_64 0xB0
#define MAG3110_DR_OS_0_31_128 0xB8
#define MAG3110_DR_OS_1_25_16 0xC0
#define MAG3110_DR_OS_0_63_32 0xC8
#define MAG3110_DR_OS_0_31_64 0xD0
#define MAG3110_DR_OS_0_16_128 0xD8
#define MAG3110_DR_OS_0_63_16 0xE0
#define MAG3110_DR_OS_0_31_32 0xE8
#define MAG3110_DR_OS_0_16_64 0xF0
#define MAG3110_DR_OS_0_08_128 0xF8

//Other CTRL_REG1 Settings
#define MAG3110_FAST_READ 0x04
#define MAG3110_TRIGGER_MEASUREMENT 0x02
#define MAG3110_ACTIVE_MODE 0x01
#define MAG3110_STANDBY_MODE 0x00

//CTRL_REG2 Settings
#define MAG3110_AUTO_MRST_EN 0x80
#define MAG3110_RAW_MODE 0x20
#define MAG3110_NORMAL_MODE 0x00
#define MAG3110_MAG_RST 0x10

//SYSMOD Readings
#define MAG3110_SYSMOD_STANDBY 0x00
#define MAG3110_SYSMOD_ACTIVE_RAW 0x01
#define MAG3110_SYSMOD_ACTIVE 0x02

#define MAG3110_X_AXIS 1
#define MAG3110_Y_AXIS 3
#define MAG3110_Z_AXIS 5

SoftWire SWireR(PB10, PB11, SOFT_FAST);
SoftWire SWireL(PB6, PB7, SOFT_FAST);

int bit16max;
int field_L[3], field_R[3], whoami;
float vect_L[3], vect_R[3];
int bg_L[3], bg_R[3];
float str_L, str_R;
int end_of_startup;
char buff;
int grid_x[441], grid_y[441], grid_z[441];
int grid_index_L, grid_index_R;
 int j = 0;
 
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
  SWireR.begin();
  SWireL.begin();
  bit16max = 65536;
  config();            // turn the MAG3110 on
  end_of_startup = 100;
  str_L = 0;
  str_R = 0;
  bg_L[0] = 0;
  bg_L[1] = 0;
  bg_L[2] = 0;
  bg_R[0] = 0;
  bg_R[1] = 0;
  bg_R[2] = 0;
  
  Serial.println("Press any key");
  while(Serial.available() < 1) buff = Serial.read();
  reset_background(field_L, field_R, bg_L, bg_R, end_of_startup);
  CreateGrid(grid_x, grid_y, grid_z, 0.014, 1, 0.006, 0.026);
}
 
void loop()
{
  whoami = mag_read_registerL(0x07);
  //Serial.print("WhoAmI Left: ");
  //Serial.print(whoami);
  whoami = mag_read_registerR(0x07);
  //Serial.print("  WhoAmI Right: ");
  //Serial.println(whoami);
  read_values_to_arrays(field_L, field_R);
  for(int i = 0; i < 3; i++)
  {
    if(field_L[i] > bit16max / 2) field_L[i] = field_L[i] - bit16max;
    if(field_R[i] > bit16max / 2) field_R[i] = field_R[i] - bit16max;
    field_L[i] -= bg_L[i];
    field_R[i] -= bg_R[i];
  }

  //Serial.print("Left: ");
  make_vectors(field_L, vect_L, str_L);
  //Serial.print(" Right: ");
  make_vectors(field_R, vect_R, str_R);
  //print_values(vect_L, str_L, vect_R, str_R); 

  grid_index_L = CheckGrid(grid_x, grid_y, grid_z, field_L);
  grid_index_R = CheckGrid(grid_x, grid_y, grid_z, field_R);

  
  Serial.print(grid_x[j]);
  Serial.print(" ");
  Serial.print(grid_y[j]);
  Serial.print(" ");
  Serial.print(grid_z[j]);
  Serial.print(" ");
  Serial.print(grid_index_L);
  Serial.print(" ");
  Serial.print(grid_index_R);
  Serial.print(" j = ");
  Serial.println(j);
  j++;
  if(j == 441) j = 0;
  
  if(Serial.available() > 0)
  {
    buff = Serial.read();
    if(buff == 'r') reset_background(field_L, field_R, bg_L, bg_R, end_of_startup);
  }
  
  delay(5);
}

void CreateGrid(int grid_x[], int grid_y[], int grid_z[], float height, float Br, float radius, float magnet_height)
{
  float u0 = 4 * 3.14159265359 * 0.0000001;
  float V = radius * radius * 3.14159265359 * magnet_height;
  float moment = (1 / u0) * Br * V;
  float e1 = u0 / (4 * 3.14159265359);
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


void read_values_to_arrays(int field_L[], int field_R[])
{
  field_L[0] = read_xL();
  field_L[1] = read_yL();
  field_L[2] = read_zL();
  field_R[0] = read_xR();
  field_R[1] = read_yR();
  field_R[2] = read_zR();
}
 
void config(void)
{
  SWireR.beginTransmission(MAG_ADDR); // transmit to device 0x0E
  SWireR.write(0x11);             // cntrl register2
  SWireR.write(0x80);             // write 0x80, enable auto resets
  SWireR.endTransmission();       // stop transmitting
  delay(15); 
  SWireR.beginTransmission(MAG_ADDR); // transmit to device 0x0E
  SWireR.write(0x10);             // cntrl register1
  SWireR.write(1);                // write 0x01, active mode
  SWireR.endTransmission();       // stop transmitting

  SWireL.beginTransmission(MAG_ADDR); // transmit to device 0x0E
  SWireL.write(0x11);             // cntrl register2
  SWireL.write(0x80);             // write 0x80, enable auto resets
  SWireL.endTransmission();       // stop transmitting
  delay(15); 
  SWireL.beginTransmission(MAG_ADDR); // transmit to device 0x0E
  SWireL.write(0x10);             // cntrl register1
  SWireL.write(1);                // write 0x01, active mode
  SWireL.endTransmission();       // stop transmitting
}
 
void reset_background(int field_L[], int field_R[], int bg_L[], int bg_R[], int end_of_startup)
{  
  for(int j = 0; j <= end_of_startup; j++)
  {
    if(j == end_of_startup)
    {
      for(int i = 0; i < 3; i++)
      {
        bg_L[i] = bg_L[i] / end_of_startup;
        bg_R[i] = bg_R[i] / end_of_startup;
      }
    }
    else
    {
      read_values_to_arrays(field_L, field_R);
      for(int i = 0; i < 3; i++)
      {
        if(field_L[i] > bit16max / 2) field_L[i] = field_L[i] - bit16max;
        if(field_R[i] > bit16max / 2) field_R[i] = field_R[i] - bit16max;
        bg_L[i] += field_L[i];
        bg_R[i] += field_R[i];
      }
    }
  }
}

void make_vectors(int field[], float vect[], float& vect_length)
{
  vect_length = 0;

  for(int i = 0; i < 3; i++) vect_length += pow(field[i], 2);
  vect_length = sqrt(vect_length);
  for(int i = 0; i < 3; i++) vect[i] = field[i]*1.0 / vect_length;  
}

int mag_read_registerL(int reg)
{
  int reg_val;
 
  SWireL.beginTransmission(MAG_ADDR); // transmit to device 0x0E
  SWireL.write(reg);              // x MSB reg
  SWireL.endTransmission();       // stop transmitting
  delayMicroseconds(2); //needs at least 1.3us free time between start and stop
 
  SWireL.requestFrom(MAG_ADDR, 1); // request 1 byte
  while(SWireL.available())    // slave may write less than requested
  { 
    reg_val = SWireL.read(); // read the byte
  } 
  return reg_val;
}
int mag_read_registerR(int reg)
{
  int reg_val;
 
  SWireR.beginTransmission(MAG_ADDR); // transmit to device 0x0E
  SWireR.write(reg);              // x MSB reg
  SWireR.endTransmission();       // stop transmitting
  delayMicroseconds(2); //needs at least 1.3us free time between start and stop
 
  SWireR.requestFrom(MAG_ADDR, 1); // request 1 byte
  while(SWireR.available())    // slave may write less than requested
  { 
    reg_val = SWireR.read(); // read the byte
  }
  return reg_val;
}
 
int mag_read_valueL(int msb_reg, int lsb_reg)
{
  int val_low, val_high;  //define the MSB and LSB
  val_high = mag_read_registerL(msb_reg);
  delayMicroseconds(2); //needs at least 1.3us free time between start and stop
  val_low = mag_read_registerL(lsb_reg);
  int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
  return out;
}
int mag_read_valueR(int msb_reg, int lsb_reg)
{
  int val_low, val_high;  //define the MSB and LSB
  val_high = mag_read_registerR(msb_reg);
  delayMicroseconds(2); //needs at least 1.3us free time between start and stop
  val_low = mag_read_registerR(lsb_reg);
  int out = (val_low|(val_high << 8)); //concatenate the MSB and LSB
  return out;
}
 
int read_xL(void)
{
  return mag_read_valueL(0x01, 0x02);
}
int read_xR(void)
{
  return mag_read_valueR(0x01, 0x02);
}
 
int read_yL(void)
{
  return mag_read_valueL(0x03, 0x04);
}
int read_yR(void)
{
  return mag_read_valueR(0x03, 0x04);
}
 
int read_zL(void)
{
  return mag_read_valueL(0x05, 0x06);
}
int read_zR(void)
{
  return mag_read_valueR(0x05, 0x06);
}

void print_values(float vect_L[], float vect_length_L, float vect_R[], float vect_length_R)
{
  Serial.print(" ");
  Serial.print(vect_L[0]);
  Serial.print(" ");    
  Serial.print(vect_L[1]);      
  Serial.print(" ");    
  Serial.print(vect_L[2]);
  Serial.print(" ");
  Serial.print(vect_R[0]);
  Serial.print(" ");    
  Serial.print(vect_R[1]);      
  Serial.print(" ");    
  Serial.println(vect_R[2]);
  //Serial.print(" Strength= "); 
  //Serial.println(vect_length);
  //location(vect, vect_length);
  //Serial.print(" section= "); 
  //Serial.print(q);
}
