/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:48:19 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 17:49:32 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memset(void)
{
	char	*ptr1 = NULL;
	char	*ptr2 = NULL;
	char	c = rand_char();

	printf("...ft_memset\n");
	ptr1 = (char *) malloc(sizeof(char) * 9);
	ptr2 = (char *) malloc(sizeof(char) * 9);
	bzero(ptr1, 9);
	bzero(ptr2, 9);
	ft_memset(ptr1, c, sizeof(char) * 8);
	memset(ptr2, c, sizeof(char) * 8);
	printf("[%s] vs [%s]\n", ptr1, ptr2);
	assert(memcmp(ptr1, ptr2, sizeof(char) * 8) == 0);
	printf("test with n=0\n");
	ft_memset(ptr1, '\t', (0));
	memset(ptr2, '\t', (0));
	assert(memcmp(ptr1, ptr2, sizeof(char) * 8) == 0);
	free(ptr1);
	free(ptr2);
}
