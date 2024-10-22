/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:38:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 19:28:12 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_x(va_list *args, t_format *fm, char *base)
{
	unsigned int	n;
	char			str[13];
	char			*_str;
	int				str_len;

	n = va_arg(*args, unsigned int);
	_str = str;
	str[0] = '0';
	str[1] = 'x';
	str_len = ft_uitoa(str + 2, n, base);
	if (fm->is_prefix_hex)
		str_len += 2;
	else
		_str += 2;
	if (fm->precision > str_len)
		return (ft_run_precision_unsigned(fm, _str, str_len));
	if (fm->is_precision_defined && !fm->precision)
		return (ft_run(fm, ft_put_pad(_str, 0, fm)));
	fm->put_count = ft_put_pad(_str, str_len, fm);
}

void	format_x_lower(va_list *args, t_format *fm)
{
	format_x(args, fm, "0123456789abcdef");
}

void	format_x_upper(va_list *args, t_format *fm)
{
	format_x(args, fm, "0123456789ABCDEF");
}
