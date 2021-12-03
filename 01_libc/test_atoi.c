/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:01:34 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 22:02:20 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	valid_atoi(size_t max_spaces, size_t i)
{
	size_t	spaces = randi(max_spaces) + 1;
	char	*str, *s1;
	int		n = (int) randi(INT_MAX);

	str = (char *) malloc(sizeof(char) * (spaces + 12));
	s1 = str;
	while (spaces)
	{
		if (randi(2))
			*s1++ = (char) (randi(5) + 9);
		else
			*s1++ = ' ';
		spaces--;
	}
	if (randi(10) > 6)
	{
		if (randi(2))
			*s1++ = '-';
		else
			*s1++ = '+';
	}
	sprintf(s1, "%d", n);
	*(s1 + randi(strlen(s1))) = rand_char();
	if (ft_atoi(str) != atoi(str))
	{
		printf("test #%zu failed\nstr: [%s]\ngot %d, expected %d\n", 
				i, str, ft_atoi(str), atoi(str));
		abort();
	}
	free(str);
}

void	bad_atoi(size_t max_spaces, size_t i)
{
	size_t	spaces = randi(max_spaces) + 1;
	size_t	len = spaces + 20;
	char	*str, *s1;
	int		n = (int) randi(INT_MAX);

	str = (char *) malloc(sizeof(char) * (len));
	bzero(str, len);
	s1 = str;
	while (spaces > randi(4))
	{
		if (randi(3))
			*s1++ = ' ';
		else
			*s1++ = (char) randi(14);
		spaces--;
	}
	while (spaces > 0)
	{
		if (randi(2))
			*s1++ = '-';
		else
			*s1++ = '+';
		spaces--;
	}
	sprintf(s1, "%d", n);
	while (randi(4))
		*(str + randi(strlen(str))) = rand_char();
	if (ft_atoi(str) != atoi(str))
	{
		printf("test #%zu failed\nstr: [%s]\ngot %d, expected %d\n", 
				i, str, ft_atoi(str), atoi(str));
		abort();
	}
	free(str);
}

void	test_atoi(void)
{
	size_t	tests = 100, max_spaces = 10, i = 0;
	char	str0[] = "                 ";
	char	str1[] = " 42";
	char	str2[] = " -42";
	char	str3[] = " 0";
	char	str4[] = " 2147483647";
	char	str5[] = " -2147483648";

	printf("...ft_atoi\n");
	valid_atoi(10, 0);
	printf("testing easy strings\n");
	printf("%d\n%d\n%d\n%d\n%d\n", ft_atoi(str1), ft_atoi(str2), ft_atoi(str3), ft_atoi(str4), ft_atoi(str5));
	assert(ft_atoi(str0) == atoi(str0));
	assert(ft_atoi(str1) == atoi(str1));
	assert(ft_atoi(str2) == atoi(str2));
	assert(ft_atoi(str3) == atoi(str3));
	assert(ft_atoi(str4) == atoi(str4));
	assert(ft_atoi(str5) == atoi(str5));
	printf("testing valid strings\n");
	while (i < tests)
		valid_atoi(max_spaces, i++);
	printf("testing bad strings\n");
	i = 0;
	while (i < tests)
		bad_atoi(max_spaces, i++);
	printf("testing ints of all lengths\n");
	for (unsigned int len = 1; len < 11; len++)
	{
		char *str = (char *) malloc(sizeof(char) * (len + 2));
		sprintf(str, "+%zu", randi_len(len));
		printf("[%11d]\t>\t%d\n", atoi(str), ft_atoi(str));
		assert(ft_atoi(str) == atoi(str));
		sprintf(str, "-%zu", randi_len(len));
		printf("[%11d]\t>\t%d\n", atoi(str), ft_atoi(str));
		assert(ft_atoi(str) == atoi(str));
		free(str);
	}
}
