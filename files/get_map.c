#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"

static int convert_variables(char c, t_params *maze, int i, int j)
{
	if (c == '1' || c == '@' || c == '#')
		return ((c == '1') ? ID_WALL : (c == '@') ? ID_WALL_CUBE : ID_WALL_DEST);
	if (c == '0' || c == '8')
		return ((c == '0') ? ID_FLOOR : ID_FLOOR2);

	if (c == '2' || c == '3' || c == '4' || c == '5' || c == '6')
		return ((c == '2') ? ID_BLOCK_L : (c == '3') ? ID_BLOCK_C : (c == '4') ?ID_BLOCK_R : (c == '5') ? ID_BLOCK_E : ID_BLOCK_F);

	if (c == 'D' || c == 'U' || c == 'H' || c == 'M')
		return ((c == 'D') ? ID_COL_B : (c == 'U') ? ID_COL_T : (c == 'H') ? ID_COL_H : ID_COL_M);

	if (c == '^' || c == 'V' || c == '>' || c == '<')
		return ((c == '^') ? ID_TEETH_B : (c == 'V') ? ID_TEETH_T : (c == '>') ? ID_TEETH_L : ID_TEETH_R);

	if (c == 'T' || c == '|')
		return ((c == 'T') ? ID_CHAIN_T : ID_CHAIN);

	if (c == 'G')
		return (ID_GRASS1);
	if (c == 'L')
		return (ID_LAVA1);
	if (c == '*')
		return (ID_ICE);

	if (c == 'E') {
		maze->end_y = i;
		maze->end_x = j;
		return (ID_FLOOR);
	}
	if (c == 'P') {
		maze->start_y = i;
		maze->start_x = j;
		return (ID_FLOOR);
	}
	if (c == 'C')
	{
		maze->sprites_count++;
		return (ID_SPRITE);
	}
	error_case("INVALID EVERYTHING", -100500);
	return (-1);
}

static void get_char_set(char *map_name, t_params *maze)
{
	int fd = open(map_name, O_RDONLY);;
	char *line;
	int i = -1;

	if (fd < 0)
		error_case("Failed to open map", -1);
	maze->sprites_count = 0;
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