const int TIMER = 18;
const int LED_PINS[] = { 
  2, 3, 5, 
  6, 7, 8, 
  9, 11, 12 
};
const int LEDS_AMOUNT = 9;
const int TIMER_PORTION = TIMER / LEDS_AMOUNT;

int seconds = TIMER;

const setLowAndBlinkSpecificLed(int currentLed) {
  if (currentLed < LEDS_AMOUNT) {
    digitalWrite(LED_PINS[currentLed], LOW);
  } if (currentLed > 0) {
    digitalWrite(LED_PINS[currentLed - 1], LOW);
  delay(500);
  digitalWrite(LED_PINS[currentLed - 1], HIGH);
  delay(500);
   }
  
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LEDS_AMOUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(1000);
}

void loop() {
  if (seconds >= 0) {
    Serial.println(seconds);
    seconds--;
    if (seconds == TIMER) {
      setLowAndBlinkSpecificLed(LEDS_AMOUNT);
    } 
    if (seconds == 0) {
      setLowAndBlinkSpecificLed(0);
    }

    for (int i = 0; i < 9; i++) {
      int index = 9 - i;
      if (
        seconds <  (TIMER_PORTION) * index && 
        seconds >= (TIMER_PORTION) * index - 1
      ) {
       for (int j = 0; j < TIMER_PORTION; j++) {
        setLowAndBlinkSpecificLed(index);
       }
      } 
    }
    
  }
}
