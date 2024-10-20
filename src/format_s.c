/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 21:03:41 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_s(va_list args)
{
	char	*str;
	char	*cursor;

	str = va_arg(args, char *);
	cursor = str;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (*cursor)
		if (write(1, cursor++, 1) == -1)
			return (-1);
	return (cursor - str);
}
