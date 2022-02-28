/*
 * IVT_Sensor.h
 *
 *  Created on: 21 feb. 2022
 *      Author: Juan Galbis
 */

#ifndef INC_IVT_SENSOR_H_
#define INC_IVT_SENSOR_H_

#include "stdint.h"

#define ID_CAN_SENSOR_IVT  0x411

/**
  * @brief  Enumerado que contiene los identifcadores CAN de los mensajes enviados por el sensor IVT
  */
typedef enum tCAN_IVT_CAN_ids{

	id_Msg_Command 		   = 0x411,
	id_Msg_Debug 		   = 0x510,
	id_Msg_Response 	   = 0x511,
	id_Msg_Result_I 	   = 0x521,
	id_Msg_Result_U1,
	id_Msg_Result_U2,
	id_Msg_Result_U3,
	id_Msg_Result_T,
	id_Msg_Result_W,
	id_Msg_Result_As,
	id_Msg_Result_Wh

}eCAN_IVT_CAN_ids;

/**
  * @brief  Enumerado que contiene los comandos para interectuar por CAN con el sensor IVT
  */
typedef enum tCAN_IVT_CAN_Comandos{

	/** SET-CONFIG RESULT			*/
	IVT_Msg_Result_I	   = 0x20,
	IVT_Msg_Result_U1	   = 0x21,
	IVT_Msg_Result_U2	   = 0x22,
	IVT_Msg_Result_U3	   = 0x23,
	IVT_Msg_Result_T	   = 0x24,
	IVT_Msg_Result_W	   = 0x25,
	IVT_Msg_Result_As	   = 0x26,
	IVT_Msg_Result_Wh	   = 0x27,

	/** SET-COMMANDS 				*/
	Reset_Error_Log_Data   = 0x30,
	TRIGGER 		       = 0x31,
	STORE 				   = 0x32,
	START_OC_TEST 	       = 0x33,
	SET_MODE			   = 0x34,
	SET_THRESHOLD_POS 	   = 0x35,
	SET_THRESHOLD_NEG	   = 0x36,
	RESTART_to_Bitrate	   = 0x3A,
	RESTART_to_default     = 0x3D,
	RESTART				   = 0x3F,

	/** GET ERROR AND LOGDATA 		*/
	Get_Measurement_Errors = 0x40,
	Get_System_Errors 	   = 0x41,
	Get_Overall_Logdata    = 0x42

}eCAN_IVT_CAN_Comandos;

/**
  * @brief  Enumerado que contiene los estados de marcha/paro del sensor IVT
  */
typedef enum tCAN_IVT_CAN_Estados{

	Stop 		     	= 0x00,
	Run					= 0x01

}eCAN_IVT_CAN_Estados;

/**
  * @brief  Enumerado que contiene los distintos valores de disparo del sensor IVT
  */
typedef enum tCAN_IVT_CAN_Trigger_Modo{

	Disabled	     	= 0x00,
	Triggered			= 0x01,
	Cyclic_Running   	= 0x02

}eCAN_IVT_CAN_Trigger_Modo;

/**
  * @brief  Enumerado que contiene las distintas velocidades de tranmsión configurables del sensor IVT
  */
typedef enum tCAN_IVT_CAN_BitRate{

	kbits_250	     	= 0x08,
	kbits_500			= 0x04,
	Mbits_1000   		= 0x02

}eCAN_IVT_CAN_BitRate;

/**
  * @brief  Estructura que almacana los datos del sensor recibidos por CAN
  */
typedef struct tCAN_IVT_CAN_Data{
	int32_t IVT_Corriente;
	int32_t IVT_Tension_1;
	int32_t IVT_Tension_2;
	int32_t IVT_Tension_3;
	float   IVT_Temperatura;

}eCAN_IVT_CAN_Data;


/** PROTOTIPOS FUNCIONES */

void Gestion_Datos_Sensor_IVT (uint32_t id_CAN_RX);
void Start_IVT_Sensor 		  (void);
void Stop_IVT_Sensor 		  (void);
void Guardado_IVT_Sensor	  (void);
void Init_Config_IVT_Sensor   (void);
void BitRate_IVT_Sensor	  	  (eCAN_IVT_CAN_BitRate Velocidad);

#endif /* INC_IVT_SENSOR_H_ */
