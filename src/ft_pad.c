/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:53:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 18:11:59 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_padleft(char *str, int str_len, t_format *format)
{
	int		to_add;
	int		print_count;
	char	fill;

	fill = ' ';
	if (format->is_expand_zero)
		fill = '0';
	to_add = format->width - str_len;
	print_count = 0;
	while (print_count < to_add)
	{
		if (write(1, &fill, 1) == -1)
			return (-1);
		print_count++;
	}
	if (write(1, str, str_len) == -1)
		return (-1);
	return (print_count + str_len);
}

static int	ft_padright(char *str, int str_len, t_format *format)
{
	int	to_add;
	int	print_count;

	to_add = format->width - str_len;
	if (write(1, str, str_len) == -1)
		return (-1);
	print_count = 0;
	while (print_count < to_add)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		print_count++;
	}
	return (print_count + str_len);
}

int	ft_pad(char *str, int str_len, t_format *format)
{
	if (format->is_padright)
		return (ft_padright(str, str_len, format));
	return (ft_padleft(str, str_len, format));
}
