/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnequ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:20:58 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:21:41 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strnequ(void)
{
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortyseven";

	printf("...ft_strnequ\n");
	for (size_t i = 0; i <= strlen(s2); i++)
	{
		printf("%zu: %d\n", i, ft_strnequ(s1, s2, i));
		assert(ft_strnequ(s1, s2, i) == (strncmp(s1, s2, i) != 0 ? 0 : 1));
	}
}
