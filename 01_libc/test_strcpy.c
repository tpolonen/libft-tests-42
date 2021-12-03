/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:35:38 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:35:58 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	rand_strcpy(size_t max_len, size_t i)
{
	size_t	buf_extra = 5;
	size_t	len = randi(max_len);
	char	*str, *cpy;

	str = (char *) malloc(sizeof(char) * (len + 1));
	cpy = (char *) malloc(sizeof(char) * (len + buf_extra + 1));
	memset(cpy, 'a', len + buf_extra + 1);
	rand_str(str, len);
	cpy = ft_strcpy(cpy, str);
	if (strcmp(str, cpy) != 0)
	{
		printf("test #%zu failed\nstr: [%s]\ncpy: [%s]\n", i, str, cpy);
		abort();
	}
	free(str);
	free(cpy);
}

void	test_strcpy(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strcpy\n");
	rand_strcpy(0, i++);
	while (i < tests)
		rand_strcpy(100, i++);
}
