## libstring
## About
The `libstring` library is a new C library meant to implement dynamic strings for C programmers that just want to program faster, and worry less about having memory corruption with their strings.
It's features include support for formatting, such as:
```c
string_t string;
string_create(&string);
string_setf(&string, "Hello, world!\nHere's a number: %d\n", 12345);
puts(string->pointer);
string_destroy(&string);
```
Or if you want to append text, like:
```c
string_t string;
string_create(&string);
string_appendf(&string, "Hello, world!\nHere's a number: %d\n", 12345);
string_appendf(&string, "Here's a hexadecimal number: %x\n", 0xBEEF);
puts(string.pointer);
string_destroy(&string);
```
Support for many more features are coming, and dynamic arrays are also expected to be implemented in this library soon.
## Building
To build this library, you'll need some sort of program that can execute `Makefile` scripts. You can use GNU Make or BSD Make in order to achieve this, by running:
```sh
make
```
Of course, make sure that you have one of the two programs installed. Support for `CMake` is coming soon, for the Windows users.
## Installing
Due to this library still being experimental, there's no `make install` or `make uninstall`. Soon however, this will be implemented.