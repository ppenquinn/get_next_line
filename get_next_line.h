/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:27:42 by nappalav          #+#    #+#             */
/*   Updated: 2023/10/04 22:28:52 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
t_list	*ft_ultimate_lstnew(t_list **lst, int fd);

#endif
