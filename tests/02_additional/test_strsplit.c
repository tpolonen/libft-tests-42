/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:24:05 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:24:34 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	free_str_tab(char ***tab)
{
	char	**t1 = *tab;

	while (*t1 != NULL)
		free(*t1++);
	free(*t1);
	free(*tab);
}

static void	validate_split(char const *s, char c, size_t i, char const *expected)
{
	char	**tab;

	tab = ft_strsplit(s, c);
	printf("[%s]\n", tab[i]);
	assert(strcmp(tab[i], expected) == 0);
	free_str_tab(&tab);
}

static void validate_full_split(char const *s, char c, char const **expected)
{
	char	**words;
	size_t	i = 0;

	words = ft_strsplit(s, c);
	while (words[i] != NULL)
	{
		printf("[%s] vs [%s]\n", words[i], expected[i]);
		assert(strcmp(words[i], expected[i]) == 0);
		i++;
	}
	printf("[%s] vs [%s]\n", words[i], expected[i]);
	if (words[i] != NULL)
	{
		printf("failed: split array does not terminate properly\n");
		printf("expected NULL, got [%s]\n", words[i]);
		abort();
	}
	free_str_tab(&words);
}

void	test_strsplit(void)
{
	char const	s1[] = "The ships hung in the sky in much the same way that bricks don't.";
	char const	s2[] = "Time is an illusion. Lunchtime doubly so.";
	char const	s3[] = "//////////Don't/////////// ////////////Panic////////!////";
	char const	s4[] = "fortytwo";
	char const	s5[] = "";
	char const	s6[] = "-----------------------------------";

	char const *full_s1[] = { "The", "ships", "hung", "in", "the", "sky", "in", "much", "the", "same", "way", "that", "bricks", "don't.", 0 };
	char const *full_s3[] = { "Don't", " ", "Panic", "!", 0 };
	char const *full_s6[] = { 0 };

	printf("...ft_strsplit\n");
	validate_full_split(s1, ' ', full_s1);
	validate_full_split(s3, '/', full_s3);
	validate_full_split(s6, '-', full_s6);
	validate_split(s1, ' ', 7, "much");
	validate_split(s2, '.', 1, " Lunchtime doubly so");
	validate_split(s3, '/', 3, "!");
	validate_split(s4, '\t', 0, "fortytwo");

	char **tab = ft_strsplit(s5, 'a');
	assert(*tab == NULL);
	free_str_tab(&tab);
	tab = ft_strsplit(s6, '-');
	assert(*tab == NULL);
	free_str_tab(&tab);
}
