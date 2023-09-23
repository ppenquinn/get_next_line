/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:35:54 by nappalav          #+#    #+#             */
/*   Updated: 2023/09/23 23:25:14 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
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
	return (str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	char	*first;

// 	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	first = str;
// 	str = ft_memmove(str, s1, ft_strlen(s1));
// 	str += ft_strlen(s1);
// 	str = ft_memmove(str, s2, ft_strlen(s2));
// 	return (first);
// }

int	main(void)
{
	char *s2 = NULL;
	char *s1 = "Hello";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}
