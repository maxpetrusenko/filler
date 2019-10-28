
#ifndef FILLER_H
# define FILLER_H

# include "./libft/header/libft.h"
# include "stdlib.h"

typedef struct s_filler
{
	int		map_height;
	int		map_width;
	int		p_width;
	int		p_height;
	int		got_map;
	int		got_player;
	char	my_sign;
	char	enemy_sign;
	int		fd;
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;
	int		map_start;
	int		piece_start;
	char	**map;
	char	**piece;

}               t_filler;

void	read_line(char *line, t_filler *data);
char	*get_map_size(char *line, t_filler *data);
char	*get_player(char *line, t_filler *data);
char	*get_map(char *line, t_filler *data);
char	*get_piece_size(char *line, t_filler *data);
char	*get_piece(char *line, t_filler *data);
void	*malloc_map(t_filler *data);
void	*malloc_piece(t_filler *data);

#endif