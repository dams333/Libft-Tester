/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:40:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 18:57:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	test1()
{
	return ft_isascii(-1);
}
static int	test2()
{
	return ft_isascii(0);
}
static int	test3()
{
	return ft_isascii('g');
}
static int	test4()
{
	return ft_isascii(127);
}
static int	test5()
{
	return ft_isascii(5148);
}

t_tests_list	*is_ascii_list()
{
	t_tests_list	*list = init_tests_list("Is ascii");
	add_test(list, "Negative char", "ft_isascii(-1)", FALSE, INT_VALUE, &test1, 0);
	add_test(list, "Char 0", "ft_isascii(0)", FALSE, INT_VALUE, &test2, 1);
	add_test(list, "Alpha", "ft_isascii('g')", FALSE, INT_VALUE, &test3, 1);
	add_test(list, "Del", "ft_isascii(127)", FALSE, INT_VALUE, &test4, 1);
	add_test(list, "Not a char", "ft_isascii(5148)", FALSE, INT_VALUE, &test5, 0);
	return (list);
}