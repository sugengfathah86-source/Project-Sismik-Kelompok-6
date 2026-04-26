#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Alamat LCD biasanya 0x27 atau 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int motorPin = 6;

int val = 0;
float temperatureC = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);

  lcd.init();        // inisialisasi LCD
  lcd.backlight();   // nyalakan lampu LCD

  lcd.setCursor(0,0);
  lcd.print("Temp Control");
  lcd.setCursor(0,1);
  lcd.print("Fan System");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Baca sensor
  val = analogRead(sensorPin);

  // Konversi ke tegangan
  float voltage = val * 5.0;
  voltage /= 1024.0;

  // Konversi ke suhu (TMP36)
  temperatureC = (voltage - 0.5) * 100;

  // Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Tampilkan ke LCD
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print((char)223); // simbol derajat
  lcd.print("C   ");

  // Kontrol motor + tampilkan status
  lcd.setCursor(0,1);

  if (temperatureC < 20) {
    analogWrite(motorPin, 0);
    lcd.print("Fan: OFF      ");
  }
  else if (temperatureC < 30) {
    analogWrite(motorPin, 40);
    lcd.print("Fan: LOW      ");
  }
  else if (temperatureC < 40) {
    analogWrite(motorPin, 180);
    lcd.print("Fan: MEDIUM   ");
  }
  else {
    analogWrite(motorPin, 255);
    lcd.print("Fan: SUPER HIGH     ");
  }

  delay(1000);
}
