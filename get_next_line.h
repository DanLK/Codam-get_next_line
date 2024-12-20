/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/19 12:39:42 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/20 10:58:10 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 28

# endif

typedef struct chunk
{
	char			*content;
	struct chunk	*next;
}		t_node;

char	*get_next_line(int fd);

#endif