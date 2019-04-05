/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wchar.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 09:52:04 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/04 09:52:06 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Write 3 and 4 byte characters
** @param unsigned int c - character in decimal for writing
** @return 3 if 3 byte character was written
** @return 4 if 4 byte character was written
** @return 0 if character is not UTF - 8
*/

static int	ft_wchar_big(unsigned int c)
{
	unsigned char letter[4];

	if (c >= 0x800 && c <= 0xFFFF)
	{
		letter[0] = ((c & 0x3F000) >> 12) | 0xE0;
		letter[1] = ((c & 0xFC0) >> 6) | 0x80;
		letter[2] = (c & 0x3F) | 0x80;
		write(1, letter, 3);
		return (3);
	}
	else if (c >= 0x10000 && c <= 0x10FFFF)
	{
		letter[0] = ((c & 0x1C0000) >> 18) | 0xF0;
		letter[1] = ((c & 0x3F000) >> 12) | 0x80;
		letter[2] = ((c & 0xFC0) >> 6) | 0x80;
		letter[3] = (c & 0x3F) | 0x80;
		write(1, letter, 4);
		return (4);
	}
	return (0);
}

/*
** @desc Write 1 and 2 byte characters
** @param t_node *node - structure of a conversion specifier
** @param unsigned int c - character in decimal for writing
** @return 1 if 1 byte character was written
** @return 2 if 2 byte character was written
** @return 3 or 4 based on calling ft_char_big
*/

int			ft_wchar(t_node *node, unsigned int c)
{
	unsigned char letter[4];

	if ((c > 0x0 && c <= 0x7F) || (node->conversion_specifier == 'c'
	&& ft_strcmp("l", node->length) != 0))
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c >= 0x80 && c <= 0x7FF)
	{
		letter[0] = ((c & 0xFC0) >> 6) | 0xC0;
		letter[1] = (c & 0x3F) | 0x80;
		write(1, letter, 2);
		return (2);
	}
	else if (c > 0x7FF)
		return (ft_wchar_big(c));
	else
	{
		write(1, &c, 1);
		return (1);
	}
}

/*
** @desc Write 1 and 2 byte characters
** @param t_node *node - structure of a conversion specifier
** @param const wchar_t *s1 - multibyte string
** @param int wlen - count of characters to output
** @return size - size in bytes of printed characters
*/

int			ft_wchar_putnstr(t_node *node, const wchar_t *s1, int wlen)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s1 != NULL && i < wlen)
	{
		size = size + ft_wchar(node, s1[i]);
		i++;
	}
	return (size);
}

/*
** @desc Determine size of whole multibyte string
** @param wchar_t *s1 - multibyte string
** @return size - size in bytes of multibyte string
*/

size_t		ft_wchar_bytes(wchar_t *s)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] > 0x0 && s[i] <= 0x7F)
				size = size + 1;
			else if (s[i] >= 0x80 && s[i] <= 0x7FF)
				size = size + 2;
			else if (s[i] >= 0x800 && s[i] <= 0xFFFF)
				size = size + 3;
			else if (s[i] >= 0x10000 && s[i] <= 0x10FFFF)
				size = size + 4;
			i++;
		}
	}
	return (size);
}

/*
** @desc Return size in bytes of a character
** @param wchar_t c - multibyte character
** @return 1 to 4 based on the size of the character
*/

size_t		ft_wchar_size(wchar_t c)
{
	if (c > 0x0 && c <= 0x7F)
		return (1);
	else if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if (c >= 0x800 && c <= 0xFFFF)
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	return (0);
}
