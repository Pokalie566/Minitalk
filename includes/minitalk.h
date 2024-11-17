/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:39:33 by adeboose          #+#    #+#             */
/*   Updated: 2024/11/16 14:35:45 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
# include <unistd.h>
#include <stdbool.h>

# define BUFFER_SIZE 10

typedef struct s_signal_state
{
	int		bit_count;
	char	current_char;
}			t_signal_state;

#endif
