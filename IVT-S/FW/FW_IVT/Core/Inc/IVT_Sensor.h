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
************************************************************************************
\typedef        tCAN_IVT_CAN_ids
\brief          Tipo definido para guardado de los identifcadores CAN de los
 	 	 	 	mensajes enviados por el sensor IVT
\struct         tCAN_IVT_CAN_ids
\brief          Estructura para guardado de los identifcadores CAN de los mensajes
 	 	 	 	enviados por el sensor IVT
**********************************************************************************/
typedef enum eCAN_IVT_CAN_ids{

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

}tCAN_IVT_CAN_ids;

/**
************************************************************************************
\typedef        tCAN_IVT_CAN_Comandos
\brief          Tipo definido para guardado de los comandos	para interectuar por CAN
 	 	 	 	con el sensor IVT
\struct         tCAN_IVT_CAN_Comandos
\brief          Estructura para guardado de los comandos	para interectuar por CAN
 	 	 	 	con el sensor IVT
**********************************************************************************/
typedef enum eCAN_IVT_CAN_Comandos{

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
	Get_Overall_Logdata    = 0x42,

	/** GET COMMANDS          		*/
	Get_Device_ID		   = 0x79,
	Get_Device_SW_Version  = 0x7A,
	Get_Serial_Number      = 0x7B

}tCAN_IVT_CAN_Comandos;

/**
*******************************************************************************
\typedef        tCAN_IVT_CAN_Estados
\brief          Tipo definido para la identificación de los estados de
 	 	 	 	marcha/paro del sensor IVT
\enum           eCAN_IVT_CAN_Estados
\brief          Enumerado definido para la identificación de estados de
 	 	 	 	marcha/paro del sensor IVT
******************************************************************************/
typedef enum eCAN_IVT_CAN_Estados{

	Stop 		     	= 0x00,
	Run					= 0x01

}tCAN_IVT_CAN_Estados;

/**
*******************************************************************************
\typedef        tCAN_IVT_CAN_Trigger_Modo
\brief          Tipo definido para la identificación de los distintos
				valores de disparo del sensor IVT
\enum           eCAN_IVT_CAN_Trigger_Modo
\brief          Enumerado definido para la identificación de los distintos
				valores de disparo del sensor IVT
******************************************************************************/
typedef enum eCAN_IVT_CAN_Trigger_Modo{

	Disabled	     	= 0x00,
	Triggered			= 0x01,
	Cyclic_Running   	= 0x02

}tCAN_IVT_CAN_Trigger_Modo;

/**
*******************************************************************************
\typedef        tCAN_IVT_CAN_BitRate
\brief          Tipo definido para la identificación de las velocidades de
 	 	 	 	transmisión configurables.
\enum           eCAN_IVT_CAN_BitRate
\brief          Enumerado definido para la identificación de las velocidades
                de transmisión configurables.
******************************************************************************/
typedef enum eCAN_IVT_CAN_BitRate{

	kbits_250	     	= 0x08,
	kbits_500			= 0x04,
	Mbits_1000   		= 0x02

}tCAN_IVT_CAN_BitRate;

/**
************************************************************************************
\typedef        tCAN_IVT_CAN_Data
\brief          Tipo definido para guardado de parametros medidos por el sensor IVT
\struct         tCAN_IVT_CAN_Data
\brief          Estructura para guardado de parametros medidos por el sensor IVT
**********************************************************************************/
typedef struct sCAN_IVT_CAN_Data{

	float Corriente;
	float Tension_1;
	float Tension_2;
	float Tension_3;
	float Temperatura;

}tCAN_IVT_CAN_Data;

/**
*******************************************************************************
\typedef        tCAN_IVT_CAN_Error_Measurement
\brief          Tipo definido para los flags del sensor IVT
\struct         tCAN_IVT_CAN_Error_Measurement
\brief          Estructura para guardar los flags de alarma del sensor IVT
******************************************************************************/
typedef struct sCAN_IVT_CAN_Error_Measurement{

	uint8_t Total_Errores;
	uint8_t Init_Loop;
    union
        {
        uint8_t All;
        struct
        {
        	uint8_t  ADC_Interrupt:1;
        	uint8_t  OVF_ADC_CH1:1;
        	uint8_t  UVF_ADC_CH1:1;
        	uint8_t  OVF_ADC_CH2:1;
        	uint8_t  UVF_ADC_CH2:1;
        	uint8_t  Vref:1;
        	uint8_t  Current_Measurement:1;
        	uint8_t  Thermal_EMF:1;
        	uint8_t  I_Open_Circuit:1;
        	uint8_t  U1_Open_Circuit:1;
        	uint8_t  U2_Open_Circuit:1;
        	uint8_t  U3_Open_Circuit:1;
        	uint8_t  ntch_Open_Circuit:1;
        	uint8_t  ntcl_Open_Circuit:1;
        	uint8_t  Calibration_Data:1;
        	uint8_t  Reservado:1;
        } Bit ;
    }Flags;

}tCAN_IVT_CAN_Error_Measurement;


/**
*******************************************************************************
\typedef        tIVT_Sensor
\brief          Tipo definido para gestion de sensor IVT
\struct         tIVT_Sensor
\brief          Estructura general para gestion de sensor IVT
******************************************************************************/
typedef struct sIVT_Sensor{

	uint32_t 							Numero_Serie;
	tCAN_IVT_CAN_Data					Datos;
	tCAN_IVT_CAN_Error_Measurement		Alarmas;

}tIVT_Sensor;

//////////////////////////////////////////////////////
/* 				PROTOTIPOS FUNCIONES 				*/
//////////////////////////////////////////////////////

void	 Start_IVT_Sensor 		 	 (void);
void	 Stop_IVT_Sensor 		 	 (void);
void	 Stop_Reset_IVT_Sensor 	 	 (void);
void	 Config_IVT_Sensor		 	 (void);
void	 Guardado_IVT_Sensor	  	 (void);
void 	 Numero_Serie_IVT_Sensor  	 (void);
void	 Consulta_Alarmas_IVT_Sensor (void);
void 	 Flags_Alarmas_IVT_Sensor    (uint8_t Byte);
void	 Gestion_Datos_IVT_Sensor	 (uint32_t id_CAN_RX);
void 	 BitRate_IVT_Sensor	  	 	 (tCAN_IVT_CAN_BitRate Velocidad);


#endif /* INC_IVT_SENSOR_H_ */
