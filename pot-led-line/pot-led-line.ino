const int LED_PINS[] = { 
  2, 3, 5, 
  6, 7, 8, 
  9, 11, 12 
};
const int POT_PIN = A0;

void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
}

void loop() {
  int val = analogRead(POT_PIN); 
  if (val == 0) {
    digitalWrite(LED_PINS[0], LOW);
    digitalWrite(LED_PINS[1], LOW);
    digitalWrite(LED_PINS[2], LOW);
    digitalWrite(LED_PINS[3], LOW);
    digitalWrite(LED_PINS[4], LOW);
    digitalWrite(LED_PINS[5], LOW);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 0 && val < 113) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], LOW);
    digitalWrite(LED_PINS[2], LOW);
    digitalWrite(LED_PINS[3], LOW);
    digitalWrite(LED_PINS[4], LOW);
    digitalWrite(LED_PINS[5], LOW);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 113 && val < 227) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], LOW);
    digitalWrite(LED_PINS[3], LOW);
    digitalWrite(LED_PINS[4], LOW);
    digitalWrite(LED_PINS[5], LOW);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 227 && val < 340) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], LOW);
    digitalWrite(LED_PINS[4], LOW);
    digitalWrite(LED_PINS[5], LOW);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 340 && val < 453) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], LOW);
    digitalWrite(LED_PINS[5], LOW);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 453 && val < 566) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], HIGH);
    digitalWrite(LED_PINS[5], LOW);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 566 && val < 679) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], HIGH);
    digitalWrite(LED_PINS[5], HIGH);
    digitalWrite(LED_PINS[6], LOW);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 679 && val < 792) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], HIGH);
    digitalWrite(LED_PINS[5], HIGH);
    digitalWrite(LED_PINS[6], HIGH);
    digitalWrite(LED_PINS[7], LOW);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 792 && val < 925) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], HIGH);
    digitalWrite(LED_PINS[5], HIGH);
    digitalWrite(LED_PINS[6], HIGH);
    digitalWrite(LED_PINS[7], HIGH);
    digitalWrite(LED_PINS[8], LOW);
    digitalWrite(LED_PINS[9], LOW);
  } else if (val >= 925  && val < 1022) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], HIGH);
    digitalWrite(LED_PINS[5], HIGH);
    digitalWrite(LED_PINS[6], HIGH);
    digitalWrite(LED_PINS[7], HIGH);
    digitalWrite(LED_PINS[8], HIGH);
    digitalWrite(LED_PINS[9], LOW);
  } else {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    digitalWrite(LED_PINS[4], HIGH);
    digitalWrite(LED_PINS[5], HIGH);
    digitalWrite(LED_PINS[6], HIGH);
    digitalWrite(LED_PINS[7], HIGH);
    digitalWrite(LED_PINS[8], HIGH);
    digitalWrite(LED_PINS[9], HIGH);
  } 
}
