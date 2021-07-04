#include "../includes/so_long.h"
#include "../libft/libft.h"

void error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

static int	esc(void)
{
	exit(0);
}

int	key_event(int key, t_params *maze)
{
	if (key == 53)
		esc();
//	if (key == 2)
//		map->move_x -= 50;
//	if (key == 0)
//		map->move_x += 50;
//	if (key == 1)
//		map->move_y -= 50;
//	if (key == 13)
//		map->move_y += 50;
//	if (key == 24)
//		map->scale += 1;
//	if (key == 27)
//		map->scale -= 1;
//	mlx_clear_window(map->mlx, map->win);
//	build_blocks(maze);
	return (0);
}

int main(int argc, char *argv[])
{
	t_params	maze;
	t_frame 	img;

	if (argc != 2)
		error_case("Invalid config", 1);
	get_map(argv[1], &maze);

	for (int j = 0; j < maze.width+2; j++)
		printf("\033[47m  \033[0m");
	printf("\n");
	for (int i = 0; i < maze.height; i++)
	{
		printf("\033[47m  \033[0m");
		for (int j = 0; j < maze.width; j++) {
			if (maze.table[i][j] == 0)
				printf("\033[47m  \033[0m");
			if (maze.table[i][j] == 1)
				printf("\033[37m  \033[0m");
			if (maze.table[i][j] == 2)
				printf("\033[46m  \033[0m");
			if (maze.table[i][j] == -1)
				printf("\033[41m  \033[0m");
			if (maze.table[i][j] == 3)
				printf("\033[42m  \033[0m");
		}
		printf("\033[47m  \033[0m\n");
	}
	for (int j = 0; j < maze.width+2; j++)
		printf("\033[47m  \033[0m");
	printf("\n");
	usleep(1000);

	maze.mlx = mlx_init();
	if (!maze.mlx)
		error_case("Mlx failed", -1);
	maze.win = mlx_new_window(maze.mlx, maze.width * 32, maze.height * 32, "So_long");

//	img.img = mlx_new_image(maze.mlx, maze.width * 32, maze.height * 32);
//	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.length, &img.end);
	int x = 0;
	int y = 0;
	mlx_xpm_file_to_image(maze.mlx, "../cherry.xpm", &x, &y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.length, &img.end);
	mlx_put_image_to_window(maze.mlx, maze.win, img.img, 0, 0);

//	build_blocks(&img, &maze);
//	mlx_put_image_to_window(maze.mlx, maze.win, img.img, 0, 0);

	mlx_hook(maze.win, 2, 0, key_event, &maze);
	mlx_hook(maze.win, 17, 0, esc, &maze);
	mlx_loop(maze.mlx);

	return 0;
}
