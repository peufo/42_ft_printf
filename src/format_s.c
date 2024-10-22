/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 19:46:47 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_s(va_list *args, t_format *fm)
{
	char	*str;
	char	str_null[7];
	int		str_len;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_strcpy(str_null, "(null)");
		str = str_null;
	}
	str_len = ft_strlen(str);
	if (fm->is_precision_null)
		fm->put_count = ft_put_pad(str, 0, fm);
	else if (fm->precision < str_len)
		fm->put_count = ft_put_pad(str, fm->precision, fm);
	else
		fm->put_count = ft_put_pad(str, str_len, fm);
}
