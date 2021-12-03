/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:42:01 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:43:34 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	null_strncat(void)
{
	char	src1[] = "hello ";
	char	src2[] = "world!!!";
	char	buf[30];

	memset(buf, 'a', 30);
	memcpy(buf, src1, sizeof(char) * (strlen(src1) + 1));
	ft_strncat(buf, src2, sizeof(char) * 6);
	if (strcmp("hello world!", buf) != 0)
	{
		printf("test failed: doesn't add null byte\n[%s] + [%s] (n=6)\nresult: [%s]\n", 
		src1, src2, buf);
		abort();
	}
}

static void	zero_strncat(void)
{
	char	buf1[] = "So long ";
	char	buf2[] = "So long ";
	char	src[] = "and thanks for all the fish";
	char 	*p1, *p2;

	p1 = strncat(buf1, src, 0);
	p2 = ft_strncat(buf2, src, 0);
	if (strcmp(buf1, buf2) != 0)
	{
		printf("failed when n=0\nlibc\t[%s]\nlibft\t[%s]\n", p1, p2);
		abort();
	}
}

static void	rand_strncat(size_t max_len, size_t i)
{
	char	*str1, *str2, *ft_cat, *libc_cat;
	size_t	len1 = randi(max_len) + 1;
	size_t	len2 = randi(max_len) + 1;
	size_t	n = randi(len2);

	str1 = (char *) malloc(sizeof(char) * (len1 + 1));
	str2 = (char *) malloc(sizeof(char) * (len2 + 1));
	ft_cat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	libc_cat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	bzero(str1, len1 + 1);
	bzero(str2, len2 + 1);
	bzero(ft_cat, len1 + len2 + 1);
	bzero(libc_cat, len1 + len2 + 1);
	rand_str(str1, len1);
	rand_str(str2, len2);
	ft_cat = ft_strncat(ft_cat, str1, len1);
	ft_cat = ft_strncat(ft_cat, str2, n);
	libc_cat = strncat(libc_cat, str1, len1);
	libc_cat = strncat(libc_cat, str2, n);
	if (strcmp(ft_cat, libc_cat) != 0)
	{
		printf("test #%zu failed for strings [%s] + [%s] n=%zu\nexpected [%s], got [%s]\n",
			   i, str1, str2, n, libc_cat, ft_cat);
		abort();
	}
	free(str1);
	free(str2);
	free(ft_cat);
	free(libc_cat);
}

void	test_strncat(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strncat\n");
	null_strncat();
	zero_strncat();
	while (i < tests)
		rand_strncat(50, i++);
}
