/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/10/30 16:41:48 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>

// TODO: replace free with ftlib-equivalent
void	test_memalloc(void)
{
	void	*ptr;
	int		i;

	ptr = ft_memalloc(sizeof(char) * 8);
	i = 0;
	while (i < 7)
	{
		(char *) ptr[i] = 'a';
		i++;
	}
	(char *) ptr[i] = '\0';
	assert(ft_strcmp("aaaaaaa", (char *) ptr) == 0);
	free(ptr);
}
