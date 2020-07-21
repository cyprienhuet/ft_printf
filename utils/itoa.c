/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

char		*itoa_spec(intmax_t n)
{
	char		*str;
	int			i;
	int			neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (!(str = (char *)malloc(sizeof(char) * (64))))
		return (0);
	i = 0;
	neg = (n < 0) ? 1 : 0;
	n *= (n < 0) ? -1 : 1;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

char		*itoa_spec_u(uintmax_t n)
{
	char			*str;
	int				i;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * (64))))
		return (0);
	i = 0;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

char		*itoa_spec_u_base(uintmax_t n, int base, int upp)
{
	int			i;
	char		*str;

	if (base == 10)
		return (itoa_spec_u(n));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * (64))))
		return (0);
	i = 0;
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10) && upp)
			str[i] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i] = (n % base) - 10 + 'a';
		else
			str[i] = (n % base) + '0';
		n /= base;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	return ((str));
}
