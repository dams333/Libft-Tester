/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:40:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 18:50:12 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	test1()
{
	return ft_isdigit(-1);
}
static int	test2()
{
	return ft_isdigit(5);
}
static int	test3()
{
	return ft_isdigit('0');
}
static int	test4()
{
	return ft_isdigit('9');
}
static int	test5()
{
	return ft_isdigit(5148);
}

t_tests_list	*is_digit_list()
{
	t_tests_list	*list = init_tests_list("Is digit");
	add_test(list, "Negative char", "ft_isdigit(-1)", FALSE, INT_VALUE, &test1, 0);
	add_test(list, "Not digit", "ft_isdigit(5)", FALSE, INT_VALUE, &test2, 0);
	add_test(list, "zero", "ft_isdigit('0')", FALSE, INT_VALUE, &test3, 1);
	add_test(list, "nine", "ft_isdigit('9')", FALSE, INT_VALUE, &test4, 1);
	add_test(list, "Not a char", "ft_isdigit(5148)", FALSE, INT_VALUE, &test5, 0);
	return (list);
}