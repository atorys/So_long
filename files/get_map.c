#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"

static int convert_variables(char c, t_params *maze, int i, int j)
{
	if (c == '1')
		return (WALL_ID);
	if (c == '0')
		return (FLOOR_ID);
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
	if (c == 'L')
		return (LAVA_ID);
	if (c == 'G')
		return (GRASS_ID);
	error_case("INVALID EVERYTHING", -100500);
	return (15);
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