// Pin definitions
const int trigPin1 = 9;    // Trigger pin for sensor 1
const int echoPin1 = 8;    // Echo pin for sensor 1
const int trigPin2 = 7;    // Trigger pin for sensor 2
const int echoPin2 = 6;    // Echo pin for sensor 2
const int buzzerPin = 3;   // Pin for the passive buzzer

// Constants for the notes in the pentatonic scale (A, C, D, E, G)
const int notes[] = {440, 523, 587, 659, 784};  // Frequencies for A, C, D, E, G
const int numNotes = sizeof(notes) / sizeof(notes[0]);

// Function to measure distance from ultrasonic sensor
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;  // Convert to centimeters
  Serial.println(distance);
  return distance;
}

// Function to generate PWM signal for sound
void playFrequency(int frequency) {
  // Play sound by generating PWM on buzzerPin
  int period = 1000000 / frequency;  // Period in microseconds
  int halfPeriod = period / 2;
  
  for (long i = 0; i < 1000000; i += period) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(halfPeriod);
  }
}

void stopSound() {
  digitalWrite(buzzerPin, LOW);
}

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);  // Initialize serial for debugging
}

void loop() {
  // Measure distance from the first ultrasonic sensor (Trigger Sensor)
  long distance1 = measureDistance(trigPin1, echoPin1);
  
  // If an object is detected within 20 cm by the first sensor
  if (distance1 <= 20) {
    // Measure distance from the second ultrasonic sensor (Note Selector Sensor)
    long distance2 = measureDistance(trigPin2, echoPin2);
    
    // Map the second sensor's distance to a note (every 4cm corresponds to a note)
    int noteIndex = distance2 / 4;  // Every 4 cm
    if (noteIndex >= 0 && noteIndex < numNotes) {
      int frequency = notes[noteIndex];  // Select the corresponding note
      playFrequency(frequency);          // Play the selected note
      Serial.print("Playing note: ");
      Serial.println(frequency);
    } else {
      stopSound();  // Stop playing sound if out of range
    }
  } else {
    stopSound();  // No object detected, stop sound
  }

  delay(100);  // Short delay between sensor readings
}

