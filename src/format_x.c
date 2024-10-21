/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:38:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 13:05:12 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_x_lower(va_list args, t_format *format)
{
	unsigned int	n;

	(void)format;
	n = va_arg(args, unsigned int);
	return (ft_put_nbr(n, "0123456789abcdef"));
}

int	format_x_upper(va_list args, t_format *format)
{
	unsigned int	n;

	(void)format;
	n = va_arg(args, unsigned int);
	return (ft_put_nbr(n, "0123456789ABCDEF"));
}
