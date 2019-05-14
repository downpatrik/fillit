/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:40:49 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/06 19:33:48 by dhilll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		counttetr(t_tetr *tetr)
{
	int i;

	i = 0;
	while (tetr)
	{
		i++;
		tetr = tetr->next;
	}
	return (i);
}

void	ft_freetetr(t_tetr **tetr)
{
	if (*tetr)
	{
		ft_freetetr(&(*tetr)->next);
		free((*tetr)->line);
		free((*tetr)->snake);
		free(*tetr);
	}
}

int		main(int ac, char **av)
{
	t_tetr	*tetr;
	t_map	*map;
	char	*tmp;
	int		n;

	if (!ft_read_tetr(av[1], &tetr) || !tetr || ac == 1)
	{
		ft_putendl("error");
		return (0);
	}
	n = ft_solve(&map, tetr);
	tmp = map->content;
	while (n--)
	{
		write(1, tmp, map->size);
		ft_putchar('\n');
		tmp += map->size;
	}
	free(map->content);
	free(map);
	ft_freetetr(&tetr);
	return (0);
}
