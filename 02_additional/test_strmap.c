/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:19:08 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:19:32 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static char	f_strmap(char c)
{
	return (c + 1);
}

void	test_strmap(void)
{
	char const	s1[] = "fortytwo";
	char const	s0[] = "";
	char		*s2;

	printf("...ft_strmap\n");
	printf("[%s] -> ", s1);
	s2 = ft_strmap(s1, &f_strmap);
	printf("[%s]\n", s2);
	assert(strcmp("gpsuzuxp", s2) == 0);
	free(s2);
	s2 = ft_strmap(s0, &f_strmap);
	printf("[%s] -> [%s]\n", s0, s2);
	free(s2);
}
