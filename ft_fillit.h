/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:08:23 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/02 19:07:57 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetr
{
	char			*line;
	int				*snake;
	char			letter;
    struct s_tetr	*next;
    struct s_tetr	*previous;
}					t_tetr;

typedef struct		s_map
{
	int				size;
	int				count;
	char			*content;
}					t_map;

t_map				fill_dots(int a);
void				print_map(t_map map);
int					ft_check_tetr(char *av);
int					check_connection(char *av);
void				del_tetr(t_map *map, char letter);
t_tetr				*ft_read_tetr(const int fd);
t_tetr				*fill_tetr(char *str, t_tetr *prev, char c);
int					count(t_tetr *tetr);

#endif
