/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ischar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:02:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 22:09:39 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	validate_chartest(int (*ft_func)(int), int (*lib_func)(int))
{
	int c;

	c = 0;
	while (c <= CHAR_MAX)
	{
		if ((ft_func(c) != 0 ? 1 : 0) != (lib_func(c) != 0 ? 1 : 0))
		{
			printf("failed for c=%d [%c]\n", c, c);
			abort();
		}
		c++;
	}
}

void	test_isalpha(void)
{
	printf("...ft_isalpha\n");
	validate_chartest(&ft_isalpha, &isalpha);
}

void	test_isdigit(void)
{
	printf("...ft_isdigit\n");
	validate_chartest(&ft_isdigit, &isdigit);
}

void	test_isalnum(void)
{
	printf("...ft_isalnum\n");
	validate_chartest(&ft_isalnum, &isalnum);
}

void	test_isascii(void)
{
	printf("...ft_isascii\n");
	validate_chartest(&ft_isascii, &isascii);
}

void	test_isprint(void)
{
	printf("...ft_isprint\n");
	validate_chartest(&ft_isprint, &isprint);
}
