const int suhuPin = A0;
const int cahayaPin = A1;
const int hujanPin = A2;

const int lampuPin = 3;
const int tutupJendelaPin = 4;

void setup() {
  // Set pin output
  pinMode(kipasPin, OUTPUT);
  pinMode(lampuPin, OUTPUT);
  pinMode(tutupJendelaPin, OUTPUT);
  
  // Mulai serial communication
  Serial.begin(9600);
}

void loop() {
  // nilai sensor suhu
  float suhu = analogRead(suhuPin);
  suhu = (suhu * 5.0) / 1024.0; // Konversi nilai analog menjadi voltase
  suhu = suhu * 100.0; // Konversi voltase menjadi derajat Celcius
  
  // Baca nilai sensor cahaya
  int cahaya = analogRead(cahayaPin);
  
  // Baca nilai sensor hujan
  int hujan = analogRead(hujanPin);
  
  // Cek suhu
  if (suhu s>= 30) {
    digitalWrite(kipasPin, HIGH);
  } else {
    digitalWrite(kipasPin, LOW); // Matikan kipas
  }
  
  // Cek cahaya
  if (cahaya < 200) {
    digitalWrite(lampuPin, HIGH); // Nyalakan lampu
  } else {
    digitalWrite(lampuPin, LOW); // Matikan lampu
  }
  
  // Cek hujan
  if (hujan < 500) {
    digitalWrite(tutupJendelaPin, HIGH); // Tutup jendela
  } else {
    digitalWrite(tutupJendelaPin, LOW); // Buka jendela
  }
  
  // Tampilkan nilai sensor pada Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" C, Cahaya: ");
  Serial.print(cahaya);
  Serial.print(", Hujan: ");
  Serial.print(hujan);
  Serial.println();
  
  delay(1000); // Tunggu 1 detik sebelum membaca sensor lagi
}
