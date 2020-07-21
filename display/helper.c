/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:42:11 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:42:14 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

void		helper_minus(int width, char *str, char *disp)
{
	int i;

	fill_space(disp, width);
	i = 0;
	while (str[i] && disp[i])
	{
		disp[i] = str[i];
		i++;
	}
}

static void	helper_not_minus(t_placeholder *place_holder, char *str,
	char *disp, int neg)
{
	int i;
	int j;

	i = place_holder->width - ft_strlen(str);
	j = 0;
	if (place_holder->zero && neg && place_holder->precision == -1)
		disp[j++] = '-';
	else if (place_holder->zero && place_holder->precision == -1
		&& place_holder->plus)
		disp[j++] = '+';
	else if (place_holder->hash && place_holder->zero &&
		(str[1] == 'x' || str[1] == 'X'))
	{
		disp[j++] = str[0];
		disp[j++] = str[1];
	}
	else if (place_holder->space && !neg && !place_holder->plus)
		disp[j++] = ' ';
	while (disp[i + j] && str[j])
	{
		disp[j + i] = str[j];
		j++;
	}
}

void		helper_disp_width(t_placeholder *place_holder, char *str, int neg)
{
	char	*disp;

	if (!(disp = (char *)malloc(sizeof(*disp) * (place_holder->width + 1))))
		return ;
	if (place_holder->minus)
		helper_minus(place_holder->width, str, disp);
	else
	{
		if (place_holder->zero && place_holder->precision == -1)
			fill_zero(disp, place_holder->width);
		else
			fill_space(disp, place_holder->width);
		helper_not_minus(place_holder, str, disp, neg);
	}
	ft_putstr(disp);
	place_holder->length_print = ft_strlen(disp);
	free(disp);
}

char		*helper_precision(t_placeholder *place_holder, char *str, int neg)
{
	char	*temp;
	char	c;

	temp = str;
	if (((int)ft_strlen(str) - 1 < place_holder->precision) &&
		(neg || place_holder->plus || place_holder->space))
	{
		c = (place_holder->space) ? ' ' : 0;
		c = (place_holder->plus) ? '+' : c;
		c = (neg) ? '-' : c;
		str = ft_substr(str, 1, ft_strlen(str));
		str = add_zero_front(str, place_holder->precision + 1);
		str[0] = c;
	}
	else if (((int)ft_strlen(str) - 1 < place_holder->precision &&
		place_holder->space) || ((int)ft_strlen(str) < place_holder->precision))
	{
		str = ((int)ft_strlen(str) - 1 < place_holder->precision &&
			place_holder->space) ? ft_substr(str, 1, ft_strlen(str)) : str;
		str = add_zero_front(str, place_holder->precision);
	}
	else
		return (str);
	free(temp);
	return (str);
}
