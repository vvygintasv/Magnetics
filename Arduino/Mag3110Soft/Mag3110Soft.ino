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
int koord_kaire[3];
int koord_desine[3];

 
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
  SWireR.begin();
  SWireL.begin();
  bit16max = 65536;
  config();            // turn the MAG3110 on
}
 
void loop()
{
  read_values_to_arrays(koord_kaire, koord_desine);
  for(int i = 0; i < 3; i++)
  {
    if(koord_kaire[i] > bit16max / 2) koord_kaire[i] = koord_kaire[i] - bit16max;
    if(koord_desine[i] > bit16max / 2) koord_desine[i] = koord_desine[i] - bit16max;
  }
  print_values(koord_kaire, koord_desine);

  
  delay(5);
}

void read_values_to_arrays(int koord_kaire[], int koord_desine[])
{
  koord_kaire[0] = read_xL();
  koord_kaire[1] = read_yL();
  koord_kaire[2] = read_zL();
  koord_desine[0] = read_xR();
  koord_desine[1] = read_yR();
  koord_desine[2] = read_zR();
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
 
void print_values(int koord_kaire[], int koord_desine[])
{
  //Serial.print("Left: ");
  //Serial.print("x=");
  Serial.print(koord_kaire[0]);
  Serial.print(" ");  
  //Serial.print("y=");    
  Serial.print(koord_kaire[1]);
  Serial.print(" ");       
  //Serial.print("z=");    
  Serial.println(koord_kaire[2]);
  Serial.print(" ");  
  //Serial.print("  Right: ");
  //Serial.print("x=");
  //Serial.print(koord_desine[0]);
  Serial.print(" ");  
  //Serial.print("y=");    
  ///Serial.print(koord_desine[1]);
  Serial.print(" ");       
  //Serial.print("z=");    
  //Serial.println(koord_desine[2]);
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
