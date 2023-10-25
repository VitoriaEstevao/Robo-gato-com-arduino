#include <Servo.h>
// versao final
int servo_pata_dianteira_direita = 9; // pata1
int servo_pata_dianteira_esquerda = 8; // pata 2
int servo_pata_traseira_esquerda = 7; // pata 3
int servo_pata_traseira_direita = 6; // pata 4
int servo_rabo = 13;
int servo_cabeca = 10;
int servo_pata1 = 5;
int servo_pata2 = 4;
int servo_pata3 = 3;
int servo_pata4 = 2;
int servo_pescoco = 12;

char letra;

Servo motor_pata_dianteira_direita;
Servo motor_pata_dianteira_esquerda;
Servo motor_pata_traseira_esquerda;
Servo motor_pata_traseira_direita;
Servo motor_rabo;
Servo motor_cabeca;
Servo motor_pescoco;
Servo motor_pata1;
Servo motor_pata2;
Servo motor_pata3;
Servo motor_pata4;

void setup() {
  Serial.begin(9600);
  motor_pata_dianteira_direita.attach(servo_pata_dianteira_direita);
  motor_pata_dianteira_esquerda.attach(servo_pata_dianteira_esquerda);
  motor_pata_traseira_esquerda.attach(servo_pata_traseira_esquerda);
  motor_pata_traseira_direita.attach(servo_pata_traseira_direita);
  motor_rabo.attach(servo_rabo);
  motor_cabeca.attach(servo_cabeca);
  motor_pescoco.attach(servo_pescoco);
  motor_pata1.attach(servo_pata1);
  motor_pata2.attach(servo_pata2);
  motor_pata3.attach(servo_pata3);
  motor_pata4.attach(servo_pata4);
  
  motor_pata1.write(0);
  motor_pata2.write(0);
  motor_pata3.write(0);
  motor_pata4.write(0);
}

void loop() {
  letra = Serial.read();
    switch(letra){
      case'a':
        andar();
        break;
      case'b':
        mov_pescoco();
        //mov_cabeca();
        break;
      case'c':
        mov_rabo();
        break;
    }
    
}

// funcoes
void andar() {
  delay(1000);
  motor_pata_dianteira_direita.write(0);
  motor_pata_traseira_esquerda.write(0);
  delay(200);
  motor_pata_dianteira_esquerda.write(60);
  motor_pata_traseira_direita.write(45);
  delay(200);
  motor_pata_traseira_esquerda.write(90);
  motor_pata_dianteira_direita.write(60);
  delay(200);
  motor_pata_traseira_direita.write(90);
  motor_pata_dianteira_esquerda.write(40);
  delay(250);
}

void mov_rabo(){
  motor_rabo.write(0);
    delay(500);
    motor_rabo.write(80);
    delay(1000);
    motor_rabo.write(0);
    delay(500);
    motor_rabo.write(80);
    delay(1000);
}

void mov_pescoco(){
    motor_pescoco.write(0);
    delay(500);
    motor_pescoco.write(25);
    delay(500);
    motor_pescoco.write(40);
    delay(1000);
    motor_pescoco.write(30);
    delay(1000);
}
