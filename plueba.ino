#include "Globales.h"

#include "Import.h"
int PositionActual = 0;
void setup() {
  Initial(Cerrado);
  
  PrenderLed(false,true,false);
}
long time = 0;

void loop() {
  
  long distancia = GetCm();
  time = millis();
  
  if (distancia <= 10) {
    int j = 10;
    int inicio = true? PositionActual : Cerrado;
    ChangeServoTime(inicio, Abierto, 5000,10, true);
    delay(3000);
    PrenderLed(true,false,false);
    delay(10000);
    ChangeServoTime(Abierto, Cerrado, 1000,10, true);
    PrenderLed(false,true,false);
    
  }else{
    if((millis() - time)<time_verde){
      PrenderLed(false,true,false);
      PositionServo(Cerrado);
    }else if((millis() - time)<time_Amarillo){

      PrenderLed(false,false,true);
      ChangeServoTime(Abierto, Cerrado, 2000,10, true);

    }else if((millis() - time)<timeCiclo){

      PrenderLed(true,false,false);
      PositionServo(Abierto);
      
    }else{
        time = 0;
    }

  }


}