/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:56:24 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 12:41:40 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list args)
{
	int		put_count;
	long	n;

	n = va_arg(args, long);
	write(1, "0x", 2);
	put_count = ft_putnbr_base(n, "0123456789abcdef");
	if (put_count == -1)
		return (-1);
	return (put_count + 2);
}
