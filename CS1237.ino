#include <C1237.h>
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  CS1237Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //resultWeight = getValue;
  int measureVol = getValue(10);
  int minusOne = 0xFFFFFF;
  int minValue = 0x800000;
  int maxValue = 0x7FFFFF;
  double measureResult;
  double refVol = ( double ) ( 0.5 * 5.1003 / 128 );
  if ( measureVol > maxValue ) {
      measureResult = ( double ) ( minusOne - measureVol ) / maxValue * refVol ;
  }
  else { measureResult = ( double )  measureVol  / maxValue * refVol;}
  Serial.print(measureResult * 1000);
  Serial.println();
  delay(3000);
}
