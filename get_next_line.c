/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/20 10:20:07 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/20 12:41:59 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			r_result;
	static t_node	stash;

	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	r_result = read(fd, buffer, BUFFER_SIZE - 1);
	if ((int)r_result == BUFFER_SIZE - 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		return (buffer);
	}
	free(buffer);
	return (NULL);
}
