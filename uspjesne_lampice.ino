// Pin Definitions
const int relayPin = 13;  // Relay control pin
const int buttonPin = 2;  // Button pin

// Timer settings in milliseconds
unsigned long relayOnTime =  6 * 60 * 60 * 1000;  // 6 hours in milliseconds (20 seconds for testing)
unsigned long relayOffTime =  18 * 60 * 60 * 1000;  // 18 hours in milliseconds (10 seconds for testing)
unsigned long previousMillis = 0;  // Store the last time the timer was updated
bool relayState = false;  // Current state of the relay
bool lastButtonState = HIGH;  // Previous button state
bool buttonPressed = false;  // Button state (whether it was pressed or not)

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);
  
  // Initialize relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Initially turn off the relay
  
  // Initialize button pin
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
  
  // Initialize timer start time (track when Arduino is powered on)
  previousMillis = millis();  // Capture the start time when Arduino is powered on
}

void loop() {
  // Read the button state
  bool buttonState = digitalRead(buttonPin);
  
  // Check if the button has been pressed (button goes LOW when pressed)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button was pressed, toggle relay state
    relayState = !relayState;
    digitalWrite(relayPin, relayState ? HIGH : LOW);  // Change relay state
    Serial.println(relayState ? "Relay ON (Button Press)" : "Relay OFF (Button Press)");
    delay(200); // Debounce delay to avoid multiple presses
  }
  
  lastButtonState = buttonState; // Update last button state

  // Get the current time since the Arduino started (in milliseconds)
  unsigned long currentMillis = millis();

  // Timing logic for automatic relay cycling
  if (relayState == false) {
    // If relay is OFF, check if 6 hours (onDuration) have passed (for testing, use a smaller value)
    if (currentMillis - previousMillis >= relayOnTime) {
      relayState = true;
      digitalWrite(relayPin, HIGH);  // Turn the relay ON
      previousMillis = currentMillis;  // Reset the timer to wait for the next OFF period
      Serial.println("Relay ON (Timer)");
    }
  } else {
    // If relay is ON, check if 18 hours (offDuration) have passed (for testing, use a smaller value)
    if (currentMillis - previousMillis >= relayOffTime) {
      relayState = false;
      digitalWrite(relayPin, LOW);  // Turn the relay OFF
      previousMillis = currentMillis;  // Reset the timer to wait for the next ON period
      Serial.println("Relay OFF (Timer)");
    }
  }
}
