#include "statemachine_Interface.h"

// LEDs are SourceConnection
// LCD Takes 16 Char per Line => to make the Data in the old line disappear you have to push to that Number


void main()
{
    System_Init();

    while(1)
    {
        StateMachine();
    }
}

