/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 21:18:10 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/12 21:18:11 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h" 

/*
** @desc Create a new node for specific conversion
** @desc and call functions to get info about it
** @param const char *format - string parameter in ft_printf
** @param int *i - address of index of character after %
** @return t_node *new_node - address of node for conversion
** @return NULL if some format specification is invalid
*/

t_node		*ft_origin_node(const char *format, int *i, va_list ap)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->format = format;
	new_node->field_width = -3;
	new_node->next = NULL;
	new_node->error = 0;
	if (!ft_flags(new_node, format, i, ap))
		return (new_node);
	if (!ft_field_width(new_node, ap, i, 0))
		return (new_node);
	if (!ft_precision(new_node, ap, i, 0))
		return (new_node);
	if (!ft_length(new_node, format, i, 0))
		return (new_node);
	if (!ft_conversion_specifier(new_node, format, i))
		return (new_node);
	return (new_node);
}

/*
** @desc Add a node for a specific conversion at end of linked list
** @param t_node *head - start of linked list
** @param const char *format - string parameter in ft_printf
** @param int *i - address of index of character after %. Send to ft_origin_node
** @return 1 if format specifier was valid and new node was appened to list
** @return 0 if format specifier was invalid and new node was not appended
*/

int			ft_add_node(t_node *head, const char *format, int *i, va_list ap)
{
	while (head->next != NULL)
		head = head->next;
	head->next = ft_origin_node(format, i, ap);
	if (head->next != NULL)
		return (1);
	return (0);
}

/*
** @desc Iterate over input string and find %'s to store information about them
** @param const char *format - string parameter in ft_printf
** @return t_node  *head - head of linked list with nodes about all conversions
** @return NULL if one of the conversions requested was invalid
*/

t_node		*ft_extract(const char *format, va_list ap)
{
	int		i;
	t_node	*head;

	i = 0;
	head = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (head == NULL)
			{
				head = ft_origin_node(format, &i, ap);
				if (head == NULL)
					return (NULL);
			}
			else
			{
				if (!ft_add_node(head, format, &i, ap))
					return (NULL);
			}
		}
		i++;
	}
	return (head);
}

/*
** @desc Free linked list of conversion specifiers
** @param t_node *head - start of linked list
** @return void
*/

void		ft_free_list(t_node *head)
{
	t_node *head_copy;

	while (head != NULL)
	{
		head_copy = head;
		head = head->next;
		free(head_copy);
	}
}
