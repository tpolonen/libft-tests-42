/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:02:39 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:26:52 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	rand_strlen(size_t max_len, size_t i)
{
	char	*str;
	size_t	cur_len = randi(max_len);

	str = (char *) malloc(sizeof(char) * (cur_len + 1));
	str = rand_str(str, cur_len);
	if (ft_strlen(str) != strlen(str))
	{
		printf("test #%zu: failed for str [%s]\n", i, str);
		abort();
	}
	free(str);
}

void	test_strlen(void)
{
	size_t	tests = 100;
	size_t	i = 0;
	size_t	max_len = 1000;

	printf("...ft_strlen\n");
	rand_strlen(0, i++);
	while (i < tests)
		rand_strlen(max_len, i++);
}
