//#include <LiquidCrystal.h>

int sensorPin = A0;
int sensorValue = 0;
float Vout, Value_Kpa, Value_mmHg1, Value_mmHg;

//LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
    // lcd.begin(16, 2);
  // lcd.display();

}

void loop() {
  sensorValue = analogRead(sensorPin);
  Vout = (sensorValue * 0.00488);         //0.004594330400782013
  
  Value_Kpa = (Vout - 0.45)/0.09;
  Value_mmHg1 = Value_Kpa * 7.50061;       //7.50061561303
  Value_mmHg = Value_mmHg1 * 0.67;       //kalib
 // Value_mmHg = Value_mmHg1 - 20;       //kalib

  if(Value_mmHg1 < 0) Value_Kpa = 0, Value_mmHg = 0;

  Serial.print("Tekanan: ");
  Serial.print(Value_mmHg);
  Serial.println(" mmHg");


 //Serial.print(Vout);Serial.print("\t");Serial.print(Value_Kpa);Serial.print("\t");Serial.print(Value_mmHg);Serial.println("\t");
  // lcd.clear();
  // lcd.setCursor(0, 0);
  // lcd.print(Value_Kpa, 0);
  // lcd.print("Kpa");
  // lcd.setCursor(11, 0);
  // lcd.print(Vout);
  // lcd.print("V");

  // lcd.setCursor(0, 1);
  // lcd.print(Value_mmHg, 0);
  // lcd.print("mmHg");
 delay(500);
}
