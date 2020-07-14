#include<Servo.h>
Servo picchi;
Servo boro;

int store;

void setup(){
    boro.attach(2);//boro servor pin 2
    picchi.attach(7);//choto servo pin 7
    pinMode(5,INPUT_PULLUP);//rht  switch 
    pinMode(6,INPUT_PULLUP);// left switch 
    pinMode(11,OUTPUT);//motor driver
    pinMode(9,OUTPUT);//motor driver
    pinMode(10,OUTPUT);//motor driver
    Serial.begin(9600);
    boro.write(90);
    picchi.write(90);
    delay(3000);
   
}
bool lswitch,rswitch;
void loop(){
  /*digitalWrite(10,1);//clock
    digitalWrite(9,0);
    analogWrite(11,120);*/
    lswitch=digitalRead(6);
    rswitch=digitalRead(5);
//    Serial.print(lswitch);
//    Serial.print("\t\t");
//    Serial.println(rswitch);
    if (lswitch==0 && rswitch==1){
        
        picchi.write(165);
        delay(1000);
      boro.write(145);
      
      delay(1000);
      boro.write(160);
      digitalWrite(10,0);//motor rotation
      digitalWrite(9,1);//motor rotation
      analogWrite(11,120);//motor rotation
      delay(200);//rotation tym
      
     digitalWrite(10,0);
      digitalWrite(9,0);
      
      delay(1000);
      picchi.write(90);
      delay(1000);
      boro.write(130);
      delay(1000);
      picchi.write(10);
      delay(2000);
      picchi.write(180);
      //delay(1000);
     // store=-100; 
    
    }

   if (lswitch==1 && rswitch==0){
        
        picchi.write(15);
        delay(1000);
      boro.write(15);  
      delay(1000);
      boro.write(5);
      digitalWrite(10,1);
      digitalWrite(9,0);
      analogWrite(11,90);
      delay(200);

      digitalWrite(10,0);
      digitalWrite(9,0);
     
      delay(2000);
      picchi.write(90);
      delay(1000);
      boro.write(30);
      delay(1000);
      picchi.write(170);    
      delay(1000);
      picchi.write(10);
       
    }
}
