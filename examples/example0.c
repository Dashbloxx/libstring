#include <stdio.h>

#include "../source/string.h"

int main()
{
    string_t string;
    string_create(&string);
    string_appendf(&string, "Hello, world!\nHere's a number: %d\n", 12345);
    string_appendf(&string, "Here's a hexadecimal number: %x\n", 0xBEEF);
    puts(string.pointer);
    string_destroy(&string);
    return 0;
}