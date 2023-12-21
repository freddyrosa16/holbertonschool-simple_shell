# Custom __printf__ function
The  custom `_printf()` function produces an output according to the format given by the user. The function writes output to the stdout, the standard output stream. Depending on the format that specifies which function to perform.

### Format of the format string
The format string starts with the character `%` followed by a function specifier.  The arguments must correspond to the conversion specifier. The function also prints string literals.

### Conversion Specifiers
**d**, **i** - 
The `int` specifier returns integers to the standard output. The default percision is 1.

**c** - The `char` specifier retqunrs a character to the standard output.

**s** - The `string` specifier returns a given array of characters to the standard output.
## Overview
### Compilation
|$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c|
|---|
### Authorized functions and macros
 - `write` (man 2 write)
 - `malloc` (man 3 malloc)
 - `free` (man 3 free)
 - `va_start` (man 3 va_start)
 - `va_end` (man 3 va_end)
 - `va_copy` (man 3 va_copy)
 - `va_arg` (man 3 va_arg)

### Defined Macros
 - **UNUSED**
 - **BUFF_SIZE**
 - **F_MINUS**
 - **F_PLUS**
 - **F_ZERO**
 - **F_HASH**
 - **F_SPACE**
 - **S_LONG**
 - **S_SHORT**

### Functions in Header
 - int `_printf`(const char *format, ...);
 - int `handle_print`(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);
 - int `print_char`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_string`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_percent`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_int`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_binary`(va_list types, char buffer[],	int flags, int width, int precision, int size);
 - int `print_unsigned`(va_list types, char buffer[],	int flags, int width, int precision, int size);
 - int `print_octal`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_hexadecimal`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_hexa_upper`(va_list types, char buffer[],	int flags, int width, int precision, int size);
 - int `print_hexa`(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
 - int `print_non_printable`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_pointer`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `get_flags`(const char *format, int *i);
 - int `get_width`(const char *format, int *i, va_list list);
 - int `get_precision`(const char *format, int *i, va_list list);
 - int `get_size`(const char *format, int *i);
 - int `print_reverse`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `print_rot13string`(va_list types, char buffer[], int flags, int width, int precision, int size);
 - int `handle_write_char`(char c, char buffer[], int flags, int width, int precision, int size);
 - int `write_number`(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
 - int `write_num`(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
 - int `write_pointer`(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
 - int `write_unsgnd`(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
 - int `is_printable`(char);
 - int `append_hexa_code`(char, char[], int);
 - int `is_digit`(char);
 - long int `convert_size_number`(long int num, int size);
 - long int `convert_size_unsgnd`(unsigned long int num, int size);

## Authors
#### Freddy Rosa
#### Angelo Garcia