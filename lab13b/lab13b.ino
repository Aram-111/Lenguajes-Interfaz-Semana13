// Lab 13b: Ensamblador inline AVR con instrucción 'out' y retardo por software (Bono +5%)

void setup() {
  // Configura PB5 (pin 13) como salida usando sbi en DDRB (dirección I/O 0x04)
  asm volatile ("sbi %0, %1" : : "I" (0x04), "I" (5));
}

void loop() {
  // Encender LED usando 'out' en PORTB (dirección I/O 0x05)
  uint8_t valor = 0b00100000; 
  asm volatile ("out %0, %1" : : "I" (0x05), "r" (valor));
  
  // Retardo por software (reemplaza delay)
  for (volatile long i = 0; i < 100000; i++); 
  
  // Apagar LED usando 'out'
  valor = 0; 
  asm volatile ("out %0, %1" : : "I" (0x05), "r" (valor));
  
  // Retardo por software (reemplaza delay)
  for (volatile long i = 0; i < 100000; i++); 
}