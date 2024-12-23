/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/20 10:20:07 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/23 12:11:46 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*find_line(int fd, char *read_buff, char *stash)
{
	ssize_t	result;
	char	*line;

	if (ft_strlen(stash) != 0)
	{
		if (ft_strchr(stash, '\n'))
			return (ft_strdup(stash));
		line = ft_strdup(stash);
	}
	else
		line = "";
	result = read(fd, read_buff, BUFFER_SIZE);
	while (result > 0 && !ft_strchr(read_buff, '\n'))
	{
		line = ft_strjoin(line, read_buff);
		result = read(fd, read_buff, BUFFER_SIZE);
	}
	line = ft_strjoin(line, read_buff);
	return (line);
}

char	*set_stash(char *line_buff)
{
	int		i;
	char	*stash;

	while(line_buff[i] != '\n' && line_buff[i])
		i++;
	stash = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i + 1);
	line_buff[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*read_buff;
	char		*line_buff;
	static char	*stash = "";

	if (fd == -1)
		return (NULL);
	read_buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!read_buff)
		return (NULL);
	line_buff = find_line(fd, read_buff, stash);
	free(read_buff);
	stash = set_stash(line_buff);
	printf("Stash: %s\n", stash);
	return (line_buff);
}
