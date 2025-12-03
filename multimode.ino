#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32,16,2);  

#define ledR 11
#define ledB 9
#define ledG 8

#define trig 5
#define echo 4

#define butt 3
#define tempPin A0

long jarak = 0;
long waktu = 0;
int mode = 0;
int save = 0;
char input;

void setup()
{
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(butt, INPUT);
  
  lcd.init();
  lcd.display();
  
  attachInterrupt(digitalPinToInterrupt(butt), changeMode, RISING);
}

void loop()
{
  switch(mode) {
    case 0:
    	mode0();
    	break;
    case 1:
   		mode1();
    	break;
    case 2:
    	mode2();
    	break;
    case 3:
    	mode3();
    	break;
    case 4:
    	if(save != 4) {
    lcd.clear();
    save = 4;
  }
  		lcd.setCursor(0,0);
        lcd.println("red");
          digitalWrite(ledR, HIGH);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, LOW);
          delay(1500);
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, LOW);
  	lcd.clear();
         lcd.println("yellow");
          digitalWrite(ledR, HIGH);
          digitalWrite(ledG, HIGH);
          digitalWrite(ledB, LOW);
          delay(1500);
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, LOW);
  lcd.clear();
  		lcd.println("green");
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, HIGH);
          digitalWrite(ledB, LOW);
          delay(1500);
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, LOW);
  lcd.clear();
 	 	lcd.println("blue");
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, HIGH);
          delay(1500);
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, LOW);
  lcd.clear();
  		lcd.println("purple");
          digitalWrite(ledR, HIGH);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, HIGH);
          delay(1500);
          digitalWrite(ledR, LOW);
          digitalWrite(ledG, LOW);
          digitalWrite(ledB, LOW);
  lcd.clear();
    delay(1500);
    	break;
  }
  
  if (Serial.available()) {
        input = Serial.read();
        if (input == '0') {
          mode = 0;          
        } else if (input == '1') {
          mode = 1; 
        } else if (input == '2') {
          mode = 2; 
        } else if (input == '3') {
          mode = 3; 
        } else if (input == '4') {
          mode = 4; 
        } else {
          Serial.println("Input Salah");
        }
  }
  delay(500);
}
      
void changeMode() {
  Serial.println(mode);
  if (mode == 4) {
    mode = 0;
  } else {
    ++mode;
  }
}

void mode0() {
  if(save != 0) {
    lcd.clear();
    save = 0;
  }
  lcd.noBacklight();
  lcd.setCursor(0,0);
  lcd.print("Athallah J");
  lcd.setCursor(0,1);
  lcd.print("123230230");
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
}
      
void mode1() {
  if (save != 1) {
    lcd.clear();
    save = 1;
  }
  
  lcd.backlight();
  lcd.setCursor(0,0); 
  lcd.print("MODE 1");
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
  clearLine();
  
  int sensor = analogRead(tempPin);
  float volt;
  float temperature;
  volt = sensor * (5.0 / 1023.0);
  temperature = (volt - 0.5) * 100.0;
  lcd.setCursor(0,1);
  lcd.print(temperature); 
  lcd.print(" *C");
}
      
void mode2() {
  if(save != 2) {
    lcd.clear();
    save = 2;
  }
  
  lcd.setCursor(0,0);
  lcd.print("MODE 2");
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, HIGH);
  clearLine();
  
  jarak = count();
  lcd.setCursor(0,1);
  lcd.print(jarak);
  lcd.print (" cm");
}
                 
void mode3() {
  if(save != 3) {
    lcd.clear();
    save = 3;
  }
  
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, LOW);
  doubleClear();
  
  lcd.setCursor(0,0);
  int sensor = analogRead(tempPin);
  float volt;
  float temperature;
  volt = sensor * (5.0 / 1023.0);
  temperature = (volt - 0.5) * 100.0;
  lcd.print(temperature); 
  lcd.print(" *C");
  
  jarak = count();
  lcd.setCursor(0,1);
  lcd.print(jarak);
  lcd.print (" cm");
}

void mode4() {
  
}
                 
long count() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  waktu  = pulseIn(echo, HIGH);
  return (waktu * 0.0343) / 2;
}
                 
void clearLine() {
  lcd.setCursor(0,1);
  for(int i = 0; i<16; i++) {
    lcd.print(" ");
  }
}

void clear() {
  lcd.setCursor(0,0);
  for(int i = 0; i<16; i++) {
    lcd.print(" ");
  }
}

void doubleClear() {
  lcd.setCursor(0,0);
  for(int i = 0; i<16; i++) {
    lcd.print(" ");
  }
  lcd.setCursor(0,1);
  for(int i = 0; i<16; i++) {
    lcd.print(" ");
  }
}

                 
