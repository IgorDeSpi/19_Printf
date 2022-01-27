/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:03:22 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/27 13:35:27 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr_perc(char *str, int prec);
int		ft_treat_char(char c, t_flags flags);
int		ft_flag_dot(const char *save, int start, t_flags *flags, va_list args);
int		ft_treat_int(int i, t_flags flags);
int		ft_treat_percent(t_flags flags);
int		ft_treat_string(char *str, t_flags flags);
int		ft_treat_width(int width, int minus, int has_zero);
int		ft_treatment(int c, t_flags flags, va_list args);
int		ft_treat_hexa(unsigned int ui, int lower, t_flags flags);
int		ft_treat_ptr(unsigned long long ull, t_flags flags);
int		ft_is_flag_list(int c);
int		ft_is_type_list(int c);
int		ft_treat_uint(unsigned int ui, t_flags flags);

char	*ft_str_tolower(char *str);
char	*ft_ull_base(unsigned long long ull, int base);
char	*ft_u_itoa(unsigned int n);

t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);

#endif
