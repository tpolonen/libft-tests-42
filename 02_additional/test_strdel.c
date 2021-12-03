/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:16:15 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:16:32 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strdel(void)
{
	char	*str;

	printf("...ft_strdel\n");
	str = (char *) malloc(sizeof(char) * 8);
	ft_strdel(&str);
	assert(str == NULL);
}
