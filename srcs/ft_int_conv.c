/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:02:18 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/11 14:17:32 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_untoa(unsigned int n)
{
	char				*nbr_str;
	size_t				digit;
	unsigned long int	nbr;

	nbr = n;
	digit = ft_count_unsign(n);
	nbr_str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!nbr_str)
		return (NULL);
	nbr_str[digit] = '\0';
	while (digit--)
	{
		nbr_str[digit] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (nbr_str);
}

int	ft_unsigned_int(va_list args, int *printed, int *index)
{
	int				ret;
	unsigned int	nbr;
	char			*num;

	ret = 0;
	nbr = va_arg(args, unsigned int);
	num = ft_untoa(nbr);
	if (num == NULL)
		return (-1);
	*printed += ft_strlen(num);
	ft_putstr_fd(num, 1);
	free(num);
	(*index)++;
	return (ret);
}

int	ft_int_conv(va_list args, int *printed, int *index)
{
	int		nbr;
	int		ret;
	char	*num;

	ret = 0;
	nbr = va_arg(args, int);
	num = ft_itoa(nbr);
	if (num == NULL)
		return (-1);
	*printed += ft_strlen(num);
	ft_putstr_fd(num, 1);
	free(num);
	(*index)++;
	return (ret);
}
