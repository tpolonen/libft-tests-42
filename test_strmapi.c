/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:19:37 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:20:17 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static char	f_strmapi(unsigned int i, char c)
{
	return ((char) (c + (char) i));
}

void	test_strmapi(void)
{
	char const	s1[] = "00000000";
	char const	s0[] = "";
	char		*s2;

	printf("...ft_strmapi\n");
	printf("[%s] -> ", s1);
	s2 = ft_strmapi(s1, &f_strmapi);
	printf("[%s]\n", s2);
	assert(strcmp("01234567", s2) == 0);
	free(s2);
	s2 = ft_strmapi(s0, &f_strmapi);
	printf("[%s] -> [%s]\n", s0, s2);
	free(s2);
}
