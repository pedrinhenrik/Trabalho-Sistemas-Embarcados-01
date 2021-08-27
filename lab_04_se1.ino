
// include the library code:
#include <LiquidCrystal.h>

int buzzer = 8;
int fotoresistor = A0;
int leituraFotoresistor;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); // Inicia monitor serial
  pinMode(8, OUTPUT); // Seta o pino do buzzer como saída
  pinMode(fotoresistor, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  leituraFotoresistor = analogRead(fotoresistor); // Faz a leitura do fotoresistor
  lcd.print(leituraFotoresistor);
  Serial.println(leituraFotoresistor); // Printa no serial o valor da leitura
  if(leituraFotoresistor < 800){
    tone(8, 440, 100); // Condição para ligar o buzzer
  }
  else{
    digitalWrite(buzzer,LOW); // Condição para desligar o buzzer
  }
}
 