const int TIMER_LED_PINS[] = {
  4,  5,  6,
  7,  8,  10,
  11, 12, 13,
};
const int YELLOW_PIN = 3;
const int BTN_PIN = 2;

const int TIMER = 9;
const int LEDS_AMOUNT = 9;
const int TIMER_PORTION = TIMER / LEDS_AMOUNT;

int seconds = TIMER;

const setLowAndBlinkSpecificLed(int currentLed) {
  if (currentLed < LEDS_AMOUNT) {
    digitalWrite(TIMER_LED_PINS[currentLed], LOW);
  }
  digitalWrite(TIMER_LED_PINS[currentLed - 1], LOW);
  delay(500);
  digitalWrite(TIMER_LED_PINS[currentLed - 1], HIGH);
  delay(500);
}


// variables will change:
int ledState = LOW;   // the current state of LED

bool isTimerReseted = true;

int lastState = HIGH; // the previous state from the input pin
int currentState;    // the current reading from the input pin

const startAndEndTimer() {
  Serial.println("TIMER:[START]");
  if (seconds > 0) {
    for (int i = 0; i < LEDS_AMOUNT; i++) {
      const int LED_INDEX = TIMER - i - 1;
      seconds--;
      Serial.print("Remaining time: ");
      Serial.println(seconds);
      digitalWrite(TIMER_LED_PINS[LED_INDEX], LOW);
      if (seconds == 0) {
        Serial.println("TIMER:[END]");
        digitalWrite(YELLOW_PIN, HIGH);
      }
      delay(1000);
    }
  }
}

const resetTimer() {
  seconds = TIMER;
  digitalWrite(YELLOW_PIN, LOW);
  for (int i = 0; i < LEDS_AMOUNT; i++) {
    digitalWrite(TIMER_LED_PINS[i], HIGH);
  }
  Serial.println("TIMER:[RESET]");
}

void setup() {
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(YELLOW_PIN, OUTPUT);
  digitalWrite(YELLOW_PIN, LOW);
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
