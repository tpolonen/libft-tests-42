/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:23:02 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:23:46 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_strtrim(void)
{
	char const	s0[] = "\t\n \t\n \t\n ";
	char const	s1[] = "\t\n forty \t\n two \t\n";
	char const	s2[] = "forty \t\n two \t\n";
	char const	s3[] = "\t\n forty \t\n two";
	char const	s4[] = "fortytwo";
	char const	s5[] = "        f              ";
	char		*str;

	printf("...ft_strtrim\n");
	str = ft_strtrim(s0);
	printf("[%s]\n", str);
	assert(strcmp("", str) == 0);
	free(str);
	str = ft_strtrim(s1);
	printf("[%s]\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s2);
	printf("[%s]\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s3);
	printf("[%s]\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s4);
	printf("[%s]\n", str);
	assert(strcmp("fortytwo", str) == 0);
	free(str);
	str = ft_strtrim(s5);
	printf("[%s]\n", str);
	assert(strcmp("f", str) == 0);
	free(str);
}
