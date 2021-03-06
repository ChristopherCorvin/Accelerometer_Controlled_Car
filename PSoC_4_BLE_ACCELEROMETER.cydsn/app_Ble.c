/*******************************************************************************
* File Name: app_Ble.c
*
* Description:
*  Common BLE application code for client devices.
*
*******************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "app_ble.h"

/* MTU size to be used by Client and Server after MTU exchange */
uint16 mtuSize      = CYBLE_GATT_MTU;   

extern uint8 applicationPower;

/*******************************************************************************
* Function Name: HandleBleProcessing
********************************************************************************
*
* Summary:
*   Handles the BLE state machine for intiating different procedures
*   during different states of BLESS.
*
* Parameters:
*   None.
*
* Return:
*   None.
*
*******************************************************************************/
void HandleBleProcessing(void)
{    
    switch (cyBle_state)
    {
        case CYBLE_STATE_ADVERTISING:
            break;
        
        case CYBLE_STATE_CONNECTED:
		
		    connStatus= CONNECTED;

            if(CyBle_GattGetBusStatus() != CYBLE_STACK_STATE_BUSY)
            {
                SendCommand();/*This will send the command over BLE*/
				applicationPower = DEEPSLEEP;/*Once command has been sent the state has been set to DEEPSLEEP*/
			
            }
			break;
                
        case CYBLE_STATE_DISCONNECTED:
        	CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
        	break;
        default:
            break;       
    }
}

/*******************************************************************************
* Function Name: AppCallBack
********************************************************************************
*
* Summary:
*   Call back function for BLE stack to handle BLESS events
*
* Parameters:
*   event       - the event generated by stack
*   eventParam  - the parameters related to the corresponding event
*
* Return:
*   None.
*
*******************************************************************************/
void AppCallBack(uint32 event, void *eventParam)
{   
    switch (event)
    {
        case CYBLE_EVT_STACK_ON:
            break;
            
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            break;
            
        case CYBLE_EVT_GATT_CONNECT_IND:
            break;
        
               
        case CYBLE_EVT_GATTS_XCNHG_MTU_REQ:
            
            if(CYBLE_GATT_MTU > ((CYBLE_GATT_XCHG_MTU_PARAM_T *)eventParam)->mtu)
            {
                mtuSize = ((CYBLE_GATT_XCHG_MTU_PARAM_T *)eventParam)->mtu;
            }
            else
            {
                mtuSize = CYBLE_GATT_MTU;
            }
            
            break;
        default:
            break;
    }
}

/* [] END OF FILE */
