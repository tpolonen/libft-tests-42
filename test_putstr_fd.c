/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:10:11 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/01 19:10:29 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

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
