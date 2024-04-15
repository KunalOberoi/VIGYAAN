// Define ultrasonic sensor pins
const int trigPin = 2; // Trig pin of the ultrasonic sensor
const int echoPin = 3; // Echo pin of the ultrasonic sensor

// Define LED pin
const int ledPin = 13; // Pin to which the LED is connected

// Define distance thresholds for turning the LED on and off (in centimeters)
const int distanceThreshold = 20; // Distance threshold for turning the LED on

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set ultrasonic sensor pins as input and LED pin as output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor to send out pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse received by the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is within the threshold
  if (distance < distanceThreshold) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
  }

  // Delay for stability
  delay(100);
}
