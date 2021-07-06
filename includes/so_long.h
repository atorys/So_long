#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_png.h"

# define SPRITE "textures/cherry.xpm"
# define EXIT "textures/key.xpm"

# define WALL "textures/wall.xpm"
# define BLOCK_L "textures/wooden_block.xpm"
# define BLOCK_R "textures/wooden_block1.xpm"
# define BLOCK_C "textures/wooden_block2.xpm"
# define BLOCK_E "textures/wooden_block3.xpm"
# define BLOCK_F "textures/wooden_block4.xpm"



# define FLOOR "textures/floor3.xpm"
# define FLOOR2 "textures/floor4.xpm"
# define FLOOR3 "textures/floor.xpm"
# define FLOOR4 "textures/floor2.xpm"
# define GRASS "textures/grass.xpm"
# define LAVA "textures/floor_lava.xpm"
# define LAVA_D "textures/lavad.xpm"


# define COL_U "textures/column_up.xpm"
# define COL_D "textures/column_down.xpm"
# define COL_H "textures/column_half.xpm"

# define CHAIN_UP "textures/chain_up.xpm"
# define CHAIN "textures/chain.xpm"
# define TOOTH_R "textures/tooth_right.xpm"
# define TOOTH_L "textures/tooth_left.xpm"
# define TOOTH_U "textures/tooth_up.xpm"
# define TOOTH_D "textures/tooth_down.xpm"

# define PLAYER_UP "textures/character_up.xpm"
# define PLAYER_DOWN "textures/character_down.xpm"
# define PLAYER_LEFT "textures/character_left.xpm"
# define PLAYER_RIGHT "textures/character_right.xpm"


# define WALL_ID 1
# define L_W_BLOCK_ID 2
# define C_W_BLOCK_ID 3
# define R_W_BLOCK_ID 4
# define E_W_BLOCK_ID 5
# define F_W_BLOCK_ID 6

# define FLOOR_ID 7
# define FLOOR2_ID 8
# define FLOOR3_ID 22
# define FLOOR4_ID 23

# define LAVA_ID 10
# define LAVAD_ID 21

# define GRASS_ID 11
# define CHAIN_UP_ID 12
# define CHAIN_ID 13
# define TOOTH_UP_ID 14
# define TOOTH_DOWN_ID 15
# define TOOTH_RIGHT_ID 16
# define TOOTH_LEFT_ID 17
# define COL_UP_ID 18
# define COL_DOWN_ID 19
# define COL_HALF_ID 20


# define PLAYER_ID 0
# define EXIT_ID 420

# define SPRITE_ID 9


# define MALLOCERROR "\033[0;33mMalloc failed\033[0m\n"





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

	struct s_frame	*wall;
	struct s_frame	*floor;
	struct s_frame	*floor2;
	struct s_frame	*floor3;
	struct s_frame	*floor4;
	struct s_frame	*floor_lava;
	struct s_frame	*grass;
	struct s_frame	*lavad;

	struct s_frame	*col_down;
	struct s_frame	*col_up;
	struct s_frame	*col_half;

	struct s_frame	*block_r;
	struct s_frame	*block_l;
	struct s_frame	*block_c;
	struct s_frame	*block_e;
	struct s_frame	*block_f;

	struct s_frame	*chain_u;
	struct s_frame	*chain;

	struct s_frame	*tooth_r;
	struct s_frame	*tooth_l;
	struct s_frame	*tooth_u;
	struct s_frame	*tooth_d;

	struct s_frame	*player;

	struct s_frame	*exit;
	struct s_frame	*sprite;

}				t_params;

void 	error_case(char *message, int number);
void	get_map(char *map_name, t_params *maze);
void	build_static_blocks(t_params	*maze, int w, int h);
void 	build_dynamic_blocks(t_params	*maze, int w, int h);
#endif
