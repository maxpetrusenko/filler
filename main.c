
#include "filler.h"

int	main(void)
{
	char		*line;
    t_filler	*data;

	data = malloc(sizeof(t_filler));
	data->got_map = 0;
    data->got_player = 0;

	while (get_next_line(0, &line) > 0)
	{
		if( *line == '\0')
			break;
        read_line(line, data);
		find_min_dist(data);
		ft_free_double_array((void**)data->map, data->map_height);
		ft_free_double_array((void**)data->piece, data->p_height);
	}
	free(data);
	close(data->fd);
	return (0);
}

void	read_line(char *line, t_filler *data)
{
	if(data->got_player == 0)
	{
        line = get_player(line, data);
		data->got_player = 1;
	}
    if(data->got_map == 0)
	{
        line = get_map_size(line, data);
		data->got_map = 1;
	}
	line = get_map(line, data);
	line = get_piece_size(line, data);
	line = get_piece(line, data);
    free(line);
}

void	*malloc_map(t_filler *data)
{
	int i;

	i = 0;
	data->map = (char **)malloc(sizeof(char*) * (data->map_height + 1));
	if (!data->map)
		return (NULL);
	while (i < data->map_height + 1)
	{
		data->map[i] = (char*)malloc(sizeof(char) * (data->map_width + 1));
		i++;
	}
	return (NULL);
}

void	*malloc_piece(t_filler *data)
{
	int i;

	i = 0;
	data->piece = (char **)malloc(sizeof(char*) * (data->p_height + 1));
	if (!data->piece)
		return (NULL);
	while (i < data->p_height + 1)
	{
		data->piece[i] = (char*)malloc(sizeof(char) * (data->p_width + 1));
		i++;
	}
	return (NULL);
}
