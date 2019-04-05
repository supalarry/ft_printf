/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:18:06 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/14 13:18:07 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int k;
	int needle_len;
	int haystack_len;

	i = -1;
	j = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle_len == 0)
		return ((char *)haystack);
	while (i++ < (haystack_len - needle_len) && (i + needle_len) <= (int)len)
	{
		k = i;
		while (haystack[k] == needle[j] && haystack[k] != '\0')
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		j = 0;
	}
	return (NULL);
}
