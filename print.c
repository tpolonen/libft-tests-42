/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:48:14 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/03 14:48:15 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define FPATH ".test"

void	test_putchar(void)
{
	FILE	*fd;
	char	*c;

	printf("...ft_putchar\n");
	c = (char *) malloc(sizeof(char));
	fd = freopen(FPATH, "w", stdout);
	ft_putchar('!');
	fclose(fd);
	fd = fopen(FPATH, "r");
	*c = fgetc(fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%c]\n", *c);
	assert(*c == '!');
	remove(FPATH);
}

void	test_putstr(void)
{

}

void	test_putendl(void)
{

}

void	test_putnbr(void)
{

}

void	test_putchar_fd(void)
{
	
}

void	test_putstr_fd(void)
{
	
}

void	test_putendl_fd(void)
{
	
}

void	test_putnbr_fd(void)
{

}

