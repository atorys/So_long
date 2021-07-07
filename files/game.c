#include "../includes/so_long.h"

void init_frames(t_params	*maze);
void fill_frames(t_params	*maze);

void	run(t_params *maze)
{
	int width;
	int height;

	width = maze->width;
	height = maze->height;

	init_frames(maze);
	printf("\n 1 \n");
	fill_frames(maze);
	printf("\n 2 \n");
	build_static_blocks(maze, width, height);
	printf("\n 3 \n");
//	printf("\n %d %d \n", height , width);
	build_dynamic_blocks(maze, width, height);
	printf("\n 4 \n");
}

/************************************************************\
 *                   preparation funcs                       *
 ************************************************************/

void init_frames(t_params	*maze)
{
	maze->wall = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->wall) ? error_case(MALLOCERROR, -1) : 0;
	maze->wall_cube = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->wall_cube) ? error_case(MALLOCERROR, -1) : 0;
	maze->wall_dest = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->wall_dest) ? error_case(MALLOCERROR, -1) : 0;

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

	maze->floor = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor) ? error_case(MALLOCERROR, -1) : 0;
	maze->floor2 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->floor2) ? error_case(MALLOCERROR, -1) : 0;

	maze->col_bottom = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_bottom) ? error_case(MALLOCERROR, -1) : 0;
	maze->col_top = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_top) ? error_case(MALLOCERROR, -1) : 0;
	maze->col_half = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_half) ? error_case(MALLOCERROR, -1) : 0;
	maze->col_middle = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->col_middle) ? error_case(MALLOCERROR, -1) : 0;

	maze->chain_top = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->chain_top) ? error_case(MALLOCERROR, -1) : 0;
	maze->chain = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->chain) ? error_case(MALLOCERROR, -1) : 0;

	maze->lava1 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->lava1) ? error_case(MALLOCERROR, -1) : 0;
	maze->lava2 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->lava2) ? error_case(MALLOCERROR, -1) : 0;
	maze->grass1 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->grass1) ? error_case(MALLOCERROR, -1) : 0;
	maze->grass2 = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->grass2) ? error_case(MALLOCERROR, -1) : 0;
	maze->ice = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->ice) ? error_case(MALLOCERROR, -1) : 0;

	maze->teeth_r = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->teeth_r) ? error_case(MALLOCERROR, -1) : 0;
	maze->teeth_l = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->teeth_l) ? error_case(MALLOCERROR, -1) : 0;
	maze->teeth_b = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->teeth_b) ? error_case(MALLOCERROR, -1) : 0;
	maze->teeth_t = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->teeth_t) ? error_case(MALLOCERROR, -1) : 0;


	maze->player_r = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->player_r) ? error_case(MALLOCERROR, -1) : 0;
	maze->player_l = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->player_l) ? error_case(MALLOCERROR, -1) : 0;
	maze->player_u = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->player_u) ? error_case(MALLOCERROR, -1) : 0;
	maze->player_d = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->player_d) ? error_case(MALLOCERROR, -1) : 0;

	maze->exit = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->exit) ? error_case(MALLOCERROR, -1) : 0;
	maze->sprite = (struct s_frame *)malloc(sizeof(t_frame));
	(!maze->sprite) ? error_case(MALLOCERROR, -1) : 0;
}

