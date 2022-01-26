/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:40:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 18:58:22 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	test1()
{
	return ft_isprint(-1);
}
static int	test2()
{
	return ft_isprint(5);
}
static int	test3()
{
	return ft_isprint(' ');
}
static int	test4()
{
	return ft_isprint('~');
}
static int	test5()
{
	return ft_isprint(5148);
}

t_tests_list	*is_print_list()
{
	t_tests_list	*list = init_tests_list("Is print");
	add_test(list, "Negative char", "ft_isprint(-1)", FALSE, INT_VALUE, &test1, 0);
	add_test(list, "Not printable", "ft_isprint(5)", FALSE, INT_VALUE, &test2, 0);
	add_test(list, "Space", "ft_isprint(' ')", FALSE, INT_VALUE, &test3, 1);
	add_test(list, "Tild", "ft_isprint('~')", FALSE, INT_VALUE, &test4, 1);
	add_test(list, "Not a char", "ft_isprint(5148)", FALSE, INT_VALUE, &test5, 0);
	return (list);
}