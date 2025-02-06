#define LED 30 // LEDのピン

void setup() {
  pinMode(LED, OUTPUT); // LEDピンの設定
}

void loop() {
  digitalWrite(LED, HIGH); // LEDをON
  delay(1000); // 1秒待つ
  digitalWrite(LED, LOW); // LEDをOFF
  delay(1000); // 1秒待つ
}
