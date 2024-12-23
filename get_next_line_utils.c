/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/23 10:43:52 by dloustal      #+#    #+#                 */
/*   Updated: 2024/12/23 11:17:46 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*dup;
	int		i;

	i = 0;
	slen = ft_strlen(s);
	dup = (char *)malloc((slen + 1) * sizeof(char));
	if (!dup)
		return (dup);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			len_src;

	len_src = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (len_src < size - 1 && src[len_src])
	{
		dst[len_src] = src[len_src];
		len_src++;
	}
	dst[len_src] = '\0';
	while (src[len_src])
		len_src++;
	return (len_src);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	index_src;

	len_dest = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	if (len_dest >= size)
		return (size + len_src);
	index_src = 0;
	while (src[index_src] && (index_src + len_dest + 1) < size)
	{
		dst[len_dest + index_src] = src[index_src];
		index_src++;
	}
	dst[len_dest + index_src] = '\0';
	return (len_dest + len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!result)
		return (result);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcat(result, s2, len_s1 + len_s2 + 1);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (subs);
	while (i < len && len > 0)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}