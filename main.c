
#include "filler.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
    t_filler	*data;
	data = malloc(sizeof(t_filler));
	data->map_height = 0;
	data->p_height = 0;
	data->got_map = 0;
    data->got_player = 0;

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
        read_line(line, data);
		printf("%s\n", line);
        free(data);
	}
	close(fd);
	return (0);
}

char	*get_map_size(char *line, t_filler *data)
{
	char **line_data;

	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		line_data = ft_strsplit(line, ' ');
		data->map_height = ft_atoi(line_data[1]);
		data->map_width = ft_atoi(line_data[2]);
        ft_printf("this is line : %s" , line_data);
        ft_free_double_array((void*)line_data, 3);
        get_next_line(0, &line);
        data->got_map = 1;
	}
	return (line);
}

char	*get_player(char *line, t_filler *data)
{
	if (ft_strncmp(line, "$$$ exec p", 9) == 0)
	{
        data->my_sign = (line[10] == '1' ? 'O' : 'X');
        data->enemy_sign = (line[10] == '2' ? 'O' : 'X');
        data->got_player = 1;
	}
	return (line);
}

void	read_line(char *line, t_filler *data)
{
    if(data->got_map == 0)
        line = get_map_size(line, data);
    if(data->got_player == 0)
        line = get_player(line, data);

    free(line);
}


