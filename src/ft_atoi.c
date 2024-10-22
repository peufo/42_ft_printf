/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:51 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 19:09:00 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

static int	add_next_digit(const char **str, int n)
{
	int	digit;

	if (!**str || !ft_is_digit(**str))
		return (n);
	digit = **str - '0';
	(*str)++;
	return (add_next_digit(str, n * 10 + digit));
}

int	ft_atoi(const char **str)
{
	return (add_next_digit(str, 0));
}
