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

    string0->size += strlen(string1);
    string0->pointer = realloc(string0->pointer, string0->size);

    if(string0->size != 0 && string0->pointer == NULL)
    {
        return -1;
    }

    return 0;
}

int string_appendf(string_t * string, char * format, ...)
{
    if (string == NULL || format == NULL)
    {
        return -3;
    }

    va_list args;
    va_start(args, format);

    int length = vsnprintf(NULL, 0, format, args);
    
    char * formatted_string = (char *)malloc((length + 1) * sizeof(char));
    
    if (formatted_string == NULL)
    {
        va_end(args);
        return -4;
    }

    vsnprintf(formatted_string, length + 1, format, args);
    
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

    int length = vsnprintf(NULL, 0, format, args);
    
    char *formatted_str = (char *)malloc((length + 1) * sizeof(char)); 
    
    if(formatted_str == NULL)
    {
        va_end(args);
        return -1;
    }

    vsnprintf(formatted_str, length + 1, format, args);
    
    va_end(args);

    if(string->pointer != NULL)
    {
        free(string->pointer);
    }

    string->size = length;
    string->pointer = formatted_str;

    return 0;
}