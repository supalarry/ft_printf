/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:48:21 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 15:48:22 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str(char const *s)
{
	int		i;
	int		b;
	int		e;
	char	*strtrim;

	i = 0;
	b = 0;
	e = ft_strlen(s) - 1;
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && s[b] != '\0')
		b++;
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && s[b] != '\0')
		e--;
	strtrim = (char *)malloc(e - b + 1 + 1);
	if (strtrim != NULL && s[b] != '\0')
	{
		while (b <= e)
		{
			strtrim[i] = s[b];
			i++;
			b++;
		}
		strtrim[i] = '\0';
	}
	return (strtrim);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*strtrim;

	i = 0;
	strtrim = NULL;
	if (s != NULL)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i++;
		}
		if (s[i] == '\0')
		{
			strtrim = (char *)malloc(1);
			strtrim[0] = 0;
			return (strtrim);
		}
		strtrim = ft_str(s);
	}
	return (strtrim);
}
