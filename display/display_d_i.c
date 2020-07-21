/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:41:14 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:41:15 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

static char	*init_str(intmax_t nb, t_placeholder *place_holder)
{
	char	*str;
	char	*temp;

	str = NULL;
	if (place_holder->precision == 0 && nb == 0)
	{
		str = (place_holder->plus) ? ft_strdup("+") : ft_strdup("");
	}
	else if ((place_holder->plus || place_holder->space) && nb >= 0)
	{
		temp = itoa_spec(nb);
		str = (place_holder->plus) ? ft_strjoin("+", temp) :
			ft_strjoin(" ", temp);
		free(temp);
	}
	else
	{
		str = itoa_spec(nb);
	}
	return (str);
}

void		display_d_i(t_placeholder *place_holder, va_list *vl)
{
	char		*str;
	intmax_t	nb;
	int			neg;

	nb = get_nb(vl, place_holder);
	neg = (nb < 0) ? 1 : 0;
	str = init_str(nb, place_holder);
	if (place_holder->precision)
		str = helper_precision(place_holder, str, neg);
	if (place_holder->width < (int)ft_strlen(str))
	{
		place_holder->length_print = ft_strlen(str);
		ft_putstr(str);
	}
	else
		helper_disp_width(place_holder, str, neg);
	free(str);
}
