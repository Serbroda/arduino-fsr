
int fsrPin = 0;   // Port 0 definieren
int fsrReading;   // Analoges Ergebnis aus Port 0
int fsrVoltage;   // Umgerechnetes Ergebnis in Volt
 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop(void) {
  fsrReading = readValue();  
 
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);     // the raw analog reading

  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  Serial.print("Voltage reading in mV = ");
  Serial.print(fsrVoltage);  
 
  // We'll have a few threshholds, qualitatively determined
  if (fsrReading < 10) {
    Serial.println(" - No pressure");
  } else if (fsrReading < 200) {
    Serial.println(" - Light touch");
  } else if (fsrReading < 500) {
    Serial.println(" - Light squeeze");
  } else if (fsrReading < 800) {
    Serial.println(" - Medium squeeze");
  } else {
    Serial.println(" - Big squeeze");
  }

  delay(1000);
} 

int readValue() {
  return analogRead(fsrPin);
}



