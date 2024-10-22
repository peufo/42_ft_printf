/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 15:34:53 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	next_digit(char *dest, unsigned long n, char *base, int base_len)
{
	if (n == 0)
		return (0);
	*(--dest) = base[n % base_len];
	return (1 + next_digit(dest, n / base_len, base, base_len));
}

static char	*get_end(char *dest, unsigned long n, int base_len)
{
	if (n == 0)
	{
		*dest = '\0';
		return (dest);
	}
	return (get_end(dest + 1, n / base_len, base_len));
}

static int	handle_zero(char *dest)
{
	*(dest++) = '+';
	*(dest++) = '0';
	*(dest++) = '\0';
	return (2);
}

int	ft_itoa(char *dest, long n, char *base, t_format *fm)
{
	int		base_len;
	char	*dest_end;

	base_len = ft_strlen(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (n == 0)
		return (handle_zero(dest));
	if (n < 0)
	{
		*(dest++) = '-';
		dest_end = get_end(dest, -n, base_len);
		return (1 + next_digit(dest_end, -n, base, base_len));
	}
	else
	{
		*(dest++) = fm->sign_positive;
		dest_end = get_end(dest, n, base_len);
		return (1 + next_digit(dest_end, n, base, base_len));
	}
}

int	ft_uitoa(char *dest, unsigned long n, char *base)
{
	int		base_len;
	char	*dest_end;

	base_len = ft_strlen(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (n == 0)
		return (handle_zero(dest));
	dest_end = get_end(dest, n, base_len);
	return (next_digit(dest_end, n, base, base_len));
}
