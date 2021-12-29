#include <Stepper.h>
//This section declares the variables and sets the stepper
  //motors to pins 3,4,5,6 and 7,8,9,10
int FrontSensor,RightSensor,LeftSensor,BackSensor,k,dellay=50,pushcount=0,buttonStatus;
int BaseLineSensitivity=1000;
//const int stepsPerRevolution=62;
//Stepper myStepperLeft (stepsPerRevolution, 2,3,4,5);
//Stepper myStepperRight(stepsPerRevolution, 8,9,10,11);
void setup()
{
  Serial.begin(9600);
  //INSERT PINS FOR MOTOR CONTROL AS OUTPUT
  //myStepperLeft.setSpeed(30);
  //myStepperRight.setSpeed(30);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT); //BUTTON
  pinMode(7,OUTPUT); //LED
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  //This section reads the light intensities and linearizes them
  FrontSensor=analogRead(A0);
  FrontSensor=-1.0504*FrontSensor+1010.5042;
  RightSensor=analogRead(A1);
  RightSensor=-1.02671*RightSensor+1026.69;
  LeftSensor=analogRead(A2);
  LeftSensor=-1.0081*LeftSensor+1015.121;
  BackSensor=analogRead(A3);
  BackSensor=-1.0707*BackSensor+1019.272;
  buttonStatus=digitalRead(6);
  /*Serial.println("Front sensor:");
  Serial.println(FrontSensor,DEC);
  Serial.println("Right sensor:");
  Serial.println(RightSensor,DEC);
  Serial.println("Left sensor:");
  Serial.println(LeftSensor,DEC);
  Serial.println("Back sensor:");
  Serial.println(BackSensor,DEC);
  delay(1000);
  //This section controls the motor directions*/
  if(pushcount==0&&buttonStatus==1)
  {
    pushcount++;
    digitalWrite(7,HIGH);
    delay(1000);
    Serial.println(BaseLineSensitivity);
    if(FrontSensor>RightSensor&&FrontSensor>LeftSensor&&FrontSensor>BackSensor)
    {
      BaseLineSensitivity=FrontSensor+50;
    }
    if(LeftSensor>BackSensor&&LeftSensor>FrontSensor&&LeftSensor>RightSensor)
    {
      BaseLineSensitivity=LeftSensor+50;
    }
    if(BackSensor>RightSensor&&BackSensor>LeftSensor&&BackSensor>FrontSensor)
    {
      BaseLineSensitivity=BackSensor+50;
    }
    if(RightSensor>FrontSensor&&RightSensor>BackSensor&&RightSensor>LeftSensor)
    {
      BaseLineSensitivity=RightSensor+50;
    } 
   
  }
  if (pushcount==1)
  {
  if(FrontSensor>RightSensor&&FrontSensor>LeftSensor&&FrontSensor>BackSensor&&FrontSensor>BaseLineSensitivity)
  {
    //INSERT COMMAND TO GO FORWARD
    {
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
    Serial.println("Traveling forward");
  }
  }
  if(LeftSensor>BackSensor&&LeftSensor>FrontSensor&&LeftSensor>RightSensor&&LeftSensor>BaseLineSensitivity)
  {
    Serial.println("Turning left");
    //INSERT COMMAND TO TURN LEFT
    {
          digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
     }
  }
  if(BackSensor>RightSensor&&BackSensor>LeftSensor&&BackSensor>FrontSensor&&BackSensor>BaseLineSensitivity)
  {
    Serial.println("Traveling backwards");
    //INSERT COMMAND TO GO REVERSE
    {
          digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
    }
  }
  if(RightSensor>FrontSensor&&RightSensor>BackSensor&&RightSensor>LeftSensor&&RightSensor>BaseLineSensitivity)
  {
    Serial.println("Turning right");
    //INSERT COMMAND TO TURN RIGHT
    {
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(2,LOW);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(3,LOW);
     digitalWrite(2,HIGH);
     delay(dellay);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
    }

  }
  if(LeftSensor<BaseLineSensitivity&&BackSensor<BaseLineSensitivity&&FrontSensor<BaseLineSensitivity&&RightSensor<BaseLineSensitivity)
  {
    Serial.println("Standing still");
    //INSERT COMMAND TO STAND STILL
  }
  buttonStatus=digitalRead(6);
  if(buttonStatus==1)
  {
    pushcount=0;
    digitalWrite(7,LOW);
    delay(1000);
  }
  //delay(10);
  }
  
}
