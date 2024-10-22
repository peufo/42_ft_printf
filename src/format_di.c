/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:08:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 15:00:59 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_di(va_list *args, t_format *fm)
{
	char	str[12];
	int		str_len;
	int		n;
	int		is_sign_print;

	n = va_arg(*args, int);
	str_len = ft_itoa(str, n, "0123456789", fm);
	is_sign_print = (fm->sign_positive || n < 0);
	if (fm->is_expand_zero)
	{
		ft_run(fm, ft_put_sign(n, fm));
		ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm));
		return ;
	}
	if (fm->precision)
	{
		if (!fm->is_padright)
			ft_run(fm, ft_put_char_n(' ', fm->width - fm->precision - is_sign_print));
		ft_run(fm, ft_put_sign(n, fm));
		ft_put_padleft(str + 1, str_len - 1, fm->precision, '0');
		if (fm->is_padright)
			ft_run(fm, ft_put_char_n(' ', fm->width - fm->precision));
		return ;
	}
	if (!is_sign_print)
	{
		ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm));
		return ;
	}
	ft_run(fm, ft_put_pad(str, str_len, fm));
	return ;
}
