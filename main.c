/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:47:33 by nappalav          #+#    #+#             */
/*   Updated: 2023/10/14 11:47:56 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd;
	char *str;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	str = get_next_line(fd);
	printf("line %s<\n", str);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		printf("line %s<\n", str);
	}
	return (0);
}
