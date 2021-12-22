/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:56:55 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 17:58:56 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	zero_memchr(void)
{
	char	str[] = "hello there world!";
	void 	*p1, *p2;

	printf("testing with len=0 and s=[%s]\n", str);
	p1 = memchr((void *) str, '?', 0);
	p2 = ft_memchr((void *) str, '?', 0);
	if (p1 != p2)
	{
		printf("failed when size=0 and c is not present in string\n");
		abort();
	}
	p1 = memchr((void *) str, '!', 0);
	p2 = ft_memchr((void *) str, '!', 0);
	if (p1 != p2)
	{
		printf("failed when size=0 and c is present in string\n");
		abort();
	}
 	p1 = memchr((void *) str, 'h', 0);
	p2 = ft_memchr((void *) str, 'h', 0);
	if (p1 != p2)
	{
		printf("failed when size=0 and c is first char in string\n");
		abort();
	}
}

static void	found_memchr(size_t max_size, size_t i)
{
	size_t	size = randi(max_size) + 1;
	void	*ptr;
	char	seek = rand_char();
	
	ptr = malloc(size);
	memset(ptr, rand_char(), size);
	memset(ptr + randi(size), seek, 1);
	if (ft_memchr(ptr, seek, size) != memchr(ptr, seek, size))
	{
		printf("test #%zu failed (c=%c)\nptr: [", i, seek);
		print_mem(ptr, size);
		printf("]\n");
		printf("libc:\t%p\nlibft:\t%p\n", memchr(ptr, seek, size), ft_memchr(ptr, seek, size));
		abort();
	}
	free(ptr);
}

static void	not_found_memchr(size_t max_size, size_t i)
{
	size_t	size = randi(max_size) + 1;
	void	*ptr;
	
	ptr = malloc(size);
	memset(ptr, rand_char(), size);
	if (ft_memchr(ptr, '\t', size) != memchr(ptr, '\t', size))
	{
		printf("test #%zu failed\nptr: [", i);
		print_mem(ptr, size);
		printf("]\n");
		printf("libc:\t%p\nlibft:\t%p\n", memchr(ptr, '\t', size), ft_memchr(ptr, '\t', size));
		abort();
	}
	free(ptr);
}

void	test_memchr(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_memchr\n");
	zero_memchr();
	found_memchr(0, i++);
	printf("seeking present char\n");
	while (i < tests)
		found_memchr(100, i++);
	i = 0;
	printf("seeking missing char\n");
	while (i < tests)
		not_found_memchr(100, i++);
}
