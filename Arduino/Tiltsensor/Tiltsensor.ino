#define LED 31 // LEDのピン
#define TILT_SENSOR 33 // 傾きセンサーのピン

void setup() {
  pinMode(LED, OUTPUT); // LEDピンの設定
  pinMode(TILT_SENSOR, INPUT_PULLUP); // 傾きセンサーの設定
}

void loop() {
  // 傾きセンサーの状態をチェック
  if (digitalRead(TILT_SENSOR) == LOW) {
    // 傾きセンサーがONのとき
    digitalWrite(LED, HIGH);
  } else {
    // 傾きセンサーがOFFのとき
    digitalWrite(LED, LOW);
  }
}
