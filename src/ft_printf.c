/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:56:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/18 19:03:01 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_formater	formaters[UCHAR_MAX];

	(void)str;
	formaters['c'] = format_c;
	formaters['s'] = format_s;
	formaters['p'] = format_p;
	formaters['d'] = format_d;
	formaters['i'] = format_i;
	formaters['u'] = format_u;
	formaters['x'] = format_x;
	formaters['X'] = format_xx;
	formaters['%'] = format__;
	return (0);
}
