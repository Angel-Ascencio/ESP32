const int relePin = 25;
int comando = 0;

void setup() {
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, HIGH); // Rele apagado inicialmente

  Serial.begin(115200);
  Serial.println("Sistema de control de bomba listo.");
  Serial.println("Envia '1' por Serial para activar la bomba por 10 segundos.");
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.parseInt();

    if (comando == 1) {
      Serial.println("Bomba activada por 10 segundos...");
      digitalWrite(relePin, LOW); // Enciende la bomba

      delay(10000);               // Espera 10 segundos

      digitalWrite(relePin, HIGH); // Apaga la bomba
      Serial.println("Bomba desactivada.");
    } else {
      Serial.println("Comando no reconocido. Usa '1' para activar la bomba.");
    }

    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
