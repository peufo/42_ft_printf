/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:53:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 23:21:12 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_n(char c, int n)
{
	int	print_count;

	print_count = 0;
	while (n-- > 0)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		print_count++;
	}
	return (print_count);	
}

int	ft_padleft(char *str, int str_len, int width, char fill)
{
	int		print_count;

	print_count = ft_write_n(fill, width - str_len);
	if (print_count == -1)
		return (-1);
	if (write(1, str, str_len) == -1)
		return (-1);
	return (print_count + str_len);
}

static int	ft_padright(char *str, int str_len, t_format *format)
{
	int	print_count;

	if (write(1, str, str_len) == -1)
		return (-1);
	print_count = ft_write_n(' ', format->width - str_len);
	if (print_count == -1)
		return (-1);
	return (print_count + str_len);
}

int	ft_pad(char *str, int str_len, t_format *format)
{
	if (format->is_padright)
		return (ft_padright(str, str_len, format));
	if (format->is_expand_zero)
		return (ft_padleft(str, str_len, format->width, '0'));
	return (ft_padleft(str, str_len, format->width, ' '));
}
