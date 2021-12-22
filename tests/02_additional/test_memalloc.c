/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:14:53 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:15:12 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memalloc(void)
{
	void	*ptr;
	int		i;

	printf("...ft_memalloc\n");
	ptr = ft_memalloc(8);
	i = 0;
	while (i < 8)
	{
		printf("%p: %d\n", ptr + i, *(char *) (ptr + i));
		assert(*(char *) (ptr + i) == 0);
		i++;
	}
	free(ptr);
}
