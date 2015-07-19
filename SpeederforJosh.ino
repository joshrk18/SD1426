int sensorPin = A3;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int left = 0;
int increasedecrease=0;
double timer=0;
double ttimer=0;
double swingtimer=0;
double sliver=0;
int indexer=0;
int p = 0;


boolean H[10][69]={
  {1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1},
  {0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},  };
   
   void LED(boolean d[][69])
   {
    if(d[0][p]) High0(); else Low0();
    if(d[1][p]) High1(); else Low1();
    if(d[2][p]) High2(); else Low2();
    if(d[3][p]) High3(); else Low3();
    if(d[4][p]) High4(); else Low4();
    if(d[5][p]) High5(); else Low5();
    if(d[6][p]) High6(); else Low6();
    if(d[7][p]) High7(); else Low7();
    if(d[8][p]) High8(); else Low8();
    if(d[9][p]) High9(); else Low9();
    if(d[10][p]) High10(); else Low10();
    if(d[11][p]) High11(); else Low11();
    if(d[12][p]) High12(); else Low12();
    if(d[13][p]) High13(); else Low13();
   }
   
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  for(int i = 2; i < 13; i++)  {pinMode(i, OUTPUT);}  // initialize digital pins 0-50 as an output. note: 0&1 are for serial comunication
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); // turn the ledPin on


 
  if (sensorValue>460&&sensorValue<480) {
    swingtimer=ttimer;
    timer=millis();
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    if (indexer==1){
       if (swingtimer>50){
         
     indexer=3; 
    }
    }
    increasedecrease=sensorValue;
     
  }
  else {
     ttimer=(millis()-timer);
    if (ttimer>24*sliver&&ttimer<25*sliver){
      p=0;
      LED(H);
    }
   else if (ttimer>25*sliver&&ttimer<26*sliver){
   p=1;
   LED(H);
    
    }
  
    
    else if (ttimer>26*sliver&&ttimer<27*sliver){
  p=2;
  LED(H);
    }
    
       else if (ttimer>27*sliver&&ttimer<28*sliver){
p=3;
LED(H);
  }
    
        else if (ttimer>28*sliver&&ttimer<29*sliver){
  p=4;
  LED(H);
    }
    
      else if (ttimer>29*sliver&&ttimer<30*sliver){
  p=5;
  LED(H);
    }
    
      else if (ttimer>30*sliver&&ttimer<31*sliver){
p=6;
LED(H);
    }
    
    else if (ttimer>31*sliver&&ttimer<32*sliver){
p=7; 
LED(H);
    }
    
      else if (ttimer>32*sliver&&ttimer<33*sliver){
p=8;
LED(H);
    }
    
     else if (ttimer>33*sliver&&ttimer<34*sliver){
p=9;
LED(H);
    }
    
    else if (ttimer>34*sliver&&ttimer<35*sliver){
 p=10;
 LED(H);
    }
    
     else if (ttimer>35*sliver&&ttimer<36*sliver){
p=11;
LED(H);
    }
    
    else if (ttimer>36*sliver&&ttimer<37*sliver){
p=12;
LED(H);
    }
    
       else if (ttimer>37*sliver&&ttimer<38*sliver){
  p=13;
  LED(H);
    }
    
        else if (ttimer>38*sliver&&ttimer<39*sliver){
 p=14;
 LED(H);
    }
    
      else if (ttimer>39*sliver&&ttimer<40*sliver){
 p=15;
 LED(H);
    }
    
      else if (ttimer>40*sliver&&ttimer<41*sliver){
p=16;
LED(H);
    }
    
    else if (ttimer>41*sliver&&ttimer<42*sliver){
p=17;
LED(H);
    }
    
      else if (ttimer>42*sliver&&ttimer<43*sliver){
p=18;
LED(H);
    }
    
     else if (ttimer>43*sliver&&ttimer<44*sliver){
p=19;
LED(H);
    }
    
    else if (ttimer>44*sliver&&ttimer<45*sliver){
p=20;
LED(H);
    }
    
    else if (ttimer>45*sliver&&ttimer<46*sliver){
p=21;
LED(H);
    }
    
    else if (ttimer>46*sliver&&ttimer<47*sliver){
p=22;
LED(H);
    }
    
       else if (ttimer>48*sliver&&ttimer<49*sliver){
p=23;
LED(H);
    }
    
        else if (ttimer>49*sliver&&ttimer<50*sliver){
p=24;
LED(H);
    }
    
      else if (ttimer>50*sliver&&ttimer<51*sliver){
p=25;
LED(H);
    }
    
      else if (ttimer>51*sliver&&ttimer<52*sliver){
p=26;
LED(H);
    }
    
    else if (ttimer>52*sliver&&ttimer<53*sliver){
  p=27;
  LED(H);
    }
    
      else if (ttimer>53*sliver&&ttimer<54*sliver){
p=28;
LED(H);
    }
    
     else if (ttimer>54*sliver&&ttimer<55*sliver){
    p=29;
    LED(H);
    }
    
    else if (ttimer>55*sliver&&ttimer<56*sliver){
p=30;
LED(H);
    }
    
    else if (ttimer>56*sliver&&ttimer<57*sliver){
p=31;
LED(H);
    }
    
    else if (ttimer>57*sliver&&ttimer<58*sliver){
p=32;
LED(H);

    }
    
       else if (ttimer>58*sliver&&ttimer<59*sliver){
p=33;
LED(H);
    }
    
        else if (ttimer>59*sliver&&ttimer<60*sliver){
p=34;
LED(H);
    }
    
      else if (ttimer>60*sliver&&ttimer<61*sliver){
p=35;
LED(H);
      }
    
      else if (ttimer>61*sliver&&ttimer<62*sliver){
p=36;
LED(H);
    }
    
    else if (ttimer>63*sliver&&ttimer<64*sliver){
p=37;
LED(H);
    }
    
      else if (ttimer>64*sliver&&ttimer<65*sliver){
p=38;
LED(H);
    }
    
     else if (ttimer>65*sliver&&ttimer<66*sliver){
p=39;
LED(H);
    }
    
    else if (ttimer>66*sliver&&ttimer<67*sliver){
p=40;
LED(H);
    }
    
    else if (ttimer>67*sliver&&ttimer<68*sliver){
p=41;
LED(H);
    }
    
    else if (ttimer>69*sliver&&ttimer<70*sliver){
p=42;
LED(H);
    }
    
       else if (ttimer>70*sliver&&ttimer<71*sliver){
p=43;
LED(H);
    }
    
        else if (ttimer>71*sliver&&ttimer<72*sliver){
p=44;
LED(H);
    }
    
      else if (ttimer>72*sliver&&ttimer<73*sliver){
    p=45;
    LED(H);
    }
    
      else if (ttimer>73*sliver&&ttimer<74*sliver){
p=46;
LED(H);
    }
    
    else if (ttimer>74*sliver&&ttimer<75*sliver){
 p=47;
 LED(H);
    }
    
      else if (ttimer>75*sliver&&ttimer<76*sliver){
p=48;
LED(H);
    }
    
     else if (ttimer>76*sliver&&ttimer<77*sliver){
p=49;
LED(H);
    }
    
    else if (ttimer>77*sliver&&ttimer<78*sliver){
p=50;
LED(H);
    }
    
    else if (ttimer>78*sliver&&ttimer<79*sliver){
p=51;
LED(H);
    }
    
    else if (ttimer>79*sliver&&ttimer<80*sliver){
p=52;
LED(H);
    }
    
       else if (ttimer>80*sliver&&ttimer<81*sliver){
p=53;
LED(H);
    }
    
        else if (ttimer>81*sliver&&ttimer<82*sliver){
p=54;
LED(H);
    }
    
      else if (ttimer>82*sliver&&ttimer<83*sliver){
p=55;
LED(H);
    }
    
      else if (ttimer>83*sliver&&ttimer<84*sliver){
p=56;
LED(H);
    }
    
    else if (ttimer>84*sliver&&ttimer<85*sliver){
  p=57;
  LED(H);
    }
    
      else if (ttimer>85*sliver&&ttimer<86*sliver){
p=58;
LED(H);
    }
    
     else if (ttimer>86*sliver&&ttimer<87*sliver){
p=59;
LED(H);
    }
    
    else if (ttimer>87*sliver&&ttimer<88*sliver){
p=60;
LED(H);
    }
    
    else if (ttimer>88*sliver&&ttimer<89*sliver){
p=61;
LED(H);
    }
    
    else if (ttimer>89*sliver&&ttimer<90*sliver){
p=62;
LED(H);
    }
    
       else if (ttimer>90*sliver&&ttimer<91*sliver){
p=63;
LED(H);
    }
    
        else if (ttimer>91*sliver&&ttimer<92*sliver){
p=64;
LED(H);
    }
    
      else if (ttimer>92*sliver&&ttimer<93*sliver){
p=65;
LED(H);
    }
    
      else if (ttimer>93*sliver&&ttimer<94*sliver){
p=66;
LED(H);
    }
    
    else if (ttimer>94*sliver&&ttimer<95*sliver){
p=67;
LED(H);
    }
    
      else if (ttimer>95*sliver&&ttimer<96*sliver){
p=68;
LED(H);
    }
    
     else if (ttimer>96*sliver&&ttimer<97*sliver){
p=69;
LED(H);
    }
    
    
    else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
  
  
  
  if (indexer==3) {
  // Serial.println(sensorValue);
 // Serial.print(swingtimer);
 // Serial.print("\t");
  // Serial.println(sliver);
   indexer=0;
   sliver=swingtimer/98;
  }
  indexer=1;
  }
 
 Serial.println(millis());
}

