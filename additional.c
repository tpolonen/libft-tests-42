/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/25 14:08:25 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memalloc(void)
{
	void	*ptr;
	int		i;

	printf("...ft_memalloc\n");
	ptr = ft_memalloc(8);
	i = 0;
	while (i < 8)
	{
		printf("%p: %d\n", ptr + i, *(char *) (ptr + i));
		assert(*(char *) (ptr + i) == 0);
		i++;
	}
	free(ptr);
}

void	test_memdel(void)
{
	void	*ptr;

	printf("...ft_memdel\n");
	ptr = malloc(8);
	ft_memdel(&ptr);
	assert(ptr == NULL);
}

void	test_strnew(void)
{
	char *str0 = "fortytwo";
	char *str1;

	printf("...ft_strnew\n");
	str1 = ft_strnew(strlen(str0));
	printf("before strcpy:\t{");
	print_mem_val(str1, strlen(str0) + 1);
	printf("}\nafter strcpy:\t[");
	strcpy(str1, str0);
	printf("%s]\n", str1);
	free(str1);
}

void	test_strdel(void)
{
	char	*str;

	printf("...ft_strdel\n");
	str = (char *) malloc(sizeof(char) * 8);
	ft_strdel(&str);
	assert(str == NULL);
}

void 	test_strclr(void)
{
	char	str[] = "fortytwo";
	int		i;

	printf("...ft_strclr\n");
	ft_strclr(str);
	i = 0;
	while (i <= 8)
	{
		assert(str[i] == '\0');
		i++;
	}
}

static void	f_striter(char *c)
{
	*c = 'a';
}

void	test_striter(void)
{
	char	str[] = "fortytwo";
	char	s0[] = "";
	int		i;

	printf("...ft_striter\n");
	printf("[%s] -> ", str);
	ft_striter(str, &f_striter);
	printf("[%s]\n", str);
	i = 0;
	while (i < 8)
		assert(str[i++] == 'a');
	assert(str[i] == '\0');
	ft_striter(s0, &f_striter);
	printf("[%s] -> [%s]\n", "", s0);
	assert(strcmp(s0, "") == 0);
}

static void	f_striteri(unsigned int i, char *c)
{
	*c = (char) ('0' + i);
}

void	test_striteri(void)
{
	char	str[] = "fortytwo";
	char	s0[] = "";
	int		i;

	printf("...ft_striteri\n");
	printf("[%s] -> ", str);
	ft_striteri(str, &f_striteri);
	printf("[%s]\n", str);
	i = 0;
	while (i < 8)
	{
		assert(str[i] == '0' + i);
		i++;
	}
	assert(str[i] == '\0');
	ft_striteri(s0, &f_striteri);
	printf("[%s] -> [%s]\n", "", s0);
	assert(strcmp(s0, "") == 0);
}

static char	f_strmap(char c)
{
	return (c + 1);
}

void	test_strmap(void)
{
	char const	s1[] = "fortytwo";
	char const	s0[] = "";
	char		*s2;

	printf("...ft_strmap\n");
	printf("[%s] -> ", s1);
	s2 = ft_strmap(s1, &f_strmap);
	printf("[%s]\n", s2);
	assert(strcmp("gpsuzuxp", s2) == 0);
	free(s2);
	s2 = ft_strmap(s0, &f_strmap);
	printf("[%s] -> [%s]\n", s0, s2);
	free(s2);
}

static char	f_strmapi(unsigned int i, char c)
{
	return ((char) (c + (char) i));
}

void	test_strmapi(void)
{
	char const	s1[] = "00000000";
	char const	s0[] = "";
	char		*s2;

	printf("...ft_strmapi\n");
	printf("[%s] -> ", s1);
	s2 = ft_strmapi(s1, &f_strmapi);
	printf("[%s]\n", s2);
	assert(strcmp("01234567", s2) == 0);
	free(s2);
	s2 = ft_strmapi(s0, &f_strmapi);
	printf("[%s] -> [%s]\n", s0, s2);
	free(s2);
}

void	test_strequ(void)
{
	char const	s0[] = "";
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortytwo";
	char const	s3[] = "fortyseven";

	printf("...ft_strequ\n");
	assert(ft_strequ(s0, "") == 1);
	assert(ft_strequ(s1, s2) == 1);
	assert(ft_strequ(s1, s3) == 0);
}

void	test_strnequ(void)
{
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortyseven";

	printf("...ft_strnequ\n");
	for (size_t i = 0; i <= strlen(s2); i++)
	{
		printf("%zu: %d\n", i, ft_strnequ(s1, s2, i));
		assert(ft_strnequ(s1, s2, i) == (strncmp(s1, s2, i) != 0 ? 0 : 1));
	}
}

void	test_strsub(void)
{
	char const	s1[] = "get fortytwo from this string";
	char		*s2;

	printf("...ft_strsub\n");
	s2 = ft_strsub(s1, 4, 8);
	printf("%s\n", s2);
	assert(strcmp("fortytwo", s2) == 0);
	free(s2);
}

void	test_strjoin(void)
{
	char const	s1[] = "forty";
	char const	s2[] = "two";
	char		*str;

	printf("...ft_strjoin\n");
	str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	assert(strcmp("fortytwo", str) == 0);
	free(str);
}

void	test_strtrim(void)
{
	char const	s0[] = "\t\n \t\n \t\n ";
	char const	s1[] = "\t\n forty \t\n two \t\n";
	char const	s2[] = "forty \t\n two \t\n";
	char const	s3[] = "\t\n forty \t\n two";
	char const	s4[] = "fortytwo";
	char const	s5[] = "        f              ";
	char		*str;

	printf("...ft_strtrim\n");
	str = ft_strtrim(s0);
	printf("[%s]\n", str);
	assert(strcmp("", str) == 0);
	free(str);
	str = ft_strtrim(s1);
	printf("[%s]\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s2);
	printf("[%s]\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s3);
	printf("[%s]\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s4);
	printf("[%s]\n", str);
	assert(strcmp("fortytwo", str) == 0);
	free(str);
	str = ft_strtrim(s5);
	printf("[%s]\n", str);
	assert(strcmp("f", str) == 0);
	free(str);

}

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

static void	validate_itoa(int n)
{
	char	itoa[30];
	char*	result;

	sprintf(itoa, "%d", n);
	result = ft_itoa(n);
	printf("expecting [%s], got ", itoa);
	printf("[%s]\n", result);
	assert(strcmp(result, itoa) == 0);
	free(result);
}

void	test_itoa(void)
{
	int	n1 = 42;
	int	n2 = -42;
	int	n3 = 0;
	int n4 = INT_MIN;
	int	n5 = INT_MAX;

	printf("...ft_itoa\n");
	validate_itoa(n1);
	validate_itoa(n2);
	validate_itoa(n3);
	validate_itoa(n4);
	validate_itoa(n5);
	for (size_t len = 1; len < 11; len++)
	{
		validate_itoa((int) randi_len(len));
		validate_itoa((int) (-(randi_len(len))));
	}
}
