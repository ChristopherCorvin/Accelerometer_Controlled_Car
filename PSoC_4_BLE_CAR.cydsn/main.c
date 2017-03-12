/*******************************************************************************
* File Name: main.c
*
* Description:
*  This is the source code for the BLE Client Project to control an X-Y Car.
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>
#include "BLE_CAR_Client.h"
#include "LED.h"



/*******************************************************************************
* Function Name:   main
********************************************************************************
*
* Summary:
*  This function initialises the BLE and handles the functions for controlling the
*  motor states based on the commands received from the accelerometer server.
*
* Parameters:
* None

* Return:
* None
*
*******************************************************************************/

int main()
{
	/* Enabling Global interrupts */
	CyGlobalIntEnable; 
    UART_Start();
	UART_UartPutChar("123");
    int cd =5;
	/* Start BLE component with appropriate Event handler function */
	CyBle_Start(ApplicationEventHandler);	
	
	/* Turn OFF All the LEDs */
	ALL_LED_OFF();
	
	/* Loop For Ever */
    for(;;)
    {
        //UART_UartPutChar(cd+'0'); //int to char
        //DBG_PRINTF("HrssSendHeartRateNtf API Error: ");
        
		/* Function to handle the state of the Client */
		handle_ble_CAR_Client_State();		
		
		/* This function checks the internal task queue in the BLE Stack, 
		and pending operation of the BLE Stack, if any */
		CyBle_ProcessEvents();
        //CyDelay(500);
    }
}

void UART_WifiPrintString(char8 const string[])
{
    uint8 indexU8 = 1u;
    char8 current = *string;
    
    while((char8) '\0' != current)
    {
        UART_UartPutChar((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
    //UART_UartPutChar(0x0D);
    //UART_UartPutChar(0x0A);
}


/* [] END OF FILE */
