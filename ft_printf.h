/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:06:05 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/11 11:07:39 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_unsigned_int(va_list args, int *printed, int *index);
int		ft_int_conv(va_list args, int *printed, int *index);
int		ft_hexa_conv(va_list args, char to_conv, int *printed, int *index);

void	ft_char_conv(va_list args, int *printed, int *index);
void	ft_str_conv(va_list args, int *printed, int *index);

#endif
