




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


int H[10][69]={
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
   
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  for(int i = 2; i < 13; i++)  {pinMode(i, OUTPUT);}  // initialize digital pins 0-50 as an output. note: 0&1 are for serial comunication
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); // turn the ledPin on
 

 
  if (sensorValue>460&&sensorValue<480) {
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
    if (indexer==1){
       if (swingtimer>50){
         
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
  
    if (ttimer>25*sliver&&ttimer<26*sliver){
   
    digitalWrite(2, H[0][0]);
    digitalWrite(3, H[1][0]);
    digitalWrite(5, H[2][0]);
    digitalWrite(6, H[3][0]);
    digitalWrite(7, H[4][0]);
    digitalWrite(8, H[5][0]);
    digitalWrite(9, H[6][0]);
    digitalWrite(10, H[7][0]);
    digitalWrite(11, H[8][0]);
    digitalWrite(12, H[9][0]);
    }
  
    
    else if (ttimer>26*sliver&&ttimer<27*sliver){
    digitalWrite(2, H[0][1]);
    digitalWrite(3, H[1][1]);
    digitalWrite(5, H[2][1]);
    digitalWrite(6, H[3][1]);
    digitalWrite(7, H[4][1]);
    digitalWrite(8, H[5][1]);
    digitalWrite(9, H[6][1]);
    digitalWrite(10, H[7][1]);
    digitalWrite(11, H[8][1]);
    digitalWrite(12, H[9][1]);
    }
    
       else if (ttimer>27*sliver&&ttimer<28*sliver){
    digitalWrite(2, H[0][2]);
    digitalWrite(3, H[1][2]);
    digitalWrite(5, H[2][2]);
    digitalWrite(6, H[3][2]);
    digitalWrite(7, H[4][2]);
    digitalWrite(8, H[5][2]);
    digitalWrite(9, H[6][2]);
    digitalWrite(10, H[7][2]);
    digitalWrite(11, H[8][2]);
    digitalWrite(12, H[9][2]);
    }
    
        else if (ttimer>28*sliver&&ttimer<29*sliver){
    digitalWrite(2, H[0][3]);
    digitalWrite(3, H[1][3]);
    digitalWrite(5, H[2][3]);
    digitalWrite(6, H[3][3]);
    digitalWrite(7, H[4][3]);
    digitalWrite(8, H[5][3]);
    digitalWrite(9, H[6][3]);
    digitalWrite(10, H[7][3]);
    digitalWrite(11, H[8][3]);
    digitalWrite(12, H[9][3]);
    }
    
      else if (ttimer>29*sliver&&ttimer<30*sliver){
    digitalWrite(2, H[0][4]);
    digitalWrite(3, H[1][4]);
    digitalWrite(5, H[2][4]);
    digitalWrite(6, H[3][4]);
    digitalWrite(7, H[4][4]);
    digitalWrite(8, H[5][4]);
    digitalWrite(9, H[6][4]);
    digitalWrite(10, H[7][4]);
    digitalWrite(11, H[8][4]);
    digitalWrite(12, H[9][4]);
    }
    
      else if (ttimer>30*sliver&&ttimer<31*sliver){
     digitalWrite(2, H[0][5]);
    digitalWrite(3, H[1][5]);
    digitalWrite(5, H[2][5]);
    digitalWrite(6, H[3][5]);
    digitalWrite(7, H[4][5]);
    digitalWrite(8, H[5][5]);
    digitalWrite(9, H[6][5]);
    digitalWrite(10, H[7][5]);
    digitalWrite(11, H[8][5]);
    digitalWrite(12, H[9][5]);
    }
    
    else if (ttimer>31*sliver&&ttimer<32*sliver){
     digitalWrite(2, H[0][6]);
    digitalWrite(3, H[1][6]);
    digitalWrite(5, H[2][6]);
    digitalWrite(6, H[3][6]);
    digitalWrite(7, H[4][6]);
    digitalWrite(8, H[5][6]);
    digitalWrite(9, H[6][6]);
    digitalWrite(10, H[7][6]);
    digitalWrite(11, H[8][6]);
    digitalWrite(12, H[9][6]);
    }
    
      else if (ttimer>32*sliver&&ttimer<33*sliver){
    digitalWrite(2, H[0][7]);
    digitalWrite(3, H[1][7]);
    digitalWrite(5, H[2][7]);
    digitalWrite(6, H[3][7]);
    digitalWrite(7, H[4][7]);
    digitalWrite(8, H[5][7]);
    digitalWrite(9, H[6][7]);
    digitalWrite(10, H[7][7]);
    digitalWrite(11, H[8][7]);
    digitalWrite(12, H[9][7]);
    }
    
     else if (ttimer>33*sliver&&ttimer<34*sliver){
    digitalWrite(2, H[0][8]);
    digitalWrite(3, H[1][8]);
    digitalWrite(5, H[2][8]);
    digitalWrite(6, H[3][8]);
    digitalWrite(7, H[4][8]);
    digitalWrite(8, H[5][8]);
    digitalWrite(9, H[6][8]);
    digitalWrite(10, H[7][8]);
    digitalWrite(11, H[8][8]);
    digitalWrite(12, H[9][8]);
    }
    
    else if (ttimer>34*sliver&&ttimer<35*sliver){
    digitalWrite(2, H[0][9]);
    digitalWrite(3, H[1][9]);
    digitalWrite(5, H[2][9]);
    digitalWrite(6, H[3][9]);
    digitalWrite(7, H[4][9]);
    digitalWrite(8, H[5][9]);
    digitalWrite(9, H[6][9]);
    digitalWrite(10, H[7][9]);
    digitalWrite(11, H[8][9]);
    digitalWrite(12, H[9][9]);
    }
    
     else if (ttimer>35*sliver&&ttimer<36*sliver){
    digitalWrite(2, H[0][10]);
    digitalWrite(3, H[1][10]);
    digitalWrite(5, H[2][10]);
    digitalWrite(6, H[3][10]);
    digitalWrite(7, H[4][10]);
    digitalWrite(8, H[5][10]);
    digitalWrite(9, H[6][10]);
    digitalWrite(10, H[7][10]);
    digitalWrite(11, H[8][10]);
    digitalWrite(12, H[9][10]);
    }
    
    else if (ttimer>36*sliver&&ttimer<37*sliver){
    digitalWrite(2, H[0][11]);
    digitalWrite(3, H[1][11]);
    digitalWrite(5, H[2][11]);
    digitalWrite(6, H[3][11]);
    digitalWrite(7, H[4][11]);
    digitalWrite(8, H[5][11]);
    digitalWrite(9, H[6][11]);
    digitalWrite(10, H[7][11]);
    digitalWrite(11, H[8][11]);
    digitalWrite(12, H[9][11]);
    }
    
       else if (ttimer>37*sliver&&ttimer<38*sliver){
    digitalWrite(2, H[0][12]);
    digitalWrite(3, H[1][12]);
    digitalWrite(5, H[2][12]);
    digitalWrite(6, H[3][12]);
    digitalWrite(7, H[4][12]);
    digitalWrite(8, H[5][12]);
    digitalWrite(9, H[6][12]);
    digitalWrite(10, H[7][12]);
    digitalWrite(11, H[8][12]);
    digitalWrite(12, H[9][12]);
    }
    
        else if (ttimer>38*sliver&&ttimer<39*sliver){
    digitalWrite(2, H[0][13]);
    digitalWrite(3, H[1][13]);
    digitalWrite(5, H[2][13]);
    digitalWrite(6, H[13][13]);
    digitalWrite(7, H[4][13]);
    digitalWrite(8, H[5][13]);
    digitalWrite(9, H[6][13]);
    digitalWrite(10, H[7][13]);
    digitalWrite(11, H[8][13]);
    digitalWrite(12, H[9][13]);
    }
    
      else if (ttimer>39*sliver&&ttimer<40*sliver){
    digitalWrite(2, H[0][14]);
    digitalWrite(3, H[1][14]);
    digitalWrite(5, H[2][14]);
    digitalWrite(6, H[3][14]);
    digitalWrite(7, H[4][14]);
    digitalWrite(8, H[5][14]);
    digitalWrite(9, H[6][14]);
    digitalWrite(10, H[7][14]);
    digitalWrite(11, H[8][14]);
    digitalWrite(12, H[9][14]);
    }
    
      else if (ttimer>40*sliver&&ttimer<41*sliver){
    digitalWrite(2, H[0][15]);
    digitalWrite(3, H[1][15]);
    digitalWrite(5, H[2][15]);
    digitalWrite(6, H[3][15]);
    digitalWrite(7, H[4][15]);
    digitalWrite(8, H[5][15]);
    digitalWrite(9, H[6][15]);
    digitalWrite(10, H[7][15]);
    digitalWrite(11, H[8][15]);
    digitalWrite(12, H[9][15]);
    }
    
    else if (ttimer>41*sliver&&ttimer<42*sliver){
    digitalWrite(2, H[0][16]);
    digitalWrite(3, H[1][16]);
    digitalWrite(5, H[2][16]);
    digitalWrite(6, H[3][16]);
    digitalWrite(7, H[4][16]);
    digitalWrite(8, H[5][16]);
    digitalWrite(9, H[6][16]);
    digitalWrite(10, H[7][16]);
    digitalWrite(11, H[8][16]);
    digitalWrite(12, H[9][16]);
    }
    
      else if (ttimer>42*sliver&&ttimer<43*sliver){
    digitalWrite(2, H[0][17]);
    digitalWrite(3, H[1][17]);
    digitalWrite(5, H[2][17]);
    digitalWrite(6, H[3][17]);
    digitalWrite(7, H[4][17]);
    digitalWrite(8, H[5][17]);
    digitalWrite(9, H[6][17]);
    digitalWrite(10, H[7][17]);
    digitalWrite(11, H[8][17]);
    digitalWrite(12, H[9][17]);
    }
    
     else if (ttimer>43*sliver&&ttimer<44*sliver){
    digitalWrite(2, H[0][18]);
    digitalWrite(3, H[1][18]);
    digitalWrite(5, H[2][18]);
    digitalWrite(6, H[3][18]);
    digitalWrite(7, H[4][18]);
    digitalWrite(8, H[5][18]);
    digitalWrite(9, H[6][18]);
    digitalWrite(10, H[7][18]);
    digitalWrite(11, H[8][18]);
    digitalWrite(12, H[9][18]);
    }
    
    else if (ttimer>44*sliver&&ttimer<45*sliver){
    digitalWrite(2, H[0][19]);
    digitalWrite(3, H[1][19]);
    digitalWrite(5, H[2][19]);
    digitalWrite(6, H[3][19]);
    digitalWrite(7, H[4][19]);
    digitalWrite(8, H[5][19]);
    digitalWrite(9, H[6][19]);
    digitalWrite(10, H[7][19]);
    digitalWrite(11, H[8][19]);
    digitalWrite(12, H[9][19]);
    }
    
    else if (ttimer>45*sliver&&ttimer<46*sliver){
    digitalWrite(2, H[0][20]);
    digitalWrite(3, H[1][20]);
    digitalWrite(5, H[2][20]);
    digitalWrite(6, H[3][20]);
    digitalWrite(7, H[4][20]);
    digitalWrite(8, H[5][20]);
    digitalWrite(9, H[6][20]);
    digitalWrite(10, H[7][20]);
    digitalWrite(11, H[8][20]);
    digitalWrite(12, H[9][20]);
    }
    
    else if (ttimer>46*sliver&&ttimer<47*sliver){
    digitalWrite(2, H[0][21]);
    digitalWrite(3, H[1][21]);
    digitalWrite(5, H[2][21]);
    digitalWrite(6, H[3][21]);
    digitalWrite(7, H[4][21]);
    digitalWrite(8, H[5][21]);
    digitalWrite(9, H[6][21]);
    digitalWrite(10, H[7][21]);
    digitalWrite(11, H[8][21]);
    digitalWrite(12, H[9][21]);
    }
    
       else if (ttimer>48*sliver&&ttimer<49*sliver){
    digitalWrite(2, H[0][22]);
    digitalWrite(3, H[1][22]);
    digitalWrite(5, H[2][22]);
    digitalWrite(6, H[3][22]);
    digitalWrite(7, H[4][22]);
    digitalWrite(8, H[5][22]);
    digitalWrite(9, H[6][22]);
    digitalWrite(10, H[7][22]);
    digitalWrite(11, H[8][22]);
    digitalWrite(12, H[9][22]);
    }
    
        else if (ttimer>49*sliver&&ttimer<50*sliver){
    digitalWrite(2, H[0][23]);
    digitalWrite(3, H[1][23]);
    digitalWrite(5, H[2][23]);
    digitalWrite(6, H[3][23]);
    digitalWrite(7, H[4][23]);
    digitalWrite(8, H[5][23]);
    digitalWrite(9, H[6][23]);
    digitalWrite(10, H[7][23]);
    digitalWrite(11, H[8][23]);
    digitalWrite(12, H[9][23]);
    }
    
      else if (ttimer>50*sliver&&ttimer<51*sliver){
    digitalWrite(2, H[0][24]);
    digitalWrite(3, H[1][24]);
    digitalWrite(5, H[2][24]);
    digitalWrite(6, H[3][24]);
    digitalWrite(7, H[4][24]);
    digitalWrite(8, H[5][24]);
    digitalWrite(9, H[6][24]);
    digitalWrite(10, H[7][24]);
    digitalWrite(11, H[8][24]);
    digitalWrite(12, H[9][24]);
    }
    
      else if (ttimer>51*sliver&&ttimer<52*sliver){
    digitalWrite(2, H[0][25]);
    digitalWrite(3, H[1][25]);
    digitalWrite(5, H[2][25]);
    digitalWrite(6, H[3][25]);
    digitalWrite(7, H[4][25]);
    digitalWrite(8, H[5][25]);
    digitalWrite(9, H[6][25]);
    digitalWrite(10, H[7][25]);
    digitalWrite(11, H[8][25]);
    digitalWrite(12, H[9][25]);
    }
    
    else if (ttimer>52*sliver&&ttimer<53*sliver){
    digitalWrite(2, H[0][26]);
    digitalWrite(3, H[1][26]);
    digitalWrite(5, H[2][26]);
    digitalWrite(6, H[3][26]);
    digitalWrite(7, H[4][26]);
    digitalWrite(8, H[5][26]);
    digitalWrite(9, H[6][26]);
    digitalWrite(10, H[7][26]);
    digitalWrite(11, H[8][26]);
    digitalWrite(12, H[9][26]);
    }
    
      else if (ttimer>53*sliver&&ttimer<54*sliver){
    digitalWrite(2, H[0][27]);
    digitalWrite(3, H[1][27]);
    digitalWrite(5, H[2][27]);
    digitalWrite(6, H[3][27]);
    digitalWrite(7, H[4][27]);
    digitalWrite(8, H[5][27]);
    digitalWrite(9, H[6][27]);
    digitalWrite(10, H[7][27]);
    digitalWrite(11, H[8][27]);
    digitalWrite(12, H[9][27]);
    }
    
     else if (ttimer>54*sliver&&ttimer<55*sliver){
    digitalWrite(2, H[0][28]);
    digitalWrite(3, H[1][28]);
    digitalWrite(5, H[2][28]);
    digitalWrite(6, H[3][28]);
    digitalWrite(7, H[4][28]);
    digitalWrite(8, H[5][28]);
    digitalWrite(9, H[6][28]);
    digitalWrite(10, H[7][28]);
    digitalWrite(11, H[8][28]);
    digitalWrite(12, H[9][28]);
    }
    
    else if (ttimer>55*sliver&&ttimer<56*sliver){
    digitalWrite(2, H[0][29]);
    digitalWrite(3, H[1][29]);
    digitalWrite(5, H[2][29]);
    digitalWrite(6, H[3][29]);
    digitalWrite(7, H[4][29]);
    digitalWrite(8, H[5][29]);
    digitalWrite(9, H[6][29]);
    digitalWrite(10, H[7][29]);
    digitalWrite(11, H[8][29]);
    digitalWrite(12, H[9][29]);
    }
    
    else if (ttimer>56*sliver&&ttimer<57*sliver){
    digitalWrite(2, H[0][30]);
    digitalWrite(3, H[1][30]);
    digitalWrite(5, H[2][30]);
    digitalWrite(6, H[3][30]);
    digitalWrite(7, H[4][30]);
    digitalWrite(8, H[5][30]);
    digitalWrite(9, H[6][30]);
    digitalWrite(10, H[7][30]);
    digitalWrite(11, H[8][30]);
    digitalWrite(12, H[9][30]);
    }
    
    else if (ttimer>57*sliver&&ttimer<58*sliver){
    digitalWrite(2, H[0][31]);
    digitalWrite(3, H[1][31]);
    digitalWrite(5, H[2][31]);
    digitalWrite(6, H[3][31]);
    digitalWrite(7, H[4][31]);
    digitalWrite(8, H[5][31]);
    digitalWrite(9, H[6][31]);
    digitalWrite(10, H[7][31]);
    digitalWrite(11, H[8][31]);
    digitalWrite(12, H[9][31]);
    }
    
       else if (ttimer>58*sliver&&ttimer<59*sliver){
    digitalWrite(2, H[0][32]);
    digitalWrite(3, H[1][32]);
    digitalWrite(5, H[2][32]);
    digitalWrite(6, H[3][32]);
    digitalWrite(7, H[4][32]);
    digitalWrite(8, H[5][32]);
    digitalWrite(9, H[6][32]);
    digitalWrite(10, H[7][32]);
    digitalWrite(11, H[8][32]);
    digitalWrite(12, H[9][32]);
    }
    
        else if (ttimer>59*sliver&&ttimer<60*sliver){
    digitalWrite(2, H[0][33]);
    digitalWrite(3, H[1][33]);
    digitalWrite(5, H[2][33]);
    digitalWrite(6, H[3][33]);
    digitalWrite(7, H[4][33]);
    digitalWrite(8, H[5][33]);
    digitalWrite(9, H[6][33]);
    digitalWrite(10, H[7][33]);
    digitalWrite(11, H[8][33]);
    digitalWrite(12, H[9][33]);
    }
    
      else if (ttimer>60*sliver&&ttimer<61*sliver){
    digitalWrite(2, H[0][34]);
    digitalWrite(3, H[1][34]);
    digitalWrite(5, H[2][34]);
    digitalWrite(6, H[3][34]);
    digitalWrite(7, H[4][34]);
    digitalWrite(8, H[5][34]);
    digitalWrite(9, H[6][34]);
    digitalWrite(10, H[7][34]);
    digitalWrite(11, H[8][34]);
    digitalWrite(12, H[9][34]);
    }
    
      else if (ttimer>61*sliver&&ttimer<62*sliver){
    digitalWrite(2, H[0][35]);
    digitalWrite(3, H[1][35]);
    digitalWrite(5, H[2][35]);
    digitalWrite(6, H[3][35]);
    digitalWrite(7, H[4][35]);
    digitalWrite(8, H[5][35]);
    digitalWrite(9, H[6][35]);
    digitalWrite(10, H[7][35]);
    digitalWrite(11, H[8][35]);
    digitalWrite(12, H[9][35]);
    }
    
    else if (ttimer>63*sliver&&ttimer<64*sliver){
    digitalWrite(2, H[0][36]);
    digitalWrite(3, H[1][36]);
    digitalWrite(5, H[2][36]);
    digitalWrite(6, H[3][36]);
    digitalWrite(7, H[4][36]);
    digitalWrite(8, H[5][36]);
    digitalWrite(9, H[6][36]);
    digitalWrite(10, H[7][36]);
    digitalWrite(11, H[8][36]);
    digitalWrite(12, H[9][36]);
    }
    
      else if (ttimer>64*sliver&&ttimer<65*sliver){
    digitalWrite(2, H[0][37]);
    digitalWrite(3, H[1][37]);
    digitalWrite(5, H[2][37]);
    digitalWrite(6, H[3][37]);
    digitalWrite(7, H[4][37]);
    digitalWrite(8, H[5][37]);
    digitalWrite(9, H[6][37]);
    digitalWrite(10, H[7][37]);
    digitalWrite(11, H[8][37]);
    digitalWrite(12, H[9][37]);
    }
    
     else if (ttimer>65*sliver&&ttimer<66*sliver){
    digitalWrite(2, H[0][38]);
    digitalWrite(3, H[1][38]);
    digitalWrite(5, H[2][38]);
    digitalWrite(6, H[3][38]);
    digitalWrite(7, H[4][38]);
    digitalWrite(8, H[5][38]);
    digitalWrite(9, H[6][38]);
    digitalWrite(10, H[7][38]);
    digitalWrite(11, H[8][38]);
    digitalWrite(12, H[9][38]);
    }
    
    else if (ttimer>66*sliver&&ttimer<67*sliver){
    digitalWrite(2, H[0][39]);
    digitalWrite(3, H[1][39]);
    digitalWrite(5, H[2][39]);
    digitalWrite(6, H[3][39]);
    digitalWrite(7, H[4][39]);
    digitalWrite(8, H[5][39]);
    digitalWrite(9, H[6][39]);
    digitalWrite(10, H[7][39]);
    digitalWrite(11, H[8][39]);
    digitalWrite(12, H[9][39]);
    }
    
    else if (ttimer>67*sliver&&ttimer<68*sliver){
    digitalWrite(2, H[0][40]);
    digitalWrite(3, H[1][40]);
    digitalWrite(5, H[2][40]);
    digitalWrite(6, H[3][40]);
    digitalWrite(7, H[4][40]);
    digitalWrite(8, H[5][40]);
    digitalWrite(9, H[6][40]);
    digitalWrite(10, H[7][40]);
    digitalWrite(11, H[8][40]);
    digitalWrite(12, H[9][40]);
    }
    
    else if (ttimer>69*sliver&&ttimer<70*sliver){
    digitalWrite(2, H[0][41]);
    digitalWrite(3, H[1][41]);
    digitalWrite(5, H[2][41]);
    digitalWrite(6, H[3][41]);
    digitalWrite(7, H[4][41]);
    digitalWrite(8, H[5][41]);
    digitalWrite(9, H[6][41]);
    digitalWrite(10, H[7][41]);
    digitalWrite(11, H[8][41]);
    digitalWrite(12, H[9][41]);
    }
    
       else if (ttimer>70*sliver&&ttimer<71*sliver){
    digitalWrite(2, H[0][42]);
    digitalWrite(3, H[1][42]);
    digitalWrite(5, H[2][42]);
    digitalWrite(6, H[3][42]);
    digitalWrite(7, H[4][42]);
    digitalWrite(8, H[5][42]);
    digitalWrite(9, H[6][42]);
    digitalWrite(10, H[7][42]);
    digitalWrite(11, H[8][42]);
    digitalWrite(12, H[9][42]);
    }
    
        else if (ttimer>71*sliver&&ttimer<72*sliver){
    digitalWrite(2, H[0][43]);
    digitalWrite(3, H[1][43]);
    digitalWrite(5, H[2][43]);
    digitalWrite(6, H[3][43]);
    digitalWrite(7, H[4][43]);
    digitalWrite(8, H[5][43]);
    digitalWrite(9, H[6][43]);
    digitalWrite(10, H[7][43]);
    digitalWrite(11, H[8][43]);
    digitalWrite(12, H[9][43]);
    }
    
      else if (ttimer>72*sliver&&ttimer<73*sliver){
    digitalWrite(2, H[0][44]);
    digitalWrite(3, H[1][44]);
    digitalWrite(5, H[2][44]);
    digitalWrite(6, H[3][44]);
    digitalWrite(7, H[4][44]);
    digitalWrite(8, H[5][44]);
    digitalWrite(9, H[6][44]);
    digitalWrite(10, H[7][44]);
    digitalWrite(11, H[8][44]);
    digitalWrite(12, H[9][44]);
    }
    
      else if (ttimer>73*sliver&&ttimer<74*sliver){
    digitalWrite(2, H[0][45]);
    digitalWrite(3, H[1][45]);
    digitalWrite(5, H[2][45]);
    digitalWrite(6, H[3][45]);
    digitalWrite(7, H[4][45]);
    digitalWrite(8, H[5][45]);
    digitalWrite(9, H[6][45]);
    digitalWrite(10, H[7][45]);
    digitalWrite(11, H[8][45]);
    digitalWrite(12, H[9][45]);
    }
    
    else if (ttimer>74*sliver&&ttimer<75*sliver){
    digitalWrite(2, H[0][46]);
    digitalWrite(3, H[1][46]);
    digitalWrite(5, H[2][46]);
    digitalWrite(6, H[3][46]);
    digitalWrite(7, H[4][46]);
    digitalWrite(8, H[5][46]);
    digitalWrite(9, H[6][46]);
    digitalWrite(10, H[7][46]);
    digitalWrite(11, H[8][46]);
    digitalWrite(12, H[9][46]);
    }
    
      else if (ttimer>75*sliver&&ttimer<76*sliver){
    digitalWrite(2, H[0][47]);
    digitalWrite(3, H[1][47]);
    digitalWrite(5, H[2][47]);
    digitalWrite(6, H[3][47]);
    digitalWrite(7, H[4][47]);
    digitalWrite(8, H[5][47]);
    digitalWrite(9, H[6][47]);
    digitalWrite(10, H[7][47]);
    digitalWrite(11, H[8][47]);
    digitalWrite(12, H[9][47]);
    }
    
     else if (ttimer>76*sliver&&ttimer<77*sliver){
    digitalWrite(2, H[0][48]);
    digitalWrite(3, H[1][48]);
    digitalWrite(5, H[2][48]);
    digitalWrite(6, H[3][48]);
    digitalWrite(7, H[4][48]);
    digitalWrite(8, H[5][48]);
    digitalWrite(9, H[6][48]);
    digitalWrite(10, H[7][48]);
    digitalWrite(11, H[8][48]);
    digitalWrite(12, H[9][48]);
    }
    
    else if (ttimer>77*sliver&&ttimer<78*sliver){
    digitalWrite(2, H[0][49]);
    digitalWrite(3, H[1][49]);
    digitalWrite(5, H[2][49]);
    digitalWrite(6, H[3][49]);
    digitalWrite(7, H[4][49]);
    digitalWrite(8, H[5][49]);
    digitalWrite(9, H[6][49]);
    digitalWrite(10, H[7][49]);
    digitalWrite(11, H[8][49]);
    digitalWrite(12, H[9][49]);
    }
    
    else if (ttimer>78*sliver&&ttimer<79*sliver){
    digitalWrite(2, H[0][50]);
    digitalWrite(3, H[1][50]);
    digitalWrite(5, H[2][50]);
    digitalWrite(6, H[3][50]);
    digitalWrite(7, H[4][50]);
    digitalWrite(8, H[5][50]);
    digitalWrite(9, H[6][50]);
    digitalWrite(10, H[7][50]);
    digitalWrite(11, H[8][50]);
    digitalWrite(12, H[9][50]);
    }
    
    else if (ttimer>79*sliver&&ttimer<80*sliver){
    digitalWrite(2, H[0][51]);
    digitalWrite(3, H[1][51]);
    digitalWrite(5, H[2][51]);
    digitalWrite(6, H[3][51]);
    digitalWrite(7, H[4][51]);
    digitalWrite(8, H[5][51]);
    digitalWrite(9, H[6][51]);
    digitalWrite(10, H[7][51]);
    digitalWrite(11, H[8][51]);
    digitalWrite(12, H[9][51]);
    }
    
       else if (ttimer>80*sliver&&ttimer<81*sliver){
    digitalWrite(2, H[0][52]);
    digitalWrite(3, H[1][52]);
    digitalWrite(5, H[2][52]);
    digitalWrite(6, H[3][52]);
    digitalWrite(7, H[4][52]);
    digitalWrite(8, H[5][52]);
    digitalWrite(9, H[6][52]);
    digitalWrite(10, H[7][52]);
    digitalWrite(11, H[8][52]);
    digitalWrite(12, H[9][52]);
    }
    
        else if (ttimer>81*sliver&&ttimer<82*sliver){
    digitalWrite(2, H[0][53]);
    digitalWrite(3, H[1][53]);
    digitalWrite(5, H[2][53]);
    digitalWrite(6, H[3][53]);
    digitalWrite(7, H[4][53]);
    digitalWrite(8, H[5][53]);
    digitalWrite(9, H[6][53]);
    digitalWrite(10, H[7][53]);
    digitalWrite(11, H[8][53]);
    digitalWrite(12, H[9][53]);
    }
    
      else if (ttimer>82*sliver&&ttimer<83*sliver){
    digitalWrite(2, H[0][54]);
    digitalWrite(3, H[1][54]);
    digitalWrite(5, H[2][54]);
    digitalWrite(6, H[3][54]);
    digitalWrite(7, H[4][54]);
    digitalWrite(8, H[5][54]);
    digitalWrite(9, H[6][54]);
    digitalWrite(10, H[7][54]);
    digitalWrite(11, H[8][54]);
    digitalWrite(12, H[9][54]);
    }
    
      else if (ttimer>83*sliver&&ttimer<84*sliver){
    digitalWrite(2, H[0][55]);
    digitalWrite(3, H[1][55]);
    digitalWrite(5, H[2][55]);
    digitalWrite(6, H[3][55]);
    digitalWrite(7, H[4][55]);
    digitalWrite(8, H[5][55]);
    digitalWrite(9, H[6][55]);
    digitalWrite(10, H[7][55]);
    digitalWrite(11, H[8][55]);
    digitalWrite(12, H[9][55]);
    }
    
    else if (ttimer>84*sliver&&ttimer<85*sliver){
    digitalWrite(2, H[0][56]);
    digitalWrite(3, H[1][56]);
    digitalWrite(5, H[2][56]);
    digitalWrite(6, H[3][56]);
    digitalWrite(7, H[4][56]);
    digitalWrite(8, H[5][56]);
    digitalWrite(9, H[6][56]);
    digitalWrite(10, H[7][56]);
    digitalWrite(11, H[8][56]);
    digitalWrite(12, H[9][56]);
    }
    
      else if (ttimer>85*sliver&&ttimer<86*sliver){
    digitalWrite(2, H[0][57]);
    digitalWrite(3, H[1][57]);
    digitalWrite(5, H[2][57]);
    digitalWrite(6, H[3][57]);
    digitalWrite(7, H[4][57]);
    digitalWrite(8, H[5][57]);
    digitalWrite(9, H[6][57]);
    digitalWrite(10, H[7][57]);
    digitalWrite(11, H[8][57]);
    digitalWrite(12, H[9][57]);
    }
    
     else if (ttimer>86*sliver&&ttimer<87*sliver){
    digitalWrite(2, H[0][58]);
    digitalWrite(3, H[1][58]);
    digitalWrite(5, H[2][58]);
    digitalWrite(6, H[3][58]);
    digitalWrite(7, H[4][58]);
    digitalWrite(8, H[5][58]);
    digitalWrite(9, H[6][58]);
    digitalWrite(10, H[7][58]);
    digitalWrite(11, H[8][58]);
    digitalWrite(12, H[9][58]);
    }
    
    else if (ttimer>87*sliver&&ttimer<88*sliver){
    digitalWrite(2, H[0][59]);
    digitalWrite(3, H[1][59]);
    digitalWrite(5, H[2][59]);
    digitalWrite(6, H[3][59]);
    digitalWrite(7, H[4][59]);
    digitalWrite(8, H[5][59]);
    digitalWrite(9, H[6][59]);
    digitalWrite(10, H[7][59]);
    digitalWrite(11, H[8][59]);
    digitalWrite(12, H[9][59]);
    }
    
    else if (ttimer>88*sliver&&ttimer<89*sliver){
    digitalWrite(2, H[0][60]);
    digitalWrite(3, H[1][60]);
    digitalWrite(5, H[2][60]);
    digitalWrite(6, H[3][60]);
    digitalWrite(7, H[4][60]);
    digitalWrite(8, H[5][60]);
    digitalWrite(9, H[6][60]);
    digitalWrite(10, H[7][60]);
    digitalWrite(11, H[8][60]);
    digitalWrite(12, H[9][60]);
    }
    
    else if (ttimer>89*sliver&&ttimer<90*sliver){
    digitalWrite(2, H[0][61]);
    digitalWrite(3, H[1][61]);
    digitalWrite(5, H[2][61]);
    digitalWrite(6, H[3][61]);
    digitalWrite(7, H[4][61]);
    digitalWrite(8, H[5][61]);
    digitalWrite(9, H[6][61]);
    digitalWrite(10, H[7][61]);
    digitalWrite(11, H[8][61]);
    digitalWrite(12, H[9][61]);
    }
    
       else if (ttimer>90*sliver&&ttimer<91*sliver){
    digitalWrite(2, H[0][62]);
    digitalWrite(3, H[1][62]);
    digitalWrite(5, H[2][62]);
    digitalWrite(6, H[3][62]);
    digitalWrite(7, H[4][62]);
    digitalWrite(8, H[5][62]);
    digitalWrite(9, H[6][62]);
    digitalWrite(10, H[7][62]);
    digitalWrite(11, H[8][62]);
    digitalWrite(12, H[9][62]);
    }
    
        else if (ttimer>91*sliver&&ttimer<92*sliver){
    digitalWrite(2, H[0][63]);
    digitalWrite(3, H[1][63]);
    digitalWrite(5, H[2][63]);
    digitalWrite(6, H[3][63]);
    digitalWrite(7, H[4][63]);
    digitalWrite(8, H[5][63]);
    digitalWrite(9, H[6][63]);
    digitalWrite(10, H[7][63]);
    digitalWrite(11, H[8][63]);
    digitalWrite(12, H[9][63]);
    }
    
      else if (ttimer>92*sliver&&ttimer<93*sliver){
    digitalWrite(2, H[0][64]);
    digitalWrite(3, H[1][64]);
    digitalWrite(5, H[2][64]);
    digitalWrite(6, H[3][64]);
    digitalWrite(7, H[4][64]);
    digitalWrite(8, H[5][64]);
    digitalWrite(9, H[6][64]);
    digitalWrite(10, H[7][64]);
    digitalWrite(11, H[8][64]);
    digitalWrite(12, H[9][64]);
    }
    
      else if (ttimer>93*sliver&&ttimer<94*sliver){
    digitalWrite(2, H[0][65]);
    digitalWrite(3, H[1][65]);
    digitalWrite(5, H[2][65]);
    digitalWrite(6, H[3][65]);
    digitalWrite(7, H[4][65]);
    digitalWrite(8, H[5][65]);
    digitalWrite(9, H[6][65]);
    digitalWrite(10, H[7][65]);
    digitalWrite(11, H[8][65]);
    digitalWrite(12, H[9][65]);
    }
    
    else if (ttimer>94*sliver&&ttimer<95*sliver){
    digitalWrite(2, H[0][66]);
    digitalWrite(3, H[1][66]);
    digitalWrite(5, H[2][66]);
    digitalWrite(6, H[3][66]);
    digitalWrite(7, H[4][66]);
    digitalWrite(8, H[5][66]);
    digitalWrite(9, H[6][66]);
    digitalWrite(10, H[7][66]);
    digitalWrite(11, H[8][66]);
    digitalWrite(12, H[9][66]);
    }
    
      else if (ttimer>95*sliver&&ttimer<96*sliver){
    digitalWrite(2, H[0][67]);
    digitalWrite(3, H[1][67]);
    digitalWrite(5, H[2][67]);
    digitalWrite(6, H[3][67]);
    digitalWrite(7, H[4][67]);
    digitalWrite(8, H[5][67]);
    digitalWrite(9, H[6][67]);
    digitalWrite(10, H[7][67]);
    digitalWrite(11, H[8][67]);
    digitalWrite(12, H[9][67]);
    }
    
     else if (ttimer>96*sliver&&ttimer<97*sliver){
    digitalWrite(2, H[0][68]);
    digitalWrite(3, H[1][68]);
    digitalWrite(5, H[2][68]);
    digitalWrite(6, H[3][68]);
    digitalWrite(7, H[4][68]);
    digitalWrite(8, H[5][68]);
    digitalWrite(9, H[6][68]);
    digitalWrite(10, H[7][68]);
    digitalWrite(11, H[8][68]);
    digitalWrite(12, H[9][68]);
    }
    
    else if (ttimer>97*sliver&&ttimer<98*sliver){
    digitalWrite(2, H[0][69]);
    digitalWrite(3, H[1][69]);
    digitalWrite(5, H[2][69]);
    digitalWrite(6, H[3][69]);
    digitalWrite(7, H[4][69]);
    digitalWrite(8, H[5][69]);
    digitalWrite(9, H[6][69]);
    digitalWrite(10, H[7][69]);
    digitalWrite(11, H[8][69]);
    digitalWrite(12, H[9][69]);
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