static inline void Low0() { PIOA->PIO_CODR = 1<<8; }
static inline void High0() { PIOA->PIO_SODR = 1<<8; }

static inline void Low1() { PIOA->PIO_CODR = 1<<9; }
static inline void High1() { PIOA->PIO_SODR = 1<<9; }

static inline void Low2() { PIOB->PIO_CODR = 1<<25; }
static inline void High2() { PIOB->PIO_SODR = 1<<25; }

static inline void Low3() { PIOC->PIO_CODR = 1<<28; }
static inline void High3() { PIOC->PIO_SODR = 1<<28; }

static inline void Low4() { PIOA->PIO_CODR = 1<<29; PIOC->PIO_CODR = 1<<26;}
static inline void High4() { PIOA->PIO_SODR = 1<<29; PIOC->PIO_SODR = 1<<26;}

static inline void Low5() { PIOC->PIO_CODR = 1<<25; }
static inline void High5() { PIOC->PIO_SODR = 1<<25; }

static inline void Low6() { PIOC->PIO_CODR = 1<<24; }
static inline void High6() { PIOC->PIO_SODR = 1<<24; }

static inline void Low7() { PIOC->PIO_CODR = 1<<23; }
static inline void High7() { PIOC->PIO_SODR = 1<<23; }

static inline void Low8() { PIOC->PIO_CODR = 1<<22; }
static inline void High8() { PIOC->PIO_SODR = 1<<22; }

