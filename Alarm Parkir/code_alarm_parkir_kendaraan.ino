/*** DESAIN DAN SIMULASI ALARM PARKIR KENDARAAN 
 *  ELECTRONICS TIPS & TRICK
 *  TINKERCAD SIMULATION
 */

 /***************************
ALARM PARKIR KENDARAAN
****************************/                     
/*** DESAIN DAN SIMULASI ALARM PARKIR KENDARAAN 
 *  ELECTRONICS TIPS & TRICK
 *  TINKERCAD SIMULATION
 */

 /***************************
ALARM PARKIR KENDARAAN
****************************/                     

// Pendefinisian Pin dan Library:
#define TRIGPIN 6
#define ECHOPIN 7
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9,10,11,12,13);
int jarak, timer; // Deklarasi variabel

// Membuat Fungsi Setup
void setup() {
  lcd.begin(16, 2);
  lcd.print("   ALARM PARKIR");
  lcd.setCursor(0, 1);
  lcd.print("      MOBIL    ");
  delay(2000);
  lcd.clear();
  lcd.print("Status=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(5, OUTPUT); // Pin buzzer sebagai OUTPUT
}

// Membuat fungsi loop untuk pengukuran jarak
void loop() {
  // Proses pengukuran jarak menggunakan sensor ultrasonik
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak = timer / 58;                        

  // Logika status dan jarak alarm
  if (jarak > 200) { // Status AMAN: jarak > 200 cm → Tidak ada alarm.
      lcd.setCursor(7, 0);
      lcd.print("AMAN   ");
      noTone(5); // Matikan buzzer sepenuhnya
  } 
  else if (jarak > 150) { // Status AWAS:  Jarak 150-200 cm → Buzzer berbunyi dengan interval 500 ms.
      lcd.setCursor(7, 0);
      lcd.print("AWAS   ");
      tone(5, 430); // Buzzer menyala
      delay(500);
      noTone(5); // Matikan buzzer
      delay(500);
  } 
  else if (jarak > 100) { // Status WASPADA: Jarak 100-150 cm → Buzzer berbunyi dengan interval 300 ms.
      lcd.setCursor(7, 0);
      lcd.print("WASPADA");
      tone(5, 430); // Buzzer menyala
      delay(300);
      noTone(5); // Matikan buzzer
      delay(300);
  } 
  else { // Status BAHAYA: Jarak ≤ 100 cm → Buzzer berbunyi dengan interval 100 ms.
      lcd.setCursor(7, 0);
      lcd.print("BAHAYA ");
      tone(5, 430); // Buzzer menyala
      delay(100);
      noTone(5); // Matikan buzzer
      delay(100);
  }
}
