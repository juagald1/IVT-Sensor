/**
**************************************************************************************
\file          main.c
\brief         Archivo principal del Firmware Isabellenhüette Sensor STM32.
\details	   El firmware desarrollado permite configurar, iniciar y parar la
 	 	 	   adquisición datos.

 	 	 	   Tambien se ha desarrollado una función que permite registrar las alarmas
 	 	 	   generadas por el sensor.

 	 	 	   Probar firmware dando valores a la variable test.

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

uint8_t 			test;				/*!< Variable para testear la adquisición de datos del sensor IVT, solo para este ejemplo	*/
extern tIVT_Sensor 	Sensor_IVT;			/*!< Estructura General Sensor IVT        													*/


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  Init_HW  				   	   ();
  Init_CAN 				 	   ();
  Config_IVT_Sensor       	   ();

  while (1)
  {
	  if(test ==1){
		 Start_IVT_Sensor  	   ();
		 test =0;
	  }

	  if(test == 2){
		 Stop_IVT_Sensor   	   ();
		 test =0;
	  }

	  if(test == 3){
		 Stop_Reset_IVT_Sensor ();
		 test =0;
	  }

		  if(Sensor_IVT.Alarmas.Init_Loop == 1){
			Consulta_Alarmas_IVT_Sensor();
	  }
  }
}
