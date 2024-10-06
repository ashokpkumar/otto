// Define the pin and channel for tone generation
const int tonePin = 25;        // Pin where the speaker/buzzer is connected
const int freq = 1000;        // Frequency in Hz (1000 Hz = 1 kHz tone)
const int ledChannel = 0;     // LEDC channel (0-15)
const int resolution = 8;     // PWM resolution in bits

void setup() {
  // Set up the LEDC channel to generate a tone
  ledcSetup(ledChannel, freq, resolution); // Channel, frequency, resolution
  ledcAttachPin(tonePin, ledChannel);      // Attach the pin to the channel
}

void loop() {
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
  delay(1000);                     // Wait for 1 second
}
