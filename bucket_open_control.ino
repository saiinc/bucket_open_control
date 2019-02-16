#include <Servo.h> //используем библиотеку для работы с сервоприводом

Servo servo1; //объявляем переменную servo типа Servo
boolean butt_flag = 0;
boolean butt;
unsigned long last_time;
int rot_spd = 20; //скорость поворота сервы
int ugol1;

void setup() //процедура setup
{  
  servo1.attach(10); //привязываем привод к порту 10
  pinMode(3, INPUT_PULLUP);  //привязываем кнопку к порту 3
  servo1.write(5);    
}

void loop() //процедура loop
{
  butt = !digitalRead(3); //считать текущее положение кнопки
  if (butt == true && butt_flag == false) //кнопка нажата
    {
      butt_flag = true;      
      for(ugol1 = 5; ugol1 <= 165; ugol1++) //медленно открываем днище ковша
      {
        servo1.write(ugol1); 
        delay(rot_spd);
      }      
      delay(rot_spd*4);
      for(ugol1 = 165; ugol1 >= 5; ugol1--) //возвращаемся в исходное положение
      {
        servo1.write(ugol1); 
        delay(rot_spd);
      }            
      butt_flag = false;      
    }
}
