#include <CapacitiveSensor.h>

CapacitiveSensor   cs_36_34 = CapacitiveSensor(36,34);      

CapacitiveSensor   cs_36_44 = CapacitiveSensor(36,44);        

CapacitiveSensor   cs_36_46 = CapacitiveSensor(36,46);  

const int BPink_r = 2;

const int BPink_g = 3;

const int BPink_b = 4;

const int Ddong_r = 5;

const int Ddong_g = 6;

const int Ddong_b = 7;

const int Juhwong_r = 8;

const int Juhwong_g = 9;

const int Juhwong_b = 10;

const int Jpink_r = 11;

const int Jpink_g = 12;

const int Jpink_b = 13;

const int Blue_r = 22;

const int Blue_g = 23;

const int Blue_b= 24;

const int Red_r = 25;

const int Red_g = 26;

const int Red_b = 27;

const int Yellow_r = 28;

const int Yellow_g = 29;

const int Yellow_b = 30;

const int pushButton_1 = 31;

const int pushButton_2= 32;

const int pushButton_3 = 33;

long ontime1 = 500;

long offtime1= 500;

long ontime2 = 500;

long offtime2 = 1000;

long ontime3 = 500;

long offtime3 = 500;

int Flag_a = 0;

bool a=0;

bool b=0;

bool c=0;

bool d=0;

bool ledstate = true;

bool ledstate_2 = true;

bool sh_state = false;

bool fw_state = false;

long previousMillis = 0;

long previousMillis_b = 0;

long previousMillis_c = 0;

long interval = 1000;

void setColor_A(int redPIn, int red, int green, int blue);

void setColor(int redPIn, int red, int green, int blue);

void OFF_LED(int redpin);

void setup() {

  // put your setup code here, to run once:

  pinMode(BPink_g, OUTPUT);

  pinMode(BPink_r, OUTPUT);

  pinMode(BPink_b, OUTPUT);

  

  pinMode(Ddong_r, OUTPUT);

  pinMode(Ddong_g, OUTPUT);

  pinMode(Ddong_b, OUTPUT);

  pinMode(Juhwong_r, OUTPUT);

  pinMode(Juhwong_g, OUTPUT);

  pinMode(Juhwong_b, OUTPUT);

  pinMode(Jpink_r, OUTPUT);

  pinMode(Jpink_g, OUTPUT);

  pinMode(Jpink_b, OUTPUT);

  pinMode(Blue_r, OUTPUT);

  pinMode(Blue_g, OUTPUT);

  pinMode(Blue_b, OUTPUT);

  pinMode(Red_r, OUTPUT);

  pinMode(Red_g, OUTPUT);

  pinMode(Red_b, OUTPUT);

  pinMode(Yellow_r, OUTPUT);

  pinMode(Yellow_g, OUTPUT);

  pinMode(Yellow_b, OUTPUT);

  

  pinMode(pushButton_1, INPUT);

  pinMode(pushButton_2, INPUT);

  pinMode(pushButton_3, INPUT);

  

  cs_36_34.set_CS_AutocaL_Millis(0xFFFFFFFF);  

  cs_36_44.set_CS_AutocaL_Millis(0xFFFFFFFF);

  cs_36_46.set_CS_AutocaL_Millis(0xFFFFFFFF);   

  pinMode(40, OUTPUT);

  pinMode(42, OUTPUT);

  pinMode(38, OUTPUT);

  //초기 설정

  digitalWrite(pushButton_1,HIGH);

  digitalWrite(pushButton_2,HIGH);

  digitalWrite(pushButton_3,HIGH);

  

  digitalWrite(BPink_r,LOW);

  digitalWrite(BPink_g,LOW);

  digitalWrite(BPink_b,LOW);

  

  digitalWrite(Ddong_r,LOW);

  digitalWrite(Ddong_g,LOW);

  digitalWrite(Ddong_b,LOW);

  digitalWrite(Juhwong_r,LOW);

  digitalWrite(Juhwong_g,LOW);

  digitalWrite(Juhwong_b,LOW);

  digitalWrite(Jpink_r,LOW);

  digitalWrite(Jpink_g,LOW);

  digitalWrite(Jpink_b,LOW);

  digitalWrite(Blue_r,LOW);

  digitalWrite(Blue_g,LOW);

  digitalWrite(Blue_b,LOW);

  digitalWrite(Red_r,LOW);

  digitalWrite(Red_g,LOW);

  digitalWrite(Red_b,LOW);

  digitalWrite(Yellow_r,LOW);

  digitalWrite(Yellow_g,LOW);

  digitalWrite(Yellow_b,LOW);

  

  Serial.begin(9600); // 디버그용, 시리얼 모니터 초기화

  

}

