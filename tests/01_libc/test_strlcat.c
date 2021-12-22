/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:43:41 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/07 18:14:45 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	ret_strlcat(void)
{
	char *str = "Meaning of life,\0 universe and everything\0is Forty-Two.\n";
	char buff1[42] = "vogon constructor fleet";
	char buff2[42] = "vogon constructor fleet";
	size_t max = strlen("Meaning of life,\0 universe and everything\0is Forty-Two.\n") + 4;
	size_t r1 = strlcat(buff1, str, max);
	size_t r2 = ft_strlcat(buff2, str, max);

	if (r1 != r2)
	{
		printf("failed when destsize is less than dest\nlibc\t[%s](%zu)\nftlib\t[%s](%zu)\n",
			   	buff1, r1, buff2, r2);
		abort();
	}
	char s1[4] = "";
	char s2[4] = "";
	r1 = strlcat(s1, "thx to ntoniolo for this test !", 4);
	r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	if (r1 != r2)
	{
		printf("failed when dest is empty string\nlibc\t[%s](%zu)\nlibft\t[%s](%zu)\n",
			   	s1, r1, s2, r2);
		abort();
	}
}

static void dstsize_test(void)
{
	char	str0[] = "So long, and thanks for all the fish.";
	char	str1[300] = "Life, the Universe, and Everything.";
	char	str2[300] = "Life, the Universe, and Everything.";
	size_t	max = strlen(str0) + 5;
	size_t	libc, libft;

	libc = strlcat(str1, str0, max);
	libft = ft_strlcat(str2, str0, max);
	if (strcmp(str1, str2) != 0 || libc != libft)
	{
		printf("test failed when dstsize is smaller than dstlen + srclen\n");
		printf("libc:\t[%s](%zu)\nlibft:\t[%s](%zu)\n", str1, libc, str2, libft);
	   abort();
	}	   
}

static void	rand_strlcat(size_t max_len, size_t i)
{
	char	*src, *libc_cat, *ft_cat;
	size_t	src_len = randi(max_len);
	size_t	root_len = randi(max_len) + 1;
	size_t	dest_len = root_len + randi(src_len) + 1;
	size_t	ft_total, libc_total;

	src = (char *) malloc(sizeof(char) * (src_len + 1));
	rand_str(src, src_len);
	ft_cat = (char *) malloc(sizeof(char) * (dest_len + 1));
	libc_cat = (char *) malloc(sizeof(char) * (dest_len + 1));
	bzero(ft_cat, dest_len);
	bzero(libc_cat, dest_len);
	rand_str(ft_cat, root_len);
	strncat(libc_cat, ft_cat, root_len);
	libc_total = strlcat(libc_cat, src, dest_len + 1);
	ft_total = ft_strlcat(ft_cat, src, dest_len + 1);
	if (ft_total != libc_total || strcmp(ft_cat, libc_cat) != 0)
	{
		printf("test #%zu failed (dstsize=%zu, src len=%zu)\n", i, dest_len + 1, strlen(src));
		printf("strlcat returned %zu, ft_strlcat %zu\n", libc_total, ft_total);
		printf("src\t[%s]\nlibc\t[%s]\nlibft\t[%s]\n", src, libc_cat, ft_cat);
		abort();
	}
	free(src);
	free(ft_cat);
	free(libc_cat);
}

void	test_strlcat(void)
{
	size_t tests = 100, i = 0;

	printf("...ft_strlcat\n");
	ret_strlcat();
	dstsize_test();
	while (i < tests)
		rand_strlcat(25, i++);
}
