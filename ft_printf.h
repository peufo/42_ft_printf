/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:17:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/18 18:59:19 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <unistd.h>

typedef int	(*t_formater)(void *arg);

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(long nbr, char *base);
int	format_c(void *arg);
int	format_s(void *arg);
int	format_p(void *arg);
int	format_d(void *arg);
int	format_i(void *arg);
int	format_u(void *arg);
int	format_x(void *arg);
int	format_xx(void *arg);
int	format__(void *arg);

#endif
