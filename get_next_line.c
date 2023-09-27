/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:21 by nappalav          #+#    #+#             */
/*   Updated: 2023/09/26 17:02:07 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*seperate(char *str, char *line)
{
	size_t	i;
	char	*temp;

	temp = str;
	i = 0;
	while (*(str++) != '\n')
		i++;
	str = ft_strdup(str);
	//handle
	//line = malloc(sizeof(char) * (i + 2));
	while (i > 0)
	{
		line[i] = temp[i];
		i--;
	}
	line[i] = temp[i];
	printf("line is %s\n", line);
	free(temp);
	return (str);
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
	while (!ft_strchr(lst->str, '\n'))
	{
		read(fd, buf, nbyte);
		temp = lst->str;
		lst->str = ft_strjoin(temp, buf);
		if (temp)
			free(temp);
	}
	line = malloc(sizeof(char) * (ft_strchr(lst->str, '\n') - lst->str + 2));
	lst->str = seperate(lst->str, line);
	printf("final str is ||%s||\n", lst->str);
	return (line);
}
int	main(void)
{
	int	fd, fd1;
	char buff[BUFFER_SIZE + 1];
	size_t nbyte = BUFFER_SIZE;
	ssize_t rd;
	char *str;

	buff[BUFFER_SIZE] = 0;
	fd = open ("test", O_RDONLY);
	fd1 = open ("test", O_RDONLY);
	printf("fd of test = %d %d\n", fd, fd1);
	// rd = read(fd, buff, nbyte);
	// while (rd > 0)
	// {

	// 	printf("%s", buff);
	// 	printf("\nrd = %zd", rd);
	// 	rd = read(fd, buff, nbyte);
	// }
	// close (fd);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	return (0);
}
