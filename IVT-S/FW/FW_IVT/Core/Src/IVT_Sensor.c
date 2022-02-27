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

uint32_t 	      dbg[10];			//JGD Borrar tras depurar
uint8_t 		  Datos[8];
eCAN_IVT_CAN_Data Datos_Sensor;

/**
 * Se mantiene el formato Big Endian en la lectura de datos del sensor.
 * Lectura por polling, una vez activado el sensor envia datos periodicamente, ver periodos en datasheet
 */

void Gestion_Datos_Sensor_IVT (uint32_t id_CAN_RX){

	int32_t aux=0;

	  switch (id_CAN_RX){

		  case IVT_Msg_Command:
			break;
	      case IVT_Msg_Debug:
	        break;
	      case IVT_Msg_Response:
	        break;

	      case IVT_Msg_Result_I:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Corriente = aux * CONV_MIL;
	    	  dbg[0]++;
	        break;

	      case IVT_Msg_Result_U1:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Tension_1 = aux * CONV_MIL;
	    	  dbg[1]++;
	        break;

	      case IVT_Msg_Result_U2:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Tension_2 = aux * CONV_MIL;
	    	  dbg[2]++;
	        break;

	      case IVT_Msg_Result_U3:
	    	  aux = (RX_CAN_DATA[2]<<24)+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Tension_3 = aux * CONV_MIL;
	    	  dbg[3]++;
	        break;

	      case IVT_Msg_Result_T:
	    	  aux = (RX_CAN_DATA[2])+(RX_CAN_DATA[3]<<16)+(RX_CAN_DATA[4]<<8)+(RX_CAN_DATA[5]);
	    	  Datos_Sensor.IVT_Temperatura = aux*CONV_CEN;
	    	  dbg[4]++;
	        break;

	      case IVT_Msg_Result_W:
	    	  dbg[5]++;
	        break;

	      case IVT_Msg_Result_As:
	    	  dbg[6]++;
	        break;

	      case IVT_Msg_Result_Wh:
	    	  dbg[7]++;
	        break;
	  }
}



void Start_IVT_Sensor (void){

	Datos[0] = SET_MODE; Datos[1] = Run; Datos[2]=Run;
	Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;

	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
}

void Stop_IVT_Sensor (void){

	Datos[0] = SET_MODE; Datos[1] = Stop; Datos[2]=Run;
	Datos[3] = Datos[4] = Datos[5] = Datos[6] = Datos[7] = 0;

	Envio_CAN(ID_CAN_SENSOR_IVT, Datos);
}

