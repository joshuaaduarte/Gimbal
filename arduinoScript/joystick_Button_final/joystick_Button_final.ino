// Motor Pins 
const int stepPin = 2; // yaw step
const int dirPin = 5; // yaw direction
const int stepPin2 = 3; // pitch step
const int dirPin2 = 6; // pitch direction
const int stepPin3 = 4; // slide step
const int dirPin3 =7; // slide direction

// joystick setup
#define VRX_PIN  A12 // Arduino pin connected to VRX pin
#define VRY_PIN  A13 // Arduino pin connected to VRY pin
int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis

//left and right button setup 
const int buttonRight = 27; // controls right movement facing camera
const int buttonLeft = 26; // controls left movement facing camera


void setup() { ;
    //Serial.begin(9600);
    // First Motor controlling the yaw rotation
    pinMode(stepPin,OUTPUT); 
    pinMode(dirPin,OUTPUT);
    // Second Motor controlling the pitch rotation
    pinMode(stepPin2,OUTPUT); 
    pinMode(dirPin2,OUTPUT);
    // Third Motor moving across axis 
    pinMode(stepPin3, OUTPUT);
    pinMode(dirPin3, OUTPUT);
    //Buttons
    pinMode(buttonRight, INPUT);
    pinMode(buttonLeft, INPUT);
}



void loop() {

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  while ((xValue > 515 && xValue < 525) && (yValue > 510 && yValue < 520)){
    int pressedRight = digitalRead(buttonRight);
    if (pressedRight == HIGH){
      digitalWrite(dirPin3,HIGH);
      digitalWrite(stepPin3, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin3, LOW);
      delayMicroseconds(500);
    }
    int pressedLeft = digitalRead(buttonLeft);
    if (pressedLeft == HIGH){
      digitalWrite(dirPin3,LOW);
      digitalWrite(stepPin3, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin3, LOW);
      delayMicroseconds(500);
    }
    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);
  }

  

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
    if (xValue < 100){
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(6000);
  }

  xValue = analogRead(VRX_PIN);
  if (xValue == 1023){
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(6000);
  }
  
  yValue = analogRead(VRY_PIN);
  if (yValue < 100){
    digitalWrite(dirPin2,HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(6000);
  }

  yValue = analogRead(VRY_PIN);
  if (yValue == 1023){
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(6000);
  }
  

  

}
