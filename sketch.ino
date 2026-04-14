# include <Servo.h>

Servo S;  

int senzor = 7, verde = 2, rosu = 4;

void setup() {
  pinMode(senzor, INPUT);

  S.attach(A1); 
  pinMode (A1, OUTPUT);
  S.write(90);

  Serial.begin(9600);

  pinMode(rosu, OUTPUT);
  pinMode(verde, OUTPUT);
}
int rot = 0;
void Roteste_Dreapta()
{

  if (rot == 0)
  {
    for (int i = 0; i<=180; i+=20)
  {
    S.write(i);
    delay(50);
  }
  rot = 1;
  }
}
void Roteste_Stanga()
{

    S.write(0);
    rot = 1;

}
void Aprinde_Verde()
{
  digitalWrite(verde, 1);
  delay(100);
  digitalWrite(verde, 0);
  delay(100);
}
void loop() {
  int val = digitalRead(senzor);

  if (val == 0) {
    Serial.println("OBSTACOL DETECTAT");
    digitalWrite(rosu, 1);
    digitalWrite(verde, 0);
    Roteste_Dreapta();
  } else {
    digitalWrite(rosu, 0);
    Aprinde_Verde();
    Serial.println("LIBER");
    Roteste_Stanga();
    rot = 0;
  }

  delay(200);
}
