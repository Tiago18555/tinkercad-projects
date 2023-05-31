int bot;
bool isOpened = false;
bool emergency = false;
int lastMs = 10000;

void setup()
{
  pinMode(13, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  //pinMode(7, OUTPUT);
}

void loop()
{
  
  bot = digitalRead(13);
  if(bot == HIGH)
  {
    if(isOpened == false)
    {
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      
      lastMs = delayLoop(lastMs);
      
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      delay(500);
      isOpened = true;
    }
    else
    {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      
      lastMs = delayLoop(lastMs);
      
      digitalWrite(10, HIGH);
      delay(500);
      isOpened = false;
    }    
  }
  else
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }
}

int delayLoop(int ms)
{
  int loopCount;
  int i;
  delay(500); // Para evitar leitura dupla do botão
  
  //Para setar o timing da emergência VS abertura/fechamento completo
  if(ms > 100){ loopCount = ms / 100; }
  else{	loopCount = 100; ms = 10000; }
  
  for(i=0; i<=loopCount; i++)
  {
    if(digitalRead(13) == HIGH) { emergency = true; }
    if(emergency == false){ delay(100); }
    else{ emergency = false; break; }
  }
  return (loopCount-i)*100; // Retorna o tempo restante caso seja interrompido a abertura do portão
}