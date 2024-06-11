#include <Arduino.h>
#ifdef USE_TINYUSB
#include <Adafruit_TinyUSB.h>
#endif
#include <Linenoise.h>

// track DTR change
bool dtr = false;

void setup()
{
    linenoiseSetCompletionCallback(ln_completion);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    update_dtr();
    
    if (dtr) {
        char* line = linenoise(">");
        if (line) {
            linenoiseHistoryAdd(line);
            handle_line(line);
            linenoiseFree(line);
        } else {
            // CTRL-C pressed or serial port closed
        }
    }
    delay(1);
    yield();
}

// linenoise completion function callback
void ln_completion(const char *buf, linenoiseCompletions *lc)
{
    switch (buf[0]) {
    case 'd':
        linenoiseAddCompletion(lc, "debug");
        break;
    case 'h':
        linenoiseAddCompletion(lc, "hello");
        break;
    }
}

void update_dtr()
{
    if (!dtr && Serial && Serial.dtr()) {
        dtr = true;
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10);
        Serial.print("\r\n");
        Serial.flush();
    } else if (dtr && (!Serial.dtr() || !Serial)) {
        dtr = false;
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void handle_line(char* line)
{
    if (!strcmp("hello", line)) {
        Serial.println("Hello World!");
    } else if (!strcmp("debug", line)) {
        Serial.println("Enter debug mode");
        linenoisePrintKeyCodes();
        Serial.println("Exit debug mode");
    } else {
        Serial.print("line: ");
        Serial.println(line);
    }
}