void loop() {

  int buttonState_1;

  

  buttonState_1 = digitalRead(pushButton_1);

  

 

  //버튼 1에 대한 실행부분

  if(buttonState_1 == LOW)

  {

    if(Flag_a == 0)

    {

      Flag_a = 1;

      a =! a;

        if( a == 0){

            b =! b;

            if(b==0){

              c =! c;

              }}

    }

  }

 else

    Flag_a = 0;

  Serial.print(a);

  Serial.print(b);

  Serial.println(c);

  if( a && (!b && !c))//1

  { 

      unsigned long currentMillis = millis();

     

    if((currentMillis - previousMillis) >= ontime1 && ledstate==true) 

    {    

          previousMillis = currentMillis;

          OFF_LED(BPink_r);

          setColor(Ddong_r,1,0,0);

          setColor(Juhwong_r,1,0,0);

          OFF_LED(Jpink_r);

          OFF_LED(Blue_r);

          OFF_LED(Red_r);

          setColor(Yellow_r,1,0,0);

          ledstate =! ledstate;

       }

     else if((currentMillis - previousMillis) >= offtime1 && ledstate==false)            

     {    

          previousMillis = currentMillis;

          setColor(BPink_r ,1,1,0);

          OFF_LED(Ddong_r);

          OFF_LED(Juhwong_r);

          setColor(Jpink_r ,1,1,0);

          setColor(Blue_r ,1,1,0);

          setColor(Red_r ,1,1,0);

          OFF_LED(Yellow_r );

          ledstate =! ledstate;

   

        }

    }    

  

  

  else if( !a &&( b&&!c))//2

  {

    unsigned long currentMillis = millis();

     

    if((currentMillis - previousMillis_b) >= ontime2 && ledstate_2==true) 

    { 

        previousMillis_b = currentMillis;  

          setColor(BPink_r ,1,1,0);

          setColor(Ddong_r,1,0,0);

          setColor(Juhwong_r,1,0,0);

          setColor(Jpink_r ,1,1,0);

          setColor(Blue_r ,1,1,0);

          setColor(Red_r ,1,1,0);

          setColor(Yellow_r,1,0,0);

          ledstate_2 =! ledstate_2;

        }

      else if((currentMillis - previousMillis_b) >= offtime2 && ledstate_2==false)

        {       

          previousMillis_b = currentMillis; 

          OFF_LED(BPink_r);

          OFF_LED(Ddong_r);

          OFF_LED(Juhwong_r);

          OFF_LED(Jpink_r);

          OFF_LED(Blue_r);

          OFF_LED(Red_r);

          OFF_LED(Yellow_r );

         ledstate_2 =! ledstate_2;

   

        }

    }    

  

  else if( a && (b&&!c) )//3

  {

      setColor(BPink_r ,1,1,0);

      setColor(Ddong_r,1,0,0);

      setColor(Juhwong_r,1,0,0);

      setColor(Jpink_r ,1,1,0);

      setColor(Blue_r ,1,1,0);

      setColor(Red_r ,1,1,0);

      setColor(Yellow_r,1,0,0);

     

  }

  else if( !a && (!b&&c))//4

  {

      setColor(BPink_r ,0,1,0);

      setColor(Ddong_r,0,1,0);

      setColor_A(Juhwong_r,255,50,0);// 주황색

      setColor(Jpink_r ,1,0,1);

      setColor(Blue_r ,1,0,1);

      setColor(Red_r ,1,0,1);

      setColor(Yellow_r,1,1,0);

  }

    else if(a&&!(b&&c))//5

  {

    unsigned long currentMillis = millis();

    

    if((currentMillis - previousMillis_c) >= ontime3 && sh_state==false) 

    {     

          previousMillis_c = currentMillis; 

          OFF_LED(BPink_r);

          OFF_LED(Ddong_r);

          setColor(Juhwong_r,1,0,1);

          setColor(Jpink_r,1,0,1);

          OFF_LED(Blue_r);

          setColor(Red_r,1,0,1);

          OFF_LED(Yellow_r);

          sh_state =! sh_state;//s

    }

      else if((currentMillis - previousMillis_c) >= offtime3 && sh_state==true)

        { 

          previousMillis_c = currentMillis;       

          OFF_LED(BPink_r);

          OFF_LED(Ddong_r);

          setColor(Juhwong_r,1,0,1);

          setColor(Jpink_r,1,0,1);

          setColor(Blue_r,1,0,1);

          OFF_LED(Red_r);

          OFF_LED(Yellow_r );

          sh_state =! sh_state;

        }

  }

  else if(!a&&(b&&c))

  {

       setColor(BPink_r ,1,0,1);

      setColor(Ddong_r,1,0,0);

      setColor(Juhwong_r,1,0,0);

      setColor(Jpink_r ,1,0,1);

      setColor(Blue_r ,1,0,1);

      setColor(Red_r ,1,0,1);

      setColor(Yellow_r,1,0,0);

  }

  else if(a&&(b&&c))//7

  {

       long start = millis();

    //선 끝부분의 접촉으로 인해 변화하는 변수값 측정

    long total1 =  cs_36_34.capacitiveSensor(30);

    long total2 =  cs_36_44.capacitiveSensor(30);

    long total3 =  cs_36_46.capacitiveSensor(30);

    Serial.print(millis() - start);        // Capacitive Sensing 수행시간 측정

    Serial.print("\t");                    

    Serial.print(total1);                  //파란색LED를 켜기 위한 접촉 여부 값 출력

    Serial.print("\t");

    Serial.print(total2);                  //빨간색LED를 켜기 위한 접촉 여부 값 출력

    Serial.print("\t");

    Serial.println(total3);                //초록색LED를 켜기 위한 접촉 여부 값 출력

    

    //LED제어

    //정전용량값의 변화가 20이상일 경우 지정된 LED를 켜고

    //손을 떼서 다시 0이 될 경우 LED를 끈다.

    if(total1 > 20) {

      digitalWrite(40, HIGH);

    }

    else {

      digitalWrite(40, LOW);

    }

    if(total2 > 20) {

      digitalWrite(42, HIGH);

    }

    else {

      digitalWrite(42, LOW);

    }

    if(total3 > 20) {

      digitalWrite(38, HIGH);

    }

    else {

      digitalWrite(38, LOW);

    }

    

    delay(10);                            

}

 

  else{

        

          OFF_LED(BPink_r);

          OFF_LED(Ddong_r);

          OFF_LED(Juhwong_r);

          OFF_LED(Jpink_r);

          OFF_LED(Blue_r);

          OFF_LED(Red_r);

          OFF_LED(Yellow_r );  

  }

 

  }

 

void setColor_A(int redPin, int red, int green, int blue)

{

  analogWrite(redPin, red);

  analogWrite(redPin+1, green);

  analogWrite(redPin+2, blue);

}

void setColor(int redPIn, int red, int green, int blue)

{

  digitalWrite(redPIn, red);

  digitalWrite(redPIn+1, green);

  digitalWrite(redPIn+2, blue);

}

void OFF_LED(int redpin)

{

  digitalWrite(redpin,LOW);

  digitalWrite(redpin+1,LOW);

  digitalWrite(redpin+2,LOW);

}
