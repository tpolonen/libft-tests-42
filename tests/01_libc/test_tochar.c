/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tochar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:10:02 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 22:10:21 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	validate_charconv(int (*ft_func)(int), int (*lib_func)(int))
{
	int c;

	c = 0;
	while (c <= CHAR_MAX)
	{
		if (ft_func(c) != lib_func(c))
		{
			printf("failed for c=%d [%c]\n", c, c);
			abort();
		}
		c++;
	}
}

void	test_toupper(void)
{
	printf("...ft_toupper\n");
	validate_charconv(&ft_toupper, &toupper);
}

void	test_tolower(void)
{
	printf("...ft_tolower\n");
	validate_charconv(&ft_tolower, &tolower);
}
