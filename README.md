# Práctica Semana 13: Manipulación de Registros y Ensamblador Inline en AVR

**Alumno:** Aram Gutierrez Alcantar  
**Número de Control:** 23490544  
**Materia:** Lenguajes de Interfaz  
**Plataforma:** Arduino Uno (Microcontrolador ATmega328P - Arquitectura AVR)

---

## 📂 Contenido del Repositorio y Videos Demostrativos

### 🔹 Lab 13a: Parpadeo mediante Registros en C Puro
* **Archivo:** `lab13a/lab13a.ino`
* **Descripción y Retos completados:** 
  * **Código Base:** Control del pin integrado (`PB5` / Pin 13) manipulando directamente los registros `DDRB` y `PORTB` mediante operaciones a nivel de bits (`|=`, `&= ~`).
  * **Mejora:** Sustitución de la función `delay()` de Arduino por un retardo por software utilizando un ciclo `for` con una variable `volatile` para evitar optimizaciones del compilador.
* **🎥 Video Demostrativo 13a:** https://drive.google.com/file/d/1Be72rD8m9Mgwd8kVj4absMBzIOTu9VjF/view?usp=sharing

### 🔹 Lab 13b: Ensamblador Inline (`sbi`, `cbi`, `out`)
* **Archivo:** `lab13b/lab13b.ino`
* **Descripción y Retos completados:** 
  * **Código Base:** Control de hardware mediante instrucciones nativas AVR (`asm volatile`), usando `sbi` y `cbi` para manipular bits individuales.
  * **Bono del +5%:** Integración de la instrucción `out` para escribir bytes completos en `PORTB` (`0x05`), fusionado con el retardo por software (`volatile`), eliminando por completo el uso de `delay()`.
* **🎥 Video Demostrativo 13b:** https://drive.google.com/file/d/18V2x17H7bfdlfwmHOADo37JdYLF9toyq/view?usp=sharing

### 🔹 Lab 13c: Carrera de 4 LEDs
* **Archivo:** `lab13c/lab13c.ino`
* **Descripción y Retos completados:** 
  * **Código Base:** Carrera de 4 LEDs en una dirección usando C puro con máscaras y corrimiento de bits.
  * **Reto 1:** Reemplazo de la escritura en el puerto por ensamblador inline, usando la instrucción `out` dentro del ciclo `for` para enviar el valor calculado (`1 << i`).
  * **Reto 2 (Implementación Final):** Efecto bidireccional "ida y vuelta" (LED 1 → 4 → 1) o estilo *Auto Increíble*. Se logró el rebote continuo sin repetir los tiempos en los LEDs de los extremos.
* **🎥 Video Demostrativo 13c:** https://drive.google.com/file/d/1aCk4j6ilxXS_p63sMdhaJc8uqJ6ybZWR/view?usp=sharing *(En este video muestro la carrera de LEDs funcionando, señalo la línea de ASM inline en el código y explico la instrucción `out` y por qué requiere un registro).*

---

## 🤖 Declaración de Uso de IA
> *"Declaro que he utilizado IA (Gemini) como tutor de apoyo para comprender la arquitectura de registros AVR, depurar la sintaxis de Ensamblador inline (`asm volatile` con `sbi` y `out`), validar las conexiones físicas de los LEDs en el protoboard y estructurar la documentación de este repositorio. Todo el código ha sido probado en hardware real, depurado y comprendido."*

### Prompts principales utilizados:
1. *"Ayúdame a reemplazar las instrucciones sbi y cbi por la instrucción 'out' en ASM inline para controlar el puerto PORTB y explícame por qué necesita un registro."*
2. *"¿Cómo integro un retardo por software usando un ciclo for con variable volatile junto con instrucciones en ensamblador para eliminar delay()?"*
3. *"Ayúdame a modificar el código de la carrera de LEDs usando 'out' en ASM inline para lograr el efecto ida y vuelta (LED 1 a 4 y de regreso) sin repetir los extremos."*
