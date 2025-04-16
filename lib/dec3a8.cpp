#include "dec3a8.h"
int valor, i = 0;
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
    case 000:
        for (i = 0; i < 8; i++)
        {
            if (i != 0)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 0);
        break;
    case 001:
        for (i = 0; i < 8; i++)
        {
            if (i != 1)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 1);
        break;
    case 010:
        for (i = 0; i < 8; i++)
        {
            if (i != 2)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 2);
        break;
    case 011:
        for (i = 0; i < 8; i++)
        {
            if (i != 3)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 3);
        break;
    case 100:
        for (i = 0; i < 8; i++)
        {
            if (i != 4)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 4);
        break;
    case 101:
        for (i = 0; i < 8; i++)
        {
            if (i != 5)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR = (1 << 5);
        break;
    case 110:
        for (i = 0; i < 8; i++)
        {
            if (i != 6)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 6);
        break;
    case 111:
        for (i = 0; i < 8; i++)
        {
            if (i != 7)
            {
                GPIOB->BSRR |= (1 << (i + 16));
            }
        }
        GPIOB->BSRR |= (1 << 7);
        break;
    default:
        GPIOB->BSRR |= 0x00;
        break;
    }
}