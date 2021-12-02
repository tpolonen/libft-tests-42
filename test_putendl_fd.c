/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:10:41 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/01 19:10:59 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

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
