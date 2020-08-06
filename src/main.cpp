/*                            Tras                \
.                                                  \
. Negativo >>           - X(1) X(4) X(7)            \
.             Esquerdo    X(2) X(5) X(8)  Direito    \    Visão superior 
.                         X(3) X(6) X(9)             /    do cubo
.                                                   /
.                             Frente               /
.                                                 /

Lista de efeitos:
// #1: Acende todos os LEDS (deve ser repetida muitas vezes para que o LED se mantenha acesso)
// #2: Pisca os LEDs em ordem, do primeiro ao terceiro andar
// #3: Pisca od LEDs em ordem, do terceio ao primeiro andar
// #4: Pisca as colunas dos três andares ao mesmo tempo, do LED 1 ao 9
// #5: Pisca as colunas dos três andares ao mesmo tempo, do LED 9 ao 1
// #6: Pisca os andares inteiros, do 1 ao 3
// #7: Pisca os andares inteiros, do 3 ao 1
// #8: Pisca todos os LEDs da lateral esquerda a direita
// #9: Pisca todos os LEDs da lateral direita a esquerda
// #10: Pisca todos os LEDs da frente para trás
// #11: Pisca todos os LEDs de trás para frente
// #12: Os LEDs do 1 andar piscam de forma circular
// #13: Os LEDs do 2 andar piscam de forma circular
// #14: Os LEDs do 3 andar piscam de forma circular
// #15: Os LEDs da lateral direita piscam de forma circular
// #16: Os LEDs da lateral esquerda piscam de forma circular
// #17  Os LEDs do centro das laterais piscam de forma circular
// #18: Os LEDs da frente piscam de forma circular
// #19: Os LEDs do centro frontal frente piscam de forma circular
// #20: Os LEDs de tras piscam de forma circular
// #21: Explosão
// #22: Implosão
// #23: Aleatório

*/
#include <Arduino.h>

//                  0 , 1, 2, 3,  4, 5, 6, 7, 8 ,9
byte LED[3][10] = {{13, 8, 9, 10, 7, 6, 5, 2, 3, 4}, {12, 8, 9, 10, 7, 6, 5, 2, 3, 4}, {11, 8, 9, 10, 7, 6, 5, 2, 3, 4}};

void Acender(byte Andar, byte Luz, bool Estado);
void Efeito(byte NEfeito);
void E1(), E2(), E3(), E4(), E5(), E6(), E7(), E8(), E9(), E10(), E11(), E12(), E13(), E14(), E15(), E16(), E17(), E18(), E19(), E20(), E21(), E22(), E23();

void setup()
{
  for (byte i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);
  for (byte i = 0; i <= 2; i++)
    digitalWrite(LED[i][0], HIGH);
}

void loop()
{
  Efeito(5);
  Efeito(4);
  // Efeito(3);
}

void Acender(byte Andar, byte Luz, bool Estado)
{
  digitalWrite(LED[Andar - 1][0], !Estado);
  digitalWrite(LED[Andar - 1][Luz], Estado);
}

void Efeito(byte NEfeito)
{
  switch (NEfeito)
  {
  case 1:
    E1();
    break;
  case 2:
    E2();
    break;
  case 3:
    E3();
    break;
  case 4:
    E4();
    break;
  case 5:
    E5();
    break;
  case 6:
    E6();
    break;
  case 7:
    E7();
    break;
  case 8:
    E8();
    break;
  case 9:
    E9();
    break;
  case 10:
    E10();
    break;
  case 11:
    E11();
    break;
  case 12:
    E12();
    break;
  case 13:
    E13();
    break;
  case 14:
    E14();
    break;
  case 15:
    E15();
    break;
  case 16:
    E16();
    break;
  case 17:
    E17();
    break;
  case 18:
    E18();
    break;
  case 19:
    E19();
    break;
  case 20:
    E20();
    break;
  case 21:
    E21();
    break;
  case 22:
    E22();
    break;
  case 23:
    E23();
    break;
  }
}

