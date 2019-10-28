
#include "filler.h"

int	main(int ac, char **av)
{
	char	*line;
    t_filler	*data;

	data = malloc(sizeof(t_filler));
	data->got_map = 0;
    data->got_player = 0;

	if (ac < 2)
		return (0);
	data->fd = open(av[1], O_RDONLY);
	while (get_next_line(data->fd, &line) > 0)
	{
		while(1)
		{
			
		}
        read_line(line, data);
		printf("map:height: %d and width is: %d\n", data->map_height, data->map_width);
		printf("piece:height: %d and width is: %d\n", data->p_height, data->p_width);
		printf("my sign: %c and enemy is: %c\n", data->my_sign, data->enemy_sign);
        free(data);
	}
	close(data->fd);
	return (0);
}

void	read_line(char *line, t_filler *data)
{
	if(data->got_player == 0)
        line = get_player(line, data);
		data->got_player = 1;
    if(data->got_map == 0)
        line = get_map_size(line, data);
		data->got_map = 1;
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
