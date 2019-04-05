/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:23:16 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 15:23:17 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strjoin;

	i = -1;
	j = 0;
	if (s1 != NULL && s2 != NULL)
		strjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		strjoin = NULL;
	if (s1 != NULL && s2 != NULL && strjoin != NULL)
	{
		while (s1[++i] != '\0')
		{
			strjoin[i] = s1[i];
		}
		while (s2[j] != '\0')
		{
			strjoin[i] = s2[j];
			i++;
			j++;
		}
		strjoin[i] = '\0';
	}
	return (strjoin);
}
