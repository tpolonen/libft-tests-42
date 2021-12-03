/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:50:01 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 17:50:25 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_bzero(void)
{
	char	str1[] = "fortytwo";
	char	str2[] = "fortyone";
	size_t 	len = strlen(str1);

	printf("...ft_bzero\n");
	bzero(str1, (0));
	ft_bzero(str2, (0));
	printf("n=0\t[%s]\n", str1);
	assert(memcmp(str1, str2, sizeof(char) * 5) == 0);
	bzero(str1, len);
	ft_bzero(str2, len);
	printf("n=%zu\t[%s]\n", len, str1);
	assert(memcmp(str1, str2, sizeof(char) * len) == 0);
}
