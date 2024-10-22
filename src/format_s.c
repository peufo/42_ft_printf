/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 17:19:27 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_s(va_list *args, t_format *fm)
{
	char	*str;
	char	str_null[7];

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_strcpy(str_null, "(null)");
		str = str_null;
	}
	if (fm->is_precision_defined && !fm->precision)
		fm->put_count = ft_put_pad(str, 0, fm);
	else
		fm->put_count = ft_put_pad(str, ft_strlen(str) - fm->precision, fm);
}
