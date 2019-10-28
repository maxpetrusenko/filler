
#include "filler.h"

char	*get_map_size(char *line, t_filler *data)
{
	char **line_data;

	free(line);
	get_next_line(data->fd, &line);
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
	    get_next_line(data->fd, &line);
	}
    data->my_sign = (line[10] == '1' ? 'O' : 'X');
    data->enemy_sign = (line[10] == '2' ? 'O' : 'X');
	return (line);
}

char	*get_map(char *line, t_filler *data)
{
	while (ft_strncmp(line, "000 ", 4) != 0)
	{
		free(line);
	    get_next_line(data->fd, &line);
	}
	data->map_x = 0;
	while(data->map_x < data->map_height)
	{
		data->map_start = 4;
		data->map_y = 0;
		while(data->map_y < data->map_width)
		{
			data->map[data->map_x][data->map_y] = line[data->map_start];
			free(line);
			data->map_y++;
			data->map_start++;
		}
		free(line);
		get_next_line(data->fd, &line);
		data->map_x++;
	}
	return (line);
}

char	*get_piece_size(char *line, t_filler *data)
{
	char **line_data;

	while (ft_strncmp(line, "Piece", 4) != 0)
	{
		free(line);
	    get_next_line(data->fd, &line);
	}
	line_data = ft_strsplit(line, ' ');
	data->p_height = ft_atoi(line_data[1]);
	data->p_width = ft_atoi(line_data[2]);
    ft_free_double_array((void*)line_data, 3);
	return (line);
}

char	*get_piece(char *line, t_filler *data)
{

	make_piece(data);
	data->piece_x = 0;
	while (data->piece_x < data->p_height)
	{
		free(line);
		get_next_line(0, &line);
		data->piece_start = 0;
		data->piece_y = 0;
		while (data->piece_y < data->p_width)
		{
			data->piece[data->piece_x][data->piece_y] = line[data->piece_start++];
			data->piece_y++;
		}
		data->piece_x++;
	}
	return (line);
}