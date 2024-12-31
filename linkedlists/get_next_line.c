/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/26 19:17:57 by dloustalot    #+#    #+#                 */
/*   Updated: 2024/12/31 17:02:54 by dloustalot    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	read_to_list(int fd, t_list **stash);
char	*get_current_line(t_list *stash);
void	copy_line(t_list *stash, char *line);
void	set_list(t_list **stash);

/* Reads from the file, puts it in a list until it finds a \n
and then extracts the line, and cleans the list */
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 /* || read(fd, NULL, 0) < 0 */)
		return (NULL);
	// if (stash == NULL)
	// {
	// 	char *str = malloc(1);
	// 	if (str == NULL)
	// 		return (NULL);
	// 	*str = '\0';
	// 	stash = ft_lstnew(str);
	// 	if (stash == NULL)
	// 		return (free(str), NULL);
	// }
	read_to_list(fd, &stash);
	if (!stash)
		return (NULL);
	line = get_current_line(stash);
	if (line == NULL)
		return (clear_list(&stash, NULL, NULL), NULL);
	set_list(&stash);
	return (line);
}

/* Reads from the file until it sees a \n
and stores every "iteration" of read on a node of the list  */
void	read_to_list(int fd, t_list **stash)
{
	ssize_t		result;
	t_list		*new_node;
	char		*buffer;

	if (stash == NULL)
		return ;
	while (!find_new_line(*stash, 'f'))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (clear_list(stash, NULL, NULL));
		result = read(fd, buffer, BUFFER_SIZE);
		if (result <= 0)
		{
			free(buffer);
			if (result < 0)
				clear_list(stash, NULL, NULL);
			return ;
		}
		buffer[result] = '\0';
		new_node = ft_lstnew(buffer);
		if (!new_node)
			return (clear_list(stash, NULL, buffer));
		ft_lstadd_back(stash, new_node);
	}
}

/* Reads the list and returns the contents until it finds a \n */
char	*get_current_line(t_list *stash)
{
	char	*line;
	int		line_len;

/* 	if (!stash)
		return (NULL); */
	line_len = find_new_line(stash, 'c');
	line = (char *)malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	copy_line(stash, line);
	return (line);
}

/* Copies the contents of the list up to \n into the line */
void	copy_line(t_list *stash, char *line)
{
	int	i;
	int	j;

	if (!stash || !line)
		return ;
	i = 0;
	while (stash)
	{
		j = 0;
		while (stash->content[j])
		{
			line[i++] = stash->content[j];
			if (stash->content[j] == '\n')
			{
				line[i] = '\0';
				return ;
			}
			j++;
		}
		stash = stash->next;
	}
	line[i] = '\0';
}

/* Clears the list and keeps only the node with relevant content */
void	set_list(t_list **stash)
{
	t_list	*new_node;
	t_list	*last_node;
	char	*content;
	int		i;
	int		j;

	new_node = (t_list *)malloc(sizeof(t_list));
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_node || !content)
		return (free(new_node), free(content), clear_list(stash, NULL, NULL));
	last_node = ft_lstlast(*stash);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content[i] == '\n')
		i++;
	while (last_node->content[i])
		content[j++] = last_node->content[i++];
	content[j] = '\0';
	new_node->content = content;
	new_node->next = NULL;
	clear_list(stash, new_node, content);
}
