/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:41:22 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:41:24 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

void	display_p(t_placeholder *place_holder, va_list *vl)
{
	long	adr;
	char	*disp;
	char	*temp;

	adr = (long)va_arg(*vl, void *);
	temp = ft_itoa_base(adr, 16, 0);
	temp = helper_precision(place_holder, temp, 0);
	disp = (temp[0] == '0' && place_holder->precision == 0) ?
		ft_strdup("0x") : ft_strjoin("0x", temp);
	free(temp);
	if (place_holder->width > (int)ft_strlen(disp))
		if (place_holder->precision == 0)
			helper_disp_width(place_holder, "0x", 0);
		else
			helper_disp_width(place_holder, disp, 0);
	else
	{
		ft_putstr(disp);
		place_holder->length_print = ft_strlen(disp);
	}
	free(disp);
}
