#include "Port.h"
#include "Port_Reg.h"


static uint32 Port_GetBaseAddress(uint8 portNumber){
    uint32 base=0;

    switch(portNumber)
    {
        case 0:
            base = PORT_P00_BASE;
            break;
        case 2:
            base = PORT_P02_BASE;
            break;
        case 14:
            base = PORT_P14_BASE;
            break;
        case 15:
            base = PORT_P15_BASE;
            break;
        case 20:
            base = PORT_P20_BASE;
            break;
        case 21:
            base = PORT_P21_BASE;
            break;
        case 22:
            base = PORT_P22_BASE;
            break;
        case 23:
            base = PORT_P23_BASE;
            break;
        case 33:
            base = PORT_P33_BASE;
            break;

        default:
            break;

    }
    return base;

}

void Port_Init( const Port_ConfigType* ConfigPtr ){

    uint32 base;
    uint32 offset;
    uint32 shift;
    uint32 value;
    uint8 pin;

    if (ConfigPtr == 0){
        return;
    }

    pin = ConfigPtr->pinNumber;

    /*validate port and pin*/

    base = Port_GetBaseAddress(ConfigPtr->portNumber);

    if((base == 0) || (pin > 15))
    {
        return;
    }

    /*select IOCR register*/
    offset = PORT_IOCR0_OFFSET +((pin/4U)*4U);

    /*position of the pin inside IOCR */
    shift = (pin % 4U) * 8U;

    /*configure the intial output level*/
    if(ConfigPtr->direction == PORT_PIN_OUT)
    {
        if(ConfigPtr->initialLevel == 0)
        {
            PORT_REG32(base, PORT_OMR_OFFSET) = (1U << (pin +16U));
        }
        else
        {
            PORT_REG32(base, PORT_OMR_OFFSET) = (1U << pin );
        }
    }

    /* Read current IOCR value */

    value= PORT_REG32(base,offset);

    /* clear only select pins mode */

    value &= ~(0xF8U << shift);

    /*set selected pin's mode*/
    value |= ((uint32)ConfigPtr->mode << shift );

    /* write updated IOCR */

    PORT_REG32(base,offset)=value;



}

void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction ){

    uint8 portNumber;
    uint8 pinNumber;
    uint32 base;
    uint32 offset;
    uint32 shift;
    uint32 value;
    uint32 mode;


    portNumber = (uint8)(Pin >> 8U);
    pinNumber  = (uint8)(Pin & 0xFFU);

    base = Port_GetBaseAddress(portNumber);

    if ((base == 0U) || (pinNumber > 15U))
    {
        return;
    }

    if (Direction == PORT_PIN_IN)
    {
        mode = PORT_MODE_INPUT_TRISTATE_0;
    }
    else if (Direction == PORT_PIN_OUT)
    {
        mode = PORT_MODE_OUTPUT_PP;
    }
    else
    {
        return;
    }

    offset = PORT_IOCR0_OFFSET + ((pinNumber / 4U) * 4U);

    shift = (pinNumber % 4U) * 8U;

    value = PORT_REG32(base, offset);

    value &= ~(0xF8U << shift);

    value |= (mode << shift);

    PORT_REG32(base, offset) = value;

}

void Port_RefreshPortDirection( void ){

}

void Port_GetVersionInfo( Std_VersionInfoType* versioninfo){

}

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode){

    uint8 portNumber;
    uint8 pinNumber;
    uint32 base;
    uint32 offset;
    uint32 shift;
    uint32 value;

    /* Get the port and pin numbers */
    portNumber = (uint8)(Pin >> 8U);
    pinNumber = (uint8)(Pin & 0xFFU);

    /* Get the port base address */
    base = Port_GetBaseAddress(portNumber);

    if ((base == 0U) || (pinNumber > 15U))
    {
        return;
    }

    /* Check the mode value */
    if ((Mode & 0x07U) != 0U)
    {
        return;
    }

    /* Find the IOCR register and pin position */
    offset = PORT_IOCR0_OFFSET + ((pinNumber / 4U) * 4U);
    shift = (pinNumber % 4U) * 8U;

    /* Update the pin mode without changing other pins */
    value = PORT_REG32(base, offset);
    value &= ~(0xF8U << shift);
    value |= ((uint32)Mode << shift);

    PORT_REG32(base, offset) = value;

}
