/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:17:09 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/20 17:12:50 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_formaters(t_formater	*formaters)
{
	formaters['c'] = format_c;
	formaters['s'] = format_s;
	formaters['p'] = format_p;
	formaters['d'] = format_di;
	formaters['i'] = format_di;
	formaters['u'] = format_u;
	formaters['x'] = format_x_lower;
	formaters['X'] = format_x_upper;
	formaters['%'] = format_percent;
}

static void	init_flag(const char **str, t_format *format)
{
	t_formater	formaters[UCHAR_MAX];

	(*str)++;
	init_formaters(formaters);
	format->formater = formaters[(int)*(*str)++];
	(void)str;
	(void)format;
	(void)formaters;
}

int	handle_flag(const char **str, va_list args)
{
	t_format	format;

	init_flag(str, &format);
	if (format.formater)
		return (format.formater(args));
	return (-1);
}
