# ft_printf
Reproduce C's printf function.
# usage
Run "make", which results in library called libftprintf.a. In your source file, use ft_printf() function just as you would use printf().
Furthermore, compile your source code with libftprintf.a to use ft_printf() function.

ft_printf() handles c,s,p,d,i,o,u,x,X conversion characters. Furthermore, it supports multibyte characters. For multibyte character
use C and for multibyte string S conversion characters. For multibyte characters, argument must have L in front of it indicating that it consists of wide characters.
Additionally, flags (#,0,-,+ and space), length specifiers (l, L, hh, h, l, ll) and field width are supported.
Function returns bytes written to standard output.
