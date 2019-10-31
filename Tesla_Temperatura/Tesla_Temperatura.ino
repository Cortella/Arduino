//Programa: Teste de Display LCD 16 x 2
//Autor: FILIPEFLOP
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

const int LM35 = A0;
float temperatura = 0.0,temperaturaAnterior = 0.0;

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(2, 0);
  //Envia o texto entre aspas para o LCD
  temperatura = (analogRead(LM35)*(5.0/(1023)))/0.01;
  //if ((temperaturaAnterior-temperatura>=0.5) || ((temperaturaAnterior-temperatura<=-0.5))){
    temperaturaAnterior = temperatura;
    lcd.print("TEMPERATURA: ");
    lcd.setCursor(5, 1);
    lcd.print(temperatura);
    lcd.write(byte(223));
    lcd.print("C");
  //}
  delay(1000);
}
