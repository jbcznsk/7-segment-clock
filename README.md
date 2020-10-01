# 7-segment-clock
<!-- <img src="https://i.imgur.com/oLs0pGW.jpeg" width="750"> -->
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/relogio-simplificado.jpg" width="750">
Relógio feito com Arduino Nano e Displays de 7 Segmentos.

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
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/1-passo.png">

### 2º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/2-passo.png">

### 3º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/3-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/3-passo-2.png">

### 4º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/4-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/4-passo-2.png">

### 5º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/5-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/5-passo-2.png">

### 6º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo-2.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo-3.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/6-passo-4.png">

### 7º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/7-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/7-passo-2.png">

### 8º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo-2.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo-3.png">
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/8-passo-4.png">

### 9º Passo
<img src="https://github.com/JorgeJabczenski/7-segment-clock/blob/master/imgs/montagem/9-passo.png">


## Código

### Bibliotecas Utilizadas:
  - [Wire.h](https://www.arduino.cc/en/Reference/Wire)
  - [RTClib.h](https://github.com/adafruit/RTClib)
  
### Datasheets
 - [Arduino Nano](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
 - [4511](https://www.ti.com/lit/ds/symlink/cd4511b.pdf)
 - [4051](https://www.ti.com/lit/ds/symlink/cd4051b.pdf)
 - [DS3132](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)

## Resultado Final
## Ideias e sugestões
