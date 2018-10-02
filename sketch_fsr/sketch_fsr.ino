#include <Arduino.h>

int fsrPin = 0;  // Pin A0 definieren
int sensorValue; // Analoges Ergebnis aus Pin A0 in bits
long voltage;     // Umgerechnetes Ergebnis in Volt
int weight;
float arithmeticAverage;

const int size = 5;
long voltageArray[size];


// Einstieg für Arduino, bevor loop()
void setup(void)
{
    Serial.begin(115200); // Baudrate setzen
}


/*
 * ----------------------
 *    Berechnungen
 * -----------------------
 */

// Berechnet den Mittelwert der Werte aus dem Array
float calculateAverage()
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + voltageArray[i];
    }

    return sum / size;
}

// Berechnet den arithmetischen Mittelwert des arrays
float calculateArithmeticAverage()
{
    float average = calculateAverage();

    float s = 0;
    for (int i = 0; i < size; i++)
    {
        s = s + powf(average - voltageArray[i], 2);
    }

    s = s / size;
    s = powf(s, 0.5);
    return s;
}

// Berechnet Volt aus dem analogen Ergebnis
long calculateVoltage()
{
    long bitMin = 0;
    long bitMax = 1023;
    long voltMin = 0;
    long voltMax = 5000;
    return (sensorValue - bitMin) * (voltMax - voltMin) / (bitMax - bitMin) + voltMin; // gemessener Bitwert * (Volt pro Bit)
}

int calculateWeight() {
  long voltMin = 0;
  long voltMax = 2700;
  long weightMin = 0;
  long weightMax = 300;
    
  if(voltage <= 2700) {
    
  } else if (voltage <= 3500) {
    voltMin = 2701;
    voltMax = 3500;
    weightMin = 301;
    weightMax = 500;
  } else {
    voltMin = 3501;
    voltMax = 3780;
    weightMin = 501;
    weightMax = 650;
  }

  return (voltage - voltMin) * (weightMax - weightMin) / (voltMax - voltMin) + weightMin; // Volt Fallabhängig in Gramm umrechnen
}


/*
 * ----------------------
 *    Ausgaben
 * -----------------------
 */

void printPlotter()
{
    Serial.println(voltage);
}


void printWeight() {
  Serial.print("Gewicht = ");
  Serial.print(weight);
  Serial.println("g");
}

// Werte auf dem seriellen Monitor ausgeben
void printMonitor()
{

    Serial.print("Wert: Sensor = ");
    Serial.print(sensorValue);
    Serial.print(",    mV = ");
    Serial.print(voltage);
    Serial.print(",    s = ");
    Serial.println(arithmeticAverage);


    /*if (sensorValue < 10)
    {
        Serial.println(" - Nicht berührt");
    }
    else if (sensorValue < 100)
    {
        Serial.println(" - Leicht berührt");
    }
    else if (sensorValue < 300)
    {
        Serial.println(" - Leicht gedrückt");
    }
    else if (sensorValue < 600)
    {
        Serial.println(" - Mittel gedrückt");
    }
    else
    {
        Serial.println(" - Hart gedrückt");
    }*/

    if (arithmeticAverage > 1000)
    {
        Serial.println("---------------- FOTO ------------------");
    }

}


/*
 * ----------------------
 *    Loop
 * -----------------------
 */

// Fügt ein Wert in das Array hinzu
void addValue(long value)
{

    for (int i = 1; i < size; i++)
    {
        voltageArray[i-1] = voltageArray[i];
    }

    voltageArray[size-1] = value;

    /*voltageArray[0] = voltageArray[1];
    voltageArray[1] = voltageArray[2];
    voltageArray[2] = voltageArray[3];
    voltageArray[3] = voltageArray[4];
    
    voltageArray[4] = value;*/
   
}

void loop(void)
{
    // 1. SensorPin auslesen in Bits
    sensorValue = analogRead(fsrPin);

    // 2. Wert in Volt umrechnen
    voltage = calculateVoltage();

    arithmeticAverage = calculateArithmeticAverage();//der Mittelwert für den Trigger wird berechnet

    addValue(voltage); //der Spannungsstring wird mit Werten 

    weight = calculateWeight();
    

    // 3. Wert ausgeben in Monitor oder Plotter
    //printMonitor();
    printPlotter();
    printWeight();

    delay(100);
}
