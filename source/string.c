#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "string.h"

int string_create(string_t * string)
{
    if(string == NULL)
    {
        return -1;
    }

    string->size = 0;
    string->pointer = NULL;

    return 0;
}

int string_destroy(string_t * string)
{
    if(string == NULL)
    {
        return -1;
    }

    string->size = 0;

    if(string->pointer != NULL)
    {
        free(string->pointer);
        return 0;
    }

    return 1;
}

int string_append(string_t * string0, char * string1)
{
    if(string0 == NULL)
    {
        return -2;
    }

    size_t length = strlen(string1);

    size_t newsize = string0->size + length + 1;

    char * newptr = (char *)realloc(string0->pointer, newsize);

    if(newptr == NULL)
    {
        return -1;
    }

    strcpy(newptr + string0->size, string1);
    string0->pointer = newptr;
    string0->size = newsize - 1;

    return 0;
}


int string_appendf(string_t * string, char * format, ...)
{
    if(string == NULL || format == NULL)
    {
        return -3;
    }

    va_list args;
    va_start(args, format);

    int length = vsnprintf(NULL, 0, format, args) + 1;

    va_end(args);

    if(length <= 0)
    {
        return -4;
    }

    va_start(args, format);

    char * formatted_string = (char *)malloc(length * sizeof(char));

    if(formatted_string == NULL)
    {
        va_end(args);
        return -4;
    }

    vsnprintf(formatted_string, length, format, args);

    va_end(args);

    int result = string_append(string, formatted_string);
    free(formatted_string);

    return result;
}

int string_setf(string_t * string, char * format, ...)
{
    if(string == NULL || format == NULL)
    {
        return -2;
    }

    va_list args;
    va_start(args, format);

    int length = vsnprintf(NULL, 0, format, args) + 1;

    va_end(args);

    if(length <= 0)
    {
        return -1;
    }

    va_start(args, format);

    char * formattedstring = (char *)malloc(length * sizeof(char));

    if(formattedstring == NULL)
    {
        va_end(args);
        return -1;
    }

    vsnprintf(formattedstring, length, format, args);

    va_end(args);

    if(string->pointer != NULL)
    {
        free(string->pointer);
    }

    string->size = length - 1;
    string->pointer = formattedstring;

    return 0;
}