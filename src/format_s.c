/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 11:35:27 by jvoisard         ###   ########.fr       */
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
		return (-1);
	while (*cursor)
		write(1, cursor++, 1);
	return (cursor - str);
}
