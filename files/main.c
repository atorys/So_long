#include "../includes/so_long.h"
#include "../libft/libft.h"

#define UP 13
#define DOWN 1
#define LEFT 0
#define RIGHT 2

void error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

static int	esc(void)
{
	exit(0);
}

void	move_player(t_params *maze, int step_x, int step_y, int key)
{
	int	id_next;
	int curr_x;
	int	curr_y;

	curr_x = maze->start_x;
	curr_y = maze->start_y;
	id_next = maze->table[curr_y + step_y][curr_x + step_x];
	if (curr_y + step_y == maze->end_y && curr_x + step_x == maze->end_x && !maze->sprites_count)
	{
		esc();
	}
	if ((id_next >= 8 && id_next < 10) || id_next == ID_SPRITE)
	{
		if (id_next == ID_SPRITE) /** sprite*/
		{
			maze->sprites_count--;
			printf("sprites : %d\n", maze->sprites_count);
			maze->table[curr_y + step_y][curr_x + step_x] = ID_FLOOR;
			(!maze->sprites_count) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->exit->img, maze->end_x * SIZE, maze->end_y * SIZE) : 0;
		}
		build_prev_block(maze);
		maze->start_x += step_x;
		maze->start_y += step_y;
		(key == UP) ? build_player(maze, maze->player_u) :
		(key == DOWN) ? build_player(maze, maze->player_d) :
		(key == RIGHT) ? build_player(maze, maze->player_r) : build_player(maze, maze->player_l);
		sleep(50 / 60);
	}
	if (id_next == ID_CHAIN  || id_next == ID_CHAIN_T)
	{
		build_prev_block(maze);
		maze->start_x += step_x;
		maze->start_y += step_y;
		(key == UP) ? build_player(maze, maze->player_u) :
		(key == DOWN) ? build_player(maze, maze->player_d) :
		(key == RIGHT) ? build_player(maze, maze->player_r) : build_player(maze, maze->player_l);
		return ;
	}
	while (maze->table[maze->start_y + 1][maze->start_x] == ID_FLOOR || maze->table[maze->start_y + 1][maze->start_x] == ID_FLOOR2 || \
	maze->table[maze->start_y + 1][maze->start_x] == ID_SPRITE)
	{
		if (maze->table[maze->start_y + 1][maze->start_x] == ID_SPRITE) /** sprite*/
		{
			maze->sprites_count--;
			printf("sprites : %d\n", maze->sprites_count);
			maze->table[maze->start_y + 1][maze->start_x] = ID_FLOOR;
			(!maze->sprites_count) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->exit->img, maze->end_x * SIZE, maze->end_y * SIZE) : 0;
		}
		usleep(10000);
		build_prev_block(maze);
//		usleep(1);
//		falling(maze);
		maze->start_y++;
		build_player(maze, maze->player_d);
		usleep(1000);
//		sleep(60 / 60);
	}
}

int	key_event(int key, t_params *maze)
{
	if (key == 53)
		esc();
	if (key == UP)
		move_player(maze, 0, -1, UP);
	if (key == DOWN)
		move_player(maze, 0, 1, DOWN);
	if (key == LEFT)
		move_player(maze, -1, 0, LEFT);
	if (key == RIGHT)
		move_player(maze, 1, 0, RIGHT);
//	if (key == 24)
//		map->scale += 1;
//	if (key == 27)
//		map->scale -= 1;
//	mlx_clear_window(map->mlx, map->win);
	return (0);
}

int main(int argc, char *argv[])
{
	t_params	maze;
	int			width;
	int			height;

	if (argc != 2)
		error_case("Invalid config", 1);
	get_map(argv[1], &maze);

//	for (int j = 0; j < maze.width+2; j++)
//		printf("\033[47m  \033[0m");
//	printf("\n");
//	for (int i = 0; i < maze.height; i++)
//	{
//		printf("\033[47m  \033[0m");
//		for (int j = 0; j < maze.width; j++) {
//			if (maze.table[i][j] == 0)
//				printf("\033[47m  \033[0m");
//			if (maze.table[i][j] == 1)
//				printf("\033[37m  \033[0m");
//			if (maze.table[i][j] == 2)
//				printf("\033[46m  \033[0m");
//			if (maze.table[i][j] == -1)
//				printf("\033[41m  \033[0m");
//			if (maze.table[i][j] == 3)
//				printf("\033[42m  \033[0m");
//		}
//		printf("\033[47m  \033[0m\n");
//	}
//	for (int j = 0; j < maze.width+2; j++)
//		printf("\033[47m  \033[0m");
//	printf("\n");

	maze.mlx = mlx_init();
	if (!maze.mlx)
		error_case("Mlx failed", -1);
	maze.win = mlx_new_window(maze.mlx, maze.width * SIZE, maze.height * SIZE, "So_long");
	mlx_do_key_autorepeaton(maze.mlx);
	printf("sprites : %d\n", maze.sprites_count);
	run(&maze);

	mlx_hook(maze.win, 2, 0, key_event, &maze);
	mlx_hook(maze.win, 17, 0, esc, &maze);
	mlx_loop(maze.mlx);

	return 0;
}
