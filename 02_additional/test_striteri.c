/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:17:52 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:18:48 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	f_striteri(unsigned int i, char *c)
{
	*c = (char) ('0' + i);
}

void	test_striteri(void)
{
	char	str[] = "fortytwo";
	char	s0[] = "";
	int		i;

	printf("...ft_striteri\n");
	printf("[%s] -> ", str);
	ft_striteri(str, &f_striteri);
	printf("[%s]\n", str);
	i = 0;
	while (i < 8)
	{
		assert(str[i] == '0' + i);
		i++;
	}
	assert(str[i] == '\0');
	ft_striteri(s0, &f_striteri);
	printf("[%s] -> [%s]\n", "", s0);
	assert(strcmp(s0, "") == 0);
}
