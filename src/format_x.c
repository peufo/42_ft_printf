/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:38:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 15:01:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_x_lower(va_list *args, t_format *fm)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	fm->put_count = ft_put_nbr(n, "0123456789abcdef");
}

void	format_x_upper(va_list *args, t_format *fm)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	fm->put_count = ft_put_nbr(n, "0123456789ABCDEF");
}
