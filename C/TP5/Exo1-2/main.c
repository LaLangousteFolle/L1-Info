#include "utils.h"

int     main(void)
{
    Lamp lamp1 = createLamp(true);
    isOn(&lamp1);
    return(0);
}
