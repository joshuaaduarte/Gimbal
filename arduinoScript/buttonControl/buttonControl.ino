  // Motor Pins 
  const int stepPin = 2; // yaw step
  const int dirPin = 5; // yaw direction
  const int stepPin2 = 3; // pitch step
  const int dirPin2 = 6; // pitch direction
  const int stepPin3 = 4; // slide step
  const int dirPin3 =7; // slide direction
  // Motor Speed
  int SMSpeed = 600;
  // Button Controls
  const int buttonRight = 27; // controls right movement facing camera
  const int buttonLeft = 26; // controls left movement facing camera
  const int buttonUp = 23; 
  const int buttonDown = 22;
  const int buttonSpinL = 24;  
  const int buttonSpinR = 25; 
  void setup() {
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
    pinMode(buttonUp, INPUT);
    pinMode(buttonDown, INPUT);
    pinMode(buttonSpinL, INPUT);
    pinMode(buttonSpinR, INPUT);
  }


void loop() {

  buttonMove();
  
}


void buttonMove(){
  int pressedUp = digitalRead(buttonUp);
  if (pressedUp == HIGH){
    digitalWrite(dirPin2,HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(6000);
  }
  int pressedDown = digitalRead(buttonDown);
  if (pressedDown == HIGH){
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(6000);
  }

  int pressedSpinL = digitalRead(buttonSpinL);
  if (pressedSpinL == HIGH){
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(6000);
  }
  int pressedSpinR = digitalRead(buttonSpinR);
  if (pressedSpinR == HIGH){
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(6000);
  }
  
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
}
