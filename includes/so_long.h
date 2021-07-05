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
# define FLOOR "textures/floor3.xpm"
# define GRASS "textures/grass.xpm"
# define LAVA "textures/floor_lava.xpm"

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

# define LAVA_ID 10
# define GRASS_ID 11

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
	struct s_frame	*grass;
	struct s_frame	*player;
	struct s_frame	*exit;
	struct s_frame	*sprite;

}				t_params;

void 	error_case(char *message, int number);
void	get_map(char *map_name, t_params *maze);
void	build_static_blocks(t_params	*maze, int w, int h);
void 	build_dynamic_blocks(t_params	*maze, int w, int h);
#endif
