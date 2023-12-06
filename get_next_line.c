/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:16:47 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/06 17:06:36 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *str)
{
	char	*buf;
	ssize_t	rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	rd = BUFFER_SIZE;
	while (!ft_strchr(str, '\n') && rd == BUFFER_SIZE)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[rd] = 0;
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (*str == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_getline(char *str, size_t target)
{
	size_t	i;
	char	*line;

	line = malloc(sizeof(char) * (target + 1));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	line[target] = 0;
	while (i < target)
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

char	*ft_update(char *str, size_t target)
{
	char	*temp;

	temp = str;
	str += target;
	str = ft_strdup(str);
	if (!str)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	size_t		target;

	if (!ft_strchr(str, '\n'))
	{
		str = ft_readfile(fd, str);
		if (!str)
			return (NULL);
	}
	target = 0;
	while (str[target + 1] && str[target] != '\n')
		target++;
	line = ft_getline(str, target + 1);
	if (!line)
	{
		str = NULL;
		return (NULL);
	}
	str = ft_update(str, target + 1);
	if (!str)
	{
		free (line);
		return (NULL);
	}
	return (line);
}
