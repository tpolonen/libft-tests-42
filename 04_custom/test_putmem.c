/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:13:08 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/08 20:30:52 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_putmem(void)
{
	FILE	*file;
	char	str[42];
	char	buf[42];

	printf("...ft_putmem\n");
	rand_str(str, 41);
	bzero(buf, 42);
	file = freopen(FPATH, "w", stdout);
	ft_putmem(str, 42);
	fclose(file);
	file = fopen(FPATH, "r");
	fread(buf, 42, 1, file);
	fclose(file);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strcmp(buf, str) == 0);
	remove(FPATH);
}
