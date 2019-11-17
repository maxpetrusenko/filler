/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:02:27 by mpetruse          #+#    #+#             */
/*   Updated: 2019/11/16 18:14:48 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_min_dist(t_filler *data)
{
	data->map_y = 0;
	data->min_dist = 9999999;
	data->last_x = 0;
	data->last_y = 0;
	while (data->map_y < data->map_height)
	{
		data->map_x = 0;
		while (data->map_x < data->map_width)
		{
			data->can_place = place_piece(data, data->map_x, data->map_y);
			if (data->can_place == 1)
				last_location(data, data->map_x, data->map_y);
			data->map_x++;
		}
		data->map_y++;
	}
	ft_printf("%d %d\n", data->last_y, data->last_x);
}

void	last_location(t_filler *data, int x, int y)
{
	data->i = 0;
	data->j = 0;
	while (data->i++ < data->map_height)
	{
		data->j = 0;
		while (data->j++ < data->map_width)
		{
			if (data->map[data->i][data->j] == data->enemy_sign)
			{
				data->right = data->i < y ? y - data->i : data->i - y;
				data->left = data->j < x ? x - data->j : data->j - x;
				data->min_dist = data->right + data->left;
				if (data->min == -1 || data->min > data->min_dist)
				{
					data->min = data->min_dist;
					data->last_x = x;
					data->last_y = y;
				}
			}
		}
	}
}

int		place_piece(t_filler *data, int x, int y)
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
	return (data->k == 1 && check_column(data, data->i) ? 1 : 0);
}

int		check_column(t_filler *data, int y)
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

int		check_row(t_filler *data, int y, int x)
{
	while (x < data->p_width)
	{
		if (data->piece[y][x] == '*')
			return (0);
		x++;
	}
	return (1);
}
