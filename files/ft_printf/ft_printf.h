/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:13:05 by argharag          #+#    #+#             */
/*   Updated: 2025/02/10 19:34:10 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr(int nb, size_t *count);
size_t	ft_check_type(char chr, va_list args);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
int		ft_putchar(int c);
void	ft_print_nums(unsigned int i, char *str, int len, size_t *count);
void	ft_adress(size_t i, char *str, unsigned int len, size_t *count);

#endif
