/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:56:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 20:58:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args)
{
	int	c;
	int	count;	

	c = va_arg(args, int);
	count = write(1, &c, 1);
	return (count);
}
