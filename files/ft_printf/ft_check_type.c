/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:07:57 by argharag          #+#    #+#             */
/*   Updated: 2025/02/02 13:46:42 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_num_base(char chr, va_list args, size_t *count)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	str2 = "0123456789";
	if (chr == 'p')
	{
		*count += ft_putstr("0x");
		ft_adress((size_t)va_arg(args, void *), str, 16, count);
	}
	else if (chr == 'x')
		ft_print_nums(va_arg(args, unsigned int), str, 16, count);
	else if (chr == 'X')
		ft_print_nums(va_arg(args, unsigned int), str1, 16, count);
	else
		ft_print_nums(va_arg(args, unsigned int), str2, 10, count);
}

size_t	ft_check_type(char chr, va_list args)
{
	size_t	count;

	count = 0;
	if (chr == 'd' || chr == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (chr == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (chr == 'p' || chr == 'x' || chr == 'X' || chr == 'u')
		ft_check_num_base(chr, args, &count);
	else if (chr == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(va_arg(args, int));
	return (count);
}
