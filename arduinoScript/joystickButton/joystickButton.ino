  // Motor Pins 
  const int stepPin = 2; // yaw step
  const int dirPin = 5; // yaw direction
  const int stepPin2 = 3; // pitch step
  const int dirPin2 = 6; // pitch direction
  const int stepPin3 = 4; // slide step
  const int dirPin3 =7; // slide direction
  // Motor Speed
  int SMSpeed =750;
  // Button Controls
  const int buttonRight = 10; // controls right movement facing camera
  const int buttonLeft = 11; // controls left movement facing camera
  // Joystick Data
  int vrx = A0; 
  int vry = A1; 
  int vrx_data = 0; 
  int vry_data = 0; 

   
int x = 0; 
int y = 0;


  void setup() {
    // Joystick data
    pinMode(vrx , INPUT); 
    pinMode(vry, INPUT);  
    // First Motor controlling the yaw rotation
    pinMode(stepPin,OUTPUT); 
    pinMode(dirPin,OUTPUT);
    // Second Motor controlling the pitch rotation
    pinMode(stepPin2,OUTPUT); 
    pinMode(dirPin2,OUTPUT);
    // Third Motor moving across axis controlled by buttons
    pinMode(stepPin3, OUTPUT);
    pinMode(dirPin3, OUTPUT);
    pinMode(buttonRight, INPUT);
    pinMode(buttonLeft, INPUT);
  }


void loop() {

  joystick();
  buttonMove();
  
}

void joystick() {
vrx_data = analogRead(vrx);
Serial.print("Vrx:"); 
Serial.println(vrx_data); 
vry_data = analogRead(vry);
Serial.print("Vry:"); 
Serial.println(vry_data); 
 
 
//// to stop the stepper motor
//if ( (vrx_data > 490)  &&   (vrx_data < 510)   )
//{
// 
//;
//  
//}
// 
 
if ( vrx_data > 600  )
{
 
digitalWrite(dirPin,HIGH);
x = x + 1; 
 digitalWrite(stepPin,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vrx_data < 100   )
{
digitalWrite(dirPin,LOW);
x = x - 1; 
 
 digitalWrite(stepPin,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin,LOW); 
 delayMicroseconds(SMSpeed);  
}

if ( vry_data > 600  )
{
 
digitalWrite(dirPin2,HIGH);
y = y + 1; 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vry_data < 100   )
{
digitalWrite(dirPin2,LOW);
y = y - 1; 
 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed);  
}

 
//  vrx_data = analogRead(vrx);
//  vry_data = analogRead(vry);
//
//  if ( vrx_data > 600  )
//  {
//   x = x+1;
//    digitalWrite(dirPin,HIGH);
//    digitalWrite(stepPin,HIGH); 
//    delayMicroseconds(SMSpeed); 
//    digitalWrite(stepPin,LOW); 
//    delayMicroseconds(SMSpeed); 
//    
//  }
//
//  if ( vrx_data < 100   )
//  {
//    digitalWrite(dirPin,LOW);
//       x = x+1;  
//    digitalWrite(stepPin,HIGH); 
//    delayMicroseconds(SMSpeed); 
//    digitalWrite(stepPin,LOW); 
//    delayMicroseconds(SMSpeed);  
//  }
//
//  if ( vry_data > 600  )
//  {
//     
//    digitalWrite(dirPin2,HIGH);
//     y = y+1;
//    digitalWrite(stepPin2,HIGH); 
//    delayMicroseconds(SMSpeed); 
//    digitalWrite(stepPin2,LOW); 
//    delayMicroseconds(SMSpeed); 
//    
//  }
//   
//  if ( vry_data < 100   )
//  {
//    digitalWrite(dirPin2,LOW);
//        y = y+1;
//    digitalWrite(stepPin2,HIGH); 
//    delayMicroseconds(SMSpeed); 
//    digitalWrite(stepPin2,LOW); 
//    delayMicroseconds(SMSpeed);  
//  }
    if ( vrx_data > 600  )
{
 
digitalWrite(dirPin,HIGH);
x = x + 1; 
 digitalWrite(stepPin,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vrx_data < 100   )
{
digitalWrite(dirPin,LOW);
x = x - 1; 
 
 digitalWrite(stepPin,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin,LOW); 
 delayMicroseconds(SMSpeed);  
}

if ( vry_data > 600  )
{
 
digitalWrite(dirPin2,HIGH);
y = y + 1; 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vry_data < 100   )
{
digitalWrite(dirPin2,LOW);
y = y - 1; 
 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed);  
}

 
}


void buttonMove(){
  int pressedRight = digitalRead(buttonRight);
  if (pressedRight == HIGH){
    digitalWrite(dirPin3,HIGH);
    digitalWrite(stepPin3, HIGH);
    delayMicroseconds(SMSpeed);
    digitalWrite(stepPin3, LOW);
    delayMicroseconds(SMSpeed);
  }
  int pressedLeft = digitalRead(buttonLeft);
  if (pressedLeft == HIGH){
    digitalWrite(dirPin3,LOW);
    digitalWrite(stepPin3, HIGH);
    delayMicroseconds(SMSpeed);
    digitalWrite(stepPin3, LOW);
    delayMicroseconds(SMSpeed);
  }
}
