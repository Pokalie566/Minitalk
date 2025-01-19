/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 05:24:08 by adeboose          #+#    #+#             */
/*   Updated: 2025/01/19 19:34:29 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*resize_dynamic_str(char *str, size_t new_size)
{
	char	*new_str;
	size_t	len;

	if (!str)
		return (malloc(new_size));
	len = ft_strlen(str);
	if (new_size != len)
	{
		new_str = malloc(new_size);
		if (!new_str)
			return (NULL);
		ft_memcpy(new_str, str, len);
		free(str);
		return (new_str);
	}
	return (str);
}

char	*add_char_to_dynamic_str(char *str, char c)
{
	size_t	len;
	char	*new_str;

	if (!str)
	{
		new_str = malloc(2);
		if (!new_str)
			return (NULL);
		new_str[0] = c;
		new_str[1] = '\0';
		return (new_str);
	}
	len = ft_strlen(str);
	new_str = resize_dynamic_str(str, len + 2);
	if (!new_str)
		return (NULL);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}

void	free_dynamic_str(char *str)
{
	if (str)
		free(str);
}
