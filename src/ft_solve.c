/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:07:40 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/05 18:48:42 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

#include <stdio.h>

void	del_tetr(t_map *map, char letter)
{
	int		i;

	i = -1;
	while (++i < map->size * map->size)
		if (map->content[i] == letter)
			map->content[i] = '.';
}

int		placetetr(t_map *map, t_tetr *tetr, int n)
{
	int		i;
	int		g;
	int		check;

	i = -1;
	check = 0;
	while (++i < 4)
	{
		g = tetr->snake[i] / 4 * map->size + tetr->snake[i] % 4 + n;
		if (i > 0 && g / map->size != (n + tetr->snake[i] / 4 * map->size) /
			map->size && ((tetr->snake[i] - tetr->snake[i - 1]) == 1))
			break ;
		if (map->content[g] == '.')
		{
			map->content[g] = tetr->letter;
			check++;
		}
	}
	if (check == 4)
		return (1);
	del_tetr(map, tetr->letter);
	return (0);
}

int		ft_solved(t_map *map, t_tetr *tetr, char *alph)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->count && alph[j])
		j++;
	if (j == map->count)
		return (1);
	while (i < map->size * map->size)
	{
		if (placetetr(map, tetr, i++) && (alph[j] = 1))
		{
			if (ft_solved(map, tetr->next, alph))
				return (1);
			del_tetr(map, tetr->letter);
			alph[j] = 0;
		}
	}
	return (0);
}

int		minsquare(int n)
{
	int i;

	i = n * 4;
	while (!ft_sqrt(i))
		i++;
	return (ft_sqrt(i));
}

int		ft_solve(t_map **map, t_tetr *tetr)
{
	char	alph[26];

	if (!((*map) = (t_map *)malloc(sizeof(t_map))))
		return (0);
	(*map)->count = counttetr(tetr);
	if (!((*map)->content = malloc((*map)->count *
					(*map)->count * 4 * 4 * sizeof(char))))
		return (0);
	(*map)->size = minsquare((*map)->count) - 1;
	while (++((*map)->size))
	{
		ft_memset((*map)->content, '.', (*map)->size * (*map)->size);
		ft_memset(alph, 0, 26);
		(*map)->content[(*map)->size * (*map)->size] = '\0';
		if (ft_solved(*map, tetr, alph))
			break ;
	}
	return ((*map)->size);
}
