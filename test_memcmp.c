/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:00:48 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:02:09 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	same_memcmp(size_t max_size, size_t i)
{
	size_t	size = randi(max_size), j = 0;
	void	*ptr1, *ptr2;
	int		ft_result, libc_result;

	ptr1 = malloc(size);
	ptr2 = malloc(size);
	while (j < size)
		memset(ptr1 + j++, rand_char(), 1);
	memcpy(ptr2, ptr1, size);
	if ((ft_result = ft_memcmp(ptr1, ptr2, size)) != (libc_result = memcmp(ptr1, ptr2, size)))
	{
		printf("test #%zu failed:\nptr1: [", i);
		print_mem(ptr1, size);
		printf("]\nptr2: [");
		print_mem(ptr2, size);
		printf("]\ngot %d, expected %d\n", ft_result, libc_result);
		if (!signtest(ft_result, libc_result))
			abort();
		else printf("same sign though, continuing\n");
	}
	free(ptr1);
	free(ptr2);
}

static void	diff_memcmp(size_t max_size_pre, size_t max_size_post, size_t i)
{
	size_t 	size_pre = randi(max_size_pre);
	size_t 	size_post = randi(max_size_post);
	size_t	size = size_pre + size_post;
	size_t	j = 0;
	void	*ptr1, *ptr2;
	int		ft_result, libc_result;

	ptr1 = malloc(size_pre + size_post);
	ptr2 = malloc(size_pre + size_post);
	while (j < size_pre)
		memset(ptr1 + j++, rand_char(), 1);
	memcpy(ptr2, ptr1, size_pre);
	while (j < size)
	{
		memset(ptr1 + j, rand_char(), 1);
		memset(ptr2 + j, rand_char(), 1);
		j++;
	}
	if ((ft_result = ft_memcmp(ptr1, ptr2, size)) != (libc_result = memcmp(ptr1, ptr2, size)))
	{
		printf("test #%zu failed (size_pre=%zu, size_post=%zu, size=%zu)\nptr1: [", i, size_pre, size_post, size);
		print_mem(ptr1, size);
		printf("]\nptr2: [");
		print_mem(ptr2, size);
		printf("]\ngot %d, expected %d\n", ft_memcmp(ptr1, ptr2, size), memcmp(ptr1, ptr2, size));
		if (!signtest(ft_result, libc_result))
			abort();
		else printf("same sign though, continuing\n");
	}
	free(ptr1);
	free(ptr2);
}

static void	zero_memcmp(void)
{
	char	str1[] = "So long, and thanks for all the fish!";
	char	str2[] = "So long, and thanks for all the fish!";
	char	str3[] = "So long, and fortytwo";
	char	str4[] = "Fortytwo";
	int		p1, p2;

	printf("testing with size=0\n");
	p1 = memcmp(str1, str2, (0));
	p2 = ft_memcmp(str1, str2, (0));
	assert(p1 == p2);
	p1 = memcmp(str1, str3, (0));
	p2 = ft_memcmp(str1, str3, (0));
	assert(p1 == p2);
	p1 = memcmp(str1, str4, (0));
	p2 = ft_memcmp(str1, str4, (0));
	assert(p1 == p2);
}

void	test_memcmp(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_memcmp\n");
	zero_memcmp();
	printf("comparing similar pointers\n");
	while (i < tests)
		same_memcmp(100, i++);
	i = 0;
	printf("comparing differing pointers\n");
	while (i < tests)
		diff_memcmp(100,50, i++);
}
