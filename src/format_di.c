/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:08:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 23:23:19 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_sign(int n, t_format *format)
{
	if (n < 0)
	{
		format->width--;
		return (write(1, &"-", 1));
	}
	if (format->sign_positive)
	{
		format->width--;
		return (write(1, &format->sign_positive, 1));
	}
	return (0);
}

int	format_di(va_list args, t_format *format)
{
	char	str[12];
	int		str_len;
	int		n;

	n = va_arg(args, int);
	str_len = ft_itoa(str, n, "0123456789", format);
	if (format->is_expand_zero)
	{
		if (write_sign(n, format) == -1)
			return (-1);
		return (ft_pad(str + 1, str_len - 1, format));
	}
	if (format->precision)
	{
		if (write_sign(n, format) == -1)
			return (-1);
		if (ft_write_n(' ', format->width - format->precision) == -1)
			return (-1);
		return (ft_padleft(str + 1, str_len - 1, format->precision, '0'));
	}
	if (!format->sign_positive && n > 0)
		return (ft_pad(str + 1, str_len - 1, format));
	return (ft_pad(str, str_len, format));
}
