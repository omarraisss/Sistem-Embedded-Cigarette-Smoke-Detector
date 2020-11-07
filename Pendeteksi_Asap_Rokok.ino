#define Do 131
#define Re 147
#define Mi 165
#define Fa 175
#define Sol 196
#define La 220
#define Ti 247
#define Do2 262
const int SensorPIN = 8;
const int LedPIN = 7;
const int spkPin = 11;
int duration = 100;
int hold = 100;
int KeadaanSensor = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SensorPIN, INPUT);
  pinMode(LedPIN, OUTPUT);
   pinMode(spkPin,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int BacaSensor = digitalRead(SensorPIN);

  if (BacaSensor == HIGH && KeadaanSensor != BacaSensor) {
    digitalWrite(LedPIN, HIGH);
    Serial.println("Terdeteksi Asap Rokok");
    song();
    KeadaanSensor = !KeadaanSensor;
  }
  else if (BacaSensor == LOW && KeadaanSensor != BacaSensor) {
    digitalWrite(LedPIN, LOW);
    Serial.println("Tidak ada asap rokok");
    KeadaanSensor = !KeadaanSensor;
  }
}
void song() {
  // put your main code here, to run repeatedly:
  tone(spkPin, Do, duration);
  delay(hold);
  tone(spkPin, Re, duration);
  delay(hold);
  tone(spkPin, Mi, duration);
  delay(hold);
  tone(spkPin, Fa, duration);
  delay(hold);
  tone(spkPin, Sol, duration);
  delay(hold);
  tone(spkPin, La, duration);
  delay(hold);
  tone(spkPin, Ti, duration);
  delay(hold);
  tone(spkPin, Do2, duration);
  delay(hold);
}
