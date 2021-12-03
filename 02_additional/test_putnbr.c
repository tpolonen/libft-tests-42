/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:36 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/01 19:09:07 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

static void	validate_putnbr(signed long  n, char const *expected)
{
	FILE	*fd;
	char	buf[13];

	printf("[%s] -> ", expected);
	bzero(buf, 13);
	fd = freopen(FPATH, "w", stdout);
	ft_putnbr((int) n);
	fclose(fd);
	fd = fopen(FPATH, "r");
	fread(buf, 13, 1, fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strcmp(buf, expected) == 0);
	remove(FPATH);
}

void	test_putnbr(void)
{
	signed long	n1 = 42;
	signed long	n2 = -42;
	signed long	n3 = 0;
	signed long n4 = INT_MIN;
	signed long	n5 = INT_MAX;
	char	buf[30];

	printf("...ft_putnbr\n");
	validate_putnbr(n1, "42");
	validate_putnbr(n2, "-42");
	validate_putnbr(n3, "0");
	bzero(buf, 30);
	sprintf(buf, "%d", INT_MIN);
	validate_putnbr(n4, buf);
	bzero(buf, 30);
	sprintf(buf, "%d", INT_MAX);
	validate_putnbr(n5, buf);
	bzero(buf, 30);
	for (size_t len = 1; len < 11; len++)
	{
		signed long nbr = (signed long) randi_len(len);
		sprintf(buf, "%ld", nbr);
		validate_putnbr(nbr, buf);
		bzero(buf, 30);
		nbr = -nbr;
		sprintf(buf, "%ld", nbr);
		validate_putnbr(nbr, buf);
		bzero(buf, 30);
	}
}
