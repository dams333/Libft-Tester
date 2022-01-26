/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:40:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 18:53:07 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	test1()
{
	return ft_isalnum(-1);
}
static int	test2()
{
	return ft_isalnum(5);
}
static int	test3()
{
	return ft_isalnum('g');
}
static int	test4()
{
	return ft_isalnum('G');
}
static int	test5()
{
	return ft_isalnum('0');
}
static int	test6()
{
	return ft_isalnum('9');
}
static int	test7()
{
	return ft_isalnum(5148);
}

t_tests_list	*is_alnum_list()
{
	t_tests_list	*list = init_tests_list("Is alnum");
	add_test(list, "Negative char", "ft_isalnum(-1)", FALSE, INT_VALUE, &test1, 0);
	add_test(list, "Not alnum", "ft_isalnum(5)", FALSE, INT_VALUE, &test2, 0);
	add_test(list, "Lowercase", "ft_isalnum('g')", FALSE, INT_VALUE, &test3, 1);
	add_test(list, "Uppercase", "ft_isalnum('G')", FALSE, INT_VALUE, &test4, 1);
	add_test(list, "zero", "ft_isalnum('0')", FALSE, INT_VALUE, &test5, 1);
	add_test(list, "nine", "ft_isalnum('9')", FALSE, INT_VALUE, &test6, 1);
	add_test(list, "Not a char", "ft_isalnum(5148)", FALSE, INT_VALUE, &test7, 0);
	return (list);
}