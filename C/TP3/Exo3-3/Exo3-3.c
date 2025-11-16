#include <stdbool.h>
void logic(bool a, bool b, bool *and, bool *or, bool *xor)
{
    *and = (a && b);
    *or  = (a || b);
    *xor = (a != b);
}
