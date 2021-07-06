#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"

static int convert_variables(char c, t_params *maze, int i, int j)
{
	if (c == '1')
		return (WALL_ID);
	if (c == '0')
		return (FLOOR_ID);
	if (c == '8')
		return (FLOOR2_ID);
	if (c == 'E') {
		maze->end_y = i;
		maze->end_x = j;
		return (EXIT_ID);
	}
	if (c == 'P') {
		maze->start_y = i;
		maze->start_x = j;
		return (PLAYER_ID);
	}
	if (c == 'C')
		return (SPRITE_ID);
	if (c == 'L' || c == 'l')
		return ((c == 'L') ? LAVA_ID : LAVAD_ID);
	if (c == ' ' || c == '.')
		return ((c == ' ') ? FLOOR3_ID : FLOOR4_ID);
	if (c == 'G')
		return (GRASS_ID);
	if (c == '2' || c == '3' || c == '4' || c == '5' || c == '6')
		return ((c == '2') ? L_W_BLOCK_ID : (c == '3') ? C_W_BLOCK_ID : (c == '4') ? R_W_BLOCK_ID : (c == '5') ? E_W_BLOCK_ID : F_W_BLOCK_ID);
	if (c == 'T' || c == '|')
		return ((c == 'T') ? CHAIN_UP_ID : CHAIN_ID);
	if (c == '^' || c == 'V' || c == '>' || c == '<')
		return ((c == '^') ? TOOTH_DOWN_ID : (c == 'V') ? TOOTH_UP_ID : (c == '>') ? TOOTH_LEFT_ID : TOOTH_RIGHT_ID);
	if (c == 'D' || c == 'U' || c == 'H')
		return ((c == 'D') ? COL_DOWN_ID : (c == 'U') ? COL_UP_ID : COL_HALF_ID);
	printf("{%d %d}\n", i, j);
//	error_case("INVALID EVERYTHING", -100500);
	return (-1);
}

static void get_char_set(char *map_name, t_params *maze)
{
	int fd = open(map_name, O_RDONLY);;
	char *line;
	int i = -1;

	if (fd < 0)
		error_case("Failed to open map", -1);
	while (++i < maze->height && get_next_line(fd, &line))
	{
		maze->table[i] = (int *)malloc(sizeof(int) * (maze->width + 1));
		if (!maze->table)
			error_case("Malloc is dead", -2);
		for (int j = 0; j < maze->width; j++)
			maze->table[i][j] = convert_variables(line[j], maze, i, j);
		free(line);
	}
	close(fd);
}

void	get_map(char *map_name, t_params *maze)
{
	int fd;
	char *line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_case("Failed to open map", -1);
	maze->width = 0;
	maze->height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		maze->height++;
		maze->width = (int)ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
	maze->table = (int **)malloc(sizeof(int *) * (maze->height + 1));
	if(!maze->table)
		error_case("Malloc is dead", -2);
	get_char_set(map_name, maze);
}