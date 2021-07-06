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
	maze->floor2 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor2) ? error_case(MALLOCERROR, -1) : 0;
	maze->floor3 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor3) ? error_case(MALLOCERROR, -1) : 0;
	maze->floor4 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor4) ? error_case(MALLOCERROR, -1) : 0;

	maze->floor_lava = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor_lava) ? error_case(MALLOCERROR, -1) : 0;
	maze->grass = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->grass) ? error_case(MALLOCERROR, -1) : 0;
	maze->lavad = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->lavad) ? error_case(MALLOCERROR, -1) : 0;

	maze->block_c = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->block_c) ? error_case(MALLOCERROR, -1) : 0;
	maze->block_f = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->block_f) ? error_case(MALLOCERROR, -1) : 0;
	maze->block_e = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->block_e) ? error_case(MALLOCERROR, -1) : 0;
	maze->block_r = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->block_r) ? error_case(MALLOCERROR, -1) : 0;
	maze->block_l = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->block_l) ? error_case(MALLOCERROR, -1) : 0;

	maze->chain_u = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->chain_u) ? error_case(MALLOCERROR, -1) : 0;
	maze->chain = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->chain) ? error_case(MALLOCERROR, -1) : 0;

	maze->tooth_r = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->tooth_r) ? error_case(MALLOCERROR, -1) : 0;
	maze->tooth_l = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->tooth_l) ? error_case(MALLOCERROR, -1) : 0;
	maze->tooth_d = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->tooth_d) ? error_case(MALLOCERROR, -1) : 0;
	maze->tooth_u = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->tooth_u) ? error_case(MALLOCERROR, -1) : 0;

	maze->col_down = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_down) ? error_case(MALLOCERROR, -1) : 0;
	maze->col_up = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_up) ? error_case(MALLOCERROR, -1) : 0;
	maze->col_half = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_half) ? error_case(MALLOCERROR, -1) : 0;

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
	maze->floor2->img = mlx_xpm_file_to_image(&maze->mlx, FLOOR2, &maze->floor2->w, &maze->floor2->h);
	maze->floor3->img = mlx_xpm_file_to_image(&maze->mlx, FLOOR3, &maze->floor3->w, &maze->floor3->h);
	maze->floor4->img = mlx_xpm_file_to_image(&maze->mlx, FLOOR4, &maze->floor4->w, &maze->floor4->h);

	maze->floor_lava->img = mlx_xpm_file_to_image(&maze->mlx, LAVA, &maze->floor_lava->w, &maze->floor_lava->h);
	maze->grass->img = mlx_xpm_file_to_image(&maze->mlx, GRASS, &maze->grass->w, &maze->grass->h);
	maze->lavad->img = mlx_xpm_file_to_image(&maze->mlx, LAVA_D, &maze->lavad->w, &maze->lavad->h);

	maze->block_l->img = mlx_xpm_file_to_image(&maze->mlx, BLOCK_L, &maze->grass->w, &maze->grass->h);
	maze->block_c->img = mlx_xpm_file_to_image(&maze->mlx, BLOCK_C, &maze->grass->w, &maze->grass->h);
	maze->block_r->img = mlx_xpm_file_to_image(&maze->mlx, BLOCK_R, &maze->grass->w, &maze->grass->h);
	maze->block_e->img = mlx_xpm_file_to_image(&maze->mlx, BLOCK_E, &maze->grass->w, &maze->grass->h);
	maze->block_f->img = mlx_xpm_file_to_image(&maze->mlx, BLOCK_F, &maze->grass->w, &maze->grass->h);

	maze->chain_u->img = mlx_xpm_file_to_image(&maze->mlx, CHAIN_UP, &maze->chain_u->w, &maze->chain_u->h);
	maze->chain->img = mlx_xpm_file_to_image(&maze->mlx, CHAIN, &maze->chain->w, &maze->chain->h);

	maze->col_down->img = mlx_xpm_file_to_image(&maze->mlx, COL_D, &maze->col_down->w, &maze->col_down->h);
	maze->col_up->img = mlx_xpm_file_to_image(&maze->mlx, COL_U, &maze->col_up->w, &maze->col_up->h);
	maze->col_half->img = mlx_xpm_file_to_image(&maze->mlx, COL_H, &maze->col_half->w, &maze->col_half->h);

	maze->tooth_r->img = mlx_xpm_file_to_image(&maze->mlx, TOOTH_R, &maze->tooth_r->w, &maze->tooth_r->h);
	maze->tooth_l->img = mlx_xpm_file_to_image(&maze->mlx, TOOTH_L, &maze->tooth_l->w, &maze->tooth_l->h);
	maze->tooth_u->img = mlx_xpm_file_to_image(&maze->mlx, TOOTH_U, &maze->tooth_u->w, &maze->tooth_u->h);
	maze->tooth_d->img = mlx_xpm_file_to_image(&maze->mlx, TOOTH_D, &maze->tooth_d->w, &maze->tooth_d->h);

	maze->exit->img = mlx_xpm_file_to_image(&maze->mlx, EXIT, &maze->exit->w, &maze->exit->h);

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			(maze->table[y][x] == FLOOR2_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor2->img, x * 16, y * 16)
			: (maze->table[y][x] == FLOOR3_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor3->img, x * 16, y * 16)
			: (maze->table[y][x] == FLOOR4_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor4->img, x * 16, y * 16)
			:mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, x * 16, y * 16);
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			(maze->table[y][x] == WALL_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall->img, x * 16, y * 16) :
			(maze->table[y][x] == GRASS_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->grass->img, x * 16, y * 16) :
			(maze->table[y][x] == LAVA_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor_lava->img, x * 16, y * 16) :
			(maze->table[y][x] == LAVAD_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->lavad->img, x * 16, y * 16) :
			(maze->table[y][x] == EXIT_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->exit->img, x * 16, y * 16) :
			(maze->table[y][x] == L_W_BLOCK_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_l->img, x * 16, y * 16) :
			(maze->table[y][x] == C_W_BLOCK_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_c->img, x * 16, y * 16) :
			(maze->table[y][x] == R_W_BLOCK_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_r->img, x * 16, y * 16) :
			(maze->table[y][x] == E_W_BLOCK_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_e->img, x * 16, y * 16) :
			(maze->table[y][x] == F_W_BLOCK_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_f->img, x * 16, y * 16) :
			(maze->table[y][x] == CHAIN_UP_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain_u->img, x * 16, y * 16) :
			(maze->table[y][x] == CHAIN_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain->img, x * 16, y * 16) :
			(maze->table[y][x] == TOOTH_LEFT_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->tooth_l->img, x * 16, y * 16) :
			(maze->table[y][x] == TOOTH_RIGHT_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->tooth_r->img, x * 16, y * 16) :
			(maze->table[y][x] == TOOTH_DOWN_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->tooth_d->img, x * 16, y * 16) :
			(maze->table[y][x] == TOOTH_UP_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->tooth_u->img, x * 16, y * 16) :
			(maze->table[y][x] == COL_UP_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_up->img, x * 16, y * 16) :
			(maze->table[y][x] == COL_DOWN_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_down->img, x * 16, y * 16) :
			(maze->table[y][x] == COL_HALF_ID) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_half->img, x * 16, y * 16) : 0;
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