/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:34:24 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/21 14:09:21 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <stdio.h>

void	test_part1(void)
{
	test_strlen();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	printf("OK!\n");
}

void	test_part2(void)
{
	test_toupper();
	test_tolower();
	test_memchr();
	test_strchr();
	test_strrchr();
	test_bzero();
	printf("OK!\n");
}

void	test_part3(void)
{
	test_memcpy();
	test_strcpy();
	test_strcat();
	test_strcmp();
	test_strstr();
	test_memmove();
	test_memcmp();
	printf("Functions OK, checking leaks next...\n");
	(void) getchar();
	system("leaks a.out");
}

void	test_part4(void)
{
	test_strlcat();
	test_strdup();
	test_atoi();
	test_memccpy();
	test_strnstr();
	test_strncmp();
	test_strncpy();
	test_strncat();
	printf("Functions OK, checking leaks next...\n");
	(void) getchar();
	system("leaks a.out");
}

void	test_part5(void)
{
	test_memalloc();
	test_putchar();
	test_putstr();
	test_putendl();
	test_putnbr();
	test_strnew();
	test_strdel();
	test_strclr();
	test_strequ();
	test_strnequ();
	test_strsub();
	test_strjoin();
	printf("Functions OK, checking leaks next...\n");
	(void) getchar();
	system("leaks a.out");
}

void	test_part6(void)
{
	test_memset();
	test_memdel();
	test_striter();
	test_striteri();
	test_strmap();
	test_strmapi();
	test_strtrim();
	test_strsplit();
	test_itoa();
	printf("Functions OK, checking leaks next...\n");
	(void) getchar();
	system("leaks a.out");
}
#ifdef BONUS
void	test_bonus(void)
{
	test_lstnew();
	test_lstdelone();
	test_lstdel();
	test_lstadd();
	test_lstiter();
	test_lstmap();
	printf("Functions OK, checking leaks next...\n");
	(void) getchar();
	system("leaks a.out");
}
#endif

int	main(int argc, char** argv)
{
	if (argc > 1)
	{
		argv++;
		argc--;
		while (argc > 0)
		{
			switch (**argv)
			{
				case '1':
					test_part1();
					break;
				case '2':
					test_part2();
					break;
				case '3':
					test_part3();
					break;
				case '4':
					test_part4();
					break;
				case '5':
					test_part5();
					break;
				case '6':
					test_part6();
					break;
#ifdef BONUS
				case 'b':
					test_bonus();
					break;
#endif			
			}
			(void) getchar();
			argv++;
			argc--;
		}
	}
	return (0);
}
