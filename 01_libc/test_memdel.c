/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:15:18 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:15:36 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memdel(void)
{
	void	*ptr;

	printf("...ft_memdel\n");
	ptr = malloc(8);
	ft_memdel(&ptr);
	assert(ptr == NULL);
}
