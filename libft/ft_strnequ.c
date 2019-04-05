/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:37:11 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 13:37:12 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*f1;
	unsigned char	*f2;

	if (n == 0)
	{
		return (1);
	}
	if (s1 != NULL && s2 != NULL)
	{
		f1 = (unsigned char *)s1;
		f2 = (unsigned char *)s2;
		i = 0;
		while (f1[i] == f2[i] && f1[i] != '\0' && f2[i] != '\0' && i < n)
		{
			if (i + 1 == n && (f1[i] - f2[i]) == 0)
				return (1);
			else if (i + 1 == n && (f1[i] - f2[i]) != 0)
				return (0);
			i++;
		}
		if (f1[i] - f2[i] == 0)
			return (1);
	}
	return (0);
}
