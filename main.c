
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
        read_line(line, data);
		printf("height: %d and width is: %d\n", data->map_height, data->map_width);
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


