#ifndef PORT_H
#define PORT_H

#include "platform_types.h"

typedef uint16 Port_PinType;
typedef uint8 Port_PinModeType;

#define PORT_PIN_ID(port,pin) ((((uint16)(port)) << 8U) | (uint16)(pin)))




typedef enum{
    PORT_PIN_IN,PORT_PIN_OUT


}Port_PinDirectionType;


typedef struct{
        uint16 vendorID;
        uint16 moduleID;
        uint8 sw_major_version;
        uint8 sw_minor_version;
        uint8 sw_patch_version;

}Std_VersionInfoType;

/*typedef struct
{
        uint8 portNumber;
        uint8 pinNumber;

        Port_PinDirectionType direction;
        Port_PinModeType mode;

        uint8 initialLevel;

}Port_PinConfigType;*/

typedef struct{

        uint8 portNumber;
        uint8 pinNumber;

        Port_PinDirectionType direction;
        Port_PinModeType mode;

        uint8 initialLevel;

}Port_ConfigType;

void Port_Init( const Port_ConfigType* ConfigPtr);

void Port_SetPinDirection( Port_PinType Pin,Port_PinDirectionType Direction);

void Port_RefreshPortDirection( void ) ;

void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ) ;

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );


#endif
