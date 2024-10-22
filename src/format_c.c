/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:56:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 11:52:50 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args, t_format *format)
{
	char	c;

	(void)format;
	c = (char)va_arg(args, int);
	return (ft_put_pad(&c, 1, format));
}
