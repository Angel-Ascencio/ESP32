// Sensor Ultrasónico HC-SR04
const int trigPin = 5;
const int echoPin = 18;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duracion = pulseIn(echoPin, HIGH);
  float distanciaCm = duracion * 0.0343 / 2;
  
  Serial.print("Distancia: ");
  Serial.print(distanciaCm);
  Serial.println(" cm");
  
  delay(500);
}