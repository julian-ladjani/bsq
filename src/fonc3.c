/*
** fonc3.c for bsq in /home/julian-ladjani/delivery/CPE/BSQ/CPE_2016_BSQ/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Dec 18 20:40:27 2016 Julian Ladjani
** Last update Jan Dec 18 20:53:15 2016 Julian Ladjani
*/

#include "my.h"

t_square	square_fonc_red(char **map, t_square square)
{
  if (map[0][1] == '\0')
    square = search_onecol(map, square);
  else if (map[1] == NULL)
    square = search_oneline(map, square);
  else
    square = square_search(map, 0, 0, square);
  return (square);
}

t_square	search_oneline(char **map, t_square square)
{
  char		*line;
  int		i;

  line = map[0];
  while (line[i] != '\0')
    {
      if (line[i] == '.')
	{
	  square.posy = 0;
	  square.posx = i;
	  square.lenght = 1;
	  return (square);
	}
      i++;
    }
  return (square);
}

t_square	search_onecol(char **map, t_square square)
{
  int		i;

  while (map[i] != NULL)
    {
      if (map[i][0] == '.')
	{
	  square.posy = i;
	  square.posx = 0;
	  square.lenght = 1;
	  return (square);
	}
      i++;
    }
  return (square);
}
