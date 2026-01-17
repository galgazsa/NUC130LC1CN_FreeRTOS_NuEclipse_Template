/******************************************************************************
 * @file     main.c for FreeRTOS
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 14/12/08 11:51a $
 * @brief    Software Development Template.
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include "NUC100Series.h"
#include "FreeRTOS.h"
#include "task.h"
#include "sys.h"
#include "clk.h"

void SYS_Init(void)
{
   /*  Enable internal 22.1184 MHz RC oscillator
    CLK->PWRCON |= CLK_PWRCON_IRC22M_EN_Msk;
    while (!(CLK->CLKSTATUS & CLK_CLKSTATUS_IRC22M_STB_Msk));

     HCLK source = IRC22M
    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_HCLK_S_Msk)
                 | CLK_CLKSEL0_HCLK_S_HIRC;

     HCLK divider = 1
    CLK->CLKDIV = (CLK->CLKDIV & ~CLK_CLKDIV_HCLK_N_Msk)
                | CLK_CLKDIV_HCLK(1);*/

	void SYS_Init(void)
	{
	    /* Enable external 12 MHz crystal */
	    CLK->PWRCON |= CLK_PWRCON_XTL12M_EN_Msk;
	    while (!(CLK->CLKSTATUS & CLK_CLKSTATUS_XTL12M_STB_Msk));

	    /* HCLK source = HXT */
	    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_HCLK_S_Msk)
	                 | CLK_CLKSEL0_HCLK_S_HXT;

	    /* HCLK divider = 1 → 12 MHz */
	    CLK->CLKDIV = (CLK->CLKDIV & ~CLK_CLKDIV_HCLK_N_Msk)
	                | CLK_CLKDIV_HCLK(1);
	}

}


void vTestTask(void *pvParameters)
{
    while (1)
    {
        __NOP();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(void)
{

    SYS_Init();

    xTaskCreate(
        vTestTask,
        "TEST",
        128,
        NULL,
        1,
        NULL
    );


    vTaskStartScheduler();

    /* IDE SOHA nem szabad ide visszajutni */
    while (1);
}
