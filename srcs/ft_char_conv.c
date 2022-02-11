/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:58:50 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/11 14:01:45 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_char_conv(va_list args, int *printed, int *index)
{
	unsigned char	digit;

	digit = va_arg(args, int);
	ft_putchar_fd(digit, 1);
	(*index)++;
	(*printed)++;
}
