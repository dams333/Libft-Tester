/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:40:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/25 19:32:35 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	test1()
{
	return ft_strlen(NULL);
}
static int	test2()
{
	return ft_strlen("");
}
static int	test3()
{
	return ft_strlen("Salut !\n");
}
static int	test4()
{
	return ft_strlen("Salut, comment ca va ?\n Tres bien et toi ?\n");
}

t_tests_list	*strlen_list()
{
	t_tests_list	*list = init_tests_list("Strlen");
	add_test(list, "Empty", "ft_strlen(\"\")", FALSE, INT_VALUE, &test2, 0);
	add_test(list, "Classic", "ft_strlen(\"Salut !\n\")", FALSE, INT_VALUE, &test3, 8);
	add_test(list, "Long chain", "ft_strlen(\"Salut, comment ca va ?\n Tres bien et toi ?\n\")", FALSE, INT_VALUE, &test4, 43);
	add_test(list, "Null", "ft_strlen(NULL). The crash is allowed because the protection is not mandatory", TRUE, INT_VALUE, &test1, 0);
	return (list);
}