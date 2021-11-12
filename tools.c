/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:39:40 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/12 15:55:18 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	rand_char(void)
{
	char c = (char) (arc4random_uniform(128));
	while (!isprint(c))
		c = (char) (arc4random_uniform(128));
	return (c);
}

char	*rand_str(char *str, size_t len)
{
	size_t	i = 0;

	while (i < len)
		str[i++] = rand_char();
	str[i] = '\0';
	return (str);
}

void	rand_substrs(char *str1, char *str2, size_t len_pre, size_t len_post)
{
	bzero(str1, len_pre + len_post + 1);
	bzero(str2, len_pre + len_post + 1);
	rand_str(str1, len_pre);
	strncat(str2, str1, len_pre);
	rand_str((str1 + len_pre), len_post);
	rand_str((str2 + len_pre), len_post);
}

size_t	randi(size_t max)
{
	return (arc4random_uniform(max));
}

void	print_mem(void *ptr, size_t size)
{
	while (size > 0)
	{
		printf("%c", *(char *)ptr++);
		size--;
	}
}

void	print_mem_val(void *ptr, size_t size)
{
	while (size > 0)
	{
		printf("%d", *(char *)ptr++);
		size--;
		if (size > 0)
			printf(", ");
	}
}

int		signtest(int i1, int i2)
{
	i1 /= abs(i1);
	i2 /= abs(i2);
	if (i1 == i2)
		return (1);
	else return (0);
}
