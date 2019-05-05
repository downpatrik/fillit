/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:40:49 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/05 19:04:55 by wvenita          ###   ########.fr       */
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
		free((void*)((*tetr)->line));
		free((*tetr)->snake);
		(*tetr)->next = NULL;
		*tetr = NULL;
	}
}

int		main(int ac, char **av)
{
	t_tetr	*tetr;
	t_map	*map;
	int		n;

	if (ac == 1)
	{
		ft_putendl("file missing");
		return (0);
	}
	if (!ft_read_tetr(av[1], &tetr) || !tetr)
	{
		ft_putendl("error");
		return (0);
	}
	n = ft_solve(&map, tetr);
	while (n--)
	{
		write(1, map->content, map->size);
		ft_putchar('\n');
		map->content += map->size;
	}
	free(map->content);
	ft_freetetr(&tetr);
	return (0);
}
