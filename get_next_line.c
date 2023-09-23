/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:21 by nappalav          #+#    #+#             */
/*   Updated: 2023/09/22 23:29:25 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	size_t			nbyte;
	static t_list	*lst;

	nbyte = BUFFER_SIZE;
	buf[BUFFER_SIZE] = 0;
	while (lst != NULL && lst->fd != fd)
		lst = lst->next;
	if (!lst)
		ft_ultimate_lstnew(&lst, fd);
	//finish first
	read(fd, buf, nbyte);
	printf("%s\n", buf);
	lst->str = buf;
	printf("fd is %d when str is %s\n", lst->fd, lst->str);
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
	get_next_line(fd1);
	get_next_line(fd);
	return (0);
}


