/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:22:19 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:22:53 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strjoin(void)
{
	char const	s1[] = "forty";
	char const	s2[] = "two";
	char		*str;

	printf("...ft_strjoin\n");
	str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	assert(strcmp("fortytwo", str) == 0);
	free(str);
}
