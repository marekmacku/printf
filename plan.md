# Plan for ft_printf Implementation

## 1. **Main Function Structure (ft_printf)**
   - Accept `const char *format` and `...` (variable arguments)
   - Initialize `va_list` with `va_start`
   - Iterate through the format string character by character
   - Track total characters printed
   - Clean up with `va_end`
   - Return total count

## 2. **Parsing Logic**
   - Loop through each character in the format string
   - If character is not '%': write it directly and increment counter
   - If character is '%': check the next character (format specifier)
   - Use a switch statement to handle each specifier

## 3. **Switch Statement Structure**
   - Switch on the character after '%'
   - Cases: 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'
   - Each case calls a corresponding helper function
   - Default case: write '%' and the character (invalid specifier)

## 4. **Helper Functions Needed**

   **a. `ft_print_char` (for %c)**
   - Get char from `va_arg`
   - Write using `write()`
   - Return 1

   **b. `ft_print_string` (for %s)**
   - Get string from `va_arg`
   - Handle NULL case (print "(null)")
   - Write string using `write()`
   - Return length written

   **c. `ft_print_pointer` (for %p)**
   - Get pointer from `va_arg`
   - Convert to hexadecimal (lowercase)
   - Print "0x" prefix
   - Return length

   **d. `ft_print_int` (for %d and %i)**
   - Get int from `va_arg`
   - Convert to string (handle negative numbers)
   - Write string
   - Return length

   **e. `ft_print_unsigned` (for %u)**
   - Get unsigned int from `va_arg`
   - Convert to string
   - Write string
   - Return length

   **f. `ft_print_hex_lower` (for %x)**
   - Get unsigned int from `va_arg`
   - Convert to lowercase hexadecimal
   - Write string
   - Return length

   **g. `ft_print_hex_upper` (for %X)**
   - Get unsigned int from `va_arg`
   - Convert to uppercase hexadecimal
   - Write string
   - Return length

   **h. `ft_print_percent` (for %%)**
   - Write '%' character
   - Return 1

## 5. **Supporting Utility Functions**
   - `ft_itoa` or similar: convert int to string
   - `ft_utoa`: convert unsigned int to string
   - `ft_ultoa_base`: convert unsigned long to hex string (for pointers)
   - `ft_strlen`: calculate string length
   - Helper function to reverse strings (if building digits from right to left)

## 6. **Error Handling**
   - NULL string for %s → print "(null)"
   - NULL pointer for %p → print "0x0" or "(nil)" (match printf behavior)
   - Invalid format specifier → print '%' and the character

## 7. **File Structure**
   - `ft_printf.c`: main function and parsing logic
   - `ft_printf.h`: header with function prototypes
   - Helper functions can be in the same file or separate files

## 8. **Implementation Flow**
   ```
   ft_printf(format, ...)
   ├── Initialize va_list
   ├── Loop through format string
   │   ├── If char != '%': write it
   │   └── If char == '%':
   │       └── Switch on next char:
   │           ├── 'c' → ft_print_char()
   │           ├── 's' → ft_print_string()
   │           ├── 'p' → ft_print_pointer()
   │           ├── 'd' → ft_print_int()
   │           ├── 'i' → ft_print_int()
   │           ├── 'u' → ft_print_unsigned()
   │           ├── 'x' → ft_print_hex_lower()
   │           ├── 'X' → ft_print_hex_upper()
   │           └── '%' → ft_print_percent()
   ├── Clean up va_list
   └── Return total count
   ```

## 9. **Key Considerations**
   - All helper functions should return the number of characters written
   - Accumulate return values in the main function
   - Use `write(1, ...)` for output (file descriptor 1 = stdout)
   - For number conversions, build the string in reverse or use a buffer
   - Handle edge cases: 0, negative numbers, maximum values

