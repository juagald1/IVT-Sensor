/**
**************************************************************************************
\file          main.c
\brief         Archivo principal del Firmware Isabellenhüette Sensor Driver for STM32
\details

\author        Juan Galbis Domènech
\version       1.0
\date          28/02/2022
**************************************************************************************/

//
// Included Files
//
#include "main.h"
#include "Init_HW.h"
#include "Init_CAN.h"
#include "IVT_Sensor.h"

uint8_t test;	/*!< Variable para testear la adquisición de datos del sensor IVT*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  Init_HW  ();
  Init_CAN ();
  Init_Config_IVT_Sensor ();

  while (1)
  {
	  if(test ==1){
		  Start_IVT_Sensor();
		  test =0;
	  }

	  if(test ==2){
		  Stop_IVT_Sensor();
		  test =0;
	  }
  }
}
