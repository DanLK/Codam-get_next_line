/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/26 19:15:06 by dloustalot    #+#    #+#                 */
/*   Updated: 2024/12/28 19:39:21 by dloustalot    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 28

# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	read_to_list(int fd, t_list **stash);

char	*get_line(t_list *stash);

void	copy_line(t_list *stash, char *line);

void	set_list(t_list **stash);

// Utils

t_list	*ft_lstnew(char *content);

void	ft_lstadd_back(t_list **lst, t_list *new_node);

int		find_char(t_list *node, char c);

t_list	*ft_lstlast(t_list *lst);

void	clear_list(t_list **stash, t_list *node, char *content);

#endif