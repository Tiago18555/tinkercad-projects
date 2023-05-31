bool onStatus = true;
bool isMoving;
int currentFloor = 0;
int floorSelected = 0;
void setup()
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(13,INPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  stopElevator();
  showLeds(0);
}
          
void loop()
{ 
  bool up = digitalRead(4);
  bool down = digitalRead(3);
  bool enter = digitalRead(2);
  if(onStatus == true)
  {
    digitalWrite(5, HIGH);
  	if(isMoving == false)
    {
      if(up) //UP
      {
        if(floorSelected < 4)
        {
          floorSelected ++;
          showLeds(floorSelected);
          delay(100);
        }
      }
      else if(down) //DOWN
      {
        if(floorSelected != 0)
        {
          floorSelected --;
          showLeds(floorSelected);
          delay(100);
        }
        
      }
      else if(enter) //ENTER
      {        
        isMoving = true;
        moveElevator(nextFloor(floorSelected));
        stopElevator();
      }
      else if(digitalRead(13) == HIGH)//POWER ON/OFF
      {
		powerSwitch();
      }
    }
  }
  else//onStatus
  {
    digitalWrite(5, LOW);
    if(digitalRead(13) == HIGH)
    {
      powerSwitch();
    }
  }
  delay(50);
}

void powerSwitch()
{
  if (onStatus == true){ onStatus = false; showLeds(5); }
  else { onStatus = true; showLeds(currentFloor);}
  delay(100);
}
          
int nextFloor(int targetFloor)
{
  return targetFloor - currentFloor;   
}

int reverseSignal(int number)
{
  return number - (  number * 2);
}

void stopElevator()
{
  isMoving = false;
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
}

void errorDisplay()
{
  showLeds(4);
  delay(200);
  showLeds(5);
  delay(200);
  showLeds(4);
  delay(200);
  showLeds(5);
  delay(200);
}

void moveElevator(int moveCommand)
{
  int totalLoop;
  
  //Forçando o valor de moveCommand ser positivo, para usar no laço for
  if(moveCommand < 0){ totalLoop = reverseSignal(moveCommand); }
  else{ totalLoop = moveCommand; }
  
  for(int i=0; i <= totalLoop; i++)
  {
    showLeds(currentFloor);
    if(moveCommand < 0 && i < totalLoop)
    {
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      currentFloor--;
    }
    else if(moveCommand > 0 && i < totalLoop)
    {
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      currentFloor++;
    }
    else
    {
      errorDisplay();
      showLeds(currentFloor);
      break;
    }
    delay(1000);    
  }  
}
          
void showLeds(int displayCode)
{
  switch(displayCode)
  {
    case 0:
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    break;
    case 1:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    break;
    case 2:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    break;
    case 3:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
    break;
    case 4:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
    break;
    case 5:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    break;
    default:
    break;
  }
}
