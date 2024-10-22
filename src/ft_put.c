/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:47:28 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 12:18:11 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char_n(char c, int n)
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

int	ft_put_padleft(char *str, int str_len, int width, char fill)
{
	int		print_count;

	print_count = ft_put_char_n(fill, width - str_len);
	if (print_count == -1)
		return (-1);
	if (write(1, str, str_len) == -1)
		return (-1);
	return (print_count + str_len);
}

int	ft_put_padright(char *str, int str_len, int width, char fill)
{
	int	print_count;

	if (write(1, str, str_len) == -1)
		return (-1);
	print_count = ft_put_char_n(fill, width - str_len);
	if (print_count == -1)
		return (-1);
	return (print_count + str_len);
}

int	ft_put_pad(char *str, int str_len, t_format *format)
{
	if (format->is_padright)
		return (ft_put_padright(str, str_len, format->width, ' '));
	if (format->is_expand_zero)
		return (ft_put_padleft(str, str_len, format->width, '0'));
	return (ft_put_padleft(str, str_len, format->width, ' '));
}

int	ft_put_sign(int n, t_format *format)
{
	if (n == 0)
		return (0);
	if (n < 0)
	{
		format->width--;
		return (write(1, &"-", 1));
	}
	if (format->sign_positive)
	{
		format->width--;
		return (write(1, &format->sign_positive, 1));
	}
	return (0);
}