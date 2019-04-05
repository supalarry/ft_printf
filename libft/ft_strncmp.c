/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 14:51:58 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/14 14:52:00 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f1;
	unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (f1[i] == f2[i] && f1[i] != '\0' && f2[i] != '\0' && i < n)
	{
		if (i + 1 == n)
			return (f1[i] - f2[i]);
		i++;
	}
	return (f1[i] - f2[i]);
}
