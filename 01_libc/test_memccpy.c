/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:53:13 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 17:55:40 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	basic_memccpy(void)
{
	char	str[] = "meaning of life is fortytwo";
	char	buf[30];
	char	*ptr1, *ptr2;

	bzero(buf, 30);
	ptr1 = memccpy(buf, str, 'i', 20);
	ptr2 = ft_memccpy(buf, str, 'i', 20);
	if (ptr1 != ptr2)
	{
		printf("returned wrong pointer: expected %p, got %p\n", ptr1, ptr2);
		printf("src:\t[%s], c='i'\nmemccpy:\t[%s]\nft_memccpy:\t[%s]\n", str, ptr1, ptr2);
		abort();
	}
}

static void zero_memccpy(void)
{
	char	str[] = "Don't Panic !";
	char	buf1[30];
	char	buf2[30];
	char	*ptr1, *ptr2;

	bzero(buf1, 30);
	bzero(buf2, 30);
	ptr1 = memccpy(buf1, str, '\t', 0);
	ptr2 = memccpy(buf2, str, '\t', 0);
	if (ptr1 != ptr2)
	{
		printf("failed when size=0 and src doesn't contain c: expected %p, got %p\n", ptr1, ptr2);
		printf("src:\t[%s], c='\t'\nmemccpy:\t[%s]\nft_memccpy:\t[%s]\n", str, ptr1, ptr2);
		abort();
	}
	ptr1 = memccpy(buf1, str, 'D', 0);
	ptr2 = memccpy(buf2, str, 'D', 0);
	if (ptr1 != ptr2)
	{
		printf("failed when size=0 and src contains c: expected %p, got %p\n", ptr1, ptr2);
		printf("src:\t[%s], c='D'\nmemccpy:\t[%s]\nft_memccpy:\t[%s]\n", str, ptr1, ptr2);
		abort();
	}	
	ptr1 = memccpy(buf1, str, ' ', 0);
	ptr2 = memccpy(buf2, str, ' ', 0);
	if (ptr1 != ptr2)
	{
		printf("failed when size=0 and src contains c: expected %p, got %p\n", ptr1, ptr2);
		printf("src:\t[%s], c=' '\nmemccpy:\t[%s]\nft_memccpy:\t[%s]\n", str, ptr1, ptr2);
		abort();
	}
}

static void	edge_memccpy(void)
{
	char s1[] = "hello";
	char buf1[10], buf2[10];

	bzero(buf1, 10);
	bzero(buf2, 10);
	memccpy(buf1, s1, 'o', 4);
	ft_memccpy(buf2, s1, 'o', 4);
	if (strcmp(buf1, buf2) != 0)
	{
		printf("fails when c is the array item n\n");
		printf("str\t[%s] (c='o', n=4)\n",s1);
		printf("libc\t[%s]\nlibft\t[%s]\n", buf1, buf2);
		abort();
	}
}

static void	rand_memccpy(size_t max_len, size_t i, char c)
{
	void	*src, *ptr1, *ptr2;
	size_t	len = randi(max_len) + 1;

	src = malloc(len);
	ptr1 = malloc(len);
	ptr2 = malloc(len);
	memset(src, rand_char(), len);
	if (isprint(c))
		memset(src + randi(len), c, 1);
	bzero(ptr1, len);
	bzero(ptr2, len);
	memccpy(ptr1, src, c, len);
	ft_memccpy(ptr2, src, c, len);
	if (memcmp(ptr1, ptr2, len) != 0)
	{
		printf("test #%zu failed ", i);
		if (isprint(c)) printf("(c=%c)", c);
		printf("\nsrc\t[");
		print_mem(src, len);
		printf("]\nlibc\t[");
		print_mem(ptr1, len);
		printf("]\nlibft\t[");
		print_mem(ptr2, len);
		printf("]\n");
		abort();
	}
	free(src);
	free(ptr1);
	free(ptr2);
}

void	test_memccpy(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_memccpy\n");
	basic_memccpy();
	zero_memccpy();
	edge_memccpy();
	printf("copying with present char\n");
	while (i < tests)
		rand_memccpy(100, i++, rand_char());
	i = 0;
	printf("copying with missing char\n");
	while (i < tests)
		rand_memccpy(100, i++, '\n');
}
