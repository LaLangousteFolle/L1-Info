#include "utils.h"

int     main(void)
{
    Lamp lamp = createLamp2(1, false);
    isOn(&lamp);
    swap(&lamp);
    isOn(&lamp);

    for (int i = 0; i < 10; i++)
    {
        printColor(&lamp);
        changeColor(&lamp);
    }
    swap(&lamp);
    isOn(&lamp);
    return(0);
}
