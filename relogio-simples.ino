/*
* Criado por: Jorge Lucas V. Jabczenski
*/

#include "RTClib.h"
/* Declara o RTC DS3132 */
RTC_DS3231 rtc;

/* Intervalo entre a multiplexação em ms*/
#define DELAY 5

/* Entradas do 4511 */
#define IN_A 2
#define IN_B 3
#define IN_C 4
#define IN_D 5

/* Controle do MUX A */
/* hora, minuto */
#define CTL_A 6
#define CTL_B 7

/* Pinos utilizados no decod 4511*/
int in4511[] = {IN_A, IN_B, IN_C, IN_D};

/* Pinos utilizados no mux 4051 */
int ctl[] = {CTL_A, CTL_B};

/* Seleciona o display que será ativo */
void
selDisplay(int n)
{
  for (int i = 0; i < 2; i++)
    digitalWrite(ctl[i], (n >> i) & 1);
}

/* Escreve o número utilizando os pinos selecionados  */
void
writeNumber(int n)
{
  for (int i = 0; i < 4; i++)
    digitalWrite(in4511[i], (n >> i) & 1);
}

/* Escreve a hora utilizando as duas funções anteriores */
void
writeHour(DateTime now)
{
  int horario[4];
  horario[0] = now.hour() / 10;
  horario[1] = now.hour() % 10;
  horario[2] = now.minute() / 10;
  horario[3] = now.minute() % 10;

  for (int i = 0; i < 4; i++)
  {
    selDisplay(i);
    writeNumber(horario[i]);
    delay(DELAY);
  }
}

void
setup()
{
  /* Inicia o RTC */
  rtc.begin();
  
  /* Arruma o horário baseado na hora de compilação do sketch */
  /* Descomente na primeira vez que for rodar o programa e depois comente novamente */
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  /* Configura os pinos utilizados como saída */
  for (int i = 0; i < 4; i++)
    pinMode(in4511[i], OUTPUT);
  for (int i = 0; i < 3; i++)
    pinMode(ctl[i], OUTPUT);
}


void
loop()
{
  /* Obtém o horário atual */
  DateTime now = rtc.now();

  /* Escreve o horário nos displays de 7-segmentos */
  writeHour(now);
}
