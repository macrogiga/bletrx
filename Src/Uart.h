#ifndef _UART_H_
#define _UART_H_

extern volatile uint8_t Rx_Buffer[] ;

//
extern volatile uint8_t Rx_Tx_Buffer_Cnt ;


extern void Init_Uart(void);
extern void Uart_Send_Byte(char data);
extern void Uart_Send_String(char *data);

extern void Int2ASCII(uint16_t data, uint8_t *pBuf);

extern void Byte2ASCII(uint8_t data, uint8_t *pBuf);



#endif

