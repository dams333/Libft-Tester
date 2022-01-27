/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:28:23 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 10:50:57 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char *join(char **str)
{
	int length = 0;
	int words = 0;
	for(int i = 0; str[i]; i++)
	{
		length += strlen(str[i]);
		words++;
	}
	char *result = malloc(sizeof(char) * (length + (words - 1) + 1));
	int j = 0;
	for(int i = 0; str[i]; i++)
	{
		for(int k = 0; str[i][k]; k++)
			result[j++] = str[i][k];
		if(i != (words - 1))
			result[j++] = '|';
	}
	result[j] = '\0';
	return result;
}

static char *test1()
{
	return join(ft_split("  Salut     ca va ?  ", ' '));
}
static char *test2()
{
	return join(ft_split("Salutcava?", ' '));
}
static char *test3()
{
	return join(ft_split("  Salutcava? ", ' '));
}
static char *test4()
{
	return join(ft_split("", ' '));
}
static char *test5()
{
	return join(ft_split("Salut ca va ?", '\0'));
}
static char *test6()
{
	start_malloc_catcher();
	char **str = ft_split("  Salut     ca va ?  ", ' ');
	for(int i = 0; str[i]; i++)
		free(str[i]);
	free(str);
	stop_malloc_catcher_and_print_leaks();
	return "0";
}
static char *test7()
{
	start_malloc_catcher();
	start_malloc_breaker();
	free(ft_split("  Salut     ca va ?  ", ' '));
	stop_malloc_breaker();
	stop_malloc_catcher();
	return "0";
}

t_tests_list	*split_list()
{
	t_tests_list	*list = init_tests_list("Split");
	add_test(list, "Basic", "ft_split(\"  Salut     ca va ?  \", \' \')", FALSE, STR_VALUE, &test1, "Salut|ca|va|?");
	add_test(list, "No seprartors", "ft_split(\"Salutcava?\", \' \')", FALSE, STR_VALUE, &test2, "Salutcava?");
	add_test(list, "Just at start and end", "ft_split(\"  Salutcava? \", \' \')", FALSE, STR_VALUE, &test3, "Salutcava?");
	add_test(list, "Empty string", "ft_split(\"\", \' \')", FALSE, STR_VALUE, &test4, "");
	add_test(list, "Seprator \\0", "ft_split(\"Salut ca va ?\", \'\\0\')", FALSE, STR_VALUE, &test5, "Salut ca va ?");
	add_test(list, "Leaks", "ft_split(\"  Salut     ca va ?  \", \' \')", FALSE, STR_VALUE, &test6, "0");
	add_test(list, "Malloc", "ft_split(\"  Salut     ca va ?  \", \' \') with failed malloc", FALSE, STR_VALUE, &test7, "0");
	return (list);
}