static inline void Low9() { PIOC->PIO_CODR = 1<<21; }
static inline void High9() { PIOC->PIO_SODR = 1<<21; }

static inline void Low10() { PIOC->PIO_CODR = 1<<29;  PIOA->PIO_CODR = 1<<28; }
static inline void High10() { PIOC->PIO_SODR = 1<<29; PIOA->PIO_SODR = 1<<28;}

static inline void Low11() { PIOD->PIO_CODR = 1<<7; }
static inline void High11() { PIOD->PIO_SODR = 1<<7; }

static inline void Low12() { PIOD->PIO_CODR = 1<<8; }
static inline void High12() { PIOD->PIO_SODR = 1<<8; }

static inline void Low13() { PIOB->PIO_CODR = 1<<27; }
static inline void High13() { PIOB->PIO_SODR = 1<<27; }

static inline void Low14() { PIOD->PIO_CODR = 1<<4; }
static inline void High14() { PIOD->PIO_SODR = 1<<4; }

static inline void Low15() { PIOD->PIO_CODR = 1<<5; }
static inline void High15() { PIOD->PIO_SODR = 1<<5; }

static inline void Low16() { PIOA->PIO_CODR = 1<<13; }
static inline void High16() { PIOA->PIO_SODR = 1<<13; }

static inline void Low17() { PIOA->PIO_CODR = 1<<12; }
static inline void High17() { PIOA->PIO_SODR = 1<<12; }

static inline void Low18() { PIOA->PIO_CODR = 1<<11; }
static inline void High18() { PIOA->PIO_SODR = 1<<11; }

static inline void Low19() { PIOA->PIO_CODR = 1<<10; }
static inline void High19() { PIOA->PIO_SODR = 1<<10; }

static inline void Low20() { PIOB->PIO_CODR = 1<<12; }
static inline void High20() { PIOB->PIO_SODR = 1<<12; }

static inline void Low21() { PIOB->PIO_CODR = 1<<13; }
static inline void High21() { PIOB->PIO_SODR = 1<<13; }

