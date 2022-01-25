/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:02:10 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/25 14:21:41 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_part_ptr(char *ptr, t_flags flags)
{
	int	count_char;

	count_char = 0;
	count_char += ft_putstr_perc("0x", 2);
	if (flags.dot >= 0)
	{
		count_char += ft_treat_width(flags.dot, ft_strlen(ptr), 1);
		count_char += ft_putstr_perc(ptr, flags.dot);
	}
	else
		count_char += ft_putstr_perc(ptr, ft_strlen(ptr));
	return (count_char);
}

int	ft_treat_ptr(unsigned long long ull, t_flags flags)
{
	char	*ptr;
	int		count_char;

	count_char = 0;
	if (ull == 0 && flags.dot == 0)
	{
		count_char += ft_putstr_perc("0x", 2);
		return (count_char += ft_treat_width(flags.width, 0, 1));
	}
	ptr = ft_ull_base(ull, 16);
	ptr = ft_str_tolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		count_char += ft_input_part_ptr(ptr, flags);
	count_char += ft_treat_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		count_char += ft_input_part_ptr(ptr, flags);
	free(ptr);
	return (count_char);
}
