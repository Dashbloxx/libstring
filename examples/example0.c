#include <stdio.h>

#include "../source/string.h"

int main()
{
    string_t string;
    string_create(&string);
    string_setf(&string, "Hello, world!\nHere's a number: %d\n", 12345);
    printf("%s", string.pointer);
    string_destroy(&string);
    return 0;
}