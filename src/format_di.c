/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:08:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 16:18:39 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_run_precision(t_format *fm, long n, char *str, int str_len)
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

static void	ft_run_expand_zero(t_format *fm, long n, char *str, int str_len)
{
	ft_run(fm, ft_put_sign(n, fm));
	ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm));
}

void	format_di(va_list *args, t_format *fm)
{
	char	str[12];
	int		str_len;
	int		n;

	n = va_arg(*args, int);
	str_len = ft_itoa(str, n, "0123456789", fm);
	if (fm->is_expand_zero)
		return (ft_run_expand_zero(fm, n, str, str_len));
	if (fm->precision)
		return (ft_run_precision(fm, n, str, str_len));
	if (!fm->sign_positive && n >= 0)
		return (ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm)));
	ft_run(fm, ft_put_pad(str, str_len, fm));
}
