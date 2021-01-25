#include <Button.h>
//char incomingByte = 'a';
Button button90(25);
Button button264(26);
Button buttonOnOFF(27);
bool ACOnOFF = false;
void setup() {
  // put your setup code here, to run once:
  button90.begin();
  button264.begin();
  buttonOnOFF.begin();
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (button90.pressed()) {
    Serial.write("VOLT 90;FREQ 47\n");
    }
  if (button264.pressed()) {
    Serial.write("VOLT 264;FREQ 63\n");
    }
  if (buttonOnOFF.pressed()) {
    ACOnOFF = !ACOnOFF;
    if (ACOnOFF == true){Serial.write("OUTPut ON\n");}
    if (ACOnOFF == false){Serial.write("OUTPut OFF\n");}
    }
  
  /*if (Serial.available() > 0 ) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte);
  };
  //delay(3000);
  Serial.write("OUTPut OFF\n");
  Serial.write("VOLT 264;FREQ 63\n");
  Serial.write("OUTPut ON\n");
  delay(3000);
  Serial.write("OUTPut OFF\n");*/
}
