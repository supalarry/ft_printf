/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:08:20 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 15:08:22 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strsub;
	int		state;

	i = 0;
	strsub = (char *)malloc(len + 1);
	state = 0;
	if (s != NULL)
	{
		if (strsub != NULL)
		{
			while (i < len)
			{
				strsub[i] = s[start];
				if (strsub[i] == '\0')
					state = 1;
				i++;
				start++;
			}
			if (state != 1)
				strsub[i] = '\0';
		}
	}
	return (strsub);
}
