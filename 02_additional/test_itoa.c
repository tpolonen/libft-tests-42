/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:25:04 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:25:23 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	validate_itoa(int n)
{
	char	itoa[30];
	char*	result;

	sprintf(itoa, "%d", n);
	result = ft_itoa(n);
	printf("expecting [%s], got ", itoa);
	printf("[%s]\n", result);
	assert(strcmp(result, itoa) == 0);
	free(result);
}

void	test_itoa(void)
{
	int	n1 = 42;
	int	n2 = -42;
	int	n3 = 0;
	int n4 = INT_MIN;
	int	n5 = INT_MAX;

	printf("...ft_itoa\n");
	validate_itoa(n1);
	validate_itoa(n2);
	validate_itoa(n3);
	validate_itoa(n4);
	validate_itoa(n5);
	for (size_t len = 1; len < 11; len++)
	{
		validate_itoa((int) randi_len(len));
		validate_itoa((int) (-(randi_len(len))));
	}
}
