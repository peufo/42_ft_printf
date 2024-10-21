/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 12:38:55 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	next_digit(char *dest, unsigned int n, char *base, int base_len)
{
	if (n == 0)
		return (*dest = '\0');
	*(dest++) = base[n % base_len];
	return (1 + next_digit(dest, n / base_len, base, base_len));
}

static int	handle_zero(char *dest)
{
	*(dest++) = '0';
	*(dest++) = '\0';
	return (1);
}

int	ft_itoa(char *dest, int n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (n == 0)
		return (handle_zero(dest));
	if (n < 0)
	{
		*(dest++) = '-';
		return (1 + next_digit(dest, -n, base, base_len));
	}
	return (next_digit(dest, n, base, base_len));
}

int	ft_uitoa(char *dest, unsigned int n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (n == 0)
		return (handle_zero(dest));
	return (next_digit(dest, n, base, base_len));
}
