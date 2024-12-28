/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/26 21:53:10 by dloustalot    #+#    #+#                 */
/*   Updated: 2024/12/28 19:39:05 by dloustalot    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (new);
	new->content = (char *)content;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_node;
}

int	find_char(t_list *node, char c)
{
	int	i;
	int	count;

	count = 1;
	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == c)
				return (count);
			i++;
			count++;
		}
		node = node->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	clear_list(t_list **stash, t_list *node, char *content)
{
	t_list	*to_clear;
	t_list	*temp;

	if (stash == NULL)
		return ;
	to_clear = *stash;
	while (to_clear)
	{
		temp = to_clear->next;
		free(to_clear->content);
		free(to_clear);
		to_clear = temp;
	}
	if (node->content[0])
		*stash = node;
	else
	{
		free(node);
		free(content);
	}
}
