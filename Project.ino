/*
  Senior Design Project ECE405

  modified 19/2/2015
  by Alex Liebsch, Jay Miller, Joshua Kertscher
 */

int sensorPin = A3;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int left = 0;
int rightswing=0;
double timer=0;
double ttimer=0;
double swingtimer=0;
double sliver=0;
int indexer=0;
double counter=0;
double start=0;
int p = 0;

int mapB[10][69]={
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
   

/*PIO_SODR-Set Output Data Register
PIO_CODR-Clear Output Data Register
PIOX- Parallel IO Controller X*/
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

void LED(boolean d[][20])
{
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
}
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  for(int i = 2; i < 13; i++)  {pinMode(i, OUTPUT);}  // initialize digital pins 0-50 as an output. note: 0&1 are for serial comunication
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); // turn the ledPin on
 
  if (sensorValue>460&&sensorValue<480) 
  {
    timer=millis();
    swingtimer=ttimer;

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
    if (indexer==1)
    {
       if (swingtimer>50)
       {
          indexer=3; 
          //Serial.println(indexer);
       }
    }
     
  }
  else {
   // Serial.println(millis());
    if (sensorValue<460){ttimer=millis()-timer;
        if(ttimer>98*sliver){
        counter=ttimer;
        start=timer;
        }
      }
   
  
    else if (sensorValue>480){
  ttimer=(counter-(millis()-start-counter));}
  
    if (ttimer>25*sliver&&ttimer<26*sliver)
    {
      p = 0; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
  
    
    else if (ttimer>26*sliver&&ttimer<27*sliver)
    {
      p = 1; // set position variable to 1
      LED(mapB); // Display vector 1 of mapB
    }
    
    else if (ttimer>27*sliver&&ttimer<28*sliver)
    {
      p = 2; // set position variable to 2
      LED(mapB); // Display vector 2 of mapB
    }
    
    else if (ttimer>28*sliver&&ttimer<29*sliver)
    {
      p = 3; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>29*sliver&&ttimer<30*sliver)
    {
      p = 4; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>30*sliver&&ttimer<31*sliver)
    {
      p = 5; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>31*sliver&&ttimer<32*sliver)
    {
      p = 6; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>32*sliver&&ttimer<33*sliver)
    {
      p = 7; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>33*sliver&&ttimer<34*sliver)
    {
      p = 8; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>34*sliver&&ttimer<35*sliver)
    {
      p = 9; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>35*sliver&&ttimer<36*sliver)
    {
      p = 10; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>36*sliver&&ttimer<37*sliver)
    {
      p = 11; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>37*sliver&&ttimer<38*sliver)
    {
      p = 12; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>38*sliver&&ttimer<39*sliver)
    {
      p = 13; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>39*sliver&&ttimer<40*sliver)
    {
      p = 14; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>40*sliver&&ttimer<41*sliver)
    {
      p = 15; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>41*sliver&&ttimer<42*sliver)
    {
      p = 16; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>42*sliver&&ttimer<43*sliver)
    {
      p = 17; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>43*sliver&&ttimer<44*sliver)
    {
      p = 18; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>44*sliver&&ttimer<45*sliver)
    {
      p = 19; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>45*sliver&&ttimer<46*sliver)
    {
      p = 20; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>46*sliver&&ttimer<47*sliver)
    {
      p = 21; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>48*sliver&&ttimer<49*sliver)
    {
      p = 22; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>49*sliver&&ttimer<50*sliver)
    {
      p = 23; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>50*sliver&&ttimer<51*sliver)
    {
      p = 24; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>51*sliver&&ttimer<52*sliver)
    {
      p = 25; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    
    else if (ttimer>52*sliver&&ttimer<53*sliver)
    {
      p = 26; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>53*sliver&&ttimer<54*sliver)
    {
      p = 27; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>54*sliver&&ttimer<55*sliver)
    {
      p = 28; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>55*sliver&&ttimer<56*sliver)
    {
      p = 29; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>56*sliver&&ttimer<57*sliver)
    {
      p = 30; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>57*sliver&&ttimer<58*sliver)
    {
      p = 31; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>58*sliver&&ttimer<59*sliver)
    {
      p = 32; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>59*sliver&&ttimer<60*sliver)
    {
      p = 33; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>60*sliver&&ttimer<61*sliver)
    {
      p = 34; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>61*sliver&&ttimer<62*sliver)
    {
      p = 35; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>63*sliver&&ttimer<64*sliver)
    {
      p = 36; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>64*sliver&&ttimer<65*sliver)
    {
      p = 37; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>65*sliver&&ttimer<66*sliver)
    {
      p = 38; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>66*sliver&&ttimer<67*sliver)
    {
      p = 39; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>67*sliver&&ttimer<68*sliver)
    {
      p = 40; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>69*sliver&&ttimer<70*sliver)
    {
      p = 41; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>70*sliver&&ttimer<71*sliver)
    {
      p = 42; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>71*sliver&&ttimer<72*sliver)
    {
      p = 43; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>72*sliver&&ttimer<73*sliver)
    {
      p = 44; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>73*sliver&&ttimer<74*sliver)
    {
      p = 45; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>74*sliver&&ttimer<75*sliver)
    {
      p = 46; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>75*sliver&&ttimer<76*sliver)
    {
      p = 47; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>76*sliver&&ttimer<77*sliver)
    {
      p = 48; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>77*sliver&&ttimer<78*sliver)
    {
      p = 49; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>78*sliver&&ttimer<79*sliver)
    {
      p = 50; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>79*sliver&&ttimer<80*sliver)
    {
      p = 51; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>80*sliver&&ttimer<81*sliver)
    {
      p = 52; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>81*sliver&&ttimer<82*sliver)
    {
      p = 53; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>82*sliver&&ttimer<83*sliver)
    {
      p = 54; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>83*sliver&&ttimer<84*sliver)
    {
      p = 55; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>84*sliver&&ttimer<85*sliver)
    {
      p = 56; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>85*sliver&&ttimer<86*sliver)
    {
      p = 57; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>86*sliver&&ttimer<87*sliver)
    {
      p = 58; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>87*sliver&&ttimer<88*sliver)
    {
      p = 59; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>88*sliver&&ttimer<89*sliver)
    {
      p = 60; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>89*sliver&&ttimer<90*sliver)
    {
      p = 61; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>90*sliver&&ttimer<91*sliver)
    {
      p = 62; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>91*sliver&&ttimer<92*sliver)
    {
      p = 63; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>92*sliver&&ttimer<93*sliver)
    {
      p = 64; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>93*sliver&&ttimer<94*sliver)
    {
      p = 65; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>94*sliver&&ttimer<95*sliver)
    {
      p = 66; // set position variable to 0
      LED(mapB); // Display vector 0 of mapB
    }
    
    else if (ttimer>95*sliver&&ttimer<96*sliver)
    {
      p = 67; // set position variable to 67
      LED(mapB); // Display vector 67 of mapB
    }
    
    else if (ttimer>96*sliver&&ttimer<97*sliver)
    {
      p = 68; // set position variable to 68
      LED(mapB); // Display vector 68 of mapB
    }
    
    else if (ttimer>97*sliver&&ttimer<98*sliver)
    {
      p = 69; // set position variable to 69
      LED(mapB); // Display vector 69 of mapB
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
  
  //Serial.println(indexer);
  if (indexer==3) {
   Serial.println(sensorValue);
   Serial.print(swingtimer);
   Serial.print("\t");
   Serial.println(sliver);
   indexer=0;
   sliver=swingtimer/123;
   Serial.println(sliver);
  }
   indexer=1;
  }

 
 
}
