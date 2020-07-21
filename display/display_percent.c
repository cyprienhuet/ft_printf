/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:41:28 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:41:34 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

void	display_percent(t_placeholder *place_holder)
{
	char	*str;
	char	c;

	c = '%';
	if (place_holder->width)
	{
		if (!(str = (char *)malloc(sizeof(*str) * (place_holder->width))))
			return ;
		if (place_holder->zero && !place_holder->minus)
			fill_zero(str, place_holder->width - 1);
		else
			fill_space(str, place_holder->width - 1);
		put_str_char(str, c, place_holder->minus);
		place_holder->length_print = ft_strlen(str) + 1;
		free(str);
	}
	else
	{
		ft_putchar(c);
		place_holder->length_print = 1;
	}
}
