/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:28:15 by nappalav          #+#    #+#             */
/*   Updated: 2023/10/09 12:36:42 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
	char chr;

	if (!s)
		return (NULL);
	chr = c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (*s == chr)
		return ((char *)s);
	return (0);
}

size_t ft_strlen(const char *s)
{
	size_t idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str[i + ft_strlen(s1)] = '\0';
	free(s1);
	return (str);
}

char *ft_strdup(const char *s1)
{
	char *dest;
	size_t i;

	if (!s1)
		return (NULL);
	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*setzero(char *str)
{
	
}
// t_list	*ft_ultimate_lstnew(t_list **lst, int fd)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->fd = fd;
// 	new->str = malloc(1);
// 	if (!new->str)
// 		return (NULL);
// 	*new->str = 0;
// 	new->next = NULL;
// 	*lst = new;
// 	return (*lst);
// }
