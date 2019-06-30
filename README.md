# ft_printf
ft_printf is reproduced C's printf function.

## Getting Started

Run **make**, which results in library called libftprintf.a. In your source file, use ft_printf() function just as you would use printf(). Furthermore, compile your source code with libftprintf.a to use ft_printf() function.

```
gcc main.c libftprintf.a
```
## Functionality
ft_printf acts just like printf with following conversion characters
```
%c (character)
%s (string)
%p (address)
%d (digit)
%i (integer)
%o (digit in octal)
%u (unsigned integer)
%x (hexadecimal in lowercase)
%X (hexadecimal in upper case)
```
Furthermore, it supports multibyte characters. For multibyte character argument must have L in front of it indicating that it consists of wide characters. If multibyte character or string are printed, their respective conversion character has to be in capital. For example, to print '→' character, %c becomes %C.
```
ft_printf("%C", L'→');
```

Additionally, flags (#,0,-,+ and space), length specifiers (l, L, hh, h, l, ll) and field width are supported.
Function returns bytes written to standard output.

![alt text](https://i.imgur.com/lyVmuHf.png)
![alt text](https://i.imgur.com/pFlynR9.png)
