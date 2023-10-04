/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:16:47 by nappalav          #+#    #+#             */
/*   Updated: 2023/10/04 22:27:24 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *str)
{
	char	*temp;
	char	*buf;
	size_t	nbyte;
	ssize_t	rd;

	nbyte = BUFFER_SIZE;
	buf = malloc(sizeof(char) * (nbyte + 1));
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	while (!ft_strchr(str, '\n'))
	{
		rd = read(fd, buf, nbyte);
		if (rd <= 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[rd] = 0;
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free(temp);
			free(buf);
			return (NULL);
		}
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

	if (fd <= 0)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (NULL);
	*str = 0;
	if (!ft_strchr(str, '\n'))
	{
		str = ft_readfile(fd, str);
		if (!str)
			return (NULL);
	}
	target = 0;
	while (str[target])
	{
		if (str[target] == '\n')
			break;
		target++;
	}
	line = ft_getline(str, target);
	str = ft_update(str, target);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open ("test1", O_RDONLY);
	str = get_next_line(fd);
	printf("line = %s <<END>>\n", str);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		printf("line = %s <<END>>\n", str);
	}
	return (0);
}
