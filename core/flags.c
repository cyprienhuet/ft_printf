/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:00:23 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 13:00:25 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

static void	check_width(char *str, t_placeholder *place_holder)
{
	int		i;
	int		j;
	int		start;
	char	*temp;

	i = -1;
	j = 0;
	start = -1;
	while (str[++i])
		if ((str[i] == '0' && start < 0) || str[i] == '-' ||
			str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '*')
			;
		else if (ft_isdigit(str[i]))
		{
			if (start < 0)
				start = i;
			j++;
		}
		else
			break ;
	temp = ft_substr(str, start, j);
	place_holder->width = ft_atoi(temp);
	free(temp);
}

static void	check_precision(char *str, t_placeholder *place_holder)
{
	int		i;
	int		j;
	char	*temp;

	place_holder->precision = 1;
	i = ft_get_index(str, '.');
	i++;
	j = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
			j++;
		else
			break ;
		i++;
	}
	temp = ft_substr(str, ft_get_index(str, '.') + 1, j);
	place_holder->precision = (ft_atoi(temp) >= 0) ? ft_atoi(temp) : -1;
	free(temp);
}

static void	check_wildcard(char **str, va_list *vl)
{
	int		i;
	char	*wildcard;

	while ((i = ft_get_index(*str, '*')) >= 0)
	{
		wildcard = ft_itoa(va_arg(*vl, int));
		wildcard = ft_strjoin(wildcard, ft_substr(*str, i + 1,
			ft_strlen(*str) - i));
		*str = ft_strjoin(ft_substr(*str, 0, i), wildcard);
	}
	free(wildcard);
}

static void	check_zero(char *str, t_placeholder *place_holder)
{
	int i;

	i = ft_get_index(str, '0');
	if (i == 0 || (!ft_isdigit(str[i - 1]) && str[i - 1] != '.'))
		place_holder->zero = 1;
}

void		check_flags(char *str, t_placeholder *place_holder, va_list *vl)
{
	int		i;

	if ((i = ft_get_index(str, '*')) >= 0)
	{
		if (!(ft_isdigit(str[i + 1])))
			check_wildcard(&str, vl);
		else
			va_arg(*vl, int);
	}
	if ((i = ft_get_index(str, '-')) >= 0)
		if (str[i - 1] != '.')
			place_holder->minus = 1;
	if (ft_strchr(str, '+'))
		place_holder->plus = 1;
	if (ft_strchr(str, ' '))
		place_holder->space = 1;
	if (ft_strchr(str, '#'))
		place_holder->hash = 1;
	if (ft_strchr(str, '0'))
		check_zero(str, place_holder);
	check_width(str, place_holder);
	if (ft_strchr(str, '.'))
		check_precision(str, place_holder);
}
