#include <Arduino.h>

int fsrPin = 0;  // Pin A0 definieren
int sensorValue; // Analoges Ergebnis aus Pin A0
int voltage;     // Umgerechnetes Ergebnis in Volt

const int size = 5;

long voltageArray[size];
int counter = 0;

// Einstieg für Arduino, bevor loop()
void setup(void)
{
    Serial.begin(115200); // Baudrate setzen
}

// Berechnet Volt aus dem analogen Ergebnis
long calculateVoltage(long value)
{
    long bitMin = 0;
    long bitMax = 1023;
    long voltMin = 0;
    long voltMax = 5000;
    return (value - bitMin) * (voltMax - voltMin) / (bitMax - bitMin) + voltMin;
}

void printPlotter()
{
    Serial.println(voltage);
}

void printFoto(float s)
{
    if (s > 1000)
    {
        Serial.println("Foto!!!!!");
    }
}

// Werte auf dem seriellen Monitor ausgeben
void printMonitor(float s)
{

    Serial.print("Wert: Sensor = ");
    Serial.print(sensorValue);
    Serial.print(",    mV = ");
    Serial.print(voltage);
    Serial.print(",    s = ");
    Serial.print(s);

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

    if (s > 1000)
    {
        Serial.println("---------------- FOTO ------------------");
    }
}

void addValue(long value)
{
    if (counter < size)
    {
        voltageArray[counter] = value;
        counter++;
    }
    else
    {
        /*for (int i = 0; i < size, i++)
        {
            // solange die größe des arrays nicht erreicht ist
            // sind wir in diesem block
        }*/

        voltageArray[0] = voltageArray[1];
        voltageArray[1] = voltageArray[2];
        voltageArray[2] = voltageArray[3];
        voltageArray[3] = voltageArray[4];
        voltageArray[4] = value;
    }
}

float calculateAverage()
{
    float avg = 0;
    for (int i = 0; i < size; i++)
    {
        avg = avg + voltageArray[i];
    }

    /*avg = avg + voltageArray[0];
    avg = avg + voltageArray[1];
    avg = avg + voltageArray[2];
    avg = avg + voltageArray[3];
    avg = avg + voltageArray[4];*/
    return avg / size;
}

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

void loop(void)
{
    // 1. Sensor über definierten Pin auslesen
    sensorValue = analogRead(fsrPin);

    // 2. Wert in Volt umrechnen
    voltage = calculateVoltage(sensorValue);

    float arithmeticAverage = calculateArithmeticAverage();

    addValue(voltage);

    // 3. Wert ausgeben
    printMonitor(arithmeticAverage);
    //printPlotter();
    //printFoto(arithmeticAverage);

    delay(10);
}

