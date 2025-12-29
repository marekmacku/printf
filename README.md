# Printf

*This project has been created as part of the 42 curriculum by mmacku*

## Description

The main goal of this project is to recreate the **printf()** function from the C standard library. This implementation provides a custom version of `printf` that supports **ONLY** a **subset** of format specifiers commonly used in C programming.

### Overview

`ft_printf` is a variadic function that formats and prints data according to a format string. It processes format specifiers and converts arguments to their string representations, then outputs them to standard output. The function returns the total number of characters printed, matching the behavior of the standard `printf` function.

### Supported Format Specifiers

- `%c` - Character
- `%s` - String
- `%p` - Pointer address
- `%d` / `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Unsigned hexadecimal integer (lowercase)
- `%X` - Unsigned hexadecimal integer (uppercase)
- `%%` - Percent sign

## Instructions

### Compilation

To compile the project and create the static library `libftprintf.a`:

```bash
make
```

This will compile all source files and create the static library.

### Installation

The library is compiled into `libftprintf.a`. To use it in your p√roject:

1. Include the header file:
```c
#include "ft_printf.h"
```

2. Link the library when compiling:
```bash
gcc your_program.c -L. -lftprintf -o your_program
```

### Execution

Create your own test program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "World", 42);
    return (0);
}
```

### Makefile Targets

- `make` or `make all` - Compiles the library
- `make clean` - Removes object files (.o)
- `make fclean` - Removes object files and the library
- `make re` - Recompiles everything from scratch

## Algorithm and Data Structures

### Algorithm Overview

The implementation follows a **state machine pattern** combined with **variadic argument processing**:

1. **Format String Parsing**: The main `ft_printf` function iterates through the format string character by character.

2. **Format Specifier Detection**: When a `%` character is encountered, the next character is examined to determine the format specifier type.

3. **Argument Processing**: Using `va_list` macros (`va_start`, `va_arg`, `va_end`), arguments are extracted from the variadic argument list based on the format specifier.

4. **Type Conversion**: Each format specifier has a dedicated handler function that:
   - Extracts the appropriate argument type from `va_list`
   - Converts the value to its string representation
   - Writes the result to standard output
   - Returns the number of characters printed

5. **Character Counting**: The function maintains a running count of all characters printed and returns this total.

### Data Structures

The implementation uses the following key data structures:

- **`va_list`**: A type defined in `<stdarg.h>` used to access variadic function arguments. It acts as a pointer to the argument list on the stack.

- **Dynamic String Buffers**: For numeric conversions (integers, hexadecimals), the implementation uses dynamically allocated character arrays created by conversion functions (`ft_itoa`, `ft_utoa`, `ft_ultoa_base`). These buffers are:
  - Allocated with `malloc()`
  - Used to store the converted string representation
  - Freed immediately after printing to prevent memory leaks

### Conversion Algorithm Details

#### Integer to String Conversion (`ft_itoa`)
- **Algorithm**: Repeated division by 10, storing remainders as digits
- **Edge Cases**: Handles zero, negative numbers, and minimum integer value
- **Time Complexity**: O(log₁₀ n) where n is the number
- **Space Complexity**: O(log₁₀ n) for the string buffer

#### Hexadecimal Conversion (`ft_ultoa_base`)
- **Algorithm**: Repeated division by 16, using a lookup table for hex digits
- **Optimization**: Uses a conditional string for uppercase/lowercase hex characters
- **Time Complexity**: O(log₁₆ n)
- **Space Complexity**: O(log₁₆ n)

#### Pointer Conversion
- **Algorithm**: Casts pointer to `unsigned long`, then converts to hexadecimal
- **Special Case**: Handles NULL pointers by printing "0x0"

### Design Choices

1. **Modular Function Design**: Each format specifier has its own handler function, making the code maintainable and easy to extend.

2. **Dynamic Memory Allocation**: Numbers are converted to strings using heap-allocated buffers. While this adds memory management overhead, it allows for clean separation of concerns and handles numbers of any size within type limits.

3. **Direct Write System Calls**: Uses `write()` system call directly instead of buffered I/O, matching the standard `printf` behavior for character counting accuracy.

4. **Return Value Tracking**: Each function returns the number of characters printed, allowing the main function to accurately track and return the total count.

## Resources

### Documentation and References

- [printf(3) - Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C Standard Library - stdarg.h](https://en.cppreference.com/w/c/variadic)
- [Variadic Functions in C](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [Integer to String Conversion Algorithms](https://www.geeksforgeeks.org/convert-integer-to-string-in-c/)

### AI Usage

AI was used in the following aspects of this project:

- **Concepts explanation**: Assisted in understanding variadic function implementation and the proper use of `va_list`, `va_start`, `va_arg`, and `va_end`.
- **Edge Case Handling**: Helped identify edge cases such as NULL pointer handling, zero values to match the original **printf** behavior
- **README**: Installation section & formulation refactoring
