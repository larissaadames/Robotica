#include <Vector.h>

//CORES
#define LEDRED 2
#define LEDYELLOW 5
#define LEDGREEN 9
#define LEDBLUE 12

//botoes
const int ButtonRed = 3;
const int ButtonYellow = 6;
const int ButtonGreen = 10;
const int ButtonBlue = 13;

//numero de rodadas e numero maximo do vetor
#define MAX_ROUNDS 15

//criacao do TIPO cor tlg
enum color {
  red,
  yellow,
  green,
  blue
};

const Vector<color> sequence;
long randNumber;

void setup() {
  Serial.begin(9600);
  //se nao iniciar a serial o codigo para aqui
  while (!Serial);
  //incersao das variaveis do vetor
  sequence.push_back(red);
  sequence.push_back(yellow);
  sequence.push_back(green);
  sequence.push_back(blue);
  //maximo de variaveis do vetor consequentemente o numero de rodadas
  color colorSize[MAX_ROUNDS];
  sequence.setStorage(colorSize);
  //random ne fzr oq
  randomSeed(analogRead(0));
  //leds
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  //btoes
  pinMode(ButtonRed, INPUT);
  pinMode(ButtonYellow, INPUT);
  pinMode(ButtonGreen, INPUT);
  pinMode(ButtonBlue, INPUT);
}


void loop() {
  randNumber = random(1, 5);
  //inicial do jogo
  digitalWrite(LEDRED, HIGH);
  digitalWrite(LEDYELLOW, HIGH);
  digitalWrite(LEDGREEN, HIGH);
  digitalWrite(LEDBLUE, HIGH);
  delay(2000);
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDYELLOW, LOW);
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDBLUE, LOW);

  if (checkButton() == ButtonRed || checkButton() == ButtonYellow || checkButton() == ButtonGreen || checkButton() == ButtonBlue) {
    if (randNumber == 1) {
      digitalWrite(LEDRED, HIGH);
      delay(1000);
      digitalWrite(LEDRED, LOW);
    }
    else if (randNumber == 2) {
      digitalWrite(LEDYELLOW, HIGH);
      delay(1000);
      digitalWrite(LEDYELLOW, LOW);
    }
    else if (randNumber == 3) {
      digitalWrite(LEDGREEN, HIGH);
      delay(1000);
      digitalWrite(LEDGREEN, LOW);
    }
    else if (randNumber == 4) {\
      digitalWrite(LEDBLUE, HIGH);
      delay(1000);
      digitalWrite(LEDBLUE, LOW);
    }
  }
}
