/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:02:34 by mpetruse          #+#    #+#             */
/*   Updated: 2019/11/16 15:02:27 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_map_size(char *line, t_filler *data)
{
	char **line_data;

	while (ft_strncmp(line, "Plateau", 7) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	line_data = ft_strsplit(line, ' ');
	data->map_height = ft_atoi(line_data[1]);
	data->map_width = ft_atoi(line_data[2]);
	ft_free_double_array((void*)line_data, 3);
	return (line);
}

char	*get_player(char *line, t_filler *data)
{
	while (ft_strncmp(line, "$$$ exec p", 9) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	data->my_sign = (line[10] == '1' ? 'O' : 'X');
	data->enemy_sign = (line[10] == '2' ? 'O' : 'X');
	return (line);
}

char	*get_map(char *line, t_filler *data)
{
	if (!line || *line == '\0' || line == 0)
		return (NULL);
	while (ft_strncmp(line, "000", 3) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	malloc_map(data);
	data->map_x = 0;
	while (data->map_x < data->map_height)
	{
		data->map_start = 4;
		data->map_y = 0;
		while (data->map_y < data->map_width)
		{
			data->map[data->map_x][data->map_y] = line[data->map_start];
			data->map_y++;
			data->map_start++;
		}
		free(line);
		get_next_line(0, &line);
		data->map_x++;
	}
	return (line);
}

char	*get_piece_size(char *line, t_filler *data)
{
	char **line_data;

	if (!line || *line == '\0' || line == 0)
		return (NULL);
	while (ft_strncmp(line, "Piece", 4) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	line_data = ft_strsplit(line, ' ');
	data->p_height = ft_atoi(line_data[1]);
	data->p_width = ft_atoi(line_data[2]);
	ft_free_double_array((void*)line_data, 3);
	return (line);
}

char	*get_piece(char *line, t_filler *data)
{
	if (!line || *line == '\0' || line == 0)
		return (NULL);
	data->piece_x = 0;
	malloc_piece(data);
	while (data->piece_x < data->p_height)
	{
		free(line);
		get_next_line(0, &line);
		data->piece_start = 0;
		data->piece_y = 0;
		while (data->piece_y < data->p_width)
		{
			data->piece[data->piece_x][data->piece_y] = line[data->piece_start];
			data->piece_y++;
			data->piece_start++;
		}
		data->piece_x++;
	}
	return (line);
}
