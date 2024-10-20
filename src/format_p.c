/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:56:24 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/20 15:44:01 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list args)
{
	int		put_count;
	long	n;

	n = va_arg(args, long);
	if (write(1, "0x", 2) == -1)
		return (-1);
	put_count = ft_put_unbr(n, "0123456789abcdef");
	if (put_count == -1)
		return (-1);
	return (put_count + 2);
}
