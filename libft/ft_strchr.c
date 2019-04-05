/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:23:38 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/14 11:23:40 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	target;

	i = 0;
	target = c;
	while (s[i] != '\0')
	{
		if (s[i] == target)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (target == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}
