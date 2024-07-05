unsigned long time; 
unsigned long timeSecond; //Конвертор секунд *1000
const long StartAutTime = 15; //Время задержки до включения
const long TimeFillingWater = 8; //Длительность наполнения воды
unsigned long PorosessorTime;

void setup() {
  Serial.begin(9600);  pinMode(3, OUTPUT);  pinMode(13, OUTPUT);
}

void loop() {
time = millis(); //таймер в милисекундах
delay(1000);    

PorosessorTime+=1;
    if (PorosessorTime >= StartAutTime && PorosessorTime < (StartAutTime + TimeFillingWater) )
     {
      Serial.print("----ON-----!");
      digitalWrite(13, HIGH);
      digitalWrite(3, HIGH);
     }
     else  {  
      Serial.print("----Off!");
      digitalWrite(13, LOW);
      digitalWrite(3, LOW);
     }
     
    if (PorosessorTime > (StartAutTime + TimeFillingWater))
    {
      PorosessorTime =0;
      }


timeSecond +=1;   //прибавляема 1 через каждые 1000мс

  Serial.println(timeSecond);
  Serial.println(PorosessorTime);
}
