/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:15:40 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 11:02:45 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	t_stdout *stdout = init_stdout_test();
	ft_putendl_fd("Hello World !", 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test2()
{
	t_stdout *stdout = init_stdout_test();
	ft_putendl_fd("", 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test3()
{
	t_stdout *stdout = init_stdout_test();
	ft_putendl_fd("\n", 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test4()
{
	t_stdout *stdout = init_stdout_test();
	ft_putendl_fd("Salut a tous ! Comment ca va la ?\n", 1);
	end_stdout_test(stdout);
	return stdout->output;
}

t_tests_list	*putendl_list()
{
	t_tests_list	*list = init_tests_list("Putendl");
	add_test(list, "Basic", "ft_putendl_fd(\"Hello World !\", 1);", FALSE, STR_VALUE, &test1, "Hello World !\n");
	add_test(list, "Empty string", "ft_putendl_fd(\"\", 1);", FALSE, STR_VALUE, &test2, "\n");
	add_test(list, "Just \\n", "ft_putendl_fd(\"\\n\", 1);", FALSE, STR_VALUE, &test3, "\n\n");
	add_test(list, "Long text", "ft_putendl_fd(\"Salut a tous ! Comment ca va la ?\\n\", 1);", FALSE, STR_VALUE, &test4, "Salut a tous ! Comment ca va la ?\n\n");
	return (list);
}