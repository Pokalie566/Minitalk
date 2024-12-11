/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:38:01 by adeboose          #+#    #+#             */
/*   Updated: 2024/10/15 15:57:22 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	print_lenght;

	print_lenght = 0;
	if (s)
	{
		while (*s)
			print_lenght += ft_putchar(*(s++));
	}
	else
		print_lenght += ft_putstr("(null)");
	return (print_lenght);
}
