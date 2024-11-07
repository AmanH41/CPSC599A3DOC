#include <Servo.h>

// Define servos for arms and legs
Servo rightUpper;
Servo rightLower;
Servo leftUpper;
Servo leftLower;
Servo rightLeg;
Servo leftLeg;

// Initial positions for all servos
int rightUpperAngle = 0;
int rightLowerAngle = 0;
int leftUpperAngle = 90;
int leftLowerAngle = 180;
int rightLegAngle = 0;
int leftLegAngle = 90;

// Track win/loss and consecutive counts
int winCount = 0;
int lossCount = 0;
int totalGames = 0;
bool superBlockActive = false;
unsigned long superBlockTimer = 0;

// Track last action and arm used
String lastAction = "";
String lastArmUsed = "";

void setup() {
  Serial.begin(9600);

  // Attach each servo to its respective pin
  rightUpper.attach(A0);
  rightLower.attach(A1);
  leftUpper.attach(A2);
  leftLower.attach(A3);
  rightLeg.attach(A4);
  leftLeg.attach(A5);

  // Move to initial positions
  resetServosToIdle();

  Serial.println("Enter 'win' or 'loss' to simulate a game result.");
}

// Function to reset all servos to idle position
void resetServosToIdle() {
  rightUpper.write(0);
  rightLower.write(0);
  leftUpper.write(90);
  leftLower.write(180);
  rightLeg.write(0);
  leftLeg.write(90);

  Serial.println("All servos reset to idle position.");
}

// Action functions
void powerUp() {
  rightUpper.write(20);
  rightLower.write(30);
  leftUpper.write(70);
  leftLower.write(150);
  rightLeg.write(0);
  leftLeg.write(90);

  Serial.println("Powering UP!");
  lastAction = "power up";
}

void block() {
  rightUpper.write(0);
  rightLower.write(120);
  leftUpper.write(90);
  leftLower.write(60);
  rightLeg.write(rightLegAngle);
  leftLeg.write(leftLegAngle);

  Serial.println("Character is blocking");
  lastAction = "block";
}

void superBlock() {
  rightUpper.write(10);
  rightLower.write(150);
  leftUpper.write(80);
  leftLower.write(40);
  rightLeg.write(110);
  leftLeg.write(10);

  Serial.println("Character is super blocking");
  superBlockActive = true;
  superBlockTimer = millis(); // Start the 5-minute timer
  lastAction = "super block";
}

void leftPunch() {
  leftUpper.write(0);
  leftLower.write(180);

  Serial.println("Left punch");
  lastAction = "left punch";
  lastArmUsed = "left";
}

void rightPunch() {
  rightUpper.write(90);
  rightLower.write(0);

  Serial.println("Right punch");
  lastAction = "right punch";
  lastArmUsed = "right";
}

// Helper functions to reset individual limbs
void resetLeftArm() {
  leftUpper.write(90);
  leftLower.write(180);

  Serial.println("Reset left arm");
}

void resetRightArm() {
  rightUpper.write(0);
  rightLower.write(0);

  Serial.println("Reset right arm");
}

// Main function to process win/loss input
void processInput(String input) {
  Serial.println("Processing input: " + input);  // Debug
  Serial.print("Current Counts -> Wins: ");
  Serial.print(winCount);
  Serial.print(", Losses: ");
  Serial.print(lossCount);
  Serial.print(", Total Games: ");
  Serial.println(totalGames);

  if (input == "win") {
    winCount++;
    lossCount = 0; // Reset loss streak
    totalGames++;

    Serial.println("Result: Win");
    Serial.print("Updated Counts -> Wins: ");
    Serial.print(winCount);
    Serial.print(", Losses: ");
    Serial.print(lossCount);
    Serial.print(", Total Games: ");
    Serial.println(totalGames);

    // Randomly select left or right punch
    if (random(0, 2) == 0) {
      leftPunch();
      if (lastAction != "block" && lastArmUsed != "left") {
        resetLeftArm(); // Reset after punch if not a block
      }
    } else {
      rightPunch();
      if (lastAction != "block" && lastArmUsed != "right") {
        resetRightArm(); // Reset after punch if not a block
      }
    }

    // Trigger power-up if 3 consecutive wins
    if (winCount >= 3) {
      powerUp();
      winCount = 0; // Reset win streak after power-up
      Serial.println("Triggered Power-Up after 3 wins.");
    }

  } else if (input == "loss") {
    lossCount++;
    winCount = 0; // Reset win streak
    totalGames++;

    Serial.println("Result: Loss");
    float winRate = (totalGames > 0) ? (float(winCount) / totalGames) * 100 : 100;
    Serial.print("Current Win Rate: ");
    Serial.print(winRate);
    Serial.println("%");

    // Determine if block or superBlock is applied
    if (lossCount >= 5) {
      Serial.println("Condition met for Super Block.");
      superBlock();
    } else {
      Serial.println("Condition met for regular Block.");
      block();  // Use block by default for most losses
    }
  }
}


void loop() {
  // Check for serial input
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any whitespace/newline characters

    // Process win or loss input
    if (input == "win" || input == "loss") {
      processInput(input);
    } else {
      Serial.println("Invalid input. Please enter 'win' or 'loss'.");
    }
  }

  // Check if superBlock timer is active and 5 minutes have passed
  if (superBlockActive && (millis() - superBlockTimer >= 300000)) { // 300,000 ms = 5 minutes
    resetServosToIdle();
    superBlockActive = false;
  }
}
