/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:48:14 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/18 14:29:48 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

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
	char	buf[13];

	bzero(buf, 13);
	fd = freopen(FPATH, "w", stdout);
	ft_putnbr(n);
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
	int	n1 = 42;
	int	n2 = -42;
	int	n3 = 0;
	int n4 = INT_MIN;
	int	n5 = INT_MAX;
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
		signed long nbr = randi_len(len);
		sprintf(buf, "%d", nbr);
		validate_putnbr(nbr, buf);
		bzero(buf, 30);
		nbr = -nbr;
		sprintf(buf, "%d", nbr);
		validate_putnbr(nbr, buf);
		bzero(buf, 30);
	}
}

void	test_putchar_fd(void)
{
	char	buf;
	int 	fd = open(FPATH, O_WRONLY | O_CREAT, 0666);
		
	printf("...ft_putchar_fd\n");
	if (fd != -1)
	{
		ft_putchar_fd('!', fd);
		close(fd);
		fd = open(FPATH, O_RDONLY);
		read(fd, &buf, 1);
		close(fd);
		printf("[%c]\n", buf);
		assert(buf == '!');
		remove(FPATH);
	}
	else printf("opening fd failed\n");
}

void	test_putstr_fd(void)
{
	char	buf[300];
	char	str[] = "The ships hung in the sky in much the same way that bricks don't.";
	int		fd = open(FPATH, O_WRONLY | O_CREAT, 0666);

	printf("...ft_putstr_fd\n");
	bzero(buf, 300);
	if (fd != -1)
	{
		ft_putstr_fd(str, fd);
		close(fd);
		fd = open(FPATH, O_RDONLY);
		read(fd, buf, strlen(str));
		close(fd);
		printf("[%s]\n", buf);
		assert(strcmp(buf, str) == 0);
		remove(FPATH);
	}
	else printf("opening fd failed\n");
}

void	test_putendl_fd(void)
{
	char	buf[42];
	char	str[] = "Don't Panic!";
	size_t	len = strlen(str);
	int		fd = open(FPATH, O_WRONLY | O_CREAT, 0666);

	printf("...ft_putendl_fd\n");
	bzero(buf, 42);
	if (fd != -1)
	{
		ft_putendl_fd(str, fd);
		close(fd);
		fd = open(FPATH, O_RDONLY);
		read(fd, buf, len + 1);
		close(fd);
		printf("[%s]\n", buf);
		assert(strncmp(buf, str, len) == 0);
		assert(buf[len] == '\n');
		remove(FPATH);
	}
	else printf("opening fd failed\n");
}

static void	validate_putnbr_fd(int n)
{
	char	buf[30];
	char	verif[30];
	size_t	len;

	bzero(buf, 30);
	bzero(verif, 30);
	len = sprintf(verif, "%d", n);
	int fd = open(FPATH, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		printf("opening fd failed\n");
		return ;
	}
	ft_putnbr_fd(n, fd);
	close(fd);
	fd = open(FPATH, O_RDONLY);
	read(fd, buf, len);
	close(fd);
	printf("[%s]\n", buf);
	assert(strcmp(buf, verif) == 0);
	remove(FPATH);
}

void	test_putnbr_fd(void)
{
	printf("...ft_putnbr_fd\n");
	validate_putnbr_fd(42);
	validate_putnbr_fd(-42);
	validate_putnbr_fd(0);
	validate_putnbr_fd(INT_MIN);
	validate_putnbr_fd(INT_MAX);
	for (size_t len = 1; len < 11; len++)
	{
		validate_putnbr_fd(randi_len(len));
		validate_putnbr_fd(-(randi_len(len)));
	}
}
