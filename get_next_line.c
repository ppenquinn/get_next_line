/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:16:47 by nappalav          #+#    #+#             */
/*   Updated: 2023/09/30 13:35:37 by nappalav         ###   ########.fr       */
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
		return (NULL);
	buf[nbyte] = 0;
	while (!ft_strchr(str, '\n'))
	{
		rd = read(fd, buf, nbyte);
		if (!rd)
			return (NULL);
		temp = str;
		str = ft_strjoin(temp, buf);
		if (temp)
			free(temp);
	}
	return (str);
}

char	*ft_getline(char *str, size_t target)
{
	size_t	i;
	char	*line;

	line = malloc(sizeof(char) * (target + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < target)
	{
		//printf("line[%zu] is %c\n", i, str[i]);
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
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;
	size_t			target;

	while (lst != NULL && lst->fd != fd)
		lst = lst->next;
	if (!lst)
		ft_ultimate_lstnew(&lst, fd);
	if (!ft_strchr(lst->str, '\n'))
	{
		lst->str = ft_readfile(fd, lst->str);
		if (!lst->str)
			return (NULL);
	}
	target = 0;
	while (lst->str[target - 1] != '\n')
		target++;
	line = ft_getline(lst->str, target);
	lst->str = ft_update(lst->str, target);
	return (line);
}

// int	main(void)
// {
// 	int	fd, fd1;
// 	char	*str;

// 	fd = open ("test", O_RDONLY);
// 	fd1 = open ("test1", O_RDONLY);


// 	str = get_next_line(fd);
// 	printf("line = %s <<END>>\n", str);
// 	while (str != NULL)
// 	{
// 		free(str);
// 		str = get_next_line(fd);
// 		printf("line = %s <<END>>\n", str);
// 	}
// 	return (0);
// }
