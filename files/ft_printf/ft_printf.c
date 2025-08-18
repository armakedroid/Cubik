/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:11:23 by argharag          #+#    #+#             */
/*   Updated: 2025/02/14 19:47:12 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_type(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
//typedef struct {
//	unsigned int gp_offset;
//	unsigned int fp_offset;
//	void *overflow_arg_area;
//	void *reg_save_area;
//} __va_list_struct;

#include <stdio.h>
int main()
{
	//printf("%lu", sizeof(__gnuc_va_list)); //va_list

    int x = -1;
	int y = 15;
	int k = 35;
    char *str = NULL;
    char chr = 'A';
	//int a = ft_printf("%%%%%");
//	int b = printf("%p", &str);
}
*/
