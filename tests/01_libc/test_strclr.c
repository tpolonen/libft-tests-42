/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:16:37 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:17:13 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void 	test_strclr(void)
{
	char	str[] = "fortytwo";
	int		i;

	printf("...ft_strclr\n");
	ft_strclr(str);
	i = 0;
	while (i <= 8)
	{
		assert(str[i] == '\0');
		i++;
	}
}
