/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:46:23 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/18 17:53:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_unit(long nbr, char *base, int base_len, int count)
{
	int	unit;

	if (nbr == 0)
		return (count);
	if (nbr > 0)
		unit = (nbr % base_len);
	else
		unit = -(nbr % base_len);
	count = ft_putnbr_base_unit(nbr / base_len, base, base_len, count);
	write(1, base + unit, 1);
	return (count + 1);
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_includes(char str[], char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	ft_is_valid_base(char base[])
{
	while (*base)
	{
		if (*base < ' '
			|| *base == 127
			|| *base == '+'
			|| *base == '-'
			|| ft_includes(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	base_len;
	int	put_count;

	base_len = ft_strlen(base);
	put_count = 0;
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (!nbr)
	{
		write(1, base, 1);
		return (1);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		put_count++;
	}
	return (ft_putnbr_base_unit(nbr, base, base_len, put_count));
}
