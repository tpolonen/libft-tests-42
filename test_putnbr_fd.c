/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:11:19 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/01 19:11:41 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

static void	validate_putnbr_fd(signed long n)
{
	char	buf[30];
	char	verif[30];
	size_t	len;

	bzero(buf, 30);
	bzero(verif, 30);
	len = (size_t) sprintf(verif, "%d", (int) n);
	int fd = open(FPATH, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		printf("opening fd failed\n");
		return ;
	}
	ft_putnbr_fd((signed int) n, fd);
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
		validate_putnbr_fd((signed long) randi_len(len));
		validate_putnbr_fd((signed long) (-(randi_len(len))));
	}
}
