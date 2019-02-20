const int Sensor = A0;
int inputVal = 0;

void setup() 
{                
  pinMode(Sensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop() 
{
inputVal = analogRead(Sensor);
Serial.println(inputVal);
delay(100);              // wait for a second
}
