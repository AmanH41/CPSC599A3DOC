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
int winStreak = 0;
float winRate;


// Track last action and arm used
String lastAction = "";
String lastArmUsed = "";
//----------------------------------------------------------------------------------
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

  //Serial.println("Enter 'win' or 'loss' to simulate a game result.");
}
//----------------------------------------------------------------------------------
void playSound(const char* soundName) {
  Serial.println(soundName); // Send the sound name to the computer
}

void blockSound() {
  // Your servo movement code...
  playSound("block");
}

void punchSound() {
  // Your servo movement code...
  playSound("punch");
}

void powerUpSound(){
  playSound("powerUp");
}

void superBlockSound(){
  playSound("superBlock");
}

void combinationSound(){
  playSound("combination");
}
//----------------------------------------------------------------------------------
// Function to reset all servos to idle position
void resetServosToIdle() {
  rightUpper.write(0);
  rightLower.write(0);
  leftUpper.write(90);
  leftLower.write(180);
  rightLeg.write(0);
  leftLeg.write(100);

  //Serial.println("All servos reset to idle position.");
}

// Action functions
void powerUp() {
  rightUpper.write(20);
  rightLower.write(30);
  leftUpper.write(70);
  leftLower.write(150);
  rightLeg.write(0);
  leftLeg.write(90);
  powerUpSound();
  //Serial.println("Powering UP!");
  lastAction = "power up";
}

void block() {
  rightUpper.write(0);
  rightLower.write(120);
  leftUpper.write(90);
  leftLower.write(60);
  rightLeg.write(rightLegAngle);
  leftLeg.write(leftLegAngle);

  blockSound();
  //Serial.println("Character is blocking");
  lastAction = "block";
}

void blockAgian() {
  rightUpper.write(20);
  rightLower.write(150);
  leftUpper.write(80);
  leftLower.write(30);

  delay(500);

  rightUpper.write(0);
  rightLower.write(120);
  leftUpper.write(90);
  leftLower.write(60);
  rightLeg.write(rightLegAngle);
  leftLeg.write(leftLegAngle);

  blockSound();
  //Serial.println("Character is blocking");
  lastAction = "block";
}

void superBlock() {
  rightUpper.write(10);
  rightLower.write(150);
  leftUpper.write(80);
  leftLower.write(40);
  rightLeg.write(110);
  leftLeg.write(0);

  superBlockSound();
  //Serial.println("Character is super blocking");
  superBlockActive = true;
  superBlockTimer = millis(); // Start the 5-minute timer
  lastAction = "super block";
}

void leftPunch() {
  leftUpper.write(0);
  leftLower.write(180);
  rightLeg.write(rightLegAngle);
  leftLeg.write(leftLegAngle);

  //Serial.println("Left punch");
  punchSound();
  lastAction = "left punch";
  lastArmUsed = "left";
}

void rightPunch() {
  rightUpper.write(90);
  rightLower.write(0);
  rightLeg.write(rightLegAngle);
  leftLeg.write(leftLegAngle);

  //Serial.println("Right punch");
  punchSound();
  lastAction = "right punch";
  lastArmUsed = "right";
}

void combination() {

  rightUpper.write(0);
  rightLower.write(120);  
  delay(350); 
  combinationSound();
  rightUpper.write(90);
  rightLower.write(0);
  delay(350);
  rightUpper.write(0);
  rightLower.write(120); 
  delay(200);
  leftUpper.write(90);
  leftLower.write(60); 
  delay(400);
  leftUpper.write(0);
  leftLower.write(180);
  delay(300);
  leftUpper.write(90);
  leftLower.write(60); 
  delay(200);
  rightUpper.write(150);
  rightLower.write(60);
  delay(500);
  resetServosToIdle();
}

// Helper functions to reset individual limbs
void resetLeftArm() {
  leftUpper.write(90);
  leftLower.write(180);

  //Serial.println("Reset left arm");
}

void resetRightArm() {
  rightUpper.write(0);
  rightLower.write(0);

  //Serial.println("Reset right arm");
}
//----------------------------------------------------------------------------------

// Main function to process win/loss input
void processInput(String input) {
  /*  
  Serial.println("Processing input: " + input);  // Debug
  Serial.print("Current Counts -> Wins: ");
  Serial.print(winCount);
  Serial.print(", Losses: ");
  Serial.print(lossCount);
  Serial.print(", Total Games: ");
  Serial.println(totalGames);
*/
  if (input == "win") {
    winCount++;
    winStreak++; 
    lossCount = 0; // Reset loss streak
    totalGames++;
/*  
    Serial.println("Result: Win");
    Serial.print("Updated Counts -> Wins: ");
    Serial.print(winCount);
    Serial.print(", Losses: ");
    Serial.print(lossCount);
    Serial.print(", Total Games: ");
    Serial.println(totalGames);
*/


    // Trigger power-up if 3 consecutive wins
    if (winStreak >= 3) {
      powerUp();
      delay(8000);
      resetServosToIdle();
      winStreak = 0;; // Reset win streak after power-up
      //Serial.println("Triggered Power-Up after 3 wins.");
    } else{

    int action = random(0, 3); // Generate random number: 0, 1, or 2

          // Randomly select left or right punch redo this 
    if (action == 0) {

      leftPunch();
      delay(500);
      if (lastAction != "block" && lastArmUsed == "left") {
        resetLeftArm(); // Reset after punch if not a block
        resetRightArm();
      }
    } else if (action == 1){
      rightPunch();
      delay(500);
      if (lastAction != "block" && lastArmUsed == "right") {
        resetRightArm(); // Reset after punch if not a block
        resetLeftArm(); 
      }
    } else{
      combination();
    }
    }

  } else if (input == "loss") {
    lossCount++;
    winStreak = 0;
    totalGames++;

    //Serial.println("Result: Loss");
    if (totalGames > 0) {
        winRate = ((float)winCount / totalGames) * 100; // Cast winCount to float for accurate division
    } else {
        winRate = 100;
    }
    /*  
    Serial.print("Current Win Rate: ");
    Serial.print(winRate, 2);  // Print with 2 decimal places
    Serial.println("%");
*/
    // Determine if block or superBlock is applied
    if (winRate <= 20  && lossCount > 2) {
      //Serial.println("Condition met for Super Block.");
      superBlock();
    } else {
      if(lastAction == "block"){
        blockAgian();
      }else{
        block();  // Use block by default for most losses

      }
      //Serial.println("Condition met for regular Block.");
    }
  }
}
//----------------------------------------------------------------------------------

void loop() {
  // Check for serial input
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any whitespace/newline characters

    // Process win or loss input
    if (input == "win" || input == "loss") {
      //Serial.println("Received: " + input); 
      processInput(input);
    }
  }

  // Check if superBlock timer is active and 5 minutes have passed
  if (superBlockActive && (millis() - superBlockTimer >= 5000)) { // 300,000 ms = 5 minutes
    resetServosToIdle();
    superBlockActive = false;
  }
}
