// #include "filler.h"

// void find_min_dist(t_filler *data)
// {
// 	int min_dist = 9999999;
// 	int abs = ABS((data->my_x - data->enemy_x) +(data->my_y - data->enemy_y));
// 	int can_place = 0;
// 	//not nulling enemy_x_y and my_x_y = 0;
//     data->map_x = 0;

//     while (data->map_x < data->map_height)
//     {
//         data->map_y = 0;
//         while (data->map_y < data->map_width)
//         {
//             if (data->map[data->map_x][data->map_y] == data->my_sign)
//             {
//                 data->my_x = data->map_x;
//                 data->my_y = data->map_y;
//             }
// 			if (data->map[data->map_x][data->map_y] == data->enemy_sign)
// 			{
//                 data->enemy_x = data->map_x;
//                 data->enemy_y = data->map_y;
// 			}
// 			can_place = place_piece(data,data->map_x,data->map_y);
// 			if( can_place == 1)
// 				abs < min_dist ? min_dist = ABS(abs) : ABS(abs);
//             data->map_y++;
//         }
//         data->map_x++;
//     }
// 	ft_printf("%d %d\n",data->last_x, data->last_y);
// }
// //vitashit min dist in function
// //проверить если можно поставить картинку по ров и по колонке

// //postavit kartinku
// int	place_piece(t_filler *data, int x , int y)
// {

// return (1);
// }

// int				check_column(t_filler *data, int y)
// {
// 	int x;

// 	x = 0;
// 	while (y < data->p_height)
// 	{
// 		while (x < data->p_width)
// 		{
// 			if (data->piece[y][x] == '*')
// 				return (0);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return (1);
// }

// int				check_row(t_filler *data, int y, int x)
// {
// 	while (x < data->p_width)
// 	{
// 		if (data->piece[y][x] == '*')
// 			return (0);
// 		x++;
// 	}
// 	return (1);
// }