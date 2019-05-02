/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:07:40 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/02 17:30:03 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void    del_tetr(t_map *map, char letter)
{
	int i;
	
	i = -1;
	while (++i < map->size)
			if (map->content[i] == letter)
				map->content[i] = '.';
}

int		tetralph(t_map **map, t_tetr *tetr, char *alph, int i)
{

}

int		ft_solved(t_map *map, t_tetr *tetr, char *alph)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < map->count && alph[j])
		j++;
	while (i < map->size)
	{
		if(tetralph(map, tetr, alph, i++) && (alph[j] = 1))
		{
			if(ft_solved(map, tetr->next, alph))
				return (1);
			del_tetr(map, tetr->letter);
			alph[j] = 0;
		}
	}
	return (0);
}

int		ft_solve(t_map **map, t_tetr *tetr)
{
	char	alph[26];
	int		n;

	n = minsquare((*map)->count) - 1;
	while (++n)
	{
		(*map)->size = n * n;
		ft_memset((*map)->content, '.', (*map)->size);
		ft_memset(alph, 0, 26);
		(*map)->content[(*map)->size] = '\0';
		if (ft_solved(*map, tetr, alph))
			break;
	}
	return (n);
}

int		minsquare(int n)
{
	int i;

	i = n * 4;
	while(!ft_sqrt(i))
		i++;
	return(ft_sqrt(i));
}
