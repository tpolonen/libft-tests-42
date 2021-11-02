/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/02 15:39:28 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void	test_memalloc(void)
{
	void	*ptr;
	int		i;

	ptr = ft_memalloc(8);
	printf("...ft_memalloc\n");
	i = 0;
	while (i < 8)
	{
		printf("%p: %d\n", ptr + i, *(int *) (ptr + i));
		assert(*(int *) (ptr + i) == 0);
		i++;
	}
	free(ptr);
}

void	test_memdel(void)
{
	void	*ptr;

	ptr = malloc(8);
	ft_memdel(&ptr);
	printf("...ft_memdel\n");
	assert(ptr == 0);
}

void	test_strnew(void)
{
	char	*str;
	size_t	size, i;

	size = 8;
	str = ft_strnew(sizeof(char) * size);
	i = 0;
	printf("...ft_strnew\n");
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
	printf("...ft_strdel\n");
	assert(str == 0);
}

void 	test_strclr(void)
{
	char	str[] = "fortytwo";
	int		i;

	ft_strclr(str);
	i = 0;
	printf("...ft_strclr\n");
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
	printf("...ft_striter\n");
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
	printf("...ft_striteri\n");
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

	printf("...ft_strmap\n");
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

	printf("...ft_strmapi\n");
	s2 = ft_strmapi(s1, &f_strmapi);
	printf("%s\n", s2);
	assert(strcmp("01234567", s2) == 0);
	free(s2);
}

void	test_strequ(void)
{
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortytwo";
	char const	s3[] = "fortyseven";

	printf("...ft_strequ\n");
	assert(ft_strequ(s1, s2) == 1);
	assert(ft_strequ(s1, s3) == 0);
}

void	test_strnequ(void)
{
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortyseven";

	printf("...ft_strnequ\n");
	assert(ft_strnequ(s1, s2, 5) == 1);
	assert(ft_strnequ(s1, s2, 8) == 0);
}

void	test_strsub(void)
{
	char const	s1[] = "get fortytwo from this string";
	char		*s2;

	printf("...ft_strsub\n");
	s2 = ft_strsub(s1, 4, 8);
	printf("%s\n", s2);
	assert(strcmp("fortytwo", s2) == 0);
	free(s2);
}

void	test_strjoin(void)
{
	char const	s1[] = "forty";
	char const	s2[] = "two";
	char		*str;

	printf("...ft_strjoin\n");
	str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	assert(strcmp("fortytwo", str) == 0);
	free(str);
}

void	test_strtrim(void)
{
	char const	s1[] = "\t\n forty \t\n two \t\n";
	char const	s2[] = "forty \t\n two \t\n";
	char const	s3[] = "\t\n forty \t\n two";
	char		*str;

	printf("...ft_strtrim\n");
	str = ft_strtrim(s1);
	printf("%s\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s2);
	printf("%s\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s3);
	printf("%s\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
}
