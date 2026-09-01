#include "GIE_Interface.h"



void GIE_Enable()
{
    SetBit(SREG_Reg,I_Bit);
}
void GIE_Disable()
{
    ClearBit(SREG_Reg,I_Bit);
}