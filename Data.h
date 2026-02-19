#define Pin_trig  A0
#define Pin_echo  A1

#define Pin_ledRojo_Semaforo  3
#define Pin_ledVerde_Semaforo  4
#define Pin_ledAmarillo_Semaforo  5

#define Pin_ledRojo_Peaton  8
#define Pin_ledVerde_Peaton  9

#define Pin_Servo  A5

Servo Pluma;

int Cerrado = 90;
int Abierto = 0;

long timeCiclo = 22000;
long time_verde = 10000;
long time_Amarillo = 12000;