/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:05:52 by mpetruse          #+#    #+#             */
/*   Updated: 2019/11/11 18:06:53 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/header/libft.h"
# include "stdlib.h"

typedef struct	s_filler
{
	int			map_height;
	int			map_width;
	int			p_width;
	int			p_height;
	int			got_map;
	int			got_player;
	char		my_sign;
	char		enemy_sign;
	int			fd;
	int			map_x;
	int			map_y;
	int			piece_x;
	int			piece_y;
	int			map_start;
	int			piece_start;
	char		**map;
	char		**piece;
	int			my_x;
	int			my_y;
	int			enemy_x;
	int			enemy_y;
	int			last_x;
	int			last_y;
	int			min_dist;
	int			k;
	int			i;
	int			j;
}				t_filler;

void			read_line(char *line, t_filler *data);
char			*get_map_size(char *line, t_filler *data);
char			*get_player(char *line, t_filler *data);
char			*get_map(char *line, t_filler *data);
char			*get_piece_size(char *line, t_filler *data);
char			*get_piece(char *line, t_filler *data);
void			*malloc_map(t_filler *data);
void			*malloc_piece(t_filler *data);
void			find_min_dist(t_filler *data);
void			last_location(t_filler *data, int x, int y);
int				check_column(t_filler *data, int y);
int				check_row(t_filler *data, int y, int x);
int				place_piece(t_filler *data, int x, int y);

#endif
