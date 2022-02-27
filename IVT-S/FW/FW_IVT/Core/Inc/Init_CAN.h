/*
 * Init_CAN.h
 *
 *  Created on: 25 feb. 2022
 *      Author: Juan Galbis
 */

#include "stm32f1xx_hal.h"

/** CAN */
CAN_HandleTypeDef   hcan1;
//RX
CAN_RxHeaderTypeDef RX_Header;
CAN_FilterTypeDef   sFilterConfig;
uint8_t 			RX_CAN_DATA[8];
//TX
CAN_TxHeaderTypeDef TX_Header;
uint8_t             TX_CAN_DATA[8];
uint32_t            TxMailbox;

void Init_CAN  (void);
void Envio_CAN (uint32_t ID, uint8_t Datos_Envio[8]);

