#include <fcntl.h>
#include "filler.h"

void	get_player(t_fill *fill, char *line)
{
	int		i;

	i = ft_strchri(line, 'p');
	if (i == -1)
		error_f("can't find p character in first line", 0);
	fill->player = line[i + 1] + '0';
}

void	get_player_line(t_fill *fill)
{
	char	*line;

	ft_get_next_line(0, &line);
	if (line == NULL)
		error_f("malloc error in gnl", 0);
	get_player(fill, line);
	free(line);
}

void	get_map_size(t_fill *fill)
{
	char	*line;
	char	**dline;
	int		i;

	ft_get_next_line(0, &line);
	if (line == NULL)
		error_f("malloc error in gnl", 0);
	dline = ft_strsplit(line, ' ');
	if (dline == NULL)
		error_f("ft_strsplit malloc", 0);
	fill->height = ft_atoi(dline[1]);
	fill->width = ft_atoi(dline[2]);
}

int		main(void)
{
	char	*line;
	int		i;
	int		fd;
	t_fill	*fill;

	fill = error_f(NULL, 1);
	i = 0;
	fd = open("output_mine", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		ft_error_t("can't open file");
	get_player_line(fill);
	get_map_size(fill);
	while (ft_get_next_line(0, &line))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		i++;
	}
	line = ft_itoa(fill->player);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	line = ft_itoa(fill->height);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	line = ft_itoa(fill->width);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	close(fd);
	free_fill(fill);
	exit(0);
	return (0);
}