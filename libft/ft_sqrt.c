/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:11:00 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/29 20:19:55 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int n)
{
	int		i;

	i = 0;
	while ((i * i) < n && i < 46340)
		i++;
	return ((n % i == 0) ? i : 0);
}