/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:35:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 15:01:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_u(va_list *args, t_format *fm)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	fm->put_count = ft_put_nbr(n, "0123456789");
}
