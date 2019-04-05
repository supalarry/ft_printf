/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 15:15:16 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/21 15:15:17 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;
	t_list *head_next;

	head = *alst;
	while (head != NULL)
	{
		head_next = head->next;
		del(head->content, head->content_size);
		free(head);
		head = head_next;
	}
	*alst = NULL;
}
