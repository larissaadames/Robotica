#define led 2
//#define ledVerde 3
const int sensorLM35 = A0;
float temperaturaC = 0;
void setup()
{
  pinMode(led, OUTPUT);
  //pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int poten;
  analogRead (A1);
  poten = analogRead (A1);
  //Serial.println(poten);

  int valorSensor = analogRead(sensorLM35);
  float tensao = (valorSensor / 1024.0) * 5.0;
  temperaturaC = (tensao) * 100.0;
  delay(500);
  //valor central: 12
  Serial.println(temperaturaC);
  if (poten >= 511) {
    digitalWrite(led, HIGH);
  }
  else if (poten <= 511) {
    digitalWrite(led, LOW);
  }
}
