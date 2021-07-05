#include "../includes/so_long.h"

unsigned int get_pixel(t_frame *reference, int x, int y)
{
	char *dst;

	dst = reference->addr + (y * reference->length + x * (reference->bpp / 8));
	return(*(unsigned int*)dst);
}

void init_frames(t_params	*maze)
{
	maze->wall = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->wall) ? error_case(MALLOCERROR, -1) : 0;
	maze->floor = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor) ? error_case(MALLOCERROR, -1) : 0;
	maze->grass = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->grass) ? error_case(MALLOCERROR, -1) : 0;
	maze->player = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->player) ? error_case(MALLOCERROR, -1) : 0;
	maze->exit = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->exit) ? error_case(MALLOCERROR, -1) : 0;
	maze->sprite = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->sprite) ? error_case(MALLOCERROR, -1) : 0;
}
//
//void *set_size(char *path)
//{
//	t_frame
//}

void	build_static_blocks(t_params	*maze, int w, int h)
{
	init_frames(maze);
	maze->wall->img = mlx_xpm_file_to_image(&maze->mlx, WALL, &maze->wall->w, &maze->wall->h);
	maze->floor->img = mlx_xpm_file_to_image(&maze->mlx, FLOOR, &maze->floor->w, &maze->floor->h);
	maze->grass->img = mlx_xpm_file_to_image(&maze->mlx, GRASS, &maze->grass->w, &maze->grass->h);
	maze->exit->img = mlx_xpm_file_to_image(&maze->mlx, EXIT, &maze->exit->w, &maze->exit->h);

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, x * 16, y * 16);
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			(maze->table[y][x] == WALL_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall->img, x * 16, y * 16) :
			(maze->table[y][x] == GRASS_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->grass->img, x * 16, y * 16) :
			(maze->table[y][x] == EXIT_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->exit->img, x * 16, y * 16) : 0;
		}
}

void 	build_dynamic_blocks(t_params	*maze, int w, int h)
{
	maze->player->img = mlx_xpm_file_to_image(&maze->mlx, PLAYER_RIGHT, &maze->player->w, &maze->player->h);
	maze->sprite->img = mlx_xpm_file_to_image(&maze->mlx, SPRITE, &maze->sprite->w, &maze->sprite->h);
	printf("\n 1 \n");

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (maze->table[y][x] == PLAYER_ID)
				mlx_put_image_to_window(maze->mlx, maze->win, maze->player->img, x * 16, y * 16);
			if (maze->table[y][x] == SPRITE_ID)
				mlx_put_image_to_window(maze->mlx, maze->win, maze->sprite->img, x * 16, y * 16);
		}
	}
}