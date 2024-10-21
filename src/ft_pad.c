/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:53:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 13:14:18 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padleft(char *str, int str_len, t_format *format)
{
	int	to_add;
	int	print_count;

	to_add = format->width - str_len;
	if (to_add <= 0)
		return (write(1, str, str_len));
	print_count = 0;
	while (print_count < to_add)
	{
		if (write(1, &(format->fill), 1) == -1)
			return (-1);
		print_count++;
	}
	if (write(1, str, str_len) == -1)
		return (-1);
	return (print_count + str_len);
}
