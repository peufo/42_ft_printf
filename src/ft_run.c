/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:59:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 16:20:18 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_run(t_format *fm, int put_result)
{
	if (put_result == -1)
		fm->put_count = -1;
	if (fm->put_count != -1)
		fm->put_count += put_result;
}
