/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:50:56 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 17:52:44 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	rand_memcpy(size_t max_size, size_t i)
{
	char 	*str1, *str2;
	size_t	size = randi(max_size);

	str1 = (char *) malloc(sizeof(char) * size);
	str2 = (char *) malloc(sizeof(char) * size);
	for (size_t i = 0; i < size; i++)
		*(str1 + i) = rand_char();
	ft_memcpy(str2, str1, size);
	if (memcmp(str1, str2, sizeof(char) * size) != 0)
	{
		printf("test #%zu failed (size=%zu)\nstr1\t[", i, size);
		print_mem(str1, size);
		printf("]\nstr2\t[");
		print_mem(str2, size);
		printf("]\n");
		abort();
	}
	free(str1);
	free(str2);
}

static void zero_memcpy(void)
{
	char	str0[] = "";
	char	str1[] = "(null)";
	char	*str2 = NULL;
	char	*target;
	char 	*p1 = NULL, *p2 = NULL;

	target = (char *) malloc(0);
	printf("testing with n=0\n");
	if ((p1 = memcpy(target, str0, 0)) != (p2 = ft_memcpy(target, str0, 0)))
	{
		printf("failed when str=\"\"\n");
		printf("libc:\t%p\nlibft:\t%p\n", p1, p2);
		abort();
	}
	if ((p1 = memcpy(target, str1, 0)) != (p2 = ft_memcpy(target, str1, 0)))
	{
		printf("failed when str=\"(null)\"\n");
		printf("libc:\t%p\nlibft:\t%p\n", p1, p2);
		abort();
	}
	if ((p1 = memcpy(target, str2, 0)) != (p2 = ft_memcpy(target, str2, 0)))
	{
		printf("failed when str=NULL\n");
		printf("libc:\t%p\nlibft:\t%p\n", p1, p2);
		abort();
	}
	free(target);
}

void	test_memcpy(void)
{
	char	str1[] = "fortytwoaaaaa";
	char	str2[] = "aaaaaaaaaaaaa";
	char	str3[] = "aaaaaaaaaaaaa";
	size_t 	len = 8, tests = 100;

	printf("...ft_memcpy\n");
	zero_memcpy();
	ft_memcpy(str3, str1, 0);
	printf("len=0\t[%s]\n", str3);
	assert(memcmp(str3, str2, sizeof(char) * len + 2) == 0);
	ft_memcpy(str2, str1, len);
	printf("len=8\t[%s]\n", str2);
	assert(memcmp(str1, str2, sizeof(char) * len + 2) == 0);
	printf("testing random strings\n");
	for (size_t i = 1; i < tests; i++)
		rand_memcpy(100, i);
}
