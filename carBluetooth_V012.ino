/*
Управление машинкой на ардуино, через блютуз модуль HC05 */
char command;
int FrontLights = 13; //К 13 пину припаяны светодиоды для света фар

// Переменные для контактов драйвера двигателей
int IN1 = 11; 
int IN2 = 12;
int IN3 = 9;
int IN4 = 10;
void setup()
{
  Serial.begin(9600);  //Устанавливаем скорость передачи для блютуз модуля
  pinMode(FrontLights, OUTPUT);

  pinMode (IN4, OUTPUT);
  pinMode (IN4, OUTPUT);
}


 void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //при запуске моторы остановлены

    switch (command) {
      case 'F'://Двигаться прямо
        forward();
      break;
      case 'B'://Двигаться назад
        back();
      break;
      case 'L'://Повернуть колеса влево
        left();
      break;
      case 'R'://Повернуть колеса вправо
        right();
      break;
      case 'G'://Вперед и вправо
      forwardRight();
      break;
      case 'I'://Вперед и влево
      forwardLeft();
      break;
      case 'H'://Назад и вправо
      backRight();
      break;
      case 'J'://назад и влево
      backLeft();
      break;  
      case 'W': //Включить передние фары
        digitalWrite(FrontLights, HIGH);
      break;
      case 'w'://Выключить передние фары
        digitalWrite(FrontLights, LOW);
      break;
    }
  }
}

void forward()
{
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); 
}

void back()
{
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
}

void left()
{
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
}

void right()
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH); 
}

void forwardLeft()
{
forward();
right();
}
void forwardRight()
{
  forward();
  left();
}
void backLeft()
{
back();
right();
}
 void backRight() 
 {
back();
left();
}
void Stop()
{
  digitalWrite (IN3, LOW); 
  digitalWrite (IN4, LOW); 
  digitalWrite (IN2, LOW); 
  digitalWrite (IN1, LOW); 
}