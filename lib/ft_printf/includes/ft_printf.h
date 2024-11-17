/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:12:36 by adeboose          #+#    #+#             */
/*   Updated: 2024/10/15 15:57:16 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);
int		ft_ptr_len(unsigned long long num);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);
int		ft_putstr(char *str);
int		ft_putchar(char c);
void	ft_put_ptr(unsigned long long num);
void	ft_put_hex(unsigned int num, const char format);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