// #1: Acende todos os LEDS (deve ser repetida muitas vezes para que o LED se mantenha acesso)
void E1()
{
  for (int iii = 0; iii < 200; iii++)
  {
    for (int ii = 1; ii < 4; ii++)
    {
      for (int i = 1; i < 10; i++)
      {
        Acender(ii, i, HIGH);
        delayMicroseconds(100);
        Acender(ii, i, LOW);
      }
    }
  }
}
// #2: Pisca os LEDs em ordem, do primeiro ao terceiro andar
void E2()
{
  for (byte i = 0; i < 3; i++)
  {
    digitalWrite(LED[i][0], LOW);
    for (byte ii = 1; ii < 10; ii++)
    {
      digitalWrite(LED[i][ii], HIGH);
      delay(30);
      digitalWrite(LED[i][ii], LOW);
      delay(15);
    }
    digitalWrite(LED[i][0], HIGH);
  }
}
// #3: Pisca od LEDs em ordem, do terceio ao primeiro andar
void E3()
{
  for (int i = 2; i >= 0; i--)
  {
    digitalWrite(LED[i][0], LOW);
    for (byte ii = 9; ii >= 1; ii--)
    {
      digitalWrite(LED[i][ii], HIGH);
      delay(30);
      digitalWrite(LED[i][ii], LOW);
      delay(15);
    }
    digitalWrite(LED[i][0], HIGH);
  }
}
// #4: Pisca as colunas dos três andares ao mesmo tempo, do LED 1 ao 9
void E4()
{
  digitalWrite(LED[0][0], LOW);
  digitalWrite(LED[1][0], LOW);
  digitalWrite(LED[2][0], LOW);
  for (byte ii = 1; ii < 10; ii++)
  {
    for (byte i = 0; i < 3; i++)
    {
      digitalWrite(LED[i][ii], HIGH);
      delay(30);
      digitalWrite(LED[i][ii], LOW);
      delay(15);
    }
  }
  digitalWrite(LED[0][0], HIGH);
  digitalWrite(LED[1][0], HIGH);
  digitalWrite(LED[2][0], HIGH);
}
// #5: Pisca as colunas dos três andares ao mesmo tempo, do LED 9 ao 1
void E5()
{

  digitalWrite(LED[0][0], LOW);
  digitalWrite(LED[1][0], LOW);
  digitalWrite(LED[2][0], LOW);
  for (byte ii = 9; ii >= 1; ii--)
  {
    for (int i = 2; i >= 0; i--)
    {
      digitalWrite(LED[i][ii], HIGH);
      delay(30);
      digitalWrite(LED[i][ii], LOW);
      delay(15);
    }
  }
  digitalWrite(LED[0][0], HIGH);
  digitalWrite(LED[1][0], HIGH);
  digitalWrite(LED[2][0], HIGH);
}
// #6: Pisca os andares inteiros, do 1 ao 3
void E6()
{
}
// #7: Pisca os andares inteiros, do 3 ao 1
void E7()
{
}
void E8() // #8: Pisca todos os LEDs da lateral esquerda a direita
{
}
// #9: Pisca todos os LEDs da lateral direita a esquerda
void E9()
{
}
// #10: Pisca todos os LEDs da frente para trás
void E10()
{
}
// #11: Pisca todos os LEDs de trás para frente
void E11()
{
}
// #12: Os LEDs do 1 andar piscam de forma circular
void E12()
{
}
// #13: Os LEDs do 2 andar piscam de forma circular
void E13()
{
}
// #14: Os LEDs do 3 andar piscam de forma circular
void E14()
{
}
// #15: Os LEDs da lateral direita piscam de forma circular
void E15()
{
}
// #16: Os LEDs da lateral esquerda piscam de forma circular
void E16()
{
}
// #17  Os LEDs do centro das laterais piscam de forma circular
void E17()
{
}
// #18: Os LEDs da frente piscam de forma circular
void E18()
{
}
// #19: Os LEDs do centro frontal frente piscam de forma circular
void E19()
{
}
// #20: Os LEDs de tras piscam de forma circular
void E20()
{
}
// #21: Explosão
void E21()
{
}
// #22: Implosão
void E22()
{
}
// #23: Aleatório
void E23()
{
}
