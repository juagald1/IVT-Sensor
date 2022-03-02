# IVT-Sensor
Firmware desarrollado para la gestión y control del sensor IVT-S-1K-U3-I-CAN2-12/24.

Se configura el sensor queda para obtener información de manera cíclica (lectura de corriente 20ms, tensiones 60ms y temperatura 120ms).

Funciones Desarrolladas:
- Start_IVT_Sensor 		 	 
- Stop_IVT_Sensor
- Stop_Reset_IVT_Sensor
- Config_IVT_Sensor	
- Guardado_IVT_Sensor
- Numero_Serie_IVT_Sensor
- Consulta_Alarmas_IVT_Sensor
- Flags_Alarmas_IVT_Sensor
- Gestion_Datos_IVT_Sensor
- BitRate_IVT_Sensor

# Hardware Requerido
- Sensor Isabellenhutte IVT-S
- Microcontrolador STM32F1
- Interfaz CAN-USB (Opcional) https://www.ixxat.com/home
- Resistencia Potencia (1 ohm, 5W)
- Fuente de alimentación (5V/3A)

# Software Requerido
- STM32CubeIDE
- canAnalyser3 Mini (Opcional)

#  Montaje Pruebas

#  Notas
- El firmware desarrollado no implementa todas las funciones disponibles en el datasheet, ampliar segun aplicación.
- Usar un interfaz CAN a USB es recomendable para depurar en tiempo real los mensajes intercambiados entre el sensor y el microcontrolador.
