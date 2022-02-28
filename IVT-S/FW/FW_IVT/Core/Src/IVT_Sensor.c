/*
 * IVT_Sensor.c
 *
 *  Created on: 21 feb. 2022
 *      Author: Juan Galbis
 */

#include "Init_CAN.h"
#include "IVT_Sensor.h"

#define  CONV_MIL 0.001
#define  CONV_CEN 0.1

uint8_t 		  Datos[8];			/*!< Array 8 bytes transmision datos CAN   */
eCAN_IVT_CAN_Data Datos_Sensor;		/*!< Estructura Guardado Datos_Sensor      */


/**
  * @brief  Gestión de los datos recibidos por bus CAN, provenientes del sensor IVT.
  * 		Recepciona mensaje y lo guarda en la variable correspodiente en la estructura Datos_Sensor.
  * @param  id_CAN_RX: id CAN del mensaje recibido.
  * @retval None
  */
void Gestion_Datos_Sensor_IVT (uint32_t id_CAN_RX){

	int32_t aux=0;

	  switch (id_CAN_RX){

	      case id_Msg_Result_I:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Corriente = aux * CONV_MIL;
	        break;

	      case id_Msg_Result_U1:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Tension_1 = aux * CONV_MIL;
	        break;

	      case id_Msg_Result_U2:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Tension_2 = aux * CONV_MIL;
	        break;

	      case id_Msg_Result_U3:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Tension_3 = aux * CONV_MIL;
	        break;

	      case id_Msg_Result_T:
	    	  aux = (RX_CAN_DATA[2])+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Temperatura = aux*CONV_CEN;
	        break;

	      case id_Msg_Result_W:
	        break;

	      case id_Msg_Result_As:
	        break;

	      case id_Msg_Result_Wh:
	        break;
	  }
}

/**
  * @brief  Envío por bus CAN la señal de inico de la adquisición de datos.
  * @param  None
  * @retval None
  */
void Start_IVT_Sensor (void){

	Datos[0] = SET_MODE; Datos[1] = Run; Datos[2]=Run;
	Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;

	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
}

/**
  * @brief  Envío por bus CAN la señal de parada de adquisición de datos.
  * @param  None
  * @retval None
  */
void Stop_IVT_Sensor (void){

	Datos[0] = SET_MODE; Datos[1] = Stop; Datos[2]=Run;
	Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;

	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
}

/**
  * @brief  Envío por bus CAN la señal de guardado en memoria del sensor IVT.
  * 		Debe usarse cada vez que se modifique la configuración del sensor.
  * @param  None
  * @retval None
  */
void Guardado_IVT_Sensor (void){
	Datos[0] = STORE;
	Datos[1] = Datos[2]= Datos[3] = Datos[4] =
	Datos[5] = Datos[6] = Datos[7] = 0;

	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
}

/**
  * @brief  Envío por bus CAN la configuración inicial del sensor IVT para I, U1,U2,U3 y T.
  * @param  None
  * @retval None
  */
void Init_Config_IVT_Sensor (void){

	Stop_IVT_Sensor();

	/** Configura muestreo continuo corriente cada 20ms 	(0x14) 	 */
	Datos[0] = IVT_Msg_Result_I; Datos[1] = Cyclic_Running; Datos[2] = 0;
	Datos[3] = 0x14; Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);

	/** Configura muestreo continuo tensión 1 cada 60ms 	(0x3C) 	 */
	Datos[0] = IVT_Msg_Result_U1; Datos[1] = Cyclic_Running; Datos[2] = 0;
	Datos[3] = 0x3C; Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);

	/** Configura muestreo continuo tensión 2 cada 60ms 	(0x3C) 	 */
	Datos[0] = IVT_Msg_Result_U2; Datos[1] = Cyclic_Running; Datos[2] = 0;
	Datos[3] = 0x3C; Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);

	/** Configura muestreo continuo tensión 3 cada 60ms 	(0x3C) 	 */
	Datos[0] = IVT_Msg_Result_U3; Datos[1] = Cyclic_Running; Datos[2] = 0;
	Datos[3] = 0x3C; Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);

	/** Configura muestreo continuo temperatura cada 120ms 	(0x78) 	 */
	Datos[0] = IVT_Msg_Result_T; Datos[1] = Cyclic_Running; Datos[2] = 0;
	Datos[3] = 0x78; Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);

	Guardado_IVT_Sensor();

	/** Configura velodcidad tranmsión 500kbit/s 				 	 */
	BitRate_IVT_Sensor	(kbits_500);

    Stop_IVT_Sensor();
}

/**
  * @brief  Configura velocidad de transmisión del bus CAN del sensor IVT.
  * @param  Velocidades soportadas 250kbit/s, 500kbit/s y 1000Mbit/s.
  * @retval None
  */
void BitRate_IVT_Sensor	(eCAN_IVT_CAN_BitRate Velocidad){

	  switch (Velocidad){

		  case kbits_250:
			  Stop_IVT_Sensor();
			  Datos[0] = RESTART_to_Bitrate; Datos[1] = kbits_250;
			  Datos[2] = Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
			  Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
			break;

		  case kbits_500:
			  Stop_IVT_Sensor();
			  Datos[0] = RESTART_to_Bitrate; Datos[1] = kbits_500;
			  Datos[2]= Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
			  Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
			break;

		  case Mbits_1000:
			  Datos[0] = RESTART_to_Bitrate; Datos[1] = Mbits_1000;
			  Datos[2] = Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;
			  Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
			break;
	  }
}


