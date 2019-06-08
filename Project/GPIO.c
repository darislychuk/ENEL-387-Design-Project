 #include "stm32f10x.h"
 #include "project.h"

void ADCinit(void)
{
	RCC->APB2ENR |=  RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN;
	GPIOA->CRL &= ~GPIO_CRL_CNF1_0 & ~GPIO_CRL_CNF2_0 & ~GPIO_CRL_CNF3_0 & ~GPIO_CRL_CNF4_0;
	ADC1->CR2 |= 0x00000001;
}

void startTemp1(uint16_t channel)
{
	//uint8_t hexval;
	ADC1->SQR3 = 0x00000001;
	ADC1->CR2 = 0x00000001;
}

uint16_t readTemp1(void)
{
	uint16_t adc_data = 0;
	while(!(ADC1->SR & ADC_SR_EOC));
	
	adc_data = (ADC1->DR & ADC_DR_DATA);
	return(adc_data);
}

void startTemp2(uint16_t channel)
{
	//uint8_t hexval;
	ADC1->SQR3 = 0x00000001;
	ADC1->CR2 = 0x00000001;
}

uint16_t readTemp2(void)
{
	uint16_t adc_data = 0;
	while(!(ADC1->SR & ADC_SR_EOC));
	
	adc_data = (ADC1->DR & ADC_DR_DATA);
	return(adc_data);
}

void startCDS1(uint16_t CDS1channel)
{
	//uint8_t hexval;
	ADC1->SQR3 = 0x00000003;
	ADC1->CR2 = 0x00000001;
}

uint16_t readCDS1(void)
{
	uint16_t adc_data = 0;
	while(!(ADC1->SR & ADC_SR_EOC));
	
	adc_data = (ADC1->DR & ADC_DR_DATA);
	return(adc_data);
}
void startCDS2(uint16_t CDS2channel)
{
	//uint8_t hexval;
	ADC1->SQR3 = 0x00000004;
	ADC1->CR2 = 0x00000001;
}

uint16_t readCDS2(void)
{
	uint16_t adc_data = 0;
	while(!(ADC1->SR & ADC_SR_EOC));
	
	adc_data = (ADC1->DR & ADC_DR_DATA);
	return(adc_data);
}