/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:17:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/20 16:46:51 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef int	(*t_formater)(va_list args);
typedef struct s_format {
	t_formater	formater;
	int			width;
	int			precision;
	char		fill;
	char		sign_positive;
	char		prefix_hex;
}	t_format;

int		ft_printf(const char *str, ...);
int		handle_flag(const char **str, va_list args);
int		format_c(va_list args);
int		format_s(va_list args);
int		format_p(va_list args);
int		format_di(va_list args);
int		format_u(va_list args);
int		format_x_lower(va_list args);
int		format_x_upper(va_list args);
int		format_percent(va_list args);
int		ft_put_nbr(long nbr, char *base);
int		ft_put_unbr(unsigned long nbr, char *base);
int		ft_strlen(char *str);
int		ft_includes(char str[], char c);
int		ft_is_valid_base(char base[]);

#endif
