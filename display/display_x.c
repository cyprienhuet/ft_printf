/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:41:55 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:41:56 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

void	display_x(t_placeholder *place_holder, va_list *vl, int upp)
{
	char			*str;
	uintmax_t		nb;
	char			*temp;

	nb = get_nb_u(vl, place_holder);
	str = (place_holder->precision == 0 && nb == 0) ? ft_strdup("") :
		itoa_spec_u_base(nb, 16, upp);
	if (place_holder->precision)
		str = helper_precision(place_holder, str, 0);
	if (place_holder->hash && nb != 0)
	{
		temp = str;
		str = (upp) ? ft_strjoin("0X", str) :
			ft_strjoin("0x", str);
		free(temp);
	}
	if (place_holder->width < (int)ft_strlen(str))
	{
		place_holder->length_print += ft_strlen(str);
		ft_putstr(str);
	}
	else
		helper_disp_width(place_holder, str, 0);
	free(str);
}
