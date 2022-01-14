/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:03:22 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/13 11:08:25 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
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
char	*ft_str_tolower(char *str);
int		ft_treat_char(char c, t_flags flags);
int	ft_treat_int(int i, t_flags flags);
int	ft_treat_width(int width, int minus, int has_zero);

#endif
