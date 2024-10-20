/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:46:23 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 15:15:12 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_unit(long nbr, char *base, int base_len, int count)
{
	int	unit;

	if (nbr == 0 || count == -1)
		return (count);
	if (nbr > 0)
		unit = (nbr % base_len);
	else
		unit = -(nbr % base_len);
	count = ft_put_unit(nbr / base_len, base, base_len, count);
	if (count == -1 || write(1, base + unit, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_put_long(long nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (!nbr)
		return (write(1, base, 1));
	if (nbr < 0)
		return (ft_put_unit(nbr, base, base_len, write(1, "-", 1)));
	return (ft_put_unit(nbr, base, base_len, 0));
}
