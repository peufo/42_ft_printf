/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:56:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/20 16:59:39 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;
	int			write_res;

	va_start(args, str);
	count = 0;
	while (*str && count > -1)
	{
		if (*str == '%')
			write_res = handle_flag(&str, args);
		else
			write_res = write(1, str++, 1);
		if (write_res == -1)
		{
			count = -1;
			break ;
		}
		count += write_res;
	}
	va_end(args);
	return (count);
}
