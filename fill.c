#include "filler.h"

void find_min_dist(t_filler *data)
{
	int can_place = 0;
    data->map_x = 0;
	data->min_dist = 9999999;

    while (data->map_x < data->map_height)
    {
        data->map_y = 0;
        while (data->map_y < data->map_width)
        {
			can_place = place_piece(data, data->map_x, data->map_y);
			if( can_place == 1)
				last_location(data, data->map_x,data->map_y);
            data->map_y++;
        }
        data->map_x++;
    }
	ft_printf("%d %d\n", data->last_y, data->last_x);
}

void	last_location(t_filler *data, int x, int y)
{
	int abs;

	abs = (data->my_x - data->enemy_x) +(data->my_y - data->enemy_y);
	if (data->map[data->map_x][data->map_y] == data->my_sign)
	{
	    data->my_x = data->map_x;
	    data->my_y = data->map_y;
	}
	if (data->map[data->map_x][data->map_y] == data->enemy_sign)
	{
	    data->enemy_x = data->map_x;
	    data->enemy_y = data->map_y;
	}
	abs < data->min_dist ? data->last_x = x : data->last_x ;
	abs < data->min_dist ? data->last_y = y : data->last_y ;
}

int				place_piece(t_filler *data, int x, int y)
{
	data->i = 0;
	data->k = 0;
	while (data->i < data->p_height && y + data->i < data->map_height)
	{
		data->j = 0;
		while (data->j < data->p_width && x + data->j < data->map_width)
		{
			if (data->piece[data->i][data->j] == '*' && (data->map[y + \
			data->i][x + data->j] == data->my_sign || data->map[y + \
			data->i][x + data->j] == ft_tolower(data->my_sign)))
				data->k++;
			else if (data->piece[data->i][data->j] == '*' && data->map[y + \
			data->i][x + data->j] != '.')
				return (0);
			data->j++;
		}
		if (!check_row(data, data->i, data->j))
			return (0);
		data->i++;
	}
	if (data->k == 1 && check_column(data, data->i))
		return (1);
	return (0);
}

int				check_column(t_filler *data, int y)
{
	int x;

	while (y < data->p_height)
	{
		x = 0;
		while (x < data->p_width)
		{
			if (data->piece[y][x] == '*')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int				check_row(t_filler *data, int y, int x)
{
	while (x < data->p_width)
	{
		if (data->piece[y][x] == '*')
			return (0);
		x++;
	}
	return (1);
}
