/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:21 by nappalav          #+#    #+#             */
/*   Updated: 2023/09/24 01:35:42 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*seperate(char *str)
{
	size_t	i;
	char	*temp;
	char	*line;

	temp = str;
	i = 0;
	while (*(str++) != '\n')
		i++;
	str = ft_strdup(str);
	//handle
	line = malloc(sizeof(char) * (i + 2));
	while (i > 0)
	{
		line[i] = temp[i];
		i--;
	}
	line[i] = temp[i];
	free(temp);
	return (line);
}
char	*get_next_line(int fd)
{
	char			*buf;
	size_t			nbyte;
	static t_list	*lst;
	char			*temp;
	char			*line;

	nbyte = BUFFER_SIZE;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (lst != NULL && lst->fd != fd)
		lst = lst->next;
	if (!lst)
		ft_ultimate_lstnew(&lst, fd);
	//finish first
	while (!ft_strchr(lst->str, '\n'))
	{
		read(fd, buf, nbyte);
		temp = lst->str;
		lst->str = ft_strjoin(temp, buf);
		if (temp)
			free(temp);
	}
	printf("first str is ||%s||\n", lst->str);
	line = seperate(lst->str);
	printf("first line is ||%s||\n", line);
	printf("final str is ||%s||\n", lst->str);
	return (line);
}
int	main(void)
{
	int	fd, fd1;
	char buff[BUFFER_SIZE + 1];
	size_t nbyte = BUFFER_SIZE;
	ssize_t rd;

	buff[BUFFER_SIZE] = 0;
	fd = open ("test", O_RDONLY);
	fd1 = open ("test1", O_RDONLY);
	//printf("fd of test = %d %d\n", fd, fd1);
	// rd = read(fd, buff, nbyte);
	// while (rd > 0)
	// {

	// 	printf("%s", buff);
	// 	printf("\nrd = %zd", rd);
	// 	rd = read(fd, buff, nbyte);
	// }
	// close (fd);
	get_next_line(fd);
	return (0);
}
