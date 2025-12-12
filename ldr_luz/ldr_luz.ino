
const int ldrPin = 36;

// Define el valor de la resistencia
const int resistenciaFija = 10000; // Resistencia de 10k Ohmios

void setup() {
  Serial.begin(115200);

  // Configura la resolución del ADC a 12 bits
  analogReadResolution(12);
}

void loop() {
  int lecturaLDRCruda = analogRead(ldrPin);

  // Invierte y mapea la lectura cruda (0-4095) a una escala de 0 a 100.
  int intensidadLuzPorcentaje = map(lecturaLDRCruda, 0, 4095, 100, 0);

  // Imprime la lectura cruda del ADC para referencia
  Serial.print("Lectura LDR Cruda (0-4095): ");
  Serial.println(lecturaLDRCruda);

  // Imprime la intensidad de luz en porcentaje
  Serial.print("Intensidad de Luz: ");
  Serial.print(intensidadLuzPorcentaje);
  Serial.println("%");

  Serial.println("-------------------------------------------------");
  delay(1000);
}