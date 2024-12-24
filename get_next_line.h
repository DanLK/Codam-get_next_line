/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/19 12:39:42 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/24 13:43:14 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 28

# endif

#include <stdlib.h>

// typedef struct chunk
// {
// 	char			*content;
// 	struct chunk	*next;
// }		t_node;


char	*find_line_(int fd, char *read_buff, char *stash);

char	*find_line_cpy(int fd, char *read_buff, char *stash);

char	*set_stash_(char *line_buff);

char	*get_next_line_(int fd);

// Utils

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif