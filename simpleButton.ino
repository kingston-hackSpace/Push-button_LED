const int buttonPin = 2;  
const int ledPin =  7;   
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed 
  if (buttonState == LOW) { //(Pressed = LOW due to pull-up)
    
    digitalWrite(ledPin, HIGH); // Turn the LED on  
    Serial.println("pressed");
    
  } else {
    digitalWrite(ledPin, LOW); // Turn the LED off
    Serial.println("not pressed");
  }
}
