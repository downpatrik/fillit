/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:40:49 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/03 19:52:26 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int     counttetr(t_tetr *tetr)
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

int     main(int ac, char **av)
{
    int     fd;
    t_tetr  *tetr;
    t_map   *map;
    int     n;
    
	if (ac == 1)
	{
		ft_putendl("file missing");
		return (0);
	}
    if ((fd = open(av[1], O_RDONLY)) < 0)
        return (-1);
    tetr = ft_read_tetr(fd);
	close(fd);
    n = ft_solve(&map, tetr);
    while(n--)
    {
        write(1, map->content, map->size);
        ft_putchar('\n');
        map->content += map->size;
    }
    free(map);

    return (0);
}
