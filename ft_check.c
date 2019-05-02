/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:00:04 by dhilll            #+#    #+#             */
/*   Updated: 2019/05/02 19:07:59 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int ft_check_tetr(char *av)
{
	int i;
	int count_hash;

	i = -1;
	count_hash = 0;
	while (++i < 16)
        if (!((av[i] == '.') || (av[i] == '#')))
            return (0);
        else if (av[i] == '#')
            count_hash++;
	return ((count_hash != 4) ? 1 : 0);
}

int check_connection(char *av)
{
    int i;
    int connect;

    i = -1;
    connect = 0;
    while (++i < 16)
    {
        if (av[i] == '#')
        {
            if ((i - 1 >= 0) && av[i - 1] == '#')
                connect++;
            if ((i + 1 < 16) && av[i + 1] == '#')
                connect++;
            if ((i - 4 >= 0) && av[i - 4] == '#')
                connect++;
            if ((i + 4 < 16) && av[i + 4] == '#')
                connect++;
        }
    }
    return (connect == 6 || connect == 8);
}

t_tetr *ft_read_tetr(const int fd)
{
	char    *tetris;
	char    *buffer;
	size_t  fr;
    size_t  i;
 
	buffer = ft_strnew(20);
	if (fd < 0 || read(fd, buffer, 0) < 0 || !buffer)
		return (NULL);
	tetris = ft_strnew(0);
	while ((fr = read(fd, buffer, 20)))
	{
		buffer[fr] = '\0';
		tetris = ft_strjoin(tetris, buffer);
	}
    if ((ft_strlen(tetris) + 1 ) % 21 != 0 && ft_strlen(tetris) > 546)
			return (NULL);
    i = 20;
    while (i < ft_strlen(tetris))
    {
        if (tetris[i] != '\n')
            return (NULL);
        i = i + 21;
    }
    return (fill_tetr(tetris, NULL, 'A'));
}

int     *mintetr(char *str)
{
    int     *tmp;
    int     i;
    int     j;

    if (!(tmp = (int*)malloc(sizeof(int) * 4)))
        return (0);
    i = -1;
    j = -1;
    while (str[++i])
        if(str[i] == '#')
            tmp[++j] = i;
    i = tmp[0];
    if (tmp[1] - tmp[0] == 2)
        i -= 2;
    if (tmp[2] - tmp[0] == 7 || tmp[1] - tmp[0] == 3 || tmp[2] - tmp[0] == 3)
        i -= 1;
    j = -1;
    while (++j < 4)
        tmp[j] -= i;
    return (tmp);
}

t_tetr  *fill_tetr(char *str, t_tetr *prev, char c)
{
    t_tetr  *tetr;
    int i;

    if ((tetr = (t_tetr *)malloc(sizeof(*tetr))) == NULL)
        return (NULL);
    tetr->previous = prev;
    if ((tetr->line = (char *)malloc(sizeof(char) * 17)) == NULL)
        return (NULL);
    tetr->line[16] = '\0';
    i = -1;
    while (++i < 4)
    {
        tetr->line = ft_strncat(tetr->line, str, 4);
        str = ((i == 4) ? str + 6 : str + 5);
    }
    if (ft_check_tetr(tetr->line) || !check_connection(tetr->line))
        return (NULL);
    tetr->snake = mintetr(tetr->line);
    tetr->letter = c;
    if (str[0] == '\n')
        tetr->next = fill_tetr(++str, tetr, c++);
    else
        tetr->next = NULL;
    return (tetr);
}

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
    int fd;
    t_tetr *fill;
    t_map   *map;
    int     n;
    
    if ((fd = open(av[1], O_RDONLY)) < 0)
        return (-1);
    fill = ft_read_tetr(fd);
    close(fd);
    while (fill)
    {
        printf("%s %d\n", fill->line, ft_strlen(fill->line));
        fill = fill->next;
    }
    // if (!(map = (t_map *)malloc(sizeof(map))))
    //     return (0);
    // map->count = counttetr(fill);
    // if (!(map->content = malloc(map->count * map->count * 4 * 4 * sizeof(char))))
	//     return (0);

    return (0);
}
