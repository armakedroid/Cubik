/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:42:46 by argharag          #+#    #+#             */
/*   Updated: 2025/02/01 18:55:56 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, size_t *count)
{
	int			i;
	char		a;

	i = nb;
	if (nb == -2147483648)
		*count += write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		*count += write(1, "-", 1);
		ft_putnbr(-nb, count);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10, count);
		a = nb % 10 + '0';
		*count += write(1, &a, 1);
	}
}

void	ft_adress(unsigned long i, char *str, unsigned int len, size_t *count)
{
	if (i >= len)
		ft_adress(i / len, str, len, count);
	*count += ft_putchar(str[i % len]);
}

void	ft_print_nums(unsigned int i, char *str, int len, size_t *count)
{
	unsigned int	num;
	unsigned int	k;

	num = 0;
	k = (unsigned int) len;
	if (i < 0 && (ft_strlen(str) == 10))
	{
		*count += ft_putchar('-');
		num = -i;
	}
	else
		num = i;
	if (num >= k)
		ft_print_nums(num / len, str, len, count);
	*count += ft_putchar(str[num % len]);
}
