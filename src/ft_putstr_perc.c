/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_perc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:46:10 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/17 15:46:13 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_perc(char *str, int prec)
{
	int	count_char;

	count_char = 0;
	while (str[count_char] && count_char < prec)
		ft_putchar(str[count_char++]);
	return (count_char);
}
