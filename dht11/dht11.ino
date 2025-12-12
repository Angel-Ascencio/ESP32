#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando sensor DHT11...");
  
  dht.begin();
  delay(1000);
}

void loop() {
  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Verificar lecturas
  if (isnan(h) || isnan(t)) {
    Serial.println("Error leyendo el sensor!");
    return;
  }
  
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");
}