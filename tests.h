/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:49:43 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/03 13:55:21 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

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

#endif
