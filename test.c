#include "test.h"

int main()
{
    test_malloc(-1);
    test_free(-1);
    test_realloc(-1);
    test_string(0);
    return (0);
}