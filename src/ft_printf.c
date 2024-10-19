/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:56:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:44 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_formaters(t_formater	*formaters)
{
	formaters['c'] = format_c;
	formaters['s'] = format_s;
	formaters['p'] = format_p;
	formaters['d'] = format_d;
	formaters['i'] = format_i;
	formaters['u'] = format_u;
	formaters['x'] = format_x_lower;
	formaters['X'] = format_x_upper;
	formaters['%'] = format_percent;
}

static void	handle_flag(
	t_formater	*f,
	const char **str,
	int *count,
	va_list args)
{
	(*str)++;
	if (**str && f[(int)**str])
		*count = f[(int)*(*str)++](args);
	return ;
}

int	ft_printf(const char *str, ...)
{
	t_formater	formaters[UCHAR_MAX];
	va_list		args;
	int			count;

	init_formaters(formaters);
	va_start(args, str);
	count = 0;
	while (*str && count > -1)
	{
		if (*str == '%')
		{
			handle_flag(formaters, &str, &count, args);
			continue ;
		}
		write(1, str++, 1);
		count++;
	}
	va_end(args);
	return (count);
}
