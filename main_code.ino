//Ulica 1 /Street 1
const int U1red = 13;
const int U1green = 12;
const int U1sensor = A5;            
int U1Detectorstate = LOW;            
int U1val = 0;
unsigned long TU1 = 0;
bool U1moved = false;
bool U1info = true;
bool U1isitgreen = false;

//Ulica 2 /Street 2
const int U2red = 9;
const int U2green = 8;
const int U2sensor = A4;            
int U2Detectorstate = LOW;            
int U2val = 0;
unsigned long TU2 = 0;
bool U2moved = false;
bool U2info = true;
bool U2isitgreen = false;

//Ulica 3 /Street 3
const int U3red = 7;
const int U3green = 6;
const int U3sensor = A3;            
int U3Detectorstate = LOW;            
int U3val = 0;
unsigned long TU3 = 0;
bool U3moved = false;
bool U3info = true;
bool U3isitgreen = false;

//Pasy /Zebra
const int Pushbutton = 2;
const int Pred = 11;
const int Pgreen = 10;
int Pval = 0;
unsigned long TP = 0;
bool Pressed = false;
bool Pisitgreen = false;
bool Pinfo = true;



void setup() {
  Serial.begin(9600);
  //Ulica 1 /Street 1
  pinMode(U1sensor, INPUT);
  pinMode(U1red, OUTPUT);
  pinMode(U1green, OUTPUT);
  digitalWrite(U1red, HIGH);
  //Ulica 2 /Street 2
  pinMode(U2sensor, INPUT);
  pinMode(U2red, OUTPUT);
  pinMode(U2green, OUTPUT);
  digitalWrite(U2red, HIGH);
  //Ulica 3 /Street 3
  pinMode(U3sensor, INPUT);
  pinMode(U3red, OUTPUT);
  pinMode(U3green, OUTPUT);
  digitalWrite(U3red, HIGH);
  //Pasy /Zebra
  pinMode (Pushbutton, INPUT);
  pinMode(Pred, OUTPUT);
  pinMode(Pgreen, OUTPUT);
  digitalWrite(Pred, HIGH);
   
}

void loop(){
  //detectors
  Pval = digitalRead(Pushbutton);
  U1val = digitalRead(U1sensor);
   U2val = digitalRead(U2sensor);
   U3val = digitalRead(U3sensor);
   
  //Ulica 1 /Street 1
   
  if(U1val == HIGH)
   {
     U1moved = true;
     
   }
 
  if((U1moved == true)&&(digitalRead(Pgreen) == false)&&(digitalRead(U2green) == false)&&(digitalRead(U3green) == false))
  {
    TU1 = millis();
    U1moved = false;
    if(U1info == true)
    {
       
      Serial.println("Street 1 is green");
      U1info = false;
    }
    digitalWrite(U1green, HIGH);
    digitalWrite(U1red, LOW);
    U1isitgreen = true;
   
  }
  if(digitalRead(U1green)==HIGH && millis() - TU1 > 1000)
  {
    digitalWrite(U1green, LOW);
    digitalWrite(U1red, HIGH);
    U1moved = false;
    U1info = true;
    U1isitgreen = false;
  }
   //Ulica 2 /Street 2
   if(U2val == HIGH)
   {
     U2moved = true;
     
   }
  if((U2moved == true)&&(digitalRead(U1green)== false)&&(digitalRead(U3green) == false))
  {
    TU2 = millis();
    U2moved = false;
    if(U2info == true)
    {
       
      Serial.println("Street 2 is green");
      U2info = false;
    }
    digitalWrite(U2green, HIGH);
    digitalWrite(U2red, LOW);
    U2isitgreen = true;
   
  }
  if(digitalRead(U2green) == HIGH && millis() - TU2 > 1000)
  {
    digitalWrite(U2green, LOW);
    digitalWrite(U2red, HIGH);
    U2moved = false;
    U2info = true;
    U2isitgreen = false;
  }
  //Ulica 3 /Street 3
   if(U3val == HIGH)
   {
     U3moved = true;
     
   }
  if((U3moved == true)&&(digitalRead(U2green)== false)&&(digitalRead(U1green)== false))
  {
    TU3 = millis();
    U3moved = false;
    if(U3info == true)
    {
       
      Serial.println("Street 3 is green");
      U3info = false;
    }
    digitalWrite(U3green, HIGH);
    digitalWrite(U3red, LOW);
    U3isitgreen = true;
   
  }
  if(digitalRead(U3green) == HIGH && millis() - TU3 > 1000)
  {
    digitalWrite(U3green, LOW);
    digitalWrite(U3red, HIGH);
    U3moved = false;
    U3info = true;
    U3isitgreen = false;
  }
 
 
  //Pasy /Zebra
  if(Pval == LOW)
   {
     Pressed = true;
   
   }
 
  if( (Pressed == true)&&(U1isitgreen == false))
  {
    Pressed = false;
    TP = millis();
    if(Pinfo == true)
    {
      Serial.println("Zebra is green");
      Pinfo = false;
    }
    digitalWrite(Pred, LOW);
  digitalWrite(Pgreen, HIGH);
    Pisitgreen = true;
   
  }
  if(millis() - TP > 1000 && digitalRead(Pgreen) == HIGH )
  {
      digitalWrite(Pred, HIGH);
      digitalWrite(Pgreen, LOW);
      Pisitgreen = false;
     Pressed = false;
      Pinfo = true;
   
  }
   
}