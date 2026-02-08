// EDGE DETECTION + COUNTER + DEBOUNCE

const int buttonPin = 2;    // push-button pin
const int ledPin = 7;       // LED pin

int buttonState = HIGH;       // current reading
int lastButtonState = HIGH;   // previous reading
int counter = 0;              // press counter

unsigned long lastDebounceTime = 0;   // last time the button changed
const unsigned long debounceDelay = 50; // debounce time in milliseconds

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // check if the button state has changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // reset debounce timer
  }

  // only count the button press if the state is stable for debounceDelay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed after debouncing
    if (reading != buttonState) {
      buttonState = reading;

      // only increment counter on button press (LOW)
      if (buttonState == LOW) {
        counter++;
        Serial.print("Counter: ");
        Serial.println(counter);
      }
    }
  }

  lastButtonState = reading;

  // LED on every 4 presses
  if (counter > 0 && counter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
