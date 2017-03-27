#include <Keypad.h> //installtation

#define PIN_g A2
#define PIN_f A3
#define PIN_a 10
#define PIN_b 11
#define PIN_e A0
#define PIN_d A4
#define PIN_c 12
const byte seg_pins[7]={PIN_a, PIN_b, PIN_c, PIN_d, PIN_e, PIN_f, PIN_g};
const boolean data[16][7] = {
  {1, 1, 1, 1, 1, 1, 0},   
  {0, 1, 1, 0, 0, 0, 0}, 
  {1, 1, 0, 1, 1, 0, 1}, 
  {1, 1, 1, 1, 0, 0, 1}, 
  {0, 1, 1, 0, 0, 1, 1}, 
  {1, 0, 1, 1, 0, 1, 1}, 
  {1, 0, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 0, 1, 1}, 
  {1, 1, 1, 0, 1, 1, 1},
  {0, 0, 1, 1, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 1, 1},
};
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7','4','1','0'},
  {'8','5','2','A'},
  {'9','6','3','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
Serial.begin(9600);
for(int i=1;i<=12;i++)
{
   pinMode(i,OUTPUT);
}
 pinMode(A0,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(A3,OUTPUT);
 pinMode(A4,OUTPUT);
}

void loop(){
  char key = keypad.getKey();
  int key_num = chang_key(key);
  if (key != NO_KEY){
    for(int i = 0;i < 7;i++) 
    {
    digitalWrite(seg_pins[i], data[key_num][i]);     
    }
  Serial.println(key);
  }
}

int chang_key(char key)
{
  int key_num;
  if(key =='0')
  key_num = 0;
  if(key =='1')
  key_num = 1;
  if(key =='2')
  key_num = 2;
  if(key =='3')
  key_num = 3;
  if(key =='4')
  key_num = 4;
  if(key =='5')
  key_num = 5;
  if(key =='6')
  key_num = 6;
  if(key =='7')
  key_num = 7;
  if(key =='8')
  key_num = 8;
  if(key =='9')
  key_num = 9;
  if(key =='A')
  key_num = 10;
  if(key =='B')
  key_num = 11;
  if(key =='C')
  key_num = 12;
  if(key =='D')
  key_num = 13;
  if(key =='E')
  key_num = 14;
  if(key =='F')
  key_num = 15;
  return key_num; 
}
