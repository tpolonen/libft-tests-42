/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:36:19 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:38:21 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	rand_strncpy(size_t max_len, size_t i)
{
	size_t	len = randi(max_len) + 1;
	size_t	buf_extra = 5;
	size_t	n = randi(len + 1);
	char	*str, *cpy;

	str = (char *) malloc(sizeof(char) * (len + 1));
	cpy = (char *) malloc(sizeof(char) * (len + buf_extra + 1));
	memset(cpy, 'b', len + buf_extra + 1);
	rand_str(str, len);
	ft_strncpy(cpy, str, n);
	if (memcmp(str, cpy, n) != 0)
	{
		printf("test #%zu failed (len=%zu)\nstr: [%s]\ncpy: [%s]\n", i, n, str, cpy);
		abort();
	}
	free(str);
	free(cpy);
}

static void	smaller_src_strncpy(void)
{
	char	str0[] = "fortytwo";
	char	cpy[30];

	memset(cpy, 'c', 30);
	ft_strncpy(cpy, str0, 20);
	if (memcmp(str0, cpy, strlen(str0)) != 0 || cpy[15] != '\0')
	{
		printf("failed when src is smaller than dest\nsrc:\t[%s]\ndst:\t[%s]\n", str0, cpy);
		printf("dst[15]=%c (%d)\n", cpy[15], cpy[15]);
		abort();
	}
}

static void	zero_strncpy(void)
{
	char	str0[] = "fortytwo";
	char	cp1[30] = "aaaaaaaaaaaaaaaa";
	char	cp2[30] = "aaaaaaaaaaaaaaaa";

	strncpy(cp1, str0, 0);
	ft_strncpy(cp2, str0, 0);
	if (memcmp(cp1, cp2, strlen(str0)) != 0)
	{
		printf("failed when len=0\nsrc:\t[%s]\nlibc:\t[%s]\nlibft:\t[%s]\n", str0, cp1, cp2);
		abort();
	}
}

void	test_strncpy(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strncpy\n");
	smaller_src_strncpy();
	zero_strncpy();
	while (i < tests)
		rand_strncpy(100, i++);
}
