/**
**************************************************************************************
\file          Init_CAN.c
\brief         Módulo que continen las funciones para inicializado del periferico CAN1
			   y envio de datos.
\details
\author        Juan Galbis Domènech
\version       1.0
\date          25/02/2022
**************************************************************************************/

#include "stm32f1xx_hal.h"
#include "Init_CAN.h"
#include "IVT_Sensor.h"

#define ID_CAN_DISPOSITIVO 0x100

/**
  * @brief Función Inicializado Periférico CAN1
  * @param None
  * @retval None
  */
void Init_CAN (void){

  //Configuracion periférico
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 5;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_8TQ;		/** Recomendable para cálculo time quantas */
  hcan1.Init.TimeSeg2 = CAN_BS2_1TQ;		/** http://www.bittiming.can-wiki.info 	   */
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;

  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
	//Error_Handler();	   //JGD Generar Error
  }

  //Inicializado Recepciones
  RX_Header.IDE							= CAN_ID_STD;
  RX_Header.StdId						= ID_CAN_DISPOSITIVO;
  RX_Header.RTR							= CAN_RTR_DATA;
  RX_Header.DLC							= 8;

  //Inicializado Envios
  TX_Header.IDE 						= CAN_ID_STD;
  TX_Header.StdId 						= ID_CAN_SENSOR_IVT;
  TX_Header.RTR 						= CAN_RTR_DATA;
  TX_Header.DLC 						= 8;

  //Inicializado Filtro Recepción
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

/**
  * @brief Función para relizar envíos por el periférico CAN1
  * @param ID
  * @param Datos_Envio[8]
  * @retval None
  */
void Envio_CAN (uint32_t ID, uint8_t Datos_Envio[8]) {

		TX_Header.StdId 	= ID;

	if (HAL_CAN_AddTxMessage(&hcan1, &TX_Header, Datos_Envio, &TxMailbox) != HAL_OK)
	{
	   //JGD Generar Error
	}
		HAL_Delay(20); //Delay para vaciar mailbox de envíos
}
