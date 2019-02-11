/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 6 -> HX711 CLK
 Arduino pin 5 -> HX711 DOUT
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/

#include "HX711.h"


HX711 scale1(PB5, PB6);
HX711 scale2(PB15, PB10);

//load cell, kurio laidai prilituoti prie plokstes be pinu, factor = 430 - pirmas
//load cell, kurio laidai prilituoti is nugaros ir turi pinus, factor = 450 - antras
float calibration_factor_1 = 430; // this calibration factor is adjusted according to my load cell
float calibration_factor_2 = 450; 
float units_1, units_2;
float last_ten_1[10], last_ten_2[10];
float ave_1, ave_2;
int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press a to increase calibration factor 1");
  Serial.println("Press z to decrease calibration factor 1");
  Serial.println("Press + to increase calibration factor 2");
  Serial.println("Press - to decrease calibration factor 2");

  scale1.set_scale();
  scale1.tare();  //Reset the scale to 0
  scale2.set_scale();
  scale2.tare();  //Reset the scale to 0

  long zero_factor_1 = scale1.read_average(); //Get a baseline reading
  long zero_factor_2 = scale2.read_average(); //Get a baseline reading
  Serial.print("Zero factor 1: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor_1);
  Serial.print("Zero factor 2: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor_2);
}

void loop() {

  scale1.set_scale(calibration_factor_1); //Adjust to this calibration factor
  scale2.set_scale(calibration_factor_2); //Adjust to this calibration factor

  Serial.print("Reading: ");
  units_1 = scale1.get_units(), 10;
  units_2 = scale2.get_units(), 10;
  if (units_1 < 0)
  {
    units_1 = 0.00;
  }
  if (units_2 < 0)
  {
    units_2 = 0.00;
  }
  last_ten_1[i] = units_1;
  last_ten_2[i] = units_2;
  i++;
  if(i == 10) i = 0;
  ave_1 = ten_average(last_ten_1);
  ave_2 = ten_average(last_ten_2);
  String timestring = millis();
  Serial.print(timestring);
   Serial.print('\t');
  Serial.print(" First: "); 
  Serial.print('\t');
  Serial.print(units_1);
   Serial.print('\t');
  Serial.print(" g"); 
   Serial.print('\t');
  Serial.print(" calib_fact: ");
   Serial.print('\t');
  Serial.print(calibration_factor_1);
   Serial.print('\t');
  Serial.print(" avg: ");
   Serial.print('\t');
  Serial.print(ave_1);
   Serial.print('\t');
  Serial.print(" Second: "); 
   Serial.print('\t');
  Serial.print(units_2);
   Serial.print('\t');
  Serial.print(" g"); 
   Serial.print('\t');
  Serial.print(" calib_fact: ");
   Serial.print('\t');
  Serial.print(calibration_factor_2);
   Serial.print('\t');
  Serial.print(" avg: ");
   Serial.print('\t');
  Serial.print(ave_2);
  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == 'a')
      calibration_factor_1 += 1;
    else if(temp == 'z')
      calibration_factor_1 -= 1;
    if(temp == '+')
      calibration_factor_2 += 1;
    else if(temp == '-')
      calibration_factor_2 -= 1;
  }

  delay(10);
}

float ten_average(float values[])
{
  float sum = 0;
  for(int i = 0; i < 10; i++)
  {
    sum = sum + values[i];
  }
  sum = sum / 10;
  return sum;
}
