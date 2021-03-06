/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:34:06 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 11:07:56 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# include "libunit.h"
# include "libft.h"

t_tests_list	*is_alpha_list();
t_tests_list	*is_digit_list();
t_tests_list	*is_alnum_list();
t_tests_list	*is_ascii_list();
t_tests_list	*is_print_list();
t_tests_list	*strlen_list();
t_tests_list	*memset_list();
t_tests_list	*bzero_list();
t_tests_list	*memcpy_list();
t_tests_list	*atoi_list();
t_tests_list	*itoa_list();
t_tests_list	*putnbr_list();
t_tests_list	*split_list();
t_tests_list	*join_list();
t_tests_list	*putchar_list();
t_tests_list	*putstr_list();
t_tests_list	*putendl_list();
t_tests_list	*strdup_list();

#endif