/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:40:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 18:50:18 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	test1()
{
	return ft_isalpha(-1);
}
static int	test2()
{
	return ft_isalpha(5);
}
static int	test3()
{
	return ft_isalpha('g');
}
static int	test4()
{
	return ft_isalpha('G');
}
static int	test5()
{
	return ft_isalpha(5148);
}

t_tests_list	*is_alpha_list()
{
	t_tests_list	*list = init_tests_list("Is alpha");
	add_test(list, "Negative char", "ft_isalpha(-1)", FALSE, INT_VALUE, &test1, 0);
	add_test(list, "Not alpha", "ft_isalpha(5)", FALSE, INT_VALUE, &test2, 0);
	add_test(list, "Lowercase", "ft_isalpha('g')", FALSE, INT_VALUE, &test3, 1);
	add_test(list, "Uppercase", "ft_isalpha('G')", FALSE, INT_VALUE, &test4, 1);
	add_test(list, "Not a char", "ft_isalpha(5148)", FALSE, INT_VALUE, &test5, 0);
	return (list);
}