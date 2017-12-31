#include <DigitalIO.h>

#define KEYS 49
#define COL_PINS 5
#define ROWS 10

// DigitalIO columnPins[COL_PINS];
// DigitalIO rowSelectClock;
// DigitalIO rowSelectReset;

int keyConversionBaseColumn[] = {
    6,
    7,
    8,
    9,
    10,
    1,
    2,
    3,
    4};

// void setup()
// {
//     // put your setup code here, to run once:
//     //   columnPins[0].begin(7);
//     //   columnPins[1].begin(8);
//     //   columnPins[2].begin(9);
//     //   columnPins[3].begin(10);
//     //   columnPins[4].begin(11);

//     pinMode(13, OUTPUT);
//     pinMode(12, OUTPUT);
//     pinMode(7, INPUT);
//     pinMode(8, INPUT);
//     pinMode(9, INPUT);
//     pinMode(10, INPUT);
//     pinMode(11, INPUT);

//     digitalWrite(12, HIGH);
//     digitalWrite(12, LOW);

//     //   for (int i = 0; i < ROWS; i++) {
//     //      int pin = 7+i;
//     //      columnPins[i].begin(pin);
//     //      Serial.println(pin);
//     //   }
//     //
//     //   rowSelectClock.begin(13);
//     //   rowSelectClock.mode(OUTPUT);
//     //   rowSelectReset.begin(12);
//     //   rowSelectReset.mode(OUTPUT);

//     Serial.begin(9600);
// }

// void loop()
// {
//     delay(500);
//     Serial.println("\n\n\n\n\n\n\n\n\n\n\n");
//     for (int i = 0; i < ROWS; i++)
//     {
//         delay(1);
//         Serial.print(i);
//         Serial.print(":   ");
//         digitalWrite(13, HIGH);
//         delay(1);
//         digitalWrite(13, LOW);

//         int key1 = digitalRead(7);
//         int key2 = digitalRead(8);
//         int key3 = digitalRead(9);
//         int key4 = digitalRead(10);
//         int key5 = digitalRead(11);

//         Serial.print(key1);
//         Serial.print(", ");
//         Serial.print(key2);
//         Serial.print(", ");
//         Serial.print(key3);
//         Serial.print(", ");
//         Serial.print(key4);
//         Serial.print(", ");
//         Serial.println(key5);
//     }

//     //  delay(250);
//     //  Serial.println("Alto!");
//     //  rowSelectClock.write(HIGH);
//     //  delay(250);
//     //  rowSelectClock.write(LOW);
//     //
//     //  for(unsigned char sRow = 0;sRow <= (KEYS/COL_PINS);sRow++) {
//     //    for(unsigned char sCol = 0;sCol < COL_PINS;sCol++) {
//     //      // read each column pin using an array of DigitalIO objects, its faster than digital read
//     //      // and portable to UNO, Mega, Leonardo, Teensy, Teensy 3 and Due in the future
//     //      // Direct port manipulation is faster, but not portable.
//     //      if(columnPins[sCol].read()) {
//     //        unsigned char sKey = (sRow<<3) + sCol;
//     //        // Do something with this key
//     //      }
//     //    }
//     //    clockKeyScanCounter(); // clock the 4017 to scan the next keypad row
//     //  }
// }

void clockKeyScanCounter()
{
}

int getKeyNumber(int matrixRow, int matrixColumn)
{
    return keyConversionBaseColumn[matrixRow] + ((COL_PINS - 1) - matrixColumn) * 10;
}
