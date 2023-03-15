const int buttonPin = 10;  // the number of the pushbutton pin
const int buttonPin2 = 11;  // the number of the pushbutton pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == 1) {
    // turn LED on:
    Serial.println("L:On");
  } else {
    // turn LED off:
    Serial.println("L:off");
  }
  if (buttonState2 == 1) {
    // turn LED on:
    Serial.println("R:On");
  } else {
    // turn LED off:
    Serial.println("R:off");
  }
}
