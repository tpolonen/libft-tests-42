/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:15:49 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:16:06 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strnew(void)
{
	char *str0 = "fortytwo";
	char *str1;

	printf("...ft_strnew\n");
	str1 = ft_strnew(strlen(str0));
	printf("before strcpy:\t{");
	print_mem_val(str1, strlen(str0) + 1);
	printf("}\nafter strcpy:\t[");
	strcpy(str1, str0);
	printf("%s]\n", str1);
	free(str1);
}
