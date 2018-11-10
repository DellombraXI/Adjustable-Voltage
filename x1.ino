int LED1 = 3;
int LED2 = 7;
int voltage;
int brightness = voltage*51;
unsigned long oldmillis;
int interval = 100;
int flag;
unsigned long newserial;
unsigned long oldserial = 0;

void setup() {

  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  Serial.println("Enter desired voltage output to LED");
}

void loop() {
  if (Serial.available() > 0) {
    voltage = Serial.parseInt();
    Serial.read();  // consume newline character

    Serial.print("Got: ");
    Serial.println(voltage);
  }
  
  unsigned long newmillis = millis();
  if (newmillis - oldmillis >= interval){
      oldmillis = newmillis;
     Serial.println(voltage);
  }

  analogWrite(LED1, brightness);

}
