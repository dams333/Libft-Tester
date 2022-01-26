/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 19:22:51 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	char	*str = malloc(sizeof(char) * 50);
	ft_memset(str, 'a', 10);
	str[11] = '\0';
	return str;
}
static char	*compare1()
{
	char	*str = malloc(sizeof(char) * 50);
	memset(str, 'a', 10);
	str[11] = '\0';
	return str;
}

static char	*test2()
{
	char	*str = malloc(sizeof(char) * 50);
	str[1] = '\0';
	ft_memset(str, 'a', 1);
	return str;
}
static char	*compare2()
{
	char	*str = malloc(sizeof(char) * 50);
	str[1] = '\0';
	memset(str, 'a', 1);
	return str;
}

static char	*test3()
{
	char	*str = malloc(sizeof(char) * 50);
	str[49] = '\0';
	ft_memset(str, 'a', 49);
	return str;
}
static char	*compare3()
{
	char	*str = malloc(sizeof(char) * 50);
	str[49] = '\0';
	memset(str, 'a', 49);
	return str;
}

t_tests_list	*memset_list()
{
	t_tests_list	*list = init_tests_list("Memset");
	add_test(list, "Classic", "ft_memset(str, 'a', 10)", FALSE, STR_COMPARE, &test1, &compare1);
	add_test(list, "Only one", "ft_memset(str, 'a', 1)", FALSE, STR_COMPARE, &test2, &compare2);
	add_test(list, "Fill buffer", "ft_memset(str, 'a', 49)", FALSE, STR_COMPARE, &test3, &compare3);
	return (list);
}