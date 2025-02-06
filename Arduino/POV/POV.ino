#define TILT_SENSOR 33 // 傾きセンサーのピン

const int ledPins[8] = {31, 11, 10, 17, 16, 15, 14, 32};  // LEDのピン

uint8_t ptn[8][8] = 
  { // heart
    {0, 1, 1, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0}
  };

void showPattern();
void clearLEDs();

void setup() {
  // LEDピンの設定
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(TILT_SENSOR, INPUT_PULLUP); // 傾きセンサーの設定
}

void loop() {
  // 傾きセンサーの状態をチェック
  if (digitalRead(TILT_SENSOR) == LOW) {
      delay(10); // 振り始めは少し待つ
      showPattern();
    } 
  else {
    // 傾きがない場合はLEDをクリア
    clearLEDs();
  }
}

// パターンを表示
void showPattern() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      digitalWrite(ledPins[col], ptn[col][row]);
    }
    delay(1);
    clearLEDs();
    delay(4); // 点灯時間と消灯時間の比率で明るさを調整する
  }
}

// LEDをクリア
void clearLEDs() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}