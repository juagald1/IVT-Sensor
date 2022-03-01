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
typedef enum CAN_IVT_CAN_ids_s{

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

}CAN_IVT_CAN_ids_t;

/**
  * @brief  Enumerado que contiene los comandos para interectuar por CAN con el sensor IVT
  */
typedef enum CAN_IVT_CAN_Comandos_s{

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

}CAN_IVT_CAN_Comandos_t;

/**
  * @brief  Enumerado que contiene los estados de marcha/paro del sensor IVT
  */
typedef enum CAN_IVT_CAN_Estados_s{

	Stop 		     	= 0x00,
	Run					= 0x01

}CAN_IVT_CAN_Estados_t;

/**
  * @brief  Enumerado que contiene los distintos valores de disparo del sensor IVT
  */
typedef enum CAN_IVT_CAN_Trigger_Modo_s{

	Disabled	     	= 0x00,
	Triggered			= 0x01,
	Cyclic_Running   	= 0x02

}CAN_IVT_CAN_Trigger_Modo_t;

/**
  * @brief  Enumerado que contiene las distintas velocidades de tranmsión configurables del sensor IVT
  */
typedef enum CAN_IVT_CAN_BitRate_s{

	kbits_250	     	= 0x08,
	kbits_500			= 0x04,
	Mbits_1000   		= 0x02

}CAN_IVT_CAN_BitRate_t;

/**
  * @brief  Estructura que almacena los datos del sensor recibidos por CAN
  */
typedef struct CAN_IVT_CAN_Data_s{
	float Corriente;
	float Tension_1;
	float Tension_2;
	float Tension_3;
	float Temperatura;

}CAN_IVT_CAN_Data_t;

/**
  * @brief  Estructura que almacena los flags de los errores generados durante la adquisición de datos
  */
typedef struct CAN_IVT_CAN_Error_Measurement_s{

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
	uint32_t Total_Errores;

}CAN_IVT_CAN_Error_Measurement_t;


/**
  * @brief  Estructura general del Sensor IVT
  */
typedef struct IVT_Sensor_s{

	uint32_t 							Numero_Serie;
	CAN_IVT_CAN_Data_t					Datos;
	CAN_IVT_CAN_Error_Measurement_t		Alarmas;

}IVT_Sensor_t;


/** PROTOTIPOS FUNCIONES */

void	 Gestion_Datos_Sensor_IVT (uint32_t id_CAN_RX);
void	 Start_IVT_Sensor 		  (void);
void	 Stop_IVT_Sensor 		  (void);
void	 Guardado_IVT_Sensor	  (void);
void	 Init_IVT_Sensor		  (void);
void 	 BitRate_IVT_Sensor	  	  (CAN_IVT_CAN_BitRate_t Velocidad);
void 	 Numero_Serie_IVT_Sensor  (void);

#endif /* INC_IVT_SENSOR_H_ */
