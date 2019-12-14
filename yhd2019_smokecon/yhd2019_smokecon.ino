

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

#define SEQ_TYPE_DELAY 0
#define SEQ_TYPE_PLAY_PTN 1
//#define SEQ_TYPE_LOOP_START 2

int pin[6] = {2,3,4,6,7,8};
// 5, 9は未使用

int seq[][3] = { // kind, param1, speed
  { SEQ_TYPE_DELAY,      1000, 0 },
  { SEQ_TYPE_PLAY_PTN,   0,    2 },
  { SEQ_TYPE_PLAY_PTN,   1,    2 },
  { SEQ_TYPE_DELAY,      500,  0 },
  { SEQ_TYPE_PLAY_PTN,   2,    1.5 },
  { SEQ_TYPE_PLAY_PTN,   1,    1.5 },
  { SEQ_TYPE_PLAY_PTN,   2,    1.5 },
  { SEQ_TYPE_PLAY_PTN,   3,    1.5 },
  { SEQ_TYPE_PLAY_PTN,   2,    1.5 },
//  { SEQ_TYPE_LOOP_START, 0,    0 }, // 30sec
  { SEQ_TYPE_PLAY_PTN,   3,    1 },
  { SEQ_TYPE_PLAY_PTN,   4,    1 },
  { SEQ_TYPE_PLAY_PTN,   5,    1 },
  { SEQ_TYPE_PLAY_PTN,   3,    1 },
  { SEQ_TYPE_PLAY_PTN,   5,    1 }, // 45sec (+15sec)
  { SEQ_TYPE_DELAY,      1000, 0 },
  { SEQ_TYPE_PLAY_PTN,   6,    2 }, 
  { SEQ_TYPE_PLAY_PTN,   7,    2 }, 
  { SEQ_TYPE_PLAY_PTN,   6,    1 }, 
  { SEQ_TYPE_PLAY_PTN,   7,    1 }, 
  { SEQ_TYPE_PLAY_PTN,   8,    1 }, 
  { SEQ_TYPE_PLAY_PTN,   9,    1 }, // 70sec (+12sec, +12sec)
  { SEQ_TYPE_PLAY_PTN,   10,   1 }, 
  { SEQ_TYPE_PLAY_PTN,   11,   2 },
  { SEQ_TYPE_DELAY,      500,  0 }, 
  { SEQ_TYPE_PLAY_PTN,   12,   2 }, // 82sec
};
 
int pattern[][6][6] = {
  /* 0: Rrandom-sigle-1 */{
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0},
    {0,1,0,0,0,0},
    {0,0,0,1,0,0},
    {0,0,1,0,0,0}
  },
  /* 1: Rrandom-sigle-wide-1 */{
    {0,0,1,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,1,0,0},
    {1,0,0,0,0,0},
    {0,0,0,0,1,0},
    {0,0,0,1,0,0}
  },
  /* 2: Rrandom-sigle-wide-2 */{
    {0,1,0,0,0,0},
    {0,0,0,0,1,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
    {1,0,0,0,0,0},
    {0,0,0,1,0,0}
  },
  /* 3: Rrandom-multi-wide-1 */{
    {0,0,1,0,0,1},
    {0,1,1,0,0,0},
    {1,0,0,1,0,0},
    {0,0,1,0,0,1},
    {0,1,0,0,1,0},
    {1,0,0,1,0,0}
  },
  /* 4: Rrandom-multi-wide-2 */{
    {0,0,1,0,0,1},
    {0,1,0,1,0,0},
    {0,1,0,0,0,1},
    {0,0,1,0,0,1},
    {0,1,1,0,0,0},
    {0,0,0,1,1,0}
  },
  /* 5: Rrandom-multi-wide-3 */{
    {0,1,1,0,0,0},
    {1,0,0,1,1,0},
    {0,0,1,0,0,1},
    {0,1,1,1,0,0},
    {1,0,0,0,1,1},
    {0,1,0,1,0,1}
  },
  /* 6: Step-LR-single */{
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,0,1}
  },
  /* 7: Step-RL-single */{
    {0,0,0,0,0,1},
    {0,0,0,0,1,0},
    {0,0,0,1,0,0},
    {0,0,1,0,0,0},
    {0,1,0,0,0,0},
    {1,0,0,0,0,0}
  },
  /* 8: Step-LR-multi */{
    {1,0,1,0,0,0},
    {0,1,0,1,0,0},
    {0,0,1,0,1,0},
    {0,0,0,1,0,1},
    {1,0,0,0,1,0},
    {0,1,0,0,0,1}
  },
  /* 9: Step-RL-multi */{
    {0,0,0,1,0,1},
    {0,0,1,0,1,0},
    {0,1,0,1,0,0},
    {1,0,1,0,0,0},
    {0,1,0,0,0,1},
    {1,0,0,0,1,0}
  },
  /* 10: Arrow-BT */{
    {0,0,1,1,0,0},
    {0,1,0,0,1,0},
    {1,0,0,0,0,1},
    {0,0,1,1,0,0},
    {0,1,0,0,1,0},
    {1,0,0,0,0,1}
  },
  /* 11: Expand1 */{
    {0,0,1,1,0,0},
    {0,0,1,1,0,0},
    {0,1,0,0,1,0},
    {0,1,0,0,1,0},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
  },
  /* 12: Expand2 */{
    {0,0,1,1,0,0},
    {0,0,1,1,0,0},
    {0,1,1,1,1,0},
    {0,1,1,1,1,0},
    {1,1,1,1,1,1},
    {1,1,1,1,1,1},
  }
 };


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
  }
}

void playPattern(int patternId, float weight) {
  for(int x=0; x<6; x++) {
    for(int y=0; y<6; y++) {
      digitalWrite(pin[y], pattern[patternId][x][y]);
    }
    delay(OPEN_LINE_SPAN * weight);
    
    initLine();
    delay(DELAY_LINE_SPAN * weight);
  }
  delay(DELAY_CHAR_SPAN * weight);
}

int seqKind;
int seqParm1;
float seqWeight;

void loop() {
  for(int i=0; i<sizeof(seq); i++) { //全部
    seqKind = seq[i][0];
    seqParm1 = seq[i][1];
    seqWeight = seq[i][2];
    switch(seqKind) {
      case SEQ_TYPE_DELAY:
        delay(seqParm1);
        break;
      case SEQ_TYPE_PLAY_PTN:
        playPattern(seqParm1, seqWeight);
        break;
    }
    delay(500);
  }
  delay(5000);
}
