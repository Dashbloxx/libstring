#pragma once

typedef struct
{
    unsigned long size;
    char * pointer;
} string_t;

int string_create(string_t * string);
int string_destroy(string_t * string);
int string_append(string_t * string0, char * string1);
int string_appendf(string_t *string, char *format, ...);
int string_setf(string_t * string, char * format, ...);