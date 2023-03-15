  const int stepPin2 = 4; //X.STEP
  const int dirPin2 = 7; // X.DIR
 // joystick
 
int vry = A1; 
int vry_data = 0; 
int x = 0; 
int SMSpeed = 6000; // Stepper Motor Speed 

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
 pinMode(stepPin2,OUTPUT); 
 pinMode(dirPin2,OUTPUT);
 pinMode(vry, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
joystick();

}

void joystick(){
if ( vry_data > 600  )
{
 
digitalWrite(dirPin2,HIGH);
x = x + 1; 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed); 
  
}
 
if ( vry_data < 100   )
{
digitalWrite(dirPin2,LOW);
x = x - 1; 
 
 digitalWrite(stepPin2,HIGH); 
 delayMicroseconds(SMSpeed); 
 digitalWrite(stepPin2,LOW); 
 delayMicroseconds(SMSpeed);  
}



}
