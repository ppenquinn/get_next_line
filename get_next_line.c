/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:21 by nappalav          #+#    #+#             */
/*   Updated: 2023/09/23 21:33:58 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	size_t			nbyte;
	static t_list	*lst;
	char			*temp;
	size_t	i = 1;


	nbyte = BUFFER_SIZE;
	buf[BUFFER_SIZE] = 0;
	while (lst != NULL && lst->fd != fd)
		lst = lst->next;
	if (!lst)
		ft_ultimate_lstnew(&lst, fd);
	//finish first
	while (!ft_strchr(lst->str, '\n'))
	{
		printf("\nI'm in at round %zu!!\n", i);
		printf("first str is %s\n", lst->str);
		read(fd, buf, nbyte);
		temp = lst->str;
		printf("temp is ||%s||\nbuf is ||%s|| \n", temp, buf);
		lst->str = ft_strjoin(temp, buf);
		printf("str is ||%s||\n", lst->str);
		// free(temp);
		i++;
	}
	printf("finally str is ||%s||\n", lst->str);

	// read(fd, buf, nbyte);
	// printf("%s\n", buf);
	// lst->str = buf;
	// printf("fd is %d when str is %s\n", lst->fd, lst->str);
	return (0);
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
