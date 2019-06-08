#include "project.h"

int main(void)
{
//	uint16_t value;
	clockInit();
//	usartInit();
	lcd_IO_init();
	uint16_t readT1;
	uint16_t readT2;
	uint16_t readC1;
	uint16_t readC2;
	ADCinit();
	GPIOA->BSRR |= GPIO_BSRR_BR15;
	GPIOB->BSRR |= GPIO_BSRR_BR15;
	while(1)
	{
//		for(uint8_t i=0x24;i<0xFF;i++)
//		{
//		transfer(i);
//		value = receive();
//		printToLCD(value);
//		delay(5000000);
//		}
		startCDS1(0x3);
		readC1 = readCDS1();
//	delay(5000000);
		if(readC1 > 0x900)
		{
		startTemp1(0x1);
		readT1 = readTemp1();
		GPIOA->CRH |= GPIO_CRH_MODE15;
		GPIOA->CRH &= ~GPIO_CRH_CNF15;
		GPIOA->BSRR |= GPIO_BSRR_BS15;
		GPIOB->BSRR |= GPIO_BSRR_BS15;
//		transfer(0x7C);
//		transfer(0x2D);
//		transfer(readT1);
		printToLCD1(readT1);
		delay(5000000);
		}

		startCDS2(0x4);
		readC2 = readCDS2();
//	delay(5000000);
		if(readC2 > 0x900)
		{
		startTemp2(0x1);
		readT2 = readTemp2();
		GPIOA->CRH |= GPIO_CRH_MODE15;
		GPIOA->CRH &= ~GPIO_CRH_CNF15;
		GPIOA->BSRR |= GPIO_BSRR_BS15;
		GPIOB->BSRR |= GPIO_BSRR_BS15;
		
		printToLCD2(readT2);

		delay(5000000);
		}					
	}
}
