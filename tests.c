/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/10/30 19:56:16 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void	test_memalloc(void)
{
	void	*ptr;
	char	*str;
	int		i;

	ptr = ft_memalloc(sizeof(char) * 8);
	str = (char *) ptr;
	i = 0;
	while (i < 7)
	{
		str[i] = 'a';
		i++;
	}
	str[i] = '\0';
	assert(strcmp("aaaaaaa", (char *) ptr) == 0);
	free(ptr);
	str = 0;
}
