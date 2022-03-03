# IVT-Sensor
Firmware desarrollado para gestionar y controlar el sensor IVT-S-1K-U3-I-CAN2-12/24.

Se configura el sensor para obtener información de manera cíclica (lectura de corriente 20ms, tensiones 60ms y temperatura 120ms).

# Hardware Requerido
- Sensor Isabellenhutte IVT-S
- Microcontrolador STM32F1
- Interfaz CAN-USB (Opcional) https://www.ixxat.com/home
- Resistencia Potencia (1 ohm, 5W)
- Fuente de alimentación (5V/3A)

# Software Requerido
- STM32CubeIDE
- canAnalyser3 Mini (Opcional)

#  Notas
- El firmware desarrollado no implementa todas las funciones disponibles en el datasheet, ampliar segun aplicación.
- Usar un interfaz CAN a USB es recomendable para depurar en tiempo real los mensajes intercambiados entre el sensor y el microcontrolador.
