

#define PIN_SOL1 2
#define PIN_SOL2 2
#define PIN_SOL3 2
#define PIN_SOL1 2
#define PIN_SOL1 2

#define OPEN_LINE_SPAN 500
#define DELAY_LINE_SPAN 500
#define DELAY_CHAR_SPAN 1500
//#define OPEN_LINE_SPAN 100
//#define DELAY_LINE_SPAN 1500
//#define DELAY_CHAR_SPAN 3000

int pin[6] = {2,3,4,6,7,8};
// 5, 9は未使用
 
int seq[4][6][6] = {
  /* A */{
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,0,1}
  },
  /* E */{
    {0,0,0,0,0,1},
    {0,0,0,0,1,0},
    {0,0,0,1,0,0},
    {0,0,1,0,0,0},
    {0,1,0,0,0,0},
    {1,0,0,0,0,0}
  },
  /* H */{
    {0,0,1,1,0,0},
    {0,1,0,0,1,0},
    {1,0,0,0,0,1},
    {0,0,1,1,0,0},
    {0,1,0,0,1,0},
    {1,0,0,0,0,1}
  }
 };

//   /* A */{
//    {0,0,1,1,0,0},
//    {0,1,0,0,1,0},
//    {1,0,0,0,0,1},
//    {1,1,1,1,1,1},
//    {1,0,0,0,0,1},
//    {1,0,0,0,0,1}
//  },
//  /* E */{
//    {1,1,1,1,1,1},
//    {1,0,0,0,0,0},
//    {1,1,1,1,1,1},
//    {1,0,0,0,0,0},
//    {1,0,0,0,0,0},
//    {1,1,1,1,1,1}
//  },
//  /* H */{
//    {1,0,0,0,0,1},
//    {1,0,0,0,0,1},
//    {1,1,1,1,1,1},
//    {1,0,0,0,0,1},
//    {1,0,0,0,0,1},
//    {1,0,0,0,0,1}
//  },
//  /* Z */{
//    {1,1,1,1,1,1},
//    {1,0,0,0,1,0},
//    {0,0,0,1,0,0},
//    {0,0,1,0,0,0},
//    {0,1,0,0,0,1},
//    {1,1,1,1,1,1}
//  }
// };


void setup() {
  Serial.begin(9600);
  
  // setup pins
  for(int i=0; i<6; i++) {
    pinMode(pin[i], OUTPUT);
  }

  delay(100);
  
  // initial behavior
  for(int i=0; i<6; i++) {
    digitalWrite(pin[i], 1);
    delay(500);
    digitalWrite(pin[i], 0);
    delay(500);
  }

  Serial.println("initialize ok");
}

void initLine() {
  for(int y=0; y<6; y++) {
    digitalWrite(pin[y], 0);
//    delay(50);
  }
}
void playChar(int charId) {
  for(int x=0; x<6; x++) {
    for(int y=0; y<6; y++) {
      digitalWrite(pin[y], seq[charId][x][y]);
//      delay(50);
    }
    delay(OPEN_LINE_SPAN);
    
    initLine();
    delay(DELAY_LINE_SPAN);
  }
//  initLine();
  delay(DELAY_CHAR_SPAN);
}

void loop() {
  for(int i=0; i<4; i++) { //全部
    playChar(i);
  }
  delay(1000);
}
