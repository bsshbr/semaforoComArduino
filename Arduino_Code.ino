//Button
const int button = 2;
unsigned long currentMillis = millis();
const long interval = 10000;
unsigned long previousMillis = 0;

//Counter
int counter;

//LEDs do Semaforo A
const int RedLedA = 12;
const int GreenLedA = 10;
const int YellowLedA = 11;

//LEDs do Pedestre
const int RedLedPed = 9;
const int GreenLedPed = 8;

//LEDs do Semaforo B
const int RedLedB = 6;
const int GreenLedB = 4;
const int YellowLedB = 5;

//Inicialização
void setup() {
  //Inicialização dos Pinos do Semaforo A:
  pinMode(RedLedA, OUTPUT);
  pinMode(GreenLedA, OUTPUT);
  pinMode(YellowLedA, OUTPUT);

  //Inicialização dos Pinos do Semaforo B:
  pinMode(RedLedB, OUTPUT);
  pinMode(GreenLedB, OUTPUT);
  pinMode(YellowLedB, OUTPUT);

  //Inicialização dos Pinos do Semaforo Pedestre
  pinMode(RedLedPed, OUTPUT);
  pinMode(GreenLedPed, OUTPUT);

  //Inicialização do Botão
  pinMode(button, INPUT);

  //Teste de Inicialização Semaforo A & B & Pedestres
  digitalWrite(RedLedA, HIGH);
  digitalWrite(GreenLedA, HIGH);
  digitalWrite(YellowLedA, HIGH);
  digitalWrite(RedLedB, HIGH);
  digitalWrite(GreenLedB, HIGH);
  digitalWrite(YellowLedB, HIGH);
  digitalWrite(RedLedPed, HIGH);
  digitalWrite(GreenLedPed, HIGH);
  delay(1000);
  digitalWrite(RedLedA, LOW);
  digitalWrite(GreenLedA, LOW);
  digitalWrite(YellowLedA, LOW);
  digitalWrite(RedLedB, LOW);
  digitalWrite(GreenLedB, LOW);
  digitalWrite(YellowLedB, LOW);
  digitalWrite(RedLedPed, LOW);
  digitalWrite(GreenLedPed, LOW);

}

//Repetições do Sinal
void loop() {
  {
    //Ciclo I.1 - Inicio do Ciclo
    digitalWrite (RedLedB, LOW);    // Vermelho do semaforo B apaga (volta do loop)
    digitalWrite (RedLedA, HIGH);   // Vermelho do semaforo A começa aceso
    digitalWrite (GreenLedB, HIGH); // Verde do semaforo B começa aceso
    digitalWrite (RedLedPed, HIGH); // Vermelho do semaforo dos pedestres começa aceso

    // Verificação do botão em caso de ter sido pressionado enquanto o sinal verde de A esteja aberto
    for (counter = 1; counter <= 10000; counter++)
    {
      if (digitalRead (button) == HIGH && millis() - previousMillis > 10000)
      {
        counter = 10001; //Se o botão foi pressionado, o codigo segue para a proxima etapa dos semaforos


      }
      else
      {

        delay(3); //Se o botão não foi pressionado, existe um pequeno delay, que complementa o laço na questão de tempo.
      }
    }

    //Ciclo I.2 - Atenção no semaforo amarelo
    digitalWrite (GreenLedB, LOW);   // Verde do semaforo B apaga
    digitalWrite (YellowLedB, HIGH); // Amarelo do semaforo B acende
    delay (3000);

    //Ciclo I.3 - Semaforo B fecha
    digitalWrite (YellowLedB, LOW); // Amarelo apaga
    digitalWrite (RedLedB, HIGH);   // Vermelho acende
    delay (2000);

    // Ciclo I.4
    digitalWrite (RedLedPed, LOW);     // Vermelho do semaforo dos pedestres apaga
    digitalWrite (GreenLedPed, HIGH);  // Verde do semaforo dos pedestres acende
    digitalWrite (RedLedA, LOW);       // Vermelho do semaforo A apaga
    digitalWrite (GreenLedA, HIGH);    // Verde do semaforo A acende
    delay (10000);

    // Ciclo I.5
    digitalWrite (GreenLedA, LOW);     // Verde do semaforo A apaga
    digitalWrite (YellowLedA, HIGH);   // Amarelo do semaforo A acende
    digitalWrite (RedLedPed, HIGH);    // Vermelho do semaforo dos pedestres acende
    digitalWrite (GreenLedPed, HIGH);  // Verde do semaforo dos pedestres acende
    delay (3000);

    // Ciclo I.6 - Atenção na rua A e na faixa dos pedestres
    digitalWrite (RedLedPed, HIGH);    // Vermelho dos pedestres acende
    digitalWrite (GreenLedPed, LOW);   // Verde dos pedestres apaga
    digitalWrite (YellowLedA, LOW);    // Amarelo do semaforo A apaga
    digitalWrite (RedLedA, HIGH);      // Vermelho do semaforo A acende
    delay (2000);
    // Fim do Loop
    previousMillis = millis();
  }
}
