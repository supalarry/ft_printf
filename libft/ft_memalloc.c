/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 09:36:08 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 09:36:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*memory;
	char	*memory_copy;

	i = 0;
	memory = malloc(size);
	if (memory != NULL)
	{
		memory_copy = (char *)memory;
		while (i < size)
		{
			memory_copy[i] = 0;
			i++;
		}
	}
	return (memory);
}
