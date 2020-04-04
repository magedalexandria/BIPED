//Connect wireless module Pin1 to Arduino VCC
//Connect wireless module Pin2 to Arduino GND
//Connect wireless module Pin3 (RX) to Arduino digital pin 11
//Connect wireless module Pin4 (TX) to Arduino digital pin 10
//Pin5 not connected
#include <SoftwareSerial.h>
#include <Servo.h>
Servo leftfoot;
Servo lefthip;
Servo rightfoot;
Servo righthip;
#define MOVE_FORWARD 'w'
#define MOVE_BACK 's'
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define FULL_STOP 'e'
#define LEFT_DEFAULT_STOP 94  
#define RIGHT_DEFAULT_STOP 89
//int LED = 13;  //LED on Arduino board
byte rx_data = 0; //variable to store receive data

SoftwareSerial mySerial(10, 11); // RX = pin 10, TX = pin 11

void setup() {
 // pinMode(LED, OUTPUT);  
  mySerial.begin(9600); //initialize software UART for 9600bps 
  //Serial.begin(9600); 
leftfoot.attach(3);
leftfoot.write(0);  //neutral pos

lefthip.attach(9);
lefthip.write(105);  //neutral pos

rightfoot.attach(6);
rightfoot.write(40);  //neutral pos

righthip.attach(5);
righthip.write(90); //neutral pos

}
void loop(){  
 //char rx_data = 0;
 while (rx_data != 'q') {
   mySerial.readBytes(&rx_data, 1);
  if (rx_data == MOVE_FORWARD) {      //move forward
     delay(200);
  leftfoot.write(10);
    delay(200);
  leftfoot.write(20);
 delay(200);
  lefthip.write(65);

delay(200);
leftfoot.write(0);  //neutral pos
delay(200);
lefthip.write(95);  //neutral pos


//right leg movement
   delay(200);
  rightfoot.write(30);  
     delay(200);
  rightfoot.write(20);  
delay(200);
  righthip.write(120); 
   delay(200);
  rightfoot.write(40);  //neutral pos
delay(200);
  righthip.write(90); //neutral pos
  
 rx_data = 0;
    }
    
   
    if (rx_data == MOVE_BACK) {
//put move back code here
       rx_data = 0;
    }
  
    if (rx_data == MOVE_LEFT) {
//put move left code here
delay(200);
  leftfoot.write(10);
    delay(200);
  leftfoot.write(20);
 delay(200);
  lefthip.write(65);

delay(200);
leftfoot.write(0);  //neutral pos
delay(200);
lefthip.write(95);  //neutral pos
rx_data = 0;
    }
    
    if (rx_data == MOVE_RIGHT) {
//put move right code here
delay(200);
  rightfoot.write(30);  
     delay(200);
  rightfoot.write(20);  
delay(200);
  righthip.write(120); 
   delay(200);
  rightfoot.write(40);  //neutral pos
delay(200);
  righthip.write(90); //neutral pos
      rx_data = 0;
    }
    
     if (rx_data == FULL_STOP) {
//stop the robot and put servos at neutral position
leftfoot.write(0);  //neutral pos
lefthip.write(95);  //neutral pos
rightfoot.write(40);  //neutral pos
righthip.write(90); //neutral pos 
     rx_data = 0;
    }
  }
  Serial.end();
}
