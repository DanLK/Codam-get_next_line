/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/20 10:20:07 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/24 13:43:16 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*find_line_cpy(int fd, char *read_buff, char *stash)
{
	ssize_t	result;
	char	*tmp_line;

	result = 1;
	while (result > 0)
	{
		result = read(fd, read_buff, BUFFER_SIZE);
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
/* Reads and writes on the buffer until it sees a \n 
It returns the stash with the new content written
-
- The read content (plus the contents of the stash) is 
stored in a temporary variable that can later be freed
- It always reads content, if possible */
char *find_line(int fd, char *read_buff, char *stash)
{
	ssize_t	result;
	char	*tmp_line;

	result = 1;
	while (result > 0)
	{
		result = read(fd, read_buff, BUFFER_SIZE);
		if (result == -1)
		{
			free(tmp_line);
			tmp_line = NULL;
			return (NULL);
		}
		else if (result == 0)
			break ;
		read_buff[result] = '\0';
		tmp_line = ft_strdup(stash);
		stash = ft_strjoin(tmp_line, read_buff);
		free(tmp_line);
		tmp_line = NULL;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

/* The read buffer will read BUFFER_SIZE characters, and will terminate the string,
to properly join it with the stash */
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
	printf("Line buff: %s\n", line_buff);
	printf("Stash: %s\n", stash);
	free(read_buff);
	read_buff = NULL;
	if (!line_buff)
	{
		free(line_buff);
		return (NULL);
	}
	stash = set_stash(line_buff);
	return (line_buff);
}
