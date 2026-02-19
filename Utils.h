#include <Servo.h>
#include "Data.h"
#include "Globales.h"

void PositionServo(int grados = 0){
   Pluma.write(grados);
   PositionActual = grados;
}
void Initial(int grados = 0){
  
  pinMode(Pin_trig, OUTPUT);
  pinMode(Pin_echo, INPUT);
  Pluma.attach(Pin_Servo);
  PositionServo(grados);
  
  pinMode(Pin_ledRojo_Semaforo, OUTPUT);
  pinMode(Pin_ledVerde_Semaforo, OUTPUT);
  pinMode(Pin_ledAmarillo_Semaforo, OUTPUT);
  
  pinMode(Pin_ledRojo_Peaton, OUTPUT);
  pinMode(Pin_ledVerde_Peaton, OUTPUT);
}

void PrenderLed(bool Rojo = false, bool Verde = false, bool Amarillo = false){
  digitalWrite(Pin_ledRojo_Semaforo, Rojo);
  digitalWrite(Pin_ledVerde_Semaforo, Verde);
  digitalWrite(Pin_ledAmarillo_Semaforo, Amarillo);
  if(Rojo || Verde){
    digitalWrite(Pin_ledRojo_Semaforo, Verde  );
    digitalWrite(Pin_ledVerde_Semaforo, Rojo);
  }
  
}
void ChangeServoTime(int start, int end, int time, int step, bool isAnimated = false){
  if(isAnimated){
    for(int i = 1; i<= step ;i++){
        PositionServo(start + (end/step*i));
        delay(time/step);
        
          if((time/step)%1000 >= 500){    
            PrenderLed(false,false,true);
          }else{
            PrenderLed(false,false,false);
          }
        
      
    }
  }else{ 
    PrenderLed(false,false,true);
    delay(time);
    PositionServo(end);

  }
}
long GetCm(){
  
  analogWrite(Pin_trig, 255);
  delayMicroseconds(2);
  analogWrite(Pin_trig, 0);
  delayMicroseconds(10);
  analogWrite(Pin_trig, 255);
  
  long tiempo = pulseIn(Pin_echo, HIGH);
  delay(100);
  return tiempo / 56.4; 
}