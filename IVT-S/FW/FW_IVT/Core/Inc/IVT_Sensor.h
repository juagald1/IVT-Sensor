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

void Gestion_Datos_Sensor_IVT (uint32_t id_CAN_RX);
void Start_IVT_Sensor 		  (void);
void Stop_IVT_Sensor 		  (void);

/////////////////////////////////////////////////desarrollar
void Init_IVT_Sensor 		  (void);

typedef enum tCAN_IVT_CAN_ids{

	IVT_Msg_Command 	= 0x411,
	IVT_Msg_Debug 		= 0x510,
	IVT_Msg_Response 	= 0x511,
	IVT_Msg_Result_I 	= 0x521,
	IVT_Msg_Result_U1,
	IVT_Msg_Result_U2,
	IVT_Msg_Result_U3,
	IVT_Msg_Result_T,
	IVT_Msg_Result_W,
	IVT_Msg_Result_As,
	IVT_Msg_Result_Wh

}eCAN_IVT_CAN_ids;

typedef enum tCAN_IVT_CAN_Comandos{

	Reset_Error_Log_Data = 0x30,
	TRIGGER 		     = 0x31,
	STORE 				 = 0x32,
	START_OC_TEST 	     = 0x33,
	SET_MODE			 = 0x34,
	SET_THRESHOLD_POS 	 = 0x35,
	SET_THRESHOLD_NEG	 = 0x36,
	RESTART_to_Bitrate	 = 0x3A,
	RESTART_to_default   = 0x3D,
	RESTART				 = 0x3F

}eCAN_IVT_CAN_Comandos;

typedef enum tCAN_IVT_CAN_Estados{

	Stop 		     	= 0x00,
	Run					= 0x01

}eCAN_IVT_CAN_Estados;


typedef struct tCAN_IVT_CAN_Data{
	int32_t IVT_Corriente;
	int32_t IVT_Tension_1;
	int32_t IVT_Tension_2;
	int32_t IVT_Tension_3;
	float   IVT_Temperatura;

}eCAN_IVT_CAN_Data;




#endif /* INC_IVT_SENSOR_H_ */