void fill_frames(t_params	*maze)
{
	maze->wall->img = mlx_xpm_file_to_image(&maze->mlx, T_WALL, &maze->wall->w, &maze->wall->h);
	maze->wall_cube->img = mlx_xpm_file_to_image(&maze->mlx, T_WALL_CUBE, &maze->wall_cube->w, &maze->wall_cube->h);
	maze->wall_dest->img = mlx_xpm_file_to_image(&maze->mlx, T_WALL_DEST, &maze->wall_dest->w, &maze->wall_dest->h);

	maze->floor->img = mlx_xpm_file_to_image(&maze->mlx, T_FLOOR, &maze->floor->w, &maze->floor->h);
	maze->floor2->img = mlx_xpm_file_to_image(&maze->mlx, T_FLOOR2, &maze->floor2->w, &maze->floor2->h);

	maze->lava1->img = mlx_xpm_file_to_image(&maze->mlx, T_LAVA1, &maze->lava1->w, &maze->lava1->h);
	maze->lava2->img = mlx_xpm_file_to_image(&maze->mlx, T_LAVA2, &maze->lava2->w, &maze->lava2->h);
	maze->grass1->img = mlx_xpm_file_to_image(&maze->mlx, T_GRASS1, &maze->grass1->w, &maze->grass1->h);
//	maze->grass2->img = mlx_xpm_file_to_image(&maze->mlx, T_GRASS2, &maze->grass2->w, &maze->grass2->h);
	maze->ice->img = mlx_xpm_file_to_image(&maze->mlx, T_ICE, &maze->ice->w, &maze->ice->h);

	maze->block_l->img = mlx_xpm_file_to_image(&maze->mlx, T_BLOCK_L, &maze->block_l->w, &maze->block_l->h);
	maze->block_c->img = mlx_xpm_file_to_image(&maze->mlx, T_BLOCK_C, &maze->block_c->w, &maze->block_c->h);
	maze->block_r->img = mlx_xpm_file_to_image(&maze->mlx, T_BLOCK_R, &maze->block_r->w, &maze->block_r->h);
	maze->block_e->img = mlx_xpm_file_to_image(&maze->mlx, T_BLOCK_E, &maze->block_e->w, &maze->block_e->h);
	maze->block_f->img = mlx_xpm_file_to_image(&maze->mlx, T_BLOCK_F, &maze->block_f->w, &maze->block_f->h);

	maze->chain_top->img = mlx_xpm_file_to_image(&maze->mlx, T_CHAIN_T, &maze->chain_top->w, &maze->chain_top->h);
	maze->chain->img = mlx_xpm_file_to_image(&maze->mlx, T_CHAIN, &maze->chain->w, &maze->chain->h);

	maze->col_bottom->img = mlx_xpm_file_to_image(&maze->mlx, T_COL_B, &maze->col_bottom->w, &maze->col_bottom->h);
	maze->col_top->img = mlx_xpm_file_to_image(&maze->mlx, T_COL_T, &maze->col_top->w, &maze->col_top->h);
	maze->col_middle->img = mlx_xpm_file_to_image(&maze->mlx, T_COL_M, &maze->col_middle->w, &maze->col_middle->h);
	maze->col_half->img = mlx_xpm_file_to_image(&maze->mlx, T_COL_H, &maze->col_half->w, &maze->col_half->h);

	maze->teeth_r->img = mlx_xpm_file_to_image(&maze->mlx, T_TEETH_R, &maze->teeth_r->w, &maze->teeth_r->h);
	maze->teeth_l->img = mlx_xpm_file_to_image(&maze->mlx, T_TEETH_L, &maze->teeth_l->w, &maze->teeth_l->h);
	maze->teeth_t->img = mlx_xpm_file_to_image(&maze->mlx, T_TEETH_T, &maze->teeth_t->w, &maze->teeth_t->h);
	maze->teeth_b->img = mlx_xpm_file_to_image(&maze->mlx, T_TEETH_B, &maze->teeth_b->w, &maze->teeth_b->h);

	maze->exit->img = mlx_xpm_file_to_image(&maze->mlx, T_EXIT, &maze->exit->w, &maze->exit->h);
	maze->sprite->img = mlx_xpm_file_to_image(&maze->mlx, T_SPRITE, &maze->sprite->w, &maze->sprite->h);

	maze->player_d->img = mlx_xpm_file_to_image(&maze->mlx, T_PLAYER_D, &maze->player_d->w, &maze->player_d->h);
	maze->player_u->img = mlx_xpm_file_to_image(&maze->mlx, T_PLAYER_U, &maze->player_u->w, &maze->player_u->h);
	maze->player_l->img = mlx_xpm_file_to_image(&maze->mlx, T_PLAYER_L, &maze->player_l->w, &maze->player_l->h);
	maze->player_r->img = mlx_xpm_file_to_image(&maze->mlx, T_PLAYER_R, &maze->player_r->w, &maze->player_r->h);
}