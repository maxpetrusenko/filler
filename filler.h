
#ifndef FILLER_H
# define FILLER_H

# include "./libft/header/libft.h"
# include "stdlib.h"

typedef struct s_filler
{
    int     map_height;
    int     map_width;
    int     p_width;
    int     p_height;
    int     got_map;
    int     got_player;
    char    my_sign;
    char    enemy_sign;

}               t_filler;

void	read_line(char *line, t_filler *data);
char	*get_map_size(char *line, t_filler *data);

#endif