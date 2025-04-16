#include "dec3a8.h"
int valor;
void dec3a8_init()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    GPIOB->CRL |= 0x11111111; // config.: 00 : output push-pull and mode: 01 : output max speed 10MHz
}
void dec3a8(int I0, int I1, int I2)
{
    valor = I0 | I1 << 1 | I2 << 2;

    switch (valor)
    {
        case 000;
            GPIOB->BSRR|=0x00;
            GPIOB->BSRR|=(1<<0);
        case 001;
            GPIOB->BSRR|=0x00;
            GPIOB->BSRR|=(1<<1);
        case 010;
            GPIOB->BSRR|=0x00;
            GPIOB->BSRR|=(1<<2);
        case 011;
    }
}