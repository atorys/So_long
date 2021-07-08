#include "../includes/so_long.h"

//unsigned int get_pixel(t_frame *reference, int x, int y)
//{
//	char *dst;
//
//	dst = reference->addr + (y * reference->length + x * (reference->bpp / 8));
//	return(*(unsigned int*)dst);
//}

//
//void *set_size(char *path)
//{
//	t_frame
//}

void	build_static_blocks(t_params	*maze, int w, int h)
{
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			(maze->table[y][x] == ID_FLOOR) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, x * SIZE, y * SIZE)
			: (maze->table[y][x] == ID_FLOOR2) ?mlx_put_image_to_window(maze->mlx, maze->win, maze->floor2->img, x * SIZE, y * SIZE)
			: mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, x * SIZE , y * SIZE);
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			if (maze->table[y][x] < 20) {
				(maze->table[y][x] == ID_WALL) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_WALL_CUBE) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall_cube->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_WALL_DEST) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall_dest->img, x * SIZE, y * SIZE) :

				(maze->table[y][x] == ID_BLOCK_C) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_c->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_BLOCK_R) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_r->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_BLOCK_L) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_l->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_BLOCK_E) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_e->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_BLOCK_F) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_f->img, x * SIZE, y * SIZE) :

				(maze->table[y][x] == ID_COL_B) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_bottom->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_COL_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_top->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_COL_M) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_middle->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_COL_H) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_half->img, x * SIZE, y * SIZE) :

				(maze->table[y][x] == ID_TEETH_B) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_b->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_TEETH_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_t->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_TEETH_R) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_r->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_TEETH_L) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_l->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_CHAIN_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain_top->img, x * SIZE, y * SIZE) :
				(maze->table[y][x] == ID_CHAIN) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain->img, x * SIZE, y * SIZE) : 0;
			}
		}
}

void 	build_dynamic_blocks(t_params	*maze, int w, int h)
{
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (maze->table[y][x])
			{
				(maze->table[y][x] == ID_EXIT && !maze->sprites_count) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->exit->img, x * SIZE, y * SIZE)
				: (maze->table[y][x] == ID_SPRITE) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->sprite->img, x * SIZE + 5, y * SIZE + 5)
				: (maze->table[y][x] == ID_GRASS1) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->grass1->img, x * SIZE, y * SIZE)
				: (maze->table[y][x] == ID_GRASS2) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->grass2->img, x * SIZE, y * SIZE)
				: (maze->table[y][x] == ID_ICE) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->ice->img, x * SIZE, y * SIZE)
				: (maze->table[y][x] == ID_LAVA1) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->lava1->img, x * SIZE, y * SIZE)
				: (maze->table[y][x] == ID_LAVA2) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->lava2->img, x * SIZE, y * SIZE) : 0;
			}
		}
	}
}

void	build_player(t_params	*maze, t_frame *player)
{
	mlx_put_image_to_window(maze->mlx, maze->win, player->img, maze->start_x * SIZE, maze->start_y * SIZE);
}
void	build_prev_block(t_params *maze)
{
	(maze->table[maze->start_y][maze->start_x] == ID_FLOOR) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, maze->start_x * SIZE, maze->start_y * SIZE)
	: (maze->table[maze->start_y][maze->start_x] == ID_FLOOR2) ?mlx_put_image_to_window(maze->mlx, maze->win, maze->floor2->img, maze->start_x * SIZE, maze->start_y * SIZE)
	: mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, maze->start_x * SIZE , maze->start_y * SIZE);

	(maze->table[maze->start_y][maze->start_x] == ID_CHAIN_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain_top->img, maze->start_x * SIZE, maze->start_y * SIZE)
	: (maze->table[maze->start_y][maze->start_x] == ID_CHAIN) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain->img, maze->start_x * SIZE, maze->start_y * SIZE) : 0;
}