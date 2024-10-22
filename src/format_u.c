/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:35:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 18:08:39 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_u(va_list *args, t_format *fm)
{
	char			str[11];
	int				str_len;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	str_len = ft_uitoa(str, n, "0123456789");
	if (fm->precision > str_len)
	{
		if (!fm->is_padright)
			ft_run(fm, ft_put_char_n(' ', fm->width - fm->precision - 1));
		ft_run(fm, ft_put_padleft(str, str_len, fm->precision, '0'));
		if (fm->is_padright)
			ft_run(fm, ft_put_char_n(' ', fm->width - fm->precision - 1));
		return ;
	}
	ft_run(fm, ft_put_pad(str, str_len, fm));
}
