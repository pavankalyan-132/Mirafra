
#include "Port.h"
#include "Dio.h"

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
    uint8 port;
    uint8 pin;
    uint32 base;
    uint32 value;

    port = (ChannelId >> 8U) & 0xFF;
    pin  = (ChannelId) & 0xFF;

    if(pin >= 16U)
        return STD_LOW;

    base = Port_GetBaseAddress(port);

    if(base == NULL_PTR)
        return STD_LOW;

    value = PORT_REG32(base,PORT_IN_OFFSET);

    if((value >> pin) & 1)
        return STD_HIGH;
    else
        return STD_LOW;
}

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
   uint8 port;
   uint8 pin;
   uint32 base;

   port = (ChannelId >> 8U) & 0xFF;
   pin  = (ChannelId) & 0xFF;

   if(pin >= 16U)
   {
       return ;
   }

   base = Port_GetBaseAddress(port);

   if(base == NULL_PTR)
   {
       return ;
   }

   if(Level == STD_HIGH)
   {
       PORT_REG32(base,PORT_OMR_OFFSET) = (1U << pin);


   }
   else if(Level == STD_LOW)
   {
       PORT_REG32(base,PORT_OMR_OFFSET) = (1U << (pin + 16U));
   }

   else
   {
       return;

   }


}

Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
    uint8 port;
        uint8 pin;
        uint32 base;
        uint32 value;

        port = (ChannelId >> 8U) & 0xFF;
        pin  = (ChannelId) & 0xFF;

        if(pin >= 16U)
            return STD_LOW;

        base = Port_GetBaseAddress(port);

        if(base == NULL_PTR)
            return STD_LOW;

        value = PORT_REG32(base,PORT_IN_OFFSET);

        if((value >> pin) & 1)
            return STD_HIGH;
        else
            return STD_LOW;

}


void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{

}

Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{

}

void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level ) {

}
