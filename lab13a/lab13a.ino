// Lab 13a: Parpadeo mediante manipulación directa de registros (AVR-C)
// Sin usar pinMode(), digitalWrite() ni delay()

void setup() {
  // Configuramos PB5 (pin 13) como salida poniendo el bit 5 de DDRB en 1
  DDRB |= (1 << PB5); 
}

void loop() {
  // Encender LED (pone en 1 el bit 5 de PORTB sin alterar los demás)
  PORTB |= (1 << PB5);
  for (volatile long i = 0; i < 100000; i++); // Retardo por software

  // Apagar LED (pone en 0 el bit 5 de PORTB sin alterar los demás)
  PORTB &= ~(1 << PB5);
  for (volatile long i = 0; i < 100000; i++); // Retardo por software
}