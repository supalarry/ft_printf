/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 14:46:07 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/14 14:46:08 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ft_s1;
	unsigned char	*ft_s2;

	ft_s1 = (unsigned char *)s1;
	ft_s2 = (unsigned char *)s2;
	i = 0;
	while (ft_s1[i] == ft_s2[i] && ft_s1[i] != '\0' && ft_s2[i] != '\0')
	{
		i++;
	}
	return (ft_s1[i] - ft_s2[i]);
}
