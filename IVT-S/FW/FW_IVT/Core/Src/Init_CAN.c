/*
 * Init_CAN.c
 *
 *  Created on: 25 feb. 2022
 *      Author: Juan Galbis
 */

#include "stm32f1xx_hal.h"
#include "Init_CAN.h"
#include "IVT_Sensor.h"

#define ID_CAN_DISPOSITIVO 0x100

void Init_CAN (void){

  //Inicializado Recepciones
  RX_Header.IDE		= CAN_ID_STD;
  RX_Header.StdId	= ID_CAN_DISPOSITIVO;
  RX_Header.RTR		= CAN_RTR_DATA;
  RX_Header.DLC		= 8;

  //Inicializado Envios
  TX_Header.IDE 	= CAN_ID_STD;
  TX_Header.StdId 	= ID_CAN_SENSOR_IVT;
  TX_Header.RTR 	= CAN_RTR_DATA;
  TX_Header.DLC 	= 8;

  //Inicializado Filtro
  sFilterConfig.FilterFIFOAssignment	= CAN_FILTER_FIFO0;
  sFilterConfig.FilterIdHigh			= 0x245<<5;
  sFilterConfig.FilterIdLow				= 0;
  sFilterConfig.FilterMaskIdHigh		= 0;
  sFilterConfig.FilterMaskIdLow			= 0;
  sFilterConfig.FilterScale				= CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterActivation		= ENABLE;

  HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig);
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);

  //Inicializado Perifercio
  HAL_CAN_Start(&hcan1);

}

void Envio_CAN (uint32_t ID, uint8_t Datos_Envio[8]) {

		TX_Header.StdId 	= ID;

	if (HAL_CAN_AddTxMessage(&hcan1, &TX_Header, Datos_Envio, &TxMailbox) != HAL_OK)
	{
	   //JGD Generar Error
	}
	HAL_Delay(20);
}
