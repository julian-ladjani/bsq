/*
** my.h for bsq in /home/julian-ladjani/delivery/CPE/BSQ/CPE_2016_BSQ/include
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jul Dec 17 16:09:21 2016 Julian Ladjani
** Last update Jan Dec 18 20:52:47 2016 Julian Ladjani
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_square
{
	int	posx;
  	int	posy;
	int	lenght;
  	int	mapy;
}		t_square;

int		line_char(char *buffer);
t_square	square_search(char **map, int row,
			      int col, t_square square);
t_square	square_fonc_red(char **map, t_square square);
t_square	search_oneline(char **map, t_square square);
t_square	search_onecol(char **map, t_square square);
t_square	prepare_struct(t_square square);
void		write_it(char **map);
int		check_firstline(char *buffer);
int		my_get_firstline(char *buffer);
int		nb_line(char *buffer);
int		nb_col(char *buffer);
char		**make_my_map(char *buffer);

#endif /* !MY_H_ */
