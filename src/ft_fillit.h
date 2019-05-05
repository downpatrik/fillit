/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:08:23 by wvenita           #+#    #+#             */
/*   Updated: 2019/05/05 19:04:03 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <fcntl.h>
# include "../libft/libft.h"
# define ERROR if (ft_putendl("error")) return (0);

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

int					ft_check_tetr(char *av);
int					check_connection(char *av);
void				del_tetr(t_map *map, char letter);
int					ft_read_tetr(char *file, t_tetr **tetr);
int					fill_tetr(char *str, t_tetr **tetr, char c);
int					*mintetr(char *str);
int					placetetr(t_map *map, t_tetr *tetr, int n);
int					ft_solved(t_map *map, t_tetr *tetr, char *alph);
int					minsquare(int n);
int					counttetr(t_tetr *tetr);
int					ft_solve(t_map **map, t_tetr *tetr);
void				ft_freetetr(t_tetr **tetr);

#endif
