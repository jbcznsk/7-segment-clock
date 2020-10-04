Baixe e adicione a biblioteca RTCLib.h e já declare o objeto rtc
```c
#include "RTClib.h"
RTC_DS3231 rtc;
```
Defina o intervalo entre a multiplexação dos displays (em ms), pode ser ajustado caso você sinta que o display está 'piscando'
```c
#define DELAY 5
```

Defina as saída do Arduino que serão utilizadas para controlar o CD4511
```c
#define IN_A 2
#define IN_B 3
#define IN_C 4
#define IN_D 5
```

Faça a mesma coisa com o controle do mux CD4051
```c
#define CTL_A 6
#define CTL_B 7
```

Declare dois vetores com os valores definidos acima, isso facilitará o controle dos dos CIs no futuro
```c
int in4511[] = {IN_A, IN_B, IN_C, IN_D};
int ctl[] = {CTL_A, CTL_B};
```

As duas funções a seguir utilizam operações de bits para ligar e desligar as portas certas baseado em valores inteiros, 
isso pode ser otimizado utilizando diretamente os registradores do microcontrolador <br
Como exemplo, será explicada a função writeNumber:
- Digamos que queremos mostrar o número 5 no display
- 5 em binário corresponde à 0101, portando queremos botar os seguintes valores nas entradas do CD4511
  - 1 -> A - Entrada menos significativa
  - 0 -> B
  - 1 -> C
  - 0 -> D - Entrada mais significativa
- A entrada A está no in4511[0]
- O valor que queremos botar no A pode ser obtido com a seguite operação
```
(0101 >> 0) & 0001
0101 & 0001
1
```
- Isso deslocará o valor 0101 0 vezes para a direita, resultando nele mesmo, e o &0001 extrairá o dígito menos significativo e
ignorará os outros
- Repita isso com o próximo valor para botar na entrada B
```
(0101 >> 1) & 0001
0010 & 0001
0
```
E assim por diante até extrair o valor de todas as entradas. A mesma lógica se aplica para selecionar o display que deve ser ligado
```c
void
selDisplay(int n)
{
  for (int i = 0; i < 2; i++)
    digitalWrite(ctl[i], (n >> i) & 1);
}

void
writeNumber(int n)
{
  for (int i = 0; i < 4; i++)
    digitalWrite(in4511[i], (n >> i) & 1);
}
```

A função abaixo primeiramente separa os valores de hora e minuto em um vetor, por exemplo, 15h24 ficará guardado como
```c
hour[0] = 1
hour[1] = 5
hour[2] = 2
hour[3] = 4
```
Depois disso, são utilzadas as funções explicadas anteriormente
```c
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
```

Na função <b>setup</b>, é necessário iniciar o rtc declarado inicialmente e declaras as portas utilizadas 
como saídas
```c
void
setup()
{
  /* Inicia o RTC */
  rtc.begin();

  /* Configura os pinos utilizados como saída */
  for (int i = 0; i < 4; i++)
    pinMode(in4511[i], OUTPUT);
  for (int i = 0; i < 3; i++)
    pinMode(ctl[i], OUTPUT);
}
```

Na primeira vez que o programa for rodado, é necessário incluir a linha abaixo na setup para configurar o horário do 
rtc baseado no horário de compilação do sketch, nas outras vezes que o programa rodar essa linha deverá ser comentada
```c
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
```

Por fim, na função <b>loop</b> apenas obtemos o horário atual e ele é escrito nos displays
```c
void
loop()
{
  /* Obtém o horário atual */
  DateTime now = rtc.now();

  /* Escreve o horário nos displays de 7-segmentos */
  writeHour(now);
}
```

Esse programa ocupa aproximadamente 11% da memória de programa e 11% da memória dinâmica do Arduino, por isso micro-otimizações não foram implementadas, 
faça as modificações que você desejar para deixar o programa mais compacto e eficiente :smile:
