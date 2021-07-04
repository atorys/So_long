#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_png.h"

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		end;
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
}				t_params;

void 	error_case(char *message, int number);
void	get_map(char *map_name, t_params *maze);
void	build_blocks(t_frame *image, t_params	*maze);

#endif
