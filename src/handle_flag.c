/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:17:09 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 12:51:27 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_formaters(t_formater	*formaters)
{
	unsigned char	index;

	index = 0;
	while (index < UCHAR_MAX)
		formaters[index++] = NULL;
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

static char	capture_flags(char c, t_format *format)
{
	if (!c || !ft_includes("0#- +", c))
		return (0);
	if (c == '0')
		format->fill = '0';
	else if (c == '#')
		format->is_prefix_hex = 1;
	else if (c == '-')
		format->is_padright = 1;
	else if (c == ' ' && format->sign_positive != '+')
		format->sign_positive = ' ';
	else if (c == '+')
		format->sign_positive = '+';
	return (1);
}

static void	capture_precision(const char **str, t_format *format)
{
	if (**str != '.')
		return ;
	(*str)++;
	format->precision = ft_atoi(str);
}

static void	init_flag(const char **str, t_format *format)
{
	t_formater	formaters[UCHAR_MAX];

	(*str)++;
	init_formaters(formaters);
	format->fill = 0;
	format->formater = NULL;
	format->precision = 0;
	format->is_prefix_hex = 0;
	format->sign_positive = '\0';
	while (capture_flags(**str, format))
		(*str)++;
	format->width = ft_atoi(str);
	capture_precision(str, format);
	if (format->precision)
		format->fill = ' ';
	format->formater = formaters[(int)*(*str)++];
}

int	handle_flag(const char **str, va_list args)
{
	t_format	format;

	init_flag(str, &format);
	if (format.formater)
		return (format.formater(args, format));
	return (-1);
}
