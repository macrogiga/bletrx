/**
  ******************************************************************************
  * @file    :Spi.c
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
/* Private function prototypes -----------------------------------------------*/


/*******************************************************************************
* Function   :     	SPI_Write_Byte	                                                                                                     
* Parameter  :     	uint8_t data1                        
* Returns    :     	void            
* Description:      SPI write byte
* Note:      : 		
*******************************************************************************/
void SPI_Write_Byte(uint8_t data1) 
{ 
	uint8_t i;
	

	for(i=0;i<8;i++)
	{
		BLE_SCK_CLR();
		if(data1&0x80)
		{
			BLE_MOSI_MISO_SET();
		}
	 	else
		{
			BLE_MOSI_MISO_CLR();
		}
		

		BLE_SCK_SET(); 
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");

//	    __asm("nop");
//        __asm("nop");
//        __asm("nop");
//        __asm("nop");

		data1<<=1;
	}
	BLE_SCK_CLR();

	BLE_MOSI_MISO_SET();

} 


/*******************************************************************************
* Function   :     	SPI_Read	                                                                                                     
* Parameter  :     	void                       
* Returns    :     	uint8_t            
* Description:      
* Note:      : 
*******************************************************************************/
uint8_t SPI_Read_Byte(void) 
{ 
	uint8_t i,ret=0;
	
	//read data .change mosi PIN mode: INPUT PULL
	GPIO_Init(BLE_MOSI_MISO_PORT,BLE_MOSI_MISO,GPIO_Mode_In_PU_No_IT);
	//BLE_MOSI_MISO_SET();

	for(i=0;i<8;i++)
	{
		BLE_SCK_CLR();
		__asm("nop");
		__asm("nop");
        
//		__asm("nop");
//		__asm("nop");
//		__asm("nop");
//		__asm("nop");

		BLE_SCK_SET(); 

		ret<<=1;
		if(BLE_MOSI_MISO_GET() != RESET)
		{
			ret|=1;
		}
	}
	GPIO_Init(BLE_MOSI_MISO_PORT,BLE_MOSI_MISO,GPIO_Mode_Out_PP_High_Slow);
	//BLE_MOSI_MISO_SET();
	BLE_SCK_CLR();
	
	return ret;
} 


/*******************************************************************************
* Function   :     	SPI_Write_Reg	                                                                                                     
* Parameter  :     	uint8_t reg, uint8_t data                     
* Returns    :     	void            
* Description:      
* Note:      : 		
*******************************************************************************/
void SPI_Write_Reg(uint8_t reg, uint8_t data) 
{ 
	BLE_CSN_CLR();
	
	//Delay_us(10);
	SPI_Write_Byte(reg);
	SPI_Write_Byte(data);
	//Delay_us(10);

	BLE_CSN_SET();
} 

/*******************************************************************************
* Function   :     	SPI_Read_Reg	                                                                                                     
* Parameter  :     	uint8_t reg                       
* Returns    :     	uint8_t            
* Description:      
* Note:      : 		REG addr:0x00--0x1F write must or0x20
*******************************************************************************/
uint8_t SPI_Read_Reg(uint8_t reg) 
{ 
	uint8_t temp0=0;
	
    BLE_CSN_CLR();
	
	//Delay_us(10);
	SPI_Write_Byte(reg);
	temp0 = SPI_Read_Byte();
	//Delay_us(10);

	BLE_CSN_SET();
	return temp0;
} 
/*******************************************************************************
* Function   :     	SPI_Write_Buffer	                                                                                                     
* Parameter  :     	uint8_t reg, uint8_t *dataBuf, uint8_t len                     
* Returns    :     	void            
* Description:      
* Note:      : 
*******************************************************************************/
void SPI_Write_Buffer(uint8_t reg, uint8_t *dataBuf, uint8_t len) 
{ 
	uint8_t temp0=0;
	
    BLE_CSN_CLR();
	
	//Delay_us(10);
	SPI_Write_Byte(reg|0x20);

	for(temp0=0;temp0<len;temp0++)
	{
		SPI_Write_Byte(*dataBuf);
		dataBuf++;
	}
	
	//Delay_us(10);

	BLE_CSN_SET();
} 

/*******************************************************************************
* Function   :     	SPI_Read_Buffer	                                                                                                     
* Parameter  :     	uint8_t reg, uint8_t *dataBuf, uint8_t len                     
* Returns    :     	          
* Description:      
* Note:      : 
*******************************************************************************/
void SPI_Read_Buffer(uint8_t reg, uint8_t *dataBuf, uint8_t len) 
{ 
    uint8_t temp0=0;
	
    BLE_CSN_CLR();
	//Delay_us(20);
	
	SPI_Write_Byte(reg);

	for(temp0=0;temp0<len;temp0++)
	{
		*(dataBuf+temp0)=SPI_Read_Byte();
	}
	//Delay_us(20);

	BLE_CSN_SET();
} 
