  const int stepPin = 2; //X.STEP
  const int dirPin = 5; // X.DIR
  const int stepPin2 = 3; //X.STEP
  const int dirPin2 = 6; // X.DIR
  const int stepPin3 = 4; //X.STEP
  const int dirPin3 =7; // X.DIR
  const int buttonLeft = 11;  // the number of the pushbutton pin
  const int buttonRight = 10;
//  int buttonState = 0;  // variable for reading the pushbutton status
//  int buttonState2 = 0;
  // joystick
  int vrx = A0; 
  int vry = A1; 
  int vrx_data = 0; 
  int vry_data = 0; 
 
int x = 0; 
int y = 0;
int z = 0;
int SMSpeed = 800; // Stepper Motor Speed 
 void setup() {
 // Sets the two pins as Outputs
 //Serial.begin(9600);
 pinMode(stepPin,OUTPUT); 
 pinMode(dirPin,OUTPUT);
 pinMode(stepPin2,OUTPUT); 
 pinMode(dirPin2,OUTPUT);
 pinMode(vrx , INPUT); 
 pinMode(vry, INPUT);
 pinMode(stepPin3, OUTPUT);
 pinMode(dirPin3, OUTPUT); 
 pinMode(buttonRight, INPUT);
 pinMode(buttonLeft, INPUT);
 
 }
 
 
 void loop() 
 {

//  buttonMove();
joystick(); 


 
 }
 
 void joystick()
{
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
vrx_data = analogRead(vrx);
Serial.println("Vrx:"); 
//Serial.println(vrx_data); 
vry_data = analogRead(vry);
//Serial.print("Vry:"); 
Serial.println(vry_data); 
// 
 
//// to stop the stepper motor
//if ( (vrx_data > 490)  &&   (vrx_data < 510)   )
//{
// 
//;
//  
//}
// 
 
if ( vrx_data > 690  )
{
 
digitalWrite(dirPin,HIGH);
x = x + 1; 
 digitalWrite(stepPin,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vrx_data < 10   )
{
digitalWrite(dirPin,LOW);
x = x - 1; 
 
 digitalWrite(stepPin,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin,LOW); 
 delayMicroseconds(SMSpeed);  
}

if ( vry_data > 690  )
{
 
digitalWrite(dirPin2,HIGH);
y = y + 1; 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vry_data < 10   )
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
    delayMicroseconds(500 );
  }
}
