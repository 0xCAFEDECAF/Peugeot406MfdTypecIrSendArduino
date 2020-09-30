
#include <IRremote.h>

// For Arduino Uno: pin 3
IRsend irsend;

// Mark and space, in microseconds
#define B_S 1050,950
#define B_M 1050,1950
#define B_L 1050,2900

const unsigned int CodesMenu[] PROGMEM =
{
    3015,5895, 1035,2940, 1035,1950, 1035,945, 1035,1950, 1035,2940, 1035,945, 1035
};
const unsigned int CodesMod[] PROGMEM =
{
    3030,5895, 1035,2940, 1035,1935, 1035,960, 1035,1935, 1050,1935, 1050,2925, 1035
};
const unsigned int CodesEsc[] PROGMEM =
{
    3030,5880, 1035,2940, 1050,1935, 1035,960, 1035,2940, 1035,945, 1035,1950, 1035
};
const unsigned int CodesVal[] PROGMEM =
{
    3015,5895, 1035,2940, 1035,1950, 1035,1935, 1050,945, 1035,1950, 1035,1935, 1035
};
const unsigned int CodesLeft[] PROGMEM =
{
    3045,5895, 1035,2940, 1035,945, 1035,2940, 1050,1935, 1035,945, 1035,1950, 1050
};
const unsigned int CodesRight[] PROGMEM =
{
    3060,5895, 1035,2925, 1050,945, 1035,2940, 1035,945, 1050,2925, 1050,945, 1035
};
const unsigned int CodesUp[] PROGMEM =
{
    3045,5895, 1050,2925, 1035,960, 1035,2925, 1050,945, 1035,1950, 1035,2940, 1035
};
const unsigned int CodesDown[] PROGMEM =
{
    3045,5895, 1035,2940, 1035,960, 1035,1935, 1035,2940, 1050,1935, 1035,945, 1050
};

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
    // pinMode(3, OUTPUT);
    // digitalWrite(3, HIGH);

    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    Serial.println();
    Serial.println("For 'menu' button, type 'm' and press the 'Send' button.");
    Serial.println("For 'mod' button, type 'o' and press the 'Send' button.");
    Serial.println("For 'esc' button, type 'e' and press the 'Send' button.");
    Serial.println("For 'val' button, type 'v' and press the 'Send' button.");
    Serial.println("For 'left' button, type 'l' and press the 'Send' button.");
    Serial.println("For 'right' button, type 'r' and press the 'Send' button.");
    Serial.println("For 'up' button, type 'u' and press the 'Send' button.");
    Serial.println("For 'down' button, type 'd' and press the 'Send' button.");
} // setup

void loop()
{
    char c = recvOneChar();
    if (c == 'm')
    {
        const int n = sizeof(CodesMenu) / sizeof(CodesMenu[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'menu'...");
        sendIrCodes(CodesMenu, buffer, n);
    }
    else if (c == 'o')
    {
        const int n = sizeof(CodesMod) / sizeof(CodesMod[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'mod'...");
        sendIrCodes(CodesMod, buffer, n);
    }
    else if (c == 'e')
    {
        const int n = sizeof(CodesEsc) / sizeof(CodesEsc[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'esc'...");
        sendIrCodes(CodesEsc, buffer, n);
    }
    else if (c == 'v')
    {
        const int n = sizeof(CodesVal) / sizeof(CodesVal[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'val'...");
        sendIrCodes(CodesVal, buffer, n);
    }
    else if (c == 'l')
    {
        const int n = sizeof(CodesLeft) / sizeof(CodesLeft[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'left'...");
        sendIrCodes(CodesLeft, buffer, n);
    }
    else if (c == 'r')
    {
        const int n = sizeof(CodesRight) / sizeof(CodesRight[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'right'...");
        sendIrCodes(CodesRight, buffer, n);
    }
    else if (c == 'u')
    {
        const int n = sizeof(CodesUp) / sizeof(CodesUp[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'up'...");
        sendIrCodes(CodesUp, buffer, n);
    }
    else if (c == 'd')
    {
        const int n = sizeof(CodesDown) / sizeof(CodesDown[0]);
        unsigned int buffer[n];

        Serial.println("Sending 'down'...");
        sendIrCodes(CodesDown, buffer, n);
    } // if
} // loop
