/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:20:28 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:20:45 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strequ(void)
{
	char const	s0[] = "";
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortytwo";
	char const	s3[] = "fortyseven";

	printf("...ft_strequ\n");
	assert(ft_strequ(s0, "") == 1);
	assert(ft_strequ(s1, s2) == 1);
	assert(ft_strequ(s1, s3) == 0);
}
