/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:17:21 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:17:46 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	f_striter(char *c)
{
	*c = 'a';
}

void	test_striter(void)
{
	char	str[] = "fortytwo";
	char	s0[] = "";
	int		i;

	printf("...ft_striter\n");
	printf("[%s] -> ", str);
	ft_striter(str, &f_striter);
	printf("[%s]\n", str);
	i = 0;
	while (i < 8)
		assert(str[i++] == 'a');
	assert(str[i] == '\0');
	ft_striter(s0, &f_striter);
	printf("[%s] -> [%s]\n", "", s0);
	assert(strcmp(s0, "") == 0);
}
