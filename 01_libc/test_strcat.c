/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:39:03 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:39:24 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	null_strcat(void)
{
	char	src1[] = "hello ";
	char	src2[] = "world!";
	char	buf[30];

	memset(buf, 'a', 30);
	memcpy(buf, src1, sizeof(char) * (strlen(src1) + 1));
	ft_strcat(buf, src2);
	if (strcmp("hello world!", buf) != 0)
	{
		printf("test failed: doesn't add null byte\n[%s] + [%s]\nresult: [%s]\n", 
		src1, src2, buf);
		abort();
	}
}

static void	rand_strcat(size_t max_len, size_t i)
{
	char	*str1, *str2, *ft_cat, *libc_cat;
	size_t	len1 = randi(max_len);
	size_t	len2 = randi(max_len);

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
	ft_cat = ft_strcat(ft_cat, str1);
	ft_cat = ft_strcat(ft_cat, str2);
	libc_cat = strcat(libc_cat, str1);
	libc_cat = strcat(libc_cat, str2);
	if (strcmp(ft_cat, libc_cat) != 0)
	{
		printf("test #%zu failed for strings [%s] + [%s]\nexpected [%s], got [%s]\n",
			   i, str1, str2, libc_cat, ft_cat);
		abort();
	}
	free(str1);
	free(str2);
	free(ft_cat);
	free(libc_cat);
}

void	test_strcat(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strcat\n");
	null_strcat();
	rand_strcat(0, i++);
	while (i < tests)
		rand_strcat(50, i++);
}
