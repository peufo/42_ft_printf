/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 15:00:46 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_s(va_list *args, t_format *fm)
{
	char	*str;

	(void)fm;
	str = va_arg(*args, char *);
	if (!str)
		fm->put_count = write(1, "(null)", 6);
	else
		fm->put_count = write(1, str, ft_strlen(str));
}
