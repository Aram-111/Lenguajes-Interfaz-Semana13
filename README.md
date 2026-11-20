# Práctica Semana 13: Manipulación de Registros y Ensamblador Inline en AVR

**Alumno:** Aram Gutierrez Alcantar  
**Número de Control:** 23490544  
**Materia:** Lenguajes de Interfaz  
**Plataforma:** Arduino Uno (Microcontrolador ATmega328P - Arquitectura AVR)

---

## 📂 Contenido del Repositorio y Videos Demostrativos

### 🔹 Lab 13a: Parpadeo mediante Registros en C Puro
* **Archivo:** `lab13a/lab13a.ino`
* **Descripción:** Control del pin integrado (`PB5` / Pin 13) manipulando directamente los registros `DDRB` y `PORTB` mediante operaciones a nivel de bits (`|=`, `&= ~`), sustituyendo `delay()` por un retardo por software con variable `volatile`.
* **🎥 Video Demostrativo 13a:** [Pega aquí tu enlace del video para Lab 13a]

### 🔹 Lab 13b: Ensamblador Inline (`sbi`, `cbi`, `out`)
* **Archivo:** `lab13b/lab13b.ino`
* **Descripción:** Control de hardware mediante instrucciones nativas AVR (`asm volatile`). Implementa `sbi` para configurar el puerto de salida y `out` para escribir bytes completos en `PORTB` (`0x05`), integrado con retardo por software sin `delay()` (Bono +5%).
* **🎥 Video Demostrativo 13b:** [Pega aquí tu enlace del video para Lab 13b]

### 🔹 Lab 13c: Carrera de 4 LEDs ("Ida y Vuelta")
* **Archivo:** `lab13c/lab13c.ino`
* **Descripción:** Secuencia bidireccional (`LED 1 → 4 → 1`) sobre los pines digitales 8 al 11 (`PB0` a `PB3`) calculando el desplazamiento de bits (`1 << i`) y escribiendo directamente en `PORTB` mediante la instrucción `out` en ensamblador inline.
* **🎥 Video Demostrativo 13c (Demostración y Explicación):** [Pega aquí tu enlace del video para Lab 13c] *(En este video muestro la carrera de LEDs funcionando, señalo la línea de ASM inline en el código y explico la instrucción `out`).*

---

## 🤖 Declaración de Uso de IA
> *"Declaro que he utilizado IA (Gemini) como tutor de apoyo para comprender la arquitectura de registros AVR, depurar la sintaxis de Ensamblador inline (`asm volatile` con `sbi` y `out`), validar las conexiones físicas de los LEDs en el protoboard y estructurar la documentación de este repositorio. Todo el código ha sido probado en hardware real, depurado y comprendido."*

### Prompts principales utilizados:
1. *"Ayúdame a reemplazar las instrucciones sbi y cbi por la instrucción 'out' en ASM inline para controlar el puerto PORTB y explícame por qué necesita un registro."*
2. *"¿Cómo integro un retardo por software usando un ciclo for con variable volatile junto con instrucciones en ensamblador para eliminar delay()?"*
3. *"Ayúdame a modificar el código de la carrera de LEDs usando 'out' en ASM inline para lograr el efecto ida y vuelta (LED 1 a 4 y de regreso) sin repetir los extremos."*
