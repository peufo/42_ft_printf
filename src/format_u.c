/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:35:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/20 15:43:50 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_u(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_put_nbr(n, "0123456789"));
}
