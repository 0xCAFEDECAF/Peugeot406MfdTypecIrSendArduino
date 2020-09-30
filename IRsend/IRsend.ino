
#include <IRremote.h>

// For Arduino Uno: pin 3
IRsend irsend;

// Raw IR LED timing values, to be passed to irsend.sendRaw
const unsigned int irTmgMenu[] PROGMEM = {3015,5895,1035,2940,1035,1950,1035,945,1035,1950,1035,2940,1035,945,1035};
const unsigned int irTmgMod[] PROGMEM = {3030,5895,1035,2940,1035,1935,1035,960,1035,1935,1050,1935,1050,2925,1035};
const unsigned int irTmgEsc[] PROGMEM = {3030,5880,1035,2940,1050,1935,1035,960,1035,2940,1035,945,1035,1950,1035};
const unsigned int irTmgVal[] PROGMEM = {3015,5895,1035,2940,1035,1950,1035,1935,1050,945,1035,1950,1035,1935,1035};
const unsigned int irTmgLeft[] PROGMEM = {3045,5895,1035,2940,1035,945,1035,2940,1050,1935,1035,945,1035,1950,1050};
const unsigned int irTmgRight[] PROGMEM = {3060,5895,1035,2925,1050,945,1035,2940,1035,945,1050,2925,1050,945,1035};
const unsigned int irTmgUp[] PROGMEM = {3045,5895,1050,2925,1035,960,1035,2925,1050,945,1035,1950,1035,2940,1035};
const unsigned int irTmgDown[] PROGMEM = {3045,5895,1035,2940,1035,960,1035,1935,1035,2940,1050,1935,1035,945,1050};

char recvOneChar()
{
    if (Serial.available() > 0) return Serial.read();
    return 0;
} // recvOneChar

#define KHZ 38

void sendIrCodes(unsigned int* pgm_array, unsigned int* buffer, int n)
{
    for (int i = 0; i < n; i++) buffer[i] = pgm_read_word(&pgm_array[i]);

    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
    irsend.sendRaw(buffer, n, KHZ);
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
} // sendIrCodes

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);  // Initialize onboard LED as output 
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off

    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    Serial.println();
    Serial.println("Type one of the following letters, then hit <Enter> (or click the 'Send' button):");
    Serial.println("-> menu = m");
    Serial.println("-> mod = o");
    Serial.println("-> esc = e");
    Serial.println("-> val = v");
    Serial.println("-> left = l");
    Serial.println("-> right = r");
    Serial.println("-> up = u");
    Serial.println("-> down = d");
} // setup

void loop()
{
    char c = recvOneChar();
    if (c == 'm')
    {
        const int n = sizeof(irTmgMenu) / sizeof(irTmgMenu[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'menu'...");
        sendIrCodes(irTmgMenu, buffer, n);
    }
    else if (c == 'o')
    {
        const int n = sizeof(irTmgMod) / sizeof(irTmgMod[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'mod'...");
        sendIrCodes(irTmgMod, buffer, n);
    }
    else if (c == 'e')
    {
        const int n = sizeof(irTmgEsc) / sizeof(irTmgEsc[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'esc'...");
        sendIrCodes(irTmgEsc, buffer, n);
    }
    else if (c == 'v')
    {
        const int n = sizeof(irTmgVal) / sizeof(irTmgVal[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'val'...");
        sendIrCodes(irTmgVal, buffer, n);
    }
    else if (c == 'l')
    {
        const int n = sizeof(irTmgLeft) / sizeof(irTmgLeft[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'left'...");
        sendIrCodes(irTmgLeft, buffer, n);
    }
    else if (c == 'r')
    {
        const int n = sizeof(irTmgRight) / sizeof(irTmgRight[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'right'...");
        sendIrCodes(irTmgRight, buffer, n);
    }
    else if (c == 'u')
    {
        const int n = sizeof(irTmgUp) / sizeof(irTmgUp[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'up'...");
        sendIrCodes(irTmgUp, buffer, n);
    }
    else if (c == 'd')
    {
        const int n = sizeof(irTmgDown) / sizeof(irTmgDown[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'down'...");
        sendIrCodes(irTmgDown, buffer, n);
    } // if
} // loop
