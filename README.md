# 7-segment-clock
<!-- <img src="https://i.imgur.com/oLs0pGW.jpeg" width="750"> -->
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/relogio-simplificado.jpg" width="750">
<b>Relógio feito com Arduino Nano e Displays de 7 Segmentos.</b>

## Sumário
 - [Objetivo](https://github.com/JorgeJabczenski/7-segment-clock#Objetivo)
 - [Componentes Utilizados](https://github.com/JorgeJabczenski/7-segment-clock#componentes-utilizados)
   - [Arduino Nano](https://github.com/JorgeJabczenski/7-segment-clock#arduino-nano)
   - [RTC DS3231](https://github.com/JorgeJabczenski/7-segment-clock#rtc-ds3231)
   - [Display 7-Segmentos Cátodo Comum](https://github.com/JorgeJabczenski/7-segment-clock#display-7-segmentos-c%C3%A1todo-comum)
   - [CD4511](https://github.com/JorgeJabczenski/7-segment-clock#cd4511)
   - [CD4051](https://github.com/JorgeJabczenski/7-segment-clock#cd4051)
   - [Transistor NPN](https://github.com/JorgeJabczenski/7-segment-clock#transistor-npn)
   - [Resistor](https://github.com/JorgeJabczenski/7-segment-clock#resistor)
   - [Protoboard](https://github.com/JorgeJabczenski/7-segment-clock#protoboard)
 - [Montagem do Circuito](https://github.com/JorgeJabczenski/7-segment-clock#montagem-do-circuito)
 - [Código](https://github.com/JorgeJabczenski/7-segment-clock#c%C3%B3digo)
 - [Bibliotecas Utilizadas](https://github.com/JorgeJabczenski/7-segment-clock#bibliotecas-utilizadas)
 - [Datasheets](https://github.com/JorgeJabczenski/7-segment-clock#datasheets)
 - [Resultado Final](https://github.com/JorgeJabczenski/7-segment-clock#resultado-final)
 - [Ideias e sugestões](https://github.com/JorgeJabczenski/7-segment-clock#ideias-e-sugest%C3%B5es)

## Objetivo
Após 4 meses de quarentena, eu fui olhar para os componentes eletrônicos que eu tinha sobrando no meu armário e decidi fazer algo de útil com eles. Com isso, me veio a ideia de fazer algo que fosse simples e que tivesse alguma utilidade no meu dia-a-dia, e foi daí que surgiu a idéia de fazer um relógio de parede.
Porém, seria simples demais usar apenas um [display LCD](https://uploads.filipeflop.com/2011/09/LCD-16x2-com-arduino.png) ou [OLED](https://www.usinainfo.com.br/1010901-thickbox_default/display-oled-096-i2c-128x64-branco-para-arduino.jpg) para fazer isso, não seria nenhum desafio e o projeto estaria pronto em 15 minutos, portanto eu decidi utilizar [displays de 7-segmentos](https://images-na.ssl-images-amazon.com/images/I/41Araxi2mwL._SX342_.jpg), pois além serem esteticamente agradáveis e funcionarem de uma maneira bem simples, trabalhar com eles exige mais esforço e trabalho do que os métodos citados anteriormente.

## Componentes utilizados
### Arduino Nano
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/nano.jpg" width="300">
Conhecido como a versão menor do famoso Arduino UNO, o Nano utiliza o mesmo microcontrolador (ATMega328) e possui o formato ideal para ser utilzado em protoboards.

### RTC DS3231
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/ds3231.jpg" width="300">
Real Time Clock (Relógio de Tempo Real) DS3231 é o coração do projeto. Esse é o componente que é capaz de guardar a hora mesmo sem estar energizado e enviar as informações para o Arduino via I²C. Podem ser usados outros RTCs como o DS1307, porém a minha experiência pessoal com o DS3231 foi bem satisfatória.

### Display 7-Segmentos Cátodo Comum
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/display.jpg" width="300">
Esse foi o método escolhido para mostrar o horário. Ele nada mais é do que 8 leds (contando o .) organizados de uma forma propícia para mostrar números e letras.

### CD4511
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/4511.jpg" width="300">
É um decodificador capaz de receber um número de 4-bits e enviar o seu equivalente para o display de 7-Segmentos. Ele apenas funciona para números, ou seja, não é recomendado para mostrar valores em hexadecimal.

### CD4051
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/4051.jpg" width="300">
É um multiplexador de 8 canais utilizado para ativar os transistores e selecionar o display que será ativado.

### Transistor NPN
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/bc546.jpg" width="300">
Serve como uma espécie de botão que pode ser ativado eletrônicamente ao invés de fisicamente (como por exemplo um push-button).

### Resistor
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/resistores.jpg" width="300">
Resistores servem como limitadores de corrente para que os componentes não queimem, como por exemplo os leds do display de 7-Segmentos.

### Protoboard
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/protoboard.jpg" width="300">
Um protobord serve como uma placa de prototipagem. Eles são usados normalmente apenas como uma plataforma temporária de testes e desenvolvimento, mas nesse caso eu decidi deixar o projeto na protoborad permanentemente, principalmente por causa da estética que eu estava planejando. Porém, caso você queira deixar o projeto com uma cara mais "profissional", o circuito pode ser projetado para ser impresso em uma placa de fenolite e os componentes seriam soldados ao invés de apenas encaixados, o que reduziria interferências e ruídos.

## Montagem do Circuito
### 1º Passo
No primeiro passo, coloque o Arduino Nano na protoboard no canto esquerdo, apenas para uma noção de espaçamento, pois como veremos, não temos muito espaço extra para trabalhar. Logo após o Arduino, coloque o CD4511 com o entalhe para esquerda e faça as seguintes conexões: 
  - Pino 3  (LT)  -> 5V
  - Pino 4  (BL)  -> 5V
  - Pino 5  (LE)  -> GND
  - Pino 8  (VSS) -> GND
  - Pino 16 (VDD) -> 5V
  
Para um maior conhecimento do funcionamento do CD4511, [leia este exelente artigo](https://www.embarcados.com.br/cd4511-decodificador-display-7-segmentos/), onde é explicado em detalhes a função de cada um dos pinos.
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/1-passo.png">

### 2º Passo
Agora, ligue as saídas do CD4511 ao display. O display deve ficar a 3 espaços de distância para dar espaço ao transistor que será colocado futuramente
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/2-passo.png">

### 3º Passo
Coloque outro display diretamente ao lado do antigo e faça as mesmas conexões feitas no passo anterior
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/3-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/3-passo-2.png">

### 4º Passo
Pule mais três espaços e faça exatamente a mesma coisa, agora todos os displays devem estar interligados entre si. Para garantir que todas as conexões foram feitas corretametne, teste elas com um multímetro.
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/4-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/4-passo-2.png">

### 5º Passo
Agora ligue o GND e o 5V do Arduino nas trilhas corretas do protoboard, são essas conexões que irão energizar o resto do circuito. Depois, conecte os seguintes pinos:
 - D2 -> A(7)
 - D3 -> B(1)
 - D4 -> C(2)
 - D5 -> D(6)
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/5-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/5-passo-2.png">

### 6º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo-2.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo-3.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo-4.png">

### 7º Passo
Conecte o Mux CD4051 diretamente ao lado do display e faça as conexões básicas para que ele funcione corretamente. Para um entendimento mais completo desse CI [acesse este site](https://www.embarcados.com.br/multiplexador-cd4051/)
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/7-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/7-passo-2.png">

### 8º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo-2.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo-3.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo-4.png">
 - Exemplo MUX
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/exemplo-mux.gif">

### 9º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/9-passo.png">


## Código
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


### Bibliotecas Utilizadas
  - [Wire.h](https://www.arduino.cc/en/Reference/Wire)
  - [RTClib.h](https://github.com/adafruit/RTClib)
  
### Datasheets
 - [Arduino Nano](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
 - [4511](https://www.ti.com/lit/ds/symlink/cd4511b.pdf)
 - [4051](https://www.ti.com/lit/ds/symlink/cd4051b.pdf)
 - [DS3132](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)

### Preço
| Componente | Preço Individual| Quantidade |Preço Final |
| -------------------------------- | ----- | - | ------- |
| Arduino Nano                     | 44,90 | 1 | 44,90 |
| RTC DS3231                       | 17,90 | 1 | 17,90 |
| CD4511                           | 4,40  | 1 | 4,40  |
| CD4051                           | 3,00  | 1 | 3,00  |
| Transistor BC546                 | 0,30  | 4 | 1,20  |
| Display 7-Segmentos Cátodo Comum | 1,50  | 4 | 6,00  |
| Protoboard                       | 17,90 | 1 | 17,90 |
|                                  |       |   | 95,30 |

## Resultado Finals
Como resultado final temos um relógio compacto e bonito e de relativamente baixo custo para um projeto DIY, se compararmos com os relógios que utilizam displays OLED ou LCD.

## Ideias e sugestões
 - Adicionar um Shift-Register para fazer um design amigável para baterias
 - Otimizar o código utilizando diretamente os registradores do ATMega328P
 - Trocar o Arduino Nano por um Arduino Mini
 - Leds piscando todo segundo como um relógio tradicional
 - Adicionar alarmes
 - Adicionar outro protoboard e mostrar a data também
 - Mostrar o dia da semana com outro display ou com uma barra de Leds
 - Utilizar os pinos de BL e LE do CD4511 para implementar o circuito de uma maneira mais eficiente
