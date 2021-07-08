/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame_and_set_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:49:09 by lignigno          #+#    #+#             */
/*   Updated: 2021/07/07 03:34:43 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ________________________________________________INCLUDES, DEFINES AND STRUCTS

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "includes/so_long.h"

#define g "\e[1;38;2;29;153;12m"
#define r "\e[1;38;2;153;12;12m"
#define raspberry "\e[1;38;2;153;12;83m"

//typedef struct s_frame
//{
//	void	*img;
//	char	*addr;
//	int		bpp;
//	int		length;
//	int		end;
//	int		h;
//	int		w;
//}				t_frame;

// ____________________________________________________________________FUNCTIONS

// _________________________________________________________________SUBFUNCTIONS

static void	get_addr(t_frame *data_img)
{
	data_img->addr = mlx_get_data_addr(data_img->img,
									  &data_img->bpp,
									  &data_img->length,
									  &data_img->end);
	if (!data_img->addr)
	{
		free(data_img->img);
		free(data_img);
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	rewrite_image(t_frame *new_img, t_frame *old_img)
{
	int		color;
	char	*pixel;
	double	step_y;
	double	step_x;

	step_y = (double)old_img->h / new_img->h;
	step_x = (double)old_img->w / new_img->w;
//	printf("{%f, %f}\n", step_x, step_y);
	for (size_t y = 0; y < new_img->h; y++)
		for (size_t x = 0; x < new_img->w; x++)
		{
			// get_color_from_pixel
			pixel = old_img->addr;
			pixel += (size_t)(y * step_y) * old_img->length;
			pixel += (size_t)(x * step_x) * (old_img->bpp / 8);
			color = *((int *)pixel);
			// put_color_to_pixel
			pixel = new_img->addr;
			pixel += (size_t)(y * new_img->length);
			pixel += (size_t)(x * (new_img->bpp / 8));
			*(int *)pixel = color;
		}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static t_frame	*original_image(t_frame *data_img)
{
	get_addr(data_img);
	if (!data_img->addr)
		return (NULL);
	return (data_img);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static t_frame	*resize_image(void *mlx, t_frame *data, int set_w, int set_h)
{
	t_frame	*result;

	result = malloc(sizeof(t_frame));
	if (!result)
		return (NULL);
	result->img = mlx_new_image(mlx, set_w, set_h);
	if (!result->img)
	{
		free(result);
		return (NULL);
	}
	get_addr(data);
	get_addr(result);
	result->w = set_w;
	result->h = set_h;
	if (!result->addr)
		return (NULL);
	rewrite_image(result, data);
	return (result);
}

// ____________________________________________________________________MAIN FUNC

t_frame	*get_frame_and_set_size_and_pereimenyi(void *mlx, const char *file, int set_w, int set_h)
{
	t_frame	*data_img;

	data_img = malloc(sizeof(t_frame));
	if (!data_img)
		return (NULL);
	data_img->img = mlx_xpm_file_to_image(mlx,
								  (char *)file,
										 &data_img->w,
										 &data_img->h);
	if (!data_img->img)
	{
		free(data_img);
		return (NULL);
	}
	if (data_img->w == set_w && data_img->h == set_h)
		return (original_image(data_img));
	return (resize_image(mlx, data_img, set_w, set_h));
}

// ________________________________________________________________MAIN FOR TEST

//int main()
//{
//	void	*mlx;
//	void	*win;
//	t_frame	*zdes_vsyo_about_kartinka;
//
//	printf ("%sthere will be a test here\e[m\n", raspberry);
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 1600, 900, "Unicorn");
//	zdes_vsyo_about_kartinka = get_frame_and_set_size_and_pereimenyi(mlx, "for_mary/cherry.xpm", 8, 8);
//	if (!zdes_vsyo_about_kartinka)
//		return (printf ("%soshibochka\e[m\n", r));
//	mlx_put_image_to_window(mlx, win, zdes_vsyo_about_kartinka->img, 0, 0);
//	mlx_loop(mlx);
//	return (0);
//}
