/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:46:13 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/21 12:01:40 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_treat_char(char c, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count_char = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count_char + 1);
}
