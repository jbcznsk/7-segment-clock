#include <Wire.h>
#include "RTClib.h" 

RTC_DS1307 rtc; //OBJETO DO TIPO RTC_DS1307
DateTime now;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

#define DELAY 1

#define CTL_1A 6
#define CTL_1B 7
#define CTL_1C 8
#define INH_A 9

#define CTL_2A 6
#define CTL_2B 7
#define SEG_A 13
#define SEG_B 2
#define SEG_C 5 
#define SEG_D 3
#define SEG_E 4
#define SEG_F 12
#define SEG_G 11
#define INH_B 10

#define OUT_1A 2
#define OUT_1B 3
#define OUT_1C 4
#define OUT_1D 5

int displays[6] = {CTL_1A, CTL_1B, CTL_1C};
int outs[4] = {OUT_1A, OUT_1B, OUT_1C, OUT_1D};
int segs[7] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G};
int dias[7][3][7] = {
                      {{0,1,1,1,1,0,1}, // d
                       {0,0,1,1,1,0,1}, // o
                       {0,0,0,0,0,0,0}  // 
                      },
                      {{1,0,1,1,0,1,1}, // s
                       {1,0,0,1,1,1,1}, // e
                       {1,1,1,1,0,1,1}  // g
                      },
                      {{0,0,0,1,1,1,1}, // t
                       {1,0,0,1,1,1,1}, // e  
                       {0,0,0,0,1,0,1}  // r
                      },
                      {{1,1,1,0,0,1,1}, // q
                       {0,1,1,1,1,1,0}, // u
                       {1,1,1,0,1,1,1}  // a
                      },
                      {{1,1,1,0,0,1,1}, // q
                       {0,1,1,1,1,1,0}, // u
                       {0,1,1,0,0,0,0}  // i
                      },
                      {{1,0,1,1,0,1,1}, // s
                       {1,0,0,1,1,1,1}, // e
                       {0,1,1,0,1,1,1}  // x
                      },
                      {{1,0,1,1,0,1,1}, // s
                       {1,1,1,0,1,1,1}, // a
                       {0,0,1,1,1,1,1}  // b
                      }
                    };


void printDebug(){
    // Serial.print("Data: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    // Serial.print(now.day(), DEC); //IMPRIME NO MONITOR SERIAL O DIA
    // Serial.print('/'); //IMPRIME O CARACTERE NO MONITOR SERIAL
    // Serial.print(now.month(), DEC); //IMPRIME NO MONITOR SERIAL O MÊS
    // Serial.print('/'); //IMPRIME O CARACTERE NO MONITOR SERIAL
    // Serial.print(now.year(), DEC); //IMPRIME NO MONITOR SERIAL O ANO
    // Serial.print(" / Dia: "); //IMPRIME O TEXTO NA SERIAL
    // Serial.print(daysOfTheWeek[now.dayOfTheWeek()]); //IMPRIME NO MONITOR SERIAL O DIA
    // Serial.print(" / Horas: "); //IMPRIME O TEXTO NA SERIAL
    // Serial.print(now.hour(), DEC); //IMPRIME NO MONITOR SERIAL A HORA
    // Serial.print(':'); //IMPRIME O CARACTERE NO MONITOR SERIAL
    // Serial.print(now.minute(), DEC); //IMPRIME NO MONITOR SERIAL OS MINUTOS
    // Serial.print(':'); //IMPRIME O CARACTERE NO MONITOR SERIAL
    // Serial.print(now.second(), DEC); //IMPRIME NO MONITOR SERIAL OS SEGUNDOS
    // Serial.println(); //QUEBRA DE LINHA NA SERIAL
}

void writeLetter(int letra, int dia){
  for (int i = 0; i < 7; i++){
    digitalWrite(segs[i], dias[dia][letra][i]);
    
  }
}

void writeDay(int dia){
  digitalWrite(INH_A, HIGH);
  digitalWrite(INH_B,  LOW);

  for (int i = 0; i < 3; i++){
    digitalWrite(CTL_2A, (i>>0)&1);
    digitalWrite(CTL_2B, (i>>1)&1);
    writeLetter(i, dia);
    delay(DELAY);
  }
}

void writeNumber(int n, int display){

  for (int i = 0; i < 4; i++)
    digitalWrite(outs[i], (n >> i) & 1);

  for (int i = 0; i < 3; i++){
    digitalWrite(displays[i], (display >> i) & 1);
  }
  delay(DELAY);
}

void writeDate(){

  digitalWrite(INH_A,  LOW);
  digitalWrite(INH_B, HIGH);
  
  writeNumber(now.hour()  /10, 0);
  writeNumber(now.hour()  %10, 1);
  writeNumber(now.minute()/10, 2);
  writeNumber(now.minute()%10, 3);
  writeNumber(now.day() / 10, 4);
  writeNumber(now.day() % 10, 5);
  writeNumber(now.month() / 10, 6);
  writeNumber(now.month() % 10, 7);

}

void setup(){

  // Serial.begin(9600);

  for (int i = 2; i < 13; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  digitalWrite(9, LOW);
  digitalWrite(10,HIGH);

  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);

  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);

if (! rtc.begin()) { 
    Serial.println("DS1307 não encontrado"); 
    while(1);
  }
  if (! rtc.isrunning()) { 
    //Serial.println("DS1307 rodando!");
    //REMOVA O COMENTÁRIO DE UMA DAS LINHAS ABAIXO PARA INSERIR AS INFORMAÇÕES ATUALIZADAS EM SEU RTC
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //CAPTURA A DATA E HORA EM QUE O SKETCH É COMPILADO
    //rtc.adjust(DateTime(2020, 7, 22, 15, 33, 15)); //(ANO), (MÊS), (DIA), (HORA), (MINUTOS), (SEGUNDOS)
  }
  //rtc.adjust(DateTime(2020, 7, 22, 15, 33, 15)); //(ANO), (MÊS), (DIA), (HORA), (MINUTOS), (SEGUNDOS)
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  now = rtc.now();

}

long int counter = 0;

void loop() {
  now = rtc.now();
  if (counter > 50){
    //printDebug();
    counter = 0;
  }

  writeDate();
  writeDay(now.dayOfTheWeek());

  counter++;
}