static inline void Low22() { PIOB->PIO_CODR = 1<<26; }
static inline void High22() { PIOB->PIO_SODR = 1<<26; }

static inline void Low23() { PIOA->PIO_CODR = 1<<14; }
static inline void High23() { PIOA->PIO_SODR = 1<<14; }

static inline void Low24() { PIOA->PIO_CODR = 1<<15; }
static inline void High24() { PIOA->PIO_SODR = 1<<15; }

static inline void Low25() { PIOD->PIO_CODR = 1<<0; }
static inline void High25() { PIOD->PIO_SODR = 1<<0; }

static inline void Low26() { PIOD->PIO_CODR = 1<<1; }
static inline void High26() { PIOD->PIO_SODR = 1<<1; }

static inline void Low27() { PIOD->PIO_CODR = 1<<2; }
static inline void High27() { PIOD->PIO_SODR = 1<<2; }

static inline void Low28() { PIOD->PIO_CODR = 1<<3; }
static inline void High28() { PIOD->PIO_SODR = 1<<3; }

static inline void Low29() { PIOD->PIO_CODR = 1<<6; }
static inline void High29() { PIOD->PIO_SODR = 1<<6; }

static inline void Low30() { PIOD->PIO_CODR = 1<<9; }
static inline void High30() { PIOD->PIO_SODR = 1<<9; }

static inline void Low31() { PIOA->PIO_CODR = 1<<7; }
static inline void High31() { PIOA->PIO_SODR = 1<<7; }

static inline void Low32() { PIOD->PIO_CODR = 1<<10; }
static inline void High32() { PIOD->PIO_SODR = 1<<10; }

static inline void Low33() { PIOC->PIO_CODR = 1<<1; }
static inline void High33() { PIOC->PIO_SODR = 1<<1; }

static inline void Low34() { PIOC->PIO_CODR = 1<<2; }
static inline void High34() { PIOC->PIO_SODR = 1<<2; }

static inline void Low35() { PIOC->PIO_CODR = 1<<3; }
static inline void High35() { PIOC->PIO_SODR = 1<<3; }

static inline void Low36() { PIOC->PIO_CODR = 1<<4; }
static inline void High36() { PIOC->PIO_SODR = 1<<4; }

static inline void Low37() { PIOC->PIO_CODR = 1<<5; }
static inline void High37() { PIOC->PIO_SODR = 1<<5; }

static inline void Low38() { PIOC->PIO_CODR = 1<<6; }
static inline void High38() { PIOC->PIO_SODR = 1<<6; }

static inline void Low39() { PIOC->PIO_CODR = 1<<7; }
static inline void High39() { PIOC->PIO_SODR = 1<<7; }

static inline void Low40() { PIOC->PIO_CODR = 1<<8; }
static inline void High40() { PIOC->PIO_SODR = 1<<8; }

static inline void Low41() { PIOC->PIO_CODR = 1<<9; }
static inline void High41() { PIOC->PIO_SODR = 1<<9; }

static inline void Low42() { PIOA->PIO_CODR = 1<<19; }
static inline void High42() { PIOA->PIO_SODR = 1<<19; }

static inline void Low43() { PIOA->PIO_CODR = 1<<20; }
static inline void High43() { PIOA->PIO_SODR = 1<<20; }

static inline void Low44() { PIOC->PIO_CODR = 1<<19; }
static inline void High44() { PIOC->PIO_SODR = 1<<19; }

static inline void Low45() { PIOC->PIO_CODR = 1<<18; }
static inline void High45() { PIOC->PIO_SODR = 1<<18; }

static inline void Low46() { PIOC->PIO_CODR = 1<<17; }
static inline void High46() { PIOC->PIO_SODR = 1<<17; }

static inline void Low47() { PIOC->PIO_CODR = 1<<16; }
static inline void High47() { PIOC->PIO_SODR = 1<<16; }

static inline void Low48() { PIOC->PIO_CODR = 1<<15; }
static inline void High48() { PIOC->PIO_SODR = 1<<15; }

static inline void Low49() { PIOC->PIO_CODR = 1<<14; }
static inline void High49() { PIOC->PIO_SODR = 1<<14; }

static inline void Low50() { PIOC->PIO_CODR = 1<<13; }
static inline void High50() { PIOC->PIO_SODR = 1<<13; }

static inline void Low51() { PIOC->PIO_CODR = 1<<12; }
static inline void High51() { PIOC->PIO_SODR = 1<<12; }
