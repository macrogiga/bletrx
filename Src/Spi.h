#ifndef _SPI_H_
#define _SPI_H_
extern void SPI_Write_Byte(uint8_t data1) ;
extern uint8_t SPI_Read_Byte(void) ;

extern void SPI_Write_Reg(uint8_t reg, uint8_t data);

extern uint8_t SPI_Read_Reg(uint8_t reg) ;

extern void SPI_Write_Buffer(uint8_t reg, uint8_t *dataBuf, uint8_t len);

extern void SPI_Read_Buffer(uint8_t reg, uint8_t *dataBuf, uint8_t len);

#endif

