// Lab 13c: Carrera de 4 LEDs "ida y vuelta" con ASM inline ('out')
// Conexión: LEDs en pines 8, 9, 10 y 11 (PB0 a PB3)

void setup() {
  // Configuramos PB0 a PB3 (pines 8 al 11) como salidas
  DDRB |= 0b00001111; 
}

void loop() {
  // 1. IDA: LED 1 a LED 4 (bits 0 -> 1 -> 2 -> 3)
  for (uint8_t i = 0; i < 4; i++) {
    uint8_t valor = (1 << i);
    asm volatile ("out %0, %1" : : "I" (0x05), "r" (valor));
    delay(200);
  }

  // 2. VUELTA: Regresa sin repetir los extremos (bits 2 -> 1)
  for (int8_t i = 2; i > 0; i--) {
    uint8_t valor = (1 << i);
    asm volatile ("out %0, %1" : : "I" (0x05), "r" (valor));
    delay(200);
  }
}
