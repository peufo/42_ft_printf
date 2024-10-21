/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:51 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 12:14:59 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char **str)
{
	int	n;

	if (!**str || !ft_is_digit(**str))
		return (0);
	n = **str - '0';
	(*str)++;
	return (n + ft_atoi(str));
}
