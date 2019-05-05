/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:00:04 by dhilll            #+#    #+#             */
/*   Updated: 2019/05/05 19:02:10 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_check_tetr(char *av)
{
	int		i;
	int		count_hash;

	i = -1;
	count_hash = 0;
	while (++i < 16)
	{
		if (!((av[i] == '.') || (av[i] == '#')))
			return (0);
		else if (av[i] == '#')
			count_hash++;
	}
	return (count_hash == 4);
}

int		check_connection(char *av)
{
	int		i;
	int		connect;

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

int		ft_read_tetr(char *file, t_tetr **tetr)
{
	char	*str;
	char	buffer[255];
	int		fd;
	size_t	fr;
	size_t	i;

	if ((fd = open(file, O_RDONLY)) < 0 || read(fd, buffer, 0) < 0)
		return (0);
	str = ft_strnew(0);
	while ((fr = read(fd, buffer, 256)))
	{
		buffer[fr] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if ((ft_strlen(str) + 1) % 21 != 0 || ft_strlen(str) > 546 || close(fd))
		return (0);
	i = 20;
	while (i < ft_strlen(str))
	{
		if (str[i] != '\n')
			return (1);
		i = i + 21;
	}
	return (fill_tetr(str, tetr, 'A'));
}

int		*mintetr(char *str)
{
	int	*tmp;
	int	i;
	int	j;

	if (!(tmp = (int*)malloc(sizeof(int) * 4)))
		return (0);
	i = -1;
	j = -1;
	while (str[++i])
		if (str[i] == '#')
			tmp[++j] = i;
	i = tmp[0];
	if (tmp[1] - tmp[0] == 2)
		i -= 1;
	if (tmp[2] - tmp[0] == 7 || tmp[1] - tmp[0] == 3 || tmp[2] - tmp[0] == 3)
		i -= 1;
	j = -1;
	while (++j < 4)
		tmp[j] -= i;
	return (tmp);
}

int		fill_tetr(char *str, t_tetr **tetr, char c)
{
	t_tetr	*tmp;
	int		i;

	if (!(tmp = (t_tetr *)malloc(sizeof(*tmp))))
		return (0);
	if (!(tmp->line = (char *)malloc(sizeof(char) * 17)))
		return (0);
	tmp->line[16] = '\0';
	i = -1;
	while (++i < 4)
	{
		tmp->line = ft_strncat(tmp->line, str, 4);
		str = ((i == 4) ? str + 6 : str + 5);
	}
	if (!ft_check_tetr(tmp->line) || !check_connection(tmp->line))
		return (0);
	tmp->snake = mintetr(tmp->line);
	tmp->letter = c;
	*tetr = tmp;
	if (str[0] == '\n')
		return (fill_tetr(++str, &tmp->next, ++c));
	else
		return (!(int)(tmp->next = NULL));
}
