/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:49:43 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/07 19:15:35 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# define FPATH ".test"
# include <sys/errno.h>
# include <assert.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>

/* Utility functions */
char	rand_char(void);
char	*rand_str(size_t len);
int		rand_substrs(char **s1, char **s2, size_t len_pre, size_t len_post);

/* Functions from the "Mandatory" section */
void	test_memset(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_memchr(void);
void	test_memcmp(void);
void	test_strlen(void);
void	test_strdup(void);
void	test_strcpy(void);
void	test_strncpy(void);
void	test_strcat(void);
void	test_strncat(void);
void	test_strlcat(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strstr(void);
void	test_strnstr(void);
void	test_strcmp(void);
void	test_strncmp(void);
void	test_atoi(void);
void	test_isalpha(void);
void	test_isdigit(void);
void	test_isalnum(void);
void	test_isascii(void);
void	test_isprint(void);
void	test_toupper(void);
void	test_tolower(void);

/* Functions from the "Additional" section */
void	test_memalloc(void);
void	test_memdel(void);
void	test_strnew(void);
void	test_strdel(void);
void 	test_strclr(void);
void	test_striter(void);
void	test_striteri(void);
void	test_strmap(void);
void	test_strmapi(void);
void	test_strequ(void);
void	test_strnequ(void);
void	test_strsub(void);
void	test_strjoin(void);
void	test_strtrim(void);
void	test_strsplit(void);
void	test_itoa(void);

/* Functions that print to an fd */
void	test_putchar(void);
void	test_putstr(void);
void	test_putendl(void);
void	test_putnbr(void);
void	test_putchar_fd(void);
void	test_putstr_fd(void);
void	test_putendl_fd(void);
void	test_putnbr_fd(void);

/* Bonus Mode */

#endif
