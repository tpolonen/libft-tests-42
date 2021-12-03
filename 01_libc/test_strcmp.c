/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:53:36 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 21:58:25 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	strcmp_printout(char *str1, char *str2)
{
	printf("s1: [%s]\ns2: [%s]\ngot %d, expected %d\nKO D:\n", str1, str2, 
			ft_strcmp(str1, str2), strcmp(str1, str2));
}

static void	strcmp_same(size_t max_len)
{
	size_t len_pre = randi(max_len);
	char *str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len_pre + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + 1));
	rand_substrs(str1, str2, len_pre, 0);
	if ((ft_result = ft_strcmp(str1, str2)) != (libc_result = strcmp(str1, str2)))
	{
		strcmp_printout(str1, str2);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
	}
	free(str1);
	free(str2);
}

static void	strcmp_same_len(size_t max_len_pre, size_t max_len_post)
{
	size_t len_pre = randi(max_len_pre);
	size_t len_post = randi(max_len_post);
	char *str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	if ((ft_result = ft_strcmp(str1, str2)) != (libc_result = strcmp(str1, str2)))
	{
		strcmp_printout(str1, str2);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
	}
	free(str1);
	free(str2);
}

static void strcmp_diff_len(size_t max_len)
{
	size_t len = randi(max_len);
	char *str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len + 1));
	str2 = (char *) malloc (sizeof(char) * (len + 1));
	rand_substrs(str1, str2, len, 0);
	if (randi(2) == 0)
		*(str1 + randi(len)) = '\0';
	else
		*(str2 + randi(len)) = '\0';
	if ((ft_result = ft_strcmp(str1, str2)) != (libc_result = strcmp(str1, str2)))
	{
		strcmp_printout(str1, str2);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
	}
	free(str1);
	free(str2);
}

void	test_strcmp(void)
{
	size_t	tests = 100;
	size_t	i = 0;

	printf("...ft_strcmp\n");
	printf("comparing similar strings\n");
	while (i < tests)
	{
		strcmp_same(100);
		i++;
	}
	i = 0;

	printf("comparing same length strings\n");
	while (i < tests)
	{
		strcmp_same_len(50, 50);
		i++;
	}
	i = 0;

	printf("comparing different length strings\n");
	while (i < tests)
	{
		strcmp_diff_len(100);
		i++;
	}
}
