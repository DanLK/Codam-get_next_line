/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/24 13:22:01 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/24 14:24:28 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*find_line_(int fd, char *read_buff, char *stash);
char	*set_stash_(char *line_buff);

char	*get_next_line_(int fd)
{
	char		*read_buff;
	char		*line_buff;
	static char	*stash;

	if (fd == -1 || BUFFER_SIZE == 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	read_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buff)
		return (NULL);
	line_buff = find_line_(fd, read_buff, stash);
	free(read_buff);
	read_buff = NULL;
	if (!line_buff)
	{
		free(line_buff);
		return (NULL);
	}
	stash = set_stash_(line_buff);
	return (line_buff);
}

char	*find_line_(int fd, char *read_buff, char *stash)
{
	ssize_t	result;
	char	*tmpline;

	result = 1;
	while (result > 0)
	{
		result = read(fd, read_buff, BUFFER_SIZE);
		if (result == -1)
		{
			free(tmpline);
			tmpline = NULL;
			return (NULL);
		}
		if (result == 0)
			break ;
		read_buff[result] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmpline = ft_strdup(stash);
		stash = ft_strjoin(tmpline, read_buff);
		free(tmpline);
		tmpline = NULL;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*set_stash_(char *line_buff)
{
	int		i;
	char	*stash;

	// finished
	if (ft_strlen(line_buff) == 0)
		return (NULL);
	//if theres still something in the stash
	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	stash = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	line_buff[i + 1] = '\0';
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (stash);
}
