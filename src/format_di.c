/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:08:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 12:49:11 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_di(va_list args, t_format format)
{
	int	n;

	(void)format;
	n = va_arg(args, int);
	return (ft_put_nbr(n, "0123456789"));
}
