/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/10/30 22:12:42 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void	test_memalloc(void)
{
	void	*ptr;
	char	*str;
	int		i;

	ptr = ft_memalloc(sizeof(char) * 8);
	str = (char *) ptr;
	i = 0;
	while (i < 7)
	{
		str[i] = 'a';
		i++;
	}
	str[i] = '\0';
	assert(strcmp("aaaaaaa", (char *) ptr) == 0);
	free(ptr);
	str = 0;
}

void	test_memdel(void)
{
	void	*ptr;

	ptr = malloc(8);
	ft_memdel(&ptr);
	assert(ptr == 0);
}

void	test_strnew(void)
{
	char	*str;
	size_t	size, i;

	size = 8;
	str = ft_strnew(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		assert(str[i] == '\0');
		i++;
	}
}

void	test_strdel(void)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 8);
	ft_strdel(&str);
	assert(str == 0);
}
