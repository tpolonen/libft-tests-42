/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:09:15 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/01 19:09:52 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

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
