/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:17:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/19 11:22:57 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef int	(*t_formater)(va_list args);

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(long nbr, char *base);
int	format_c(va_list args);
int	format_s(va_list args);
int	format_p(va_list args);
int	format_d(va_list args);
int	format_i(va_list args);
int	format_u(va_list args);
int	format_x_lower(va_list args);
int	format_x_upper(va_list args);
int	format_percent(va_list args);

#endif
