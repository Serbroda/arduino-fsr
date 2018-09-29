#include <Arduino.h>

int fsrPin = 0;  // Pin A0 definieren
int sensorValue; // Analoges Ergebnis aus Pin A0
int voltage;     // Umgerechnetes Ergebnis in Volt

void setup(void)
{
    Serial.begin(9600);
}

// Berechnet Volt aus dem analogen Ergebnis
long calculateVoltage(long value)
{
    long inputMinimum = 0;
    long inputMaximum = 1023;
    long outputMinimum = 0;
    long outputMaximum = 5000;
    return (value - inputMinimum) * (outputMaximum - outputMinimum) / (inputMaximum - inputMinimum) + outputMinimum;
}

void printPlotter()
{
    Serial.println(voltage);
}

// Werte auf dem seriellen Monitor ausgeben
void printMonitor()
{
    Serial.print("Wert: Roh = ");
    Serial.print(sensorValue);
    Serial.print(", mV = ");
    Serial.print(voltage);

    if (sensorValue < 10)
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
    }
}

void loop(void)
{
    // 1. Sensor über definierten Pin auslesen
    sensorValue = analogRead(fsrPin);

    // 2. Wert in Volt umrechnen
    voltage = calculateVoltage(sensorValue);

    // 3. Wert ausgeben
    printMonitor();
    //printPlotter();

    delay(10);
}
