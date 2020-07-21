/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:41:42 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:41:50 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

void	display_u(t_placeholder *place_holder, va_list *vl)
{
	char			*str;
	uintmax_t		nb;

	nb = get_nb_u(vl, place_holder);
	str = itoa_spec_u(nb);
	if (place_holder->precision == 0 && str[0] == '0')
		str = ft_strdup("");
	if ((int)ft_strlen(str) < place_holder->precision)
		str = add_zero_front(str, place_holder->precision);
	if (place_holder->width < (int)ft_strlen(str))
	{
		place_holder->length_print = ft_strlen(str);
		ft_putstr(str);
	}
	else
		helper_disp_width(place_holder, str, 0);
	free(str);
}
