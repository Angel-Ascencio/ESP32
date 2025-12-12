const int sensorHumedadPin = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int valorSensor = analogRead(sensorHumedadPin);

  // Convertir a porcentaje, donde 0 es mojado (100%) y 4095 es seco (0%)
  float porcentajeHumedad = 100 - ((float)valorSensor / 4095.0) * 100.0;

  porcentajeHumedad = constrain(porcentajeHumedad, 0, 100);

  Serial.print("Humedad: ");
  Serial.print(porcentajeHumedad, 2);
  Serial.println("%");

  delay(2000);
}
