/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:00:37 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 13:00:39 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

void	dispatch_to_type(char *str, t_placeholder *place_holder, va_list *vl)
{
	if (ft_strchr(str, 'c'))
		display_c(place_holder, vl);
	else if (ft_strchr(str, 's'))
		display_s(place_holder, vl);
	else if (ft_strchr(str, 'p'))
		display_p(place_holder, vl);
	else if (ft_strchr(str, 'd') || ft_strchr(str, 'i'))
		display_d_i(place_holder, vl);
	else if (ft_strchr(str, 'u'))
		display_u(place_holder, vl);
	else if (ft_strchr(str, 'x'))
		display_x(place_holder, vl, 0);
	else if (ft_strchr(str, 'X'))
		display_x(place_holder, vl, 1);
	else if (ft_strchr(str, '%'))
		display_percent(place_holder);
	else
		place_holder->error = 1;
}
