#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_png.h"
# include "textures.h"

# define MALLOCERROR "\033[0;33mMalloc failed\033[0m\n"
# define SIZE 24

typedef struct s_frame
{
	void	*img;
	char	*addr;

	int		bpp;
	int		length;
	int		end;

	int 	h;
	int 	w;
}				t_frame;

typedef struct s_params
{
	void	*mlx;
	void	*win;

	int width;
	int	height;

	int **table;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int sprites_count;

	struct s_frame	*wall;
	struct s_frame	*wall_cube;
	struct s_frame	*wall_dest;

	struct s_frame	*block_r;
	struct s_frame	*block_l;
	struct s_frame	*block_c;
	struct s_frame	*block_e;
	struct s_frame	*block_f;

	struct s_frame	*floor;
	struct s_frame	*floor2;

	struct s_frame	*col_bottom;
	struct s_frame	*col_middle;
	struct s_frame	*col_top;
	struct s_frame	*col_half;

	struct s_frame	*chain_top;
	struct s_frame	*chain;

	struct s_frame	*lava1;
	struct s_frame	*lava2;
	struct s_frame	*grass1;
	struct s_frame	*grass2;
	struct s_frame	*ice;

	struct s_frame	*teeth_r;
	struct s_frame	*teeth_l;
	struct s_frame	*teeth_t;
	struct s_frame	*teeth_b;

	struct s_frame	*player_r;
	struct s_frame	*player_l;
	struct s_frame	*player_u;
	struct s_frame	*player_d;

	struct s_frame	*exit;
	struct s_frame	*sprite;

}				t_params;

void 	error_case(char *message, int number);
void	get_map(char *map_name, t_params *maze);

void	run(t_params *maze);
t_frame	*get_frame_and_set_size_and_pereimenyi(void *mlx, const char *file, int set_w, int set_h);

void	build_static_blocks(t_params	*maze, int w, int h);
void 	build_dynamic_blocks(t_params	*maze, int w, int h);
void	build_player(t_params	*maze, t_frame *player);
void	build_prev_block(t_params *maze);
#endif






