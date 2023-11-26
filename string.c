#include "test.h"

static char*    init_string(void)
{
    char* s = malloc(sizeof(char) * (12 + 1));
    strcpy(s, "Hello World!");
    return (s);
}

void    test_string(int mode)
{
    if (mode == -1)
        return ;
    char* s = init_string();
    printf("%s\n", s);
}