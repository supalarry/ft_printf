/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:34:54 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 13:34:56 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t			i;
	unsigned char	*ft_s1;
	unsigned char	*ft_s2;

	if (s1 != NULL && s2 != NULL)
	{
		ft_s1 = (unsigned char *)s1;
		ft_s2 = (unsigned char *)s2;
		i = 0;
		while (ft_s1[i] == ft_s2[i] && ft_s1[i] != '\0' && ft_s2[i] != '\0')
		{
			i++;
		}
		if (ft_s1[i] - ft_s2[i] == 0)
			return (1);
	}
	return (0);
}
