/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:45:24 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/15 21:43:02 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	t_i64	tmp;

	tmp = n;
	if (n < 0)
	{
		ft_putchar('-');
		tmp = -tmp;
	}
	if (tmp >= 10)
		ft_putnbr(tmp / 10);
	ft_putchar(tmp % 10 + 48);
}
