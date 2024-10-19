/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:35:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 11:36:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_u(va_list args)
{
	unsigned long	n;

	n =  va_arg(args, unsigned long);
	// TODO, handle unsingned
	return (ft_putnbr_base(n, "0123456789"));
}
