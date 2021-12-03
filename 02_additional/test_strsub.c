/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:21:54 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:22:14 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strsub(void)
{
	char const	s1[] = "get fortytwo from this string";
	char		*s2;

	printf("...ft_strsub\n");
	s2 = ft_strsub(s1, 4, 8);
	printf("%s\n", s2);
	assert(strcmp("fortytwo", s2) == 0);
	free(s2);
}
