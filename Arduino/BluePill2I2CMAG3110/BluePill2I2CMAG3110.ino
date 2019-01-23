// --------------------------------------
// i2c_scanner
//
//

#include <SoftWire.h>
/////////////////////////////////////////
// MAG3110 I2C Address             //
/////////////////////////////////////////

#define MAG3110_I2C_ADDRESS 0x0E

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
int koord_kaire[3];
int koord_desine[3];

int a10, a11, a12, a20, a21, a22, a23, a30, a32, a33, a34, a40, a43, a44;
int a2x;
int a2y;
int a3x;
int a3y;
int a4x;
int a4y;

void setup() {
  Serial.begin(115200);
  SWireR.begin();
  SWireL.begin();

  SWireR.beginTransmission(MAG3110_I2C_ADDRESS); //open communication with HMC5883
  SWireR.write(MAG3110_CTRL_REG1); //select mode register
  SWireR.write(MAG3110_DR_OS_20_32); //continuous measurement mode
  SWireR.endTransmission();

  SWireL.beginTransmission(MAG3110_I2C_ADDRESS); //open communication with HMC5883
  SWireL.write(MAG3110_CTRL_REG1); //select mode register
  SWireL.write(MAG3110_DR_OS_20_32); //continuous measurement mode
  SWireL.endTransmission();

  Serial.println("\nSoftware I2C.. Scanner");
}


void loop() {

  readMagL(&koord_kaire[0], &koord_kaire[1], &koord_kaire[2]);
  readMagR(&koord_desine[0], &koord_desine[1], &koord_desine[2]);

  Serial.print("Kaire: ");
  Serial.print(koord_kaire[0]);
  Serial.print(" ");
  Serial.print(koord_kaire[1]);
  Serial.print(" ");
  Serial.print(koord_kaire[2]);
  Serial.print(" Desine: ");
  Serial.print(koord_desine[0]);
  Serial.print(" ");
  Serial.print(koord_desine[1]);
  Serial.print(" ");
  Serial.println(koord_desine[2]);

  a10 = (-2 * a2x * koord_kaire[0]) - (2 * a2y * koord_kaire[1]);
  a11 = (2 * koord_kaire[0] ^ 2) + (2 * koord_kaire[1] ^ 2) + (2 * koord_kaire[2] ^ 2);
  a12 = (-2 * koord_kaire[0] * koord_desine[0]) - (2 * koord_kaire[1] * koord_desine[1]) - (2 * koord_kaire[2] * koord_desine[2]);

  a20 = (2 * a2x * koord_desine[0]) + (2 * a2y * koord_desine[1]);
  a21 = a12;
  a22 = (2 * koord_desine[0]^2) + (2 * koord_desine[1]^2) + (2 * koord_desine[2]^2);
  
  t1 = ((a12 * a20) - (a10 * a22)) / ((a11 * a22) - (a12 * a21));
  t2 = ((a11 * a20) - (a10 * a21)) / ((a12 * a21) - (a11 * a22));
}
