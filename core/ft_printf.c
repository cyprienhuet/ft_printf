/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:00:30 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 13:00:31 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

static void	reset_ph(t_placeholder *place_holder)
{
	place_holder->precision = -1;
	place_holder->width = 0;
	place_holder->length = 0;
	place_holder->minus = 0;
	place_holder->plus = 0;
	place_holder->space = 0;
	place_holder->zero = 0;
	place_holder->hash = 0;
	place_holder->asterisk = 0;
	place_holder->length_print = 0;
	place_holder->h = 0;
	place_holder->hh = 0;
	place_holder->l = 0;
	place_holder->ll = 0;
	place_holder->error = 0;
}

static int	is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'p' || c == 'c' || c == 's' || c == '%')
		return (1);
	else
		return (0);
}

static int	handle_ph(char *str, t_placeholder *place_holder, va_list *vl)
{
	char	*temp;
	int		i;

	reset_ph(place_holder);
	i = 0;
	temp = str;
	while (!is_type(*temp) && *temp)
	{
		i++;
		temp++;
	}
	temp = ft_substr(str, 0, i + 1);
	check_flags(temp, place_holder, vl);
	check_length(temp, place_holder);
	dispatch_to_type(temp, place_holder, vl);
	free(temp);
	return (place_holder->length_print);
}

int			ft_printf(const char *str, ...)
{
	int				count;
	t_placeholder	place_holder;
	va_list			vl;

	if (!str)
		return (-1);
	va_start(vl, str);
	count = 0;
	while (*str)
		if (*str != '%')
		{
			ft_putchar(*str++);
			count++;
		}
		else
		{
			count += handle_ph((char *)++str, &place_holder, &vl);
			if (place_holder.error)
				continue ;
			while (*str && !is_type(*str))
				str++;
			str += (is_type(*str)) ? 1 : 0;
		}
	va_end(vl);
	return (count);
}
