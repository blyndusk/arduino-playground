const int TIMER_LED_PINS[] = {
  4,  5,  6,
  7,  8,  10,
  11, 12, 13,
};
const int YELLOW_PIN = 3;
const int BTN_PIN = 2;

const int TIMER = 27;
const int LEDS_AMOUNT = 9;
const int TIMER_PORTION = TIMER / LEDS_AMOUNT;

int seconds = TIMER;

int lastState = HIGH;
int currentState;
int ledState = LOW;
bool isTimerReseted = true;

const setLowAndBlinkSpecificLed(int currentLed) {
  if (currentLed  < LEDS_AMOUNT) {
    digitalWrite(TIMER_LED_PINS[currentLed + 1], LOW);
  }
  digitalWrite(TIMER_LED_PINS[currentLed], LOW);
  delay(500);
  digitalWrite(TIMER_LED_PINS[currentLed], HIGH);
  delay(500);
  Serial.print("Remaining time: ");
  Serial.println(seconds);

}

const switchOffLed(int currentLed) {
  if (
    seconds <  TIMER_PORTION * currentLed + 1 &&
    seconds >= TIMER_PORTION * currentLed
  ) {;
    for (int j = 0; j < TIMER_PORTION; j++) {
      setLowAndBlinkSpecificLed(currentLed);
    }
  }
}

const startAndEndTimer() {
  Serial.println("TIMER:[START]");
  digitalWrite(YELLOW_PIN, LOW);
  if (seconds > 0) {
    for (int i = 0; i < TIMER; i++) {
      seconds--;
      for (int i = 0; i < TIMER; i++) {
        const int LED_INDEX = TIMER - i - 1;
        switchOffLed(TIMER - i - 1);
      }
      if (seconds == 0) {
        setLowAndBlinkSpecificLed(0);
        digitalWrite(TIMER_LED_PINS[0], LOW);
        digitalWrite(YELLOW_PIN, HIGH);
        Serial.println("TIMER:[END]");
      }
    }
  }
}

const resetTimer() {
  seconds = TIMER;
  digitalWrite(YELLOW_PIN, HIGH);
  for (int i = 0; i < TIMER; i++) {
    digitalWrite(TIMER_LED_PINS[i], HIGH);
  }
  Serial.println("TIMER:[RESET]");
}

void setup() {
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(YELLOW_PIN, OUTPUT);
  digitalWrite(YELLOW_PIN, HIGH);
  for (int i = 0; i < LEDS_AMOUNT; i++) {
    pinMode(TIMER_LED_PINS[i], OUTPUT);
    digitalWrite(TIMER_LED_PINS[i], HIGH);
  }
  Serial.println("\n\n\n----------------\nSCRIPT:[START]");
}

void loop() {
  currentState = digitalRead(BTN_PIN);
  if (
    lastState == HIGH &&
    currentState == LOW
  ) {
    isTimerReseted = !isTimerReseted;
    if (isTimerReseted == false) {
      startAndEndTimer();
    } else {
      resetTimer();
    }
  }
  lastState = currentState;
}
