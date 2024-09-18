// Define LED pins
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 2 green LEDs at index 0 and 7, red in between
int buttonPin = 10; // Pin for the button

int currentLED = 0; // Tracks the current LED in the sequence
int direction = 1; // 1 for forward, -1 for reverse
bool gameOver = false;

// Variable to control the speed of the LED sequence
int speed = 300; // Starting speed 300ms delay
int speedDecrease = 20; // reduce delay for increase speed effect 
int minSpeed = 5; // Minimum speed

void setup() {
  // Initialize LED pins
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP); // Button pin setup
  Serial.begin(9600);
}

void loop() {
  if (gameOver) {
    // Reset the game after a short delay
    delay(2000);
    gameOver = false;
    currentLED = 0;
    direction = 1;
    speed = 300; // Reset speed when game resets (optional)
  } else {
    // Light up the current LED
    lightUpLED(currentLED);
    
    // Check for button press
    if (digitalRead(buttonPin) == LOW) {
      checkButtonPress();
    }

    // Move to the next LED in sequence
    delay(speed); // Use the variable `speed` for delay
    currentLED += direction;

    // If the sequence hits either end, reverse the direction
    if (currentLED == 7 || currentLED == 0) {
      direction *= -1; // Reverse direction
    }
  }
}

// Function to light up only the current LED and turn off others
void lightUpLED(int ledIndex) {
  for (int i = 0; i < 8; i++) {
    if (i == ledIndex) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}

// Function to check if the button press was valid
void checkButtonPress() {
  if (currentLED == 4 || currentLED == 3) { // If the green LED is lit
    // User wins
    Serial.println("You win!"); //debug

    blinkLED(leds[currentLED], 3); // Blink the green LED 3 times
    increaseSpeed(); // Speed up the game after winning

  } else {
    // User loses
    Serial.println("You lose!"); //debug

    blinkLED(leds[currentLED], 5); // Blink the red LED 5 times
  gameOver = true; // Set the game over flag

  }
}

// Function to blink an LED
void blinkLED(int ledPin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200); // Control the blink speed
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}

// Function to increase the speed after a win
void increaseSpeed() {
  if (speed > minSpeed) {
    speed -= speedDecrease; // Decrease the delay, making the game faster
    if (speed < minSpeed) {
      speed = minSpeed; // Cap the speed at a minimum value
    }
  }
}
