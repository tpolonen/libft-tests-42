/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:56:09 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 17:56:38 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	const_memmove(int i)
{
	char	str1[] = "meaning of life is fortytwo and here's more chars for string";
	char	str2[] = "meaning of life is fortytwo and here's more chars for string";
	size_t	len = 0;
	size_t	test_dst;
	size_t	test_src;
	size_t	test_len;

	if (i > 0)
		len = strlen(str1);
	test_len = randi(len);
	test_dst = randi(len - test_len);
	test_src = randi(len - test_len);
	memmove((str1 + test_dst), (str1 + test_src), test_len);
	ft_memmove((str2 + test_dst), (str2 + test_src), test_len);
	if (memcmp(str1, str2, sizeof(char) * len) != 0)
	{
		printf("failed for test #%d (%zu chars):\n", i, len);
		printf("dst %zu src %zu len %zu\n", test_dst, test_src, test_len);
		printf("memmove:\t[%s]\nft_memmove:\t[%s]\n", str1, str2);
		abort();
	}
}

void	test_memmove(void)
{
	int		tests = 100;
	int		i = 0;

	printf("...ft_memmove\n");
	while (i < tests)
		const_memmove(i++);
	i = 0;
}
