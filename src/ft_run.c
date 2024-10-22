/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:59:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 18:13:42 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_run(t_format *fm, int put_result)
{
	if (put_result == -1)
		fm->put_count = -1;
	if (fm->put_count != -1)
		fm->put_count += put_result;
}
//TODO LES REMETRE DANS format_di

void	ft_run_precision(t_format *fm, long n, char *str, int str_len)
{
	char	is_sign_print;
	int		padding;

	is_sign_print = (fm->sign_positive || n < 0);
	padding = fm->width - fm->precision - is_sign_print;
	if (!fm->is_padright)
		ft_run(fm, ft_put_char_n(' ', padding));
	ft_run(fm, ft_put_sign(n, fm));
	ft_run(fm, ft_put_padleft(str + 1, str_len - 1, fm->precision, '0'));
	if (fm->is_padright)
		ft_run(fm, ft_put_char_n(' ', padding));
	return ;
}

void	ft_run_expand_zero(t_format *fm, long n, char *str, int str_len)
{
	ft_run(fm, ft_put_sign(n, fm));
	ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm));
}
