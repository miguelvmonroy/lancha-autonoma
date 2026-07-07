#include <SPI.h>
#include <SD.h>

#define SD_CS 7

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  delay(3000);
  
  Serial.println();
  Serial.println("=========================================");
  Serial.println("   🔍 PRUEBA DE ALIMENTACIÓN Y SD");
  Serial.println("=========================================");
  Serial.println();
  
  // 1. Verificar que el LED del módulo esté encendido
  Serial.println("1. ¿El LED azul del módulo SD está encendido?");
  Serial.println("   → Debe estar encendido SIEMPRE que haya VCC.");
  Serial.println();
  delay(5000);
  
  // 2. Intentar montar la tarjeta
  Serial.println("2. Intentando montar la tarjeta SD...");
  
  SPI.begin(4, 5, 6, 7);  // SCK, MISO, MOSI, CS
  
  if (SD.begin(SD_CS)) {
    Serial.println("   ✅ ¡Tarjeta SD montada!");
    Serial.println();
    Serial.println("🎉 ¡TODO FUNCIONA!");
  } else {
    Serial.println("   ❌ Error al montar la tarjeta.");
    Serial.println();
    Serial.println("🔍 CAUSA PROBABLE:");
    Serial.println("   - Módulo SD dañado");
    Serial.println("   - Tarjeta SD dañada");
    Serial.println("   - Tarjeta no formateada en FAT32");
    Serial.println("   - Cable VCC suelto");
  }
  
  Serial.println();
  Serial.println("=========================================");
}

void loop() {}
