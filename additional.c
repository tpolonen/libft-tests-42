/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:42 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/12 11:50:33 by tpolonen         ###   ########.fr       */
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
		printf("%p: %d\n", ptr + i, *(int *) (ptr + i));
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
	assert(ptr == 0);
}

void	test_strnew(void)
{
	char	*str;
	size_t	size, i;

	printf("...ft_strnew\n");
	size = 8;
	str = ft_strnew(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		assert(str[i] == '\0');
		i++;
	}
	free(str);
}

void	test_strdel(void)
{
	char	*str;

	printf("...ft_strdel\n");
	str = (char *) malloc(sizeof(char) * 8);
	ft_strdel(&str);
	assert(str == 0);
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
	int		i;

	printf("...ft_striter\n");
	ft_striter(str, &f_striter);
	i = 0;
	while (i < 8)
		assert(str[i++] == 'a');
	assert(str[i] == '\0');
}

static void	f_striteri(unsigned int i, char *c)
{
	*c = '0' + i;
}

void	test_striteri(void)
{
	char	str[] = "fortytwo";
	int		i;

	printf("...ft_striteri\n");
	ft_striteri(str, &f_striteri);
	i = 0;
	while (i < 8)
	{
		assert(str[i] == '0' + i);
		i++;
	}
	assert(str[i] == '\0');
}

static char	f_strmap(char c)
{
	return (c + 1);
}

void	test_strmap(void)
{
	char const	s1[] = "fortytwo";
	char		*s2;

	printf("...ft_strmap\n");
	s2 = ft_strmap(s1, &f_strmap);
	printf("%s\n", s2);
	assert(strcmp("gpsuzuxp", s2) == 0);
	free(s2);
}

static char	f_strmapi(unsigned int i, char c)
{
	return (c + i);
}

void	test_strmapi(void)
{
	char const	s1[] = "00000000";
	char		*s2;

	printf("...ft_strmapi\n");
	s2 = ft_strmapi(s1, &f_strmapi);
	printf("%s\n", s2);
	assert(strcmp("01234567", s2) == 0);
	free(s2);
}

void	test_strequ(void)
{
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortytwo";
	char const	s3[] = "fortyseven";

	printf("...ft_strequ\n");
	assert(ft_strequ(s1, s2) == 1);
	assert(ft_strequ(s1, s3) == 0);
}

void	test_strnequ(void)
{
	char const	s1[] = "fortytwo";
	char const	s2[] = "fortyseven";

	printf("...ft_strnequ\n");
	assert(ft_strnequ(s1, s2, 5) == 1);
	assert(ft_strnequ(s1, s2, 8) == 0);
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
	char const	s1[] = "\t\n forty \t\n two \t\n";
	char const	s2[] = "forty \t\n two \t\n";
	char const	s3[] = "\t\n forty \t\n two";
	char		*str;

	printf("...ft_strtrim\n");
	str = ft_strtrim(s1);
	printf("%s\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s2);
	printf("%s\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
	str = ft_strtrim(s3);
	printf("%s\n", str);
	assert(strcmp("forty \t\n two", str) == 0);
	free(str);
}

static void	free_str_arr(char **str_arr)
{
	while (**str_arr)
		free(*str_arr++);
	free(*str_arr);
}

static void	validate_split(char const *s, char c, size_t i, char const *expected)
{
	char	**words;

	words = ft_strsplit(s, c);
	printf("[%s]\n", words[i]);
	assert(strcmp(words[i], expected) == 0);
	free_str_arr(words);
	free(words);
}

static void validate_full_split(char const *s, char c, char const **expected)
{
	char	**words;
	int	i = 0;

	words = ft_strsplit(s, c);
	while (words[i][0])
	{
		printf("[%s] vs [%s]\n", words[i], expected[i]);
		assert(strcmp(words[i], expected[i]) == 0);
		i++;
	}
	printf("[%s] vs [%s]\n", words[i], expected[i]);
	assert(strcmp(words[i], expected[i]) == 0);	
	free_str_arr(words);
	free(words);
}


void	test_strsplit(void)
{
	char const	s1[] = "The ships hung in the sky in much the same way that bricks don't.";
	char const	s2[] = "Time is an illusion. Lunchtime doubly so.";
	char const	s3[] = "//////////Don't/////////// ////////////Panic////////!////";
	char const	s4[] = "fortytwo";
	char const	s5[] = "";

	char const *full_s1[] = { "The", "ships", "hung", "in", "the", "sky", "in", "much", "the", "same", "way", "that", "bricks", "don't.", "\0" };

	printf("...ft_strsplit\n");
	validate_split(s1, ' ', 7, "much");
	validate_split(s2, '.', 1, " Lunchtime doubly so");
	validate_split(s3, '/', 3, "!");
	validate_split(s4, '\t', 0, "fortytwo");
	validate_split(s4, '\a', 1, "\0");
	validate_split(s5, '\n', 0, "\0");
	validate_full_split(s1, ' ', full_s1);
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
}
