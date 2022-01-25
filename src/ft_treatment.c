/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:13:26 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/25 15:00:23 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') \
	|| (c == 'i') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_treatment(int c, t_flags flags, va_list args)
{
	int	count_char;

	count_char = 0;
	if (c == 'c')
		count_char = ft_treat_char(va_arg(args, int), flags);
	else if (c == 's')
		count_char = ft_treat_string(va_arg(args, char *), flags);
	else if (c == 'p')
		count_char = ft_treat_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count_char = ft_treat_int(va_arg(args, int), flags);
	else if (c == 'u')
		count_char += ft_treat_uint((unsigned int)va_arg(args, unsigned int), \
		flags);
	else if (c == 'x')
		count_char += ft_treat_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count_char += ft_treat_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count_char += ft_treat_percent(flags);
	return (count_char);
}
