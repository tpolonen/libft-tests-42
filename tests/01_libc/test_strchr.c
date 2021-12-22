/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:47:07 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:47:30 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	found_strchr(size_t max_len, char seek, size_t i)
{
	size_t	len = randi(max_len);
	size_t	hits = 3;
	char	*str;

	str = (char *) malloc(sizeof(char) * len + 1);
	rand_str(str, len);
	while (hits > 0)
	{
		str[randi(len)] = seek;
		hits--;
	}
	if (ft_strchr(str, seek) != strchr(str, seek))
	{
		printf("test #%zu failed (c=%c)\n", i, seek);
		printf("str: [%s]\nlibc:\t%p\nlibft:\t%p\n", str, strchr(str, seek), ft_strchr(str, seek));
		abort();
	}
	free(str);
}

static void	not_found_strchr(size_t max_len, char seek, size_t i)
{
	size_t	len = randi(max_len) + 1;
	char	*str;

	str = (char *) malloc(sizeof(char) * len + 1);
	rand_str(str, len);
	if (ft_strchr(str, seek) != strchr(str, seek))
	{
		printf("test #%zu failed\n", i);
		printf("str: [%s]\nlibc:\t%p\nlibft:\t%p\n", str, strchr(str, seek), ft_strchr(str, seek));
		abort();
	}
	free(str);
}

void	test_strchr(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strchr\n");
	printf("seeking present char\n");
	while (i < tests)
		found_strchr(100, rand_char(), i++);
	i = 0;
	printf("seeking missing char\n");
	while (i < tests)
		not_found_strchr(100, '\t', i++);
	i = 0;
	printf("seeking terminator\n");
	while (i < tests)
		not_found_strchr(100, '\0', i++);
}
