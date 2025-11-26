#include "utils.h"

int     main(void)
{
    Lamp lamp = createLamp2(3, true);
    isOn(&lamp);
    swap(&lamp);
    isOn(&lamp);
    return(0);
}
