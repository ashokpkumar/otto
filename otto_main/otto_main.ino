#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <FastLED.h>

const char* host = "esp32";
const char* ssid = "ashok_jio_24";
const char* password = "Ak110390#";

const int tonePin = 25;        // Pin where the speaker/buzzer is connected
const int freq = 1000;        // Frequency in Hz (1000 Hz = 1 kHz tone)
const int ledChannel = 0;     // LEDC channel (0-15)
const int resolution = 8;     // PWM resolution in bits

// LED configuration
#define LED_PIN     13    // Pin where the RGB LED is connected
#define NUM_LEDS    6     // Number of LEDs (change this if you have more LEDs)
#define BRIGHTNESS  255   // Brightness level (0-255)

CRGB leds[NUM_LEDS];      // Define an array to store LED data
WebServer server(80);
const char* serverIndex = "<form method='POST' action='/update' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form>";

void setup(void) {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() == WL_CONNECTED) {
    MDNS.begin(host);
    server.on("/", HTTP_GET, []() {
      server.sendHeader("Connection", "close");
      server.send(200, "text/html", serverIndex);
    });
    server.on("/update", HTTP_POST, []() {
      server.sendHeader("Connection", "close");
      server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
      ESP.restart();
    }, []() {
      HTTPUpload& upload = server.upload();
      if (upload.status == UPLOAD_FILE_START) {
        Serial.setDebugOutput(true);
        Serial.printf("Update: %s\n", upload.filename.c_str());
        if (!Update.begin()) { //start with max available size
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_WRITE) {
        if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_END) {
        if (Update.end(true)) { //true to set the size to the current progress
          Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        } else {
          Update.printError(Serial);
        }
        Serial.setDebugOutput(false);
      } else {
        Serial.printf("Update Failed Unexpectedly (likely broken connection): status=%d\n", upload.status);
      }
    });
    server.begin();
    MDNS.addService("http", "tcp", 80);

    Serial.printf("Ready! Open http://%s.local in your browser\n", host);
  } else {
    Serial.println("WiFi Failed");
  }

    // Set up the LEDC channel to generate a tone
  ledcSetup(ledChannel, freq, resolution); // Channel, frequency, resolution
  ledcAttachPin(tonePin, ledChannel);      // Attach the pin to the channel

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
  // Generate a 1 kHz tone for 1 second
  ledcWriteTone(ledChannel, 1000); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 20); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 300); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 100); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 800); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 300); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 500); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 900); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 15); // 1000 Hz tone
  delay(20);
  ledcWriteTone(ledChannel, 100); // 1000 Hz tone
  delay(20);                     // Wait for 1 second
  
  // Stop the tone for 1 second
  ledcWriteTone(ledChannel, 0);    // Stop the tone
  delay(1000); 

  // Set the LED to Red, Green, and Blue sequentially
  leds[0] = CRGB::Red;   // Set the LED to Red
  leds[1] = CRGB::Red;   // Set the LED to Red
  leds[2] = CRGB::Red;   // Set the LED to Red

  leds[3] = CRGB::Red;   // Set the LED to Red
  leds[4] = CRGB::Red;   // Set the LED to Red
  leds[5] = CRGB::Red;   // Set the LED to Red
  FastLED.show();        // Update the LED to display the color
  delay(1000);           // Wait for 1 second

  leds[0] = CRGB::Green; // Set the LED to Green
  leds[1] = CRGB::Green; // Set the LED to Green
  leds[2] = CRGB::Green; // Set the LED to Green

  leds[3] = CRGB::Green; // Set the LED to Green
  leds[4] = CRGB::Green; // Set the LED to Green
  leds[5] = CRGB::Green; // Set the LED to Green
  FastLED.show();        // Update the LED to display the color
  delay(1000);           // Wait for 1 second

  leds[0] = CRGB::Blue;  // Set the LED to Blue
  leds[1] = CRGB::Blue;  // Set the LED to Blue
  leds[2] = CRGB::Blue;  // Set the LED to Blue

  leds[3] = CRGB::Blue;  // Set the LED to Blue
  leds[4] = CRGB::Blue;  // Set the LED to Blue
  leds[5] = CRGB::Blue;  // Set the LED to Blue
  FastLED.show();        // Update the LED to display the color
  delay(1000);           // Wait for 1 second

}
