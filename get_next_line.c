/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/20 10:20:07 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/23 17:36:26 by dloustal      ########   odam.nl         */
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

	if (!stash)
		return (NULL);
	if (ft_strlen(stash) != 0)
	{
		if (ft_strchr(stash, '\n'))
			return (ft_strdup(stash));
		line = ft_strdup(stash);
	}
	else
		line = ft_strdup("");
	result = 1;
	while (result > 0)
	{
		result = read(fd, read_buff, BUFFER_SIZE);
		if (result == -1)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		else if (result == 0)
			break ;
		read_buff[result] = '\0';
		line = ft_strjoin(line, read_buff);
		if (ft_strchr(line, '\n'))
		break ; 
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*find_line_cpy(int fd, char *read_buff, char *stash)
{
	ssize_t	result;
	char	*tmp_line;

	result = 1;
	while (result > 0)
	{
		result = read(fd, read_buff, BUFFER_SIZE + 1);
		if (result == -1)
		{
			free(tmp_line);
			return(NULL);
		}
		else if (result == 0)
			break ;
		read_buff[result] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp_line = stash;
		stash = ft_strjoin(tmp_line, read_buff);
		free(tmp_line);
		tmp_line = NULL;
		if (ft_strchr(stash, '\n'))
		break ;
	}
	return (stash);
}

char	*set_stash(char *line_buff)
{
	int		i;
	char	*stash;
	int		stash_len;

	i = 0;
	if (!line_buff)
		return (NULL);
	while(line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	stash_len = ft_strlen(line_buff) - i;
	stash = ft_substr(line_buff, i + 1, stash_len);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line_buff[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*read_buff;
	char		*line_buff;
	static char	*stash = "";

	if (fd < -1 || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	read_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buff)
		return (NULL);
	line_buff = find_line(fd, read_buff, stash);
	free(read_buff);
	read_buff = NULL;
	if (!line_buff)
	{
		free(line_buff);
		free(stash); //?? Do I need this?
		return (NULL);
	}
	stash = set_stash(line_buff);
	return (line_buff);
}
