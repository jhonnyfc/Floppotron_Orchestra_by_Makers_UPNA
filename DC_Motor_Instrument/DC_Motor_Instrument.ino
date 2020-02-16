/* This sketch will play a melody [In this case Twinkle, Twinkle, Little Star] on a DC motor using the L239D Motor Controller
*/

// Define needed notes for melodies here, from lowest frequency (in Hz) to highest
//We are using unsigned int because it is the only allowed data type for the tone() function.
const unsigned int NC4 = 262; // Actual value is 261.63, but 262 is close enough - I rounded for some other notes too
const unsigned int ND4 = 294;
const unsigned int NE4 = 330;
const unsigned int NF4 = 349;
const unsigned int NG4 = 392;
const unsigned int NA4 = 440;

const byte tonePin = 13;

const byte bpm = 100; // Put the bpm for the song here. Program automatically converts it to needed values. 
const int millisPerBeat = (float(1.0 / (float(bpm) / 60.0))) * 1000.0; // bpm / 60 converts to beats/second, 1 / converts to seconds/beat,
// and * 1000 converts to milliseconds

int SNote = millisPerBeat / 4; // Sixteenth note
int ENote = millisPerBeat / 2; // Eighth note
int QNote = millisPerBeat;     // Quarter Note
int HNote = millisPerBeat * 2; // Half Note
int WNote = millisPerBeat * 4; // Whole Note

const int melody[] = {NC4, NC4, NG4, NG4, NA4, NA4, NG4, NF4, NF4, NE4, NE4, ND4, ND4, NC4, NG4, NG4, NF4, NF4, NE4, NE4, ND4, NG4, NG4, NF4, NF4, NE4, NE4, ND4, NC4, NC4, NG4, NG4, NA4, NA4, NG4, NF4, NF4, NE4, NE4, ND4, ND4, NC4};
const int beat_values[] = {QNote, QNote, QNote, QNote, QNote, QNote, HNote, QNote, QNote, QNote, QNote, QNote, QNote, HNote, QNote, QNote, QNote, QNote, QNote, QNote, HNote, QNote, QNote, QNote, QNote, QNote, QNote, HNote, QNote, QNote, QNote, QNote, QNote, QNote, HNote, QNote, QNote, QNote, QNote, QNote, QNote, HNote};
const int NumberOfNotes = sizeof(melody) / 2; // sizeof returns number of bytes, but int is 16 bits, so divide by 2. 

void setup() {
  pinMode(tonePin, OUTPUT);
  //Serial.begin(9600); // For Debugging
}

void loop() {
  for (int i = 0; i < NumberOfNotes; i++) {
    unsigned long lastMillis = millis(); // this will overflow after about 11 1/2 days. You could override this by including a watchdog which would reset the program at a certain interval.
    while ((millis() - lastMillis) < beat_values[i]) {
      tone(tonePin, melody[i]);
    }
    noTone(3); // The '3' refers to pin 3, not 3ms.
    delay(millisPerBeat / 10); // separate different notes with the same tune.
  } 
  
  delay(5000); // delay before repeating the melody
}
