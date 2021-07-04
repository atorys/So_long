#include "../includes/so_long.h"

static void	put_pixel(t_frame *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
void build_blocks(t_frame *image, t_params	*maze)
{
//	for (int y = -1; y < maze->height; ++y)
//		for (int i = -1; y < maze->width; ++i)
//			process_dot(img, x, y, map);
//	int x;
//	int y;
//	mlx_png_file_to_image(maze->mlx, "../cherry.png", &x, &y);
//	mlx_put_image_to_window(maze->mlx, maze->win, image->img, 0, 0);
}