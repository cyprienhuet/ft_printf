/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:21:16 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/23 09:21:18 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

intmax_t	get_nb(va_list *vl, t_placeholder *place_holder)
{
	intmax_t nb;

	nb = va_arg(*vl, intmax_t);
	if (place_holder->l)
		nb = (long int)nb;
	else if (place_holder->ll)
		nb = (long long int)nb;
	else if (place_holder->h)
		nb = (short int)nb;
	else if (place_holder->hh)
		nb = (char)nb;
	else
		nb = (int)nb;
	return (nb);
}

uintmax_t	get_nb_u(va_list *vl, t_placeholder *place_holder)
{
	uintmax_t nb;

	nb = va_arg(*vl, uintmax_t);
	if (place_holder->h)
		nb = (unsigned short int)nb;
	else if (place_holder->hh)
		nb = (unsigned char)nb;
	else if (place_holder->l)
		nb = (unsigned long int)nb;
	else if (place_holder->ll)
		nb = (unsigned long long int)nb;
	else
		nb = (unsigned int)nb;
	return (nb);
}
