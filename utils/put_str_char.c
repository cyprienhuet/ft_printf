/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:44:17 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:44:31 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	put_str_char(char *str, char c, int way)
{
	if (way)
	{
		ft_putchar(c);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		ft_putchar(c);
	}
}
