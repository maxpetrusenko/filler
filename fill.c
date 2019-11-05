#include "filler.h"

void find_min_dist(t_filler *data)
{
	int can_place = 0;
	//not nulling enemy_x_y and my_x_y = 0;
    data->map_x = 0;
	data->min_dist = 9999999;

    while (data->map_x < data->map_height)
    {
        data->map_y = 0;
        while (data->map_y < data->map_width)
        {
			// can_place = place_piece(data,data->map_x,data->map_y);
			can_place = place_piece(data, data->map_x, data->map_y);
			if( can_place == 1)
			{
				// ft_printf("%d %d    ", data->map_x, data->map_y);
				last_location(data, data->map_x,data->map_y);
			}
            data->map_y++;
        }
        data->map_x++;
    }
	ft_putnbr(data->last_y);
	ft_putchar(' ');
	ft_putnbr(data->last_x);
	ft_putchar('\n');
}
//vitashit min dist in function
//проверить если можно поставить картинку по ров и по колонке
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
	if(abs<data->min_dist)
		// ft_printf("adasf\n");
	// abs < min_dist ? min_dist = ABS(abs) : min_dist;
	
	abs < data->min_dist ? data->last_x = x : data->last_x ;
	abs < data->min_dist ? data->last_y = y : data->last_y ;
	// ft_printf(" x = %d  y = %d\n", data->last_x, data->last_y);
}
//postavit kartinku
// int	place_piece(t_filler *data, int x , int y)
int				place_piece(t_filler *data, int x, int y)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < data->p_height && y + i < data->map_height)
	{
		while (j < data->p_width && x + j < data->map_width)
		{
			if (data->piece[i][j] == '*' && (data->map[y + i][x + j] ==
	data->my_sign || data->map[y + i][x + j] == ft_tolower(data->my_sign)))
				k++;
			else if (data->piece[i][j] == '*' && data->map[y + i][x + j] != '.')
				return (0);
			j++;
		}
		if (!check_row(data, i, j))
			return (0);
		j = 0;
		i++;
	}
	return (k == 1 && check_column(data, i) ? 1 : 0);
}



int				check_column(t_filler *data, int y)
{
	int x;

	x = 0;
	while (y < data->p_height)
	{
		while (x < data->p_width)
		{
			if (data->piece[y][x] == '*')
				return (0);
			x++;
		}
		x = 0;
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