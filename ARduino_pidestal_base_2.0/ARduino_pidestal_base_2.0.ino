/* 
This is the code for the pidestal, it uses the adafruit motorshield v2.3. I am currently revising this so be nice
*/
#include <Adafruit_MotorShield.h>

const int red = 12;  //assign red normally open button to pin 12
const int blue = 11; //assign blue normally open button to pin 11
const int lim = 10;  //assign roller cam switch to pin 10, this is the limit swith to prevent a full rotation
 
Adafruit_MotorShield AFMS = Adafruit_MotorShield();   // Create the motor shield object with the default I2C address
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);         //Sets a motor at motor port 1

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
  AFMS.begin();        // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
 
  myMotor->run(RELEASE);//cuts power to motor in setup loop

  pinMode(red, INPUT);  /*Initialize pins that buttons will connect to as inputs. MAKE SURE YOU USE PULLDOWN RESISTORS,*/
  pinMode(blue, INPUT); /*place a 10K resistor between the pin and ground to pull the value to logical zero */  
  pinMode(lim, INPUT);  

}

const int x = 100; //int value used to define motor speed, small impulses are aroun 5/10, max speed is 225 *personal note, 100 is extremely fast. 

void loop() {

    //if(digitalRead(lim)!= HIGH){ //in progress still tryin to think this one out
      
      if(digitalRead(red) == HIGH){ 
     
        myMotor->run(FORWARD); //runs your motor "forward", make sure you test what forward is so you dont destoy anything expensive
        myMotor->setSpeed(x);  //sets motor speed to constant integer value defined outside of loop
      }
      else if(digitalRead(blue )== HIGH) {
      
        myMotor->run(BACKWARD); //Well I mean I guess this one runs the motor backwards 
        myMotor->setSpeed(x);   //what does it MEEEEAAAAN
    
      } 
      else {
        myMotor->setSpeed(0); // Setting the speed to zero allows the shield to actively brake the motor stopping it instantly.
        //myMotor->run(RELEASE);//Cuts power to motor but does not brake, may be useful at some point so im leaving it in here
      }
      delay(10); //wait 10 miliseconds to restart this loop

   
 }
 
 
