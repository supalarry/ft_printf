/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 12:18:39 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/14 12:18:40 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	target;
	char	*target_address;

	i = 0;
	target = c;
	target_address = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == target)
		{
			target_address = (char *)s + i;
		}
		i++;
	}
	if (target == '\0')
	{
		return ((char *)s + i);
	}
	return (target_address);
}
