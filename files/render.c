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
			(maze->table[y][x] == ID_FLOOR) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, x * 16, y * 16)
			: (maze->table[y][x] == ID_FLOOR2) ?mlx_put_image_to_window(maze->mlx, maze->win, maze->floor2->img, x * 16, y * 16)
			: mlx_put_image_to_window(maze->mlx, maze->win, maze->floor->img, x * 16, y * 16);
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			if (maze->table[y][x] < 20) {
				(maze->table[y][x] == ID_WALL) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_WALL_CUBE) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall_cube->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_WALL_DEST) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->wall_dest->img, x * 16, y * 16) :

				(maze->table[y][x] == ID_BLOCK_C) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_c->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_BLOCK_R) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_r->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_BLOCK_L) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_l->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_BLOCK_E) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_e->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_BLOCK_F) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->block_f->img, x * 16, y * 16) :

				(maze->table[y][x] == ID_COL_B) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_bottom->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_COL_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_top->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_COL_M) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_middle->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_COL_H) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->col_half->img, x * 16, y * 16) :

				(maze->table[y][x] == ID_TEETH_B) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_b->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_TEETH_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_t->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_TEETH_R) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_r->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_TEETH_L) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->teeth_l->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_CHAIN_T) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain_top->img, x * 16, y * 16) :
				(maze->table[y][x] == ID_CHAIN) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->chain->img, x * 16, y * 16) : 0;
			}
		}
}

void 	build_dynamic_blocks(t_params	*maze, int w, int h)
{
//	printf("\n %d %d \n", h , w);
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			printf("\n %d %d \n", y , x);
			if (maze->table[y][x])
			{
				(maze->table[y][x] == ID_PLAYER) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->player_r->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_EXIT) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->exit->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_SPRITE) ? mlx_put_image_to_window(maze->mlx, maze->win, maze->sprite->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_GRASS1) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->grass1->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_GRASS2) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->grass2->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_ICE) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->ice->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_LAVA1) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->lava1->img, x * 16, y * 16)
				: (maze->table[y][x] == ID_LAVA2) ?  mlx_put_image_to_window(maze->mlx, maze->win, maze->lava2->img, x * 16, y * 16) : 0;
			}
		}
	}
}