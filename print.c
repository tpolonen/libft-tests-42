/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:48:14 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/03 17:41:25 by tpolonen         ###   ########.fr       */
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
	FILE	*fd;
	char	*buf;
	char	str[] = "The ships hung in the sky in much the same way that bricks don't.";

	printf("...ft_putstr\n");
	buf = (char *) malloc(sizeof(char) * (strlen(str) + 1));
	fd = freopen(FPATH, "w", stdout);
	ft_putstr(str);
	fclose(fd);
	fd = fopen(FPATH, "r");
	fread(buf, strlen(str) + 1, 1, fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strcmp(buf, str) == 0);
	remove(FPATH);
}

void	test_putendl(void)
{
	FILE	*fd;
	char	*buf;
	char	str[] = "Don't Panic!";

	printf("...ft_putendl\n");
	buf = (char *) malloc(sizeof(char) * (strlen(str) + 2));
	fd = freopen(FPATH, "w", stdout);
	ft_putendl(str);
	fclose(fd);
	fd = fopen(FPATH, "r");
	fread(buf, strlen(str) + 2, 1, fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strncmp(buf, str, strlen(str)) == 0);
	assert(buf[strlen(str)] == '\n');
	remove(FPATH);
}

static void	validate_putnbr(int n, char const *expected)
{
	FILE	*fd;
	char	buf[12];

	bzero(buf, 12);
	fd = freopen(FPATH, "w", stdout);
	ft_putnbr(n);
	fclose(fd);
	fd = fopen(FPATH, "r");
	fread(buf, 12, 1, fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strcmp(buf, expected) == 0);
	remove(FPATH);
}

void	test_putnbr(void)
{
	int	n1 = 42;
	int	n2 = -42;
	int	n3 = 0;
	int n4 = -2147483647;
	int	n5 = 2147483647;

	printf("...ft_putnbr\n");
	validate_putnbr(n1, "42");
	validate_putnbr(n2, "-42");
	validate_putnbr(n3, "0");
	validate_putnbr(n4, "-2147483647");
	validate_putnbr(n5, "2147483647");
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

