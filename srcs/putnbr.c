/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:15:40 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/26 14:20:07 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	t_stdout *stdout = init_stdout_test();
	ft_putnbr_fd(0, 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test2()
{
	t_stdout *stdout = init_stdout_test();
	ft_putnbr_fd(42, 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test3()
{
	t_stdout *stdout = init_stdout_test();
	ft_putnbr_fd(-42, 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test4()
{
	t_stdout *stdout = init_stdout_test();
	ft_putnbr_fd(2147483647, 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test5()
{
	t_stdout *stdout = init_stdout_test();
	ft_putnbr_fd(-2147483648, 1);
	end_stdout_test(stdout);
	return stdout->output;
}

t_tests_list	*putnbr_list()
{
	t_tests_list	*list = init_tests_list("Putnbr");
	add_test(list, "Zero", "ft_putnbr_fd(0, 1)", FALSE, STR_VALUE, &test1, "0");
	add_test(list, "Positive", "ft_putnbr_fd(42, 1)", FALSE, STR_VALUE, &test2, "42");
	add_test(list, "Negative", "ft_putnbr_fd(-42, 1)", FALSE, STR_VALUE, &test3, "-42");
	add_test(list, "Int max", "ft_putnbr_fd(2147483647, 1)", FALSE, STR_VALUE, &test4, "2147483647");
	add_test(list, "Int min", "ft_putnbr_fd(-2147483648, 1)", FALSE, STR_VALUE, &test5, "-2147483648");
	return (list);
}