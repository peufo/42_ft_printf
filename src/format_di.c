/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:08:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 12:18:52 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_di(va_list args, t_format *format)
{
	char	str[12];
	int		str_len;
	int		n;
	int		is_sign_print;

	n = va_arg(args, int);
	str_len = ft_itoa(str, n, "0123456789", format);
	is_sign_print = n != 0 && (format->sign_positive || n < 0);
	if (format->is_expand_zero)
	{
		if (ft_put_sign(n, format) == -1)
			return (-1);
		return (ft_put_pad(str + 1, str_len - 1, format));
	}
	if (format->precision)
	{
		if (!format->is_padright && ft_put_char_n(' ', format->width - format->precision - is_sign_print) == -1)
			return (-1);
		if (ft_put_sign(n, format) == -1)
			return (-1);
		ft_put_padleft(str + 1, str_len - 1, format->precision, '0');
		if (format->is_padright && ft_put_char_n(' ', format->width - format->precision) == -1)
			return (-1);
		return (1);
	}
	if (!is_sign_print && n != 0)
		return (ft_put_pad(str + 1, str_len - 1, format));
	return (ft_put_pad(str, str_len, format));
}
