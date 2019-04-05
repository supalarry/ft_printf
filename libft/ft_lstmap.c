/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 17:25:56 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/22 17:25:58 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new_head;
	t_list *new_node;

	head = NULL;
	new_node = NULL;
	new_head = NULL;
	if (lst != NULL)
	{
		head = lst;
		new_node = f(head);
		new_head = new_node;
		head = head->next;
		while (head != NULL)
		{
			new_node->next = f(head);
			head = head->next;
			new_node = new_node->next;
		}
	}
	return (new_head);
}
