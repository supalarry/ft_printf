/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 09:26:36 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/21 09:26:37 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	size_t			i;
	unsigned char	*content_address;
	unsigned char	*content_copy;
	t_list			*new_node;

	i = -1;
	content_address = (unsigned char *)malloc(content_size);
	content_copy = (unsigned char *)content;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (content != NULL && content_address != NULL && new_node != NULL)
	{
		while (++i < content_size)
			content_address[i] = content_copy[i];
		new_node->content = content_address;
		new_node->content_size = content_size;
	}
	else if (content == NULL && content_address != NULL && new_node != NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	return (new_node);
}
