/**
  ******************************************************************************
  * @file    :Main.c
  * @author  :MG Team
  * @version :V1.0
  * @date
  * @brief
  ******************************************************************************
***/

/* Includes ------------------------------------------------------------------*/
#include "Includes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t txcnt = 0;
uint8_t rxcnt = 0;


/* Private function prototypes -----------------------------------------------*/


/*******************************************************************************
* Function	 :		main
* Parameter  :		void
* Returns	 :		void
* Description:
* Note: 	 :
*******************************************************************************/
void main(void)
{
    //init mcu system
    Init_System();

    LED_RED_ON();
	Delay_ms(30);

    //BLE initial
	BLE_Init();
    Uart_Send_String("BLE init ok.\r\n");

    while(1)
    {

        //////user proc
        //todo

        //////ble rtx api
        txcnt=3; //txcnt=0 is for rx only application
        rxcnt=6; //rxcnt=0 is for tx only application
        BLE_TRX();
        //Uart_Send_String("BLE trx done.\r\n");

        //delay to set ble tx interval
        Delay_ms(100);

    }
}

