/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:42:03 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:42:05 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

static void	helper(int width, char *str, char *disp)
{
	int i;
	int j;

	i = width - ft_strlen(str);
	j = 0;
	while (disp[i + j] && str[j])
	{
		disp[i + j] = str[j];
		j++;
	}
}

static char	*check_str(char *str, t_placeholder *place_holder)
{
	str = (!str) ? ft_strdup("(null)") : ft_strdup(str);
	str = (place_holder->precision == 0) ? ft_strdup("") : str;
	str = (place_holder->precision > 0) ? ft_substr(str, 0,
		place_holder->precision) : str;
	return (str);
}

void		display_s(t_placeholder *place_holder, va_list *vl)
{
	char	*str;
	char	*disp;

	str = check_str(va_arg(*vl, char *), place_holder);
	if (place_holder->width && (int)ft_strlen(str) < place_holder->width)
	{
		if (!(disp = (char *)malloc(sizeof(*disp) * (place_holder->width + 1))))
			return ;
		if (place_holder->zero && !place_holder->minus)
			fill_zero(disp, place_holder->width);
		else
			fill_space(disp, place_holder->width);
		if (place_holder->minus)
			helper_minus(place_holder->width, str, disp);
		else
			helper(place_holder->width, str, disp);
		place_holder->length_print = place_holder->width;
		ft_putstr(disp);
		free(disp);
		free(str);
		return ;
	}
	ft_putstr(str);
	place_holder->length_print = ft_strlen(str);
	free(str);
}
