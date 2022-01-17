/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:37:05 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/17 15:44:05 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_percent(t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.minus == 1)
		count_char += ft_putstr_perc("%", 1);
	count_char += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count_char += ft_putstr_perc("%", 1);
	return (count_char);
}
