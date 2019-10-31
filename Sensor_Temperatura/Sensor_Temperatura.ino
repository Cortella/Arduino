//Sensor de temperatura usando o LM35
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura=0.0; // Variável que armazenará a temperatura medida
float ultimaTemperatura = 0.0; //Armazena a ultima temperatura medida
 
//Função que será executada uma vez quando ligar ou resetar o Arduino
void setup() {
Serial.begin(9600); // inicializa a comunicação serial
}

void loop() {
temperatura = (analogRead(LM35)*(5.0/(1023)))/0.01; //Converte tensao para temperatura e armazena na variavel
//Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Temperatura: ");
  lcd.setCursor(3, 1);
  lcd.print(temperatura);
  delay(5000);
   
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
   
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);

}

//Programa: Teste de Display LCD 16 x 2
//Autor: FILIPEFLOP
 

 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  
  }
