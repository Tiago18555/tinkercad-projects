int btn = 4;
bool apertado;
//int var;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT); // Para eventuais testes
  pinMode(btn, INPUT_PULLUP);
}

void loop()
{
  apertado = digitalRead(btn);
  faseA();  
  dinamicDelay();  
  faseB();  
  delay(1800);  
  faseC();  
  dinamicDelay();  
  faseD();  
  delay(1800);
}

void faseA()
{
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
}

void faseB()
{
  digitalWrite(11, HIGH);
  digitalWrite(13, LOW);
}

void faseC()
{
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW); 
}

void faseD()
{
  digitalWrite(12, LOW);
  digitalWrite(10, HIGH); 
}
  
void dinamicDelay()
{  
  //int cont =0;
  for(int i = 0; i > 570; i++)
  {    
    delay(10);
    //cont++;
  }
  delay(1);
}