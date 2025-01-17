/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:39:33 by adeboose          #+#    #+#             */
/*   Updated: 2025/01/17 06:23:18 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_signal_state
{
	int		bit_count;
	char	current_char;
}			t_signal_state;

char	*resize_dynamic_str(char *str, size_t new_size);
char	*add_char_to_dynamic_str(char *str, char c);
void	free_dynamic_str(char *str);

#endif
