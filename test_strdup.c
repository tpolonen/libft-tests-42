/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:27:11 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 18:34:50 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	rand_strdup(size_t max_len, size_t i)
{
	size_t	len = randi(max_len);
	char	*str, *dup;

	str = (char *) malloc(sizeof(char) * (len + 1));
	rand_str(str, len);
	dup = ft_strdup(str);
	if (strcmp(str, dup) != 0)
	{
		printf("test #%zu failed\nstr: [%s]\ndup: [%s]\n", i, str, dup);
		abort();
	}
	free(str);
	free(dup);
}

void	test_strdup(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strdup\n");
	rand_strdup(0, i++);
	while (i < tests)
		rand_strdup(100, i++);
}
