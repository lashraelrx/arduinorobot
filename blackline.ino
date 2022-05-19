#define LSens A0
#define RSens A1

#define LMSpeed 3
#define LMDirection 12

#define RMSpeed 11
#define RMDirection 13

#define  RLSens A2
#define  MLSens A3
#define  LLSens A4

int right_distance;
int mid_distance;
int left_distance;

int leftcolor;
int rightcolor;



void setup(){

  pinMode(LSens,INPUT);
  pinMode(RSens,INPUT);

  pinMode(RLSens,INPUT);
  pinMode(MLSens,INPUT);
  pinMode(LLSens ,INPUT);

  pinMode(LMSpeed ,OUTPUT);
  pinMode(LMDirection,OUTPUT);

  pinMode(RMSpeed,OUTPUT);
  pinMode(RMDirection,OUTPUT);

  Serial.begin(9600);
  
  
}

void loop(){

  leftcolor = analogRead(LSens);
  rightcolor = analogRead(RSens);

  right_distance = digitalRead(RLSens);
  mid_distance = digitalRead(MLSens);
 left_distance = digitalRead(LLSens );

  
  if(sol_renk > 300 && sag_renk > 300){  
// eğer iki sensör de siyah rengi görürse rakip robotu ara
  
    if(orta_uzaklik == 1){  //ileride bir şey varsa ileri
    
       // dışarı atmak icin ileri
    analogWrite(RMSpeed,250);
    digitalWrite(RMDirection,HIGH);
  
    analogWrite(LMSpeed ,250);
    digitalWrite(LMDirection,HIGH); 
    delay(400);
    }
    
    else if(sol_uzaklik == 1){    
// sag motor calisir tespit edilene kadar
    
    analogWrite(LMSpeed ,0);
    digitalWrite(LMDirection,HIGH);

    analogWrite(RMSpeed,100);
    digitalWrite(RMDirection,HIGH); 
 
    delay(1); 
    }
    
    else if(sag_uzaklik == 1){     
// sol motor calisir tespit edene ladar
    
      analogWrite(LMSpeed ,100);
      digitalWrite(LMDirection,HIGH);
    
      analogWrite(RMSpeed,0);
      digitalWrite(RMDirection,HIGH);
      delay(10);
    
    }
    
    else{
//kendi etrafında döner 
    
     analogWrite(RMSpeed,150);
     digitalWrite(RMDirection,HIGH);
  
     analogWrite(LMSpeed ,150);
     digitalWrite(LMDirection, LOW);
     delayMicroseconds(100);
    
    }
  }
  
  else{  
// eğer sensörlerden biri ve ikisi beyaz rengi görürse sahaya geri dönmeye çalış


  
     analogWrite(RMSpeed,150);
     digitalWrite(RMDirection,LOW);
  
     analogWrite(LMSpeed ,150);
     digitalWrite(LMDirection,LOW);
    delay (929); 
    
    // tespit etmek icin etrafında doner
     analogWrite(RMSpeed,150);
     digitalWrite(RMDirection,LOW);
  
     analogWrite(LMSpeed ,150);
     digitalWrite(LMDirection,HIGH);
    
    delayMicroseconds(80);
    
   
  
    
  
  }


}