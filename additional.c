/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/01 19:08:16 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	test_memalloc(void)
{
	void	*ptr;
	char	*str;
	int		i;

	ptr = ft_memalloc(sizeof(char) * 8);
	ft_putstr("...ft_memalloc\n");
	i = 0;
	while (i < 8)
	{
		printf("%p: %d\n", ptr + i, *(int *) (ptr + i));
		assert(*(int *) (ptr + i) == 0);
		i++;
	}
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
	ft_putstr("...ft_memdel\n");
	assert(ptr == 0);
}

void	test_strnew(void)
{
	char	*str;
	size_t	size, i;

	size = 8;
	str = ft_strnew(sizeof(char) * size);
	i = 0;
	ft_putstr("...ft_strnew\n");
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
	ft_putstr("...ft_strdel\n");
	assert(str == 0);
}

void 	test_strclr(void)
{
	char	str[] = "fortytwo";
	int		i;

	ft_strclr(str);
	i = 0;
	ft_putstr("...ft_strclr\n");
	while (i <= 8)
	{
		assert(str[i] == '\0');
		i++;
	}
}

static void	f_striter(char *c)
{
	*c = 'a';
}

void	test_striter(void)
{
	char	str[] = "fortytwo";
	int		i;

	ft_striter(str, &f_striter);
	i = 0;
	ft_putstr("...ft_striter\n");
	while (i < 8)
		assert(str[i++] == 'a');
	assert(str[i] == '\0');
}

static void	f_striteri(unsigned int i, char *c)
{
	*c = '0' + i;
}

void	test_striteri(void)
{
	char	str[] = "fortytwo";
	int		i;

	ft_striteri(str, &f_striteri);
	i = 0;
	ft_putstr("...ft_striteri\n");
	while (i < 8)
	{
		assert(str[i] == '0' + i);
		i++;
	}
	assert(str[i] == '\0');
}

static char	f_strmap(char c)
{
	return (c + 1);
}

void	test_strmap(void)
{
	char const	s1[] = "fortytwo";
	char		*s2;

	ft_putstr("...ft_strmap\n");
	s2 = ft_strmap(s1, &f_strmap);
	printf("%s\n", s2);
	assert(strcmp("gpsuzuxp", s2) == 0);
	free(s2);
}

static char	f_strmapi(unsigned int i, char c)
{
	return (c + i);
}

void	test_strmapi(void)
{
	char const	s1[] = "00000000";
	char		*s2;

	ft_putstr("..ft_strmapi\n");
	s2 = ft_strmapi(s1, &f_strmapi);
	printf("%s\n", s2);
	assert(strcmp("01234567", s2) == 0);
	free(s2);
}
