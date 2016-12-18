/*
** fonc2.c for BSQ in /home/julian-ladjani/delivery/CPE/BSQ/CPE_2016_BSQ/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Apr Dec 14 19:25:46 2016 Julian Ladjani
** Last update Jan Dec 18 20:54:29 2016 Julian Ladjani
*/

#include "my.h"

int		line_char(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    i++;
  return (i);
}

int		square_size(char **map, int row, int col, int squaresize)
{
  int		colbase;
  int		rowbase;

  colbase = col;
  rowbase = row;
  while (row < (rowbase + squaresize) && map[row] != NULL)
    {
      while (col < (colbase + squaresize))
	{
	  if (map[row][col] != '.')
	    return (squaresize);
	  col++;
	}
      col = colbase;
      row++;
    }
  if (map[row] == NULL && row < (rowbase + squaresize))
    return (squaresize);
  return (square_size(map, rowbase, colbase, squaresize + 1));
}

t_square	square_search(char **map, int row, int col, t_square square)
{
  int		squaresize;

  squaresize = square.lenght;
  while (map[row + square.lenght - 1] != NULL)
    {
      while (map[row][col + squaresize] != '\0')
	{
	  if ((squaresize = square_size(map, row, col, square.lenght))
	      > square.lenght)
	    {
	      square.lenght = squaresize;
	      square.posx = col;
	      square.posy = row;
	    }
	  col++;
	}
      col = 0;
      row++;
    }
  if (map[row + square.lenght - 1] == NULL)
    square.lenght--;
  return (square);
}

char		**make_square(char **map)
{
  t_square	square;
  int		rowbase;
  int		colbase;

  square.posx = 0;
  square.posy = 0;
  square.lenght = 0;
  square = square_fonc_red(map, square);
  rowbase = square.posy;
  colbase = square.posx;
  while (square.posy < (rowbase + square.lenght) && map[square.posy] != NULL)
    {
      while (square.posx < (colbase + square.lenght))
	{
	  map[square.posy][square.posx] = 'x';
	  square.posx++;
	}
      square.posx = colbase;
      square.posy++;
    }
  return (map);
}

void		write_it(char **map)
{
  int		tab;
  int		col;

  tab = 0;
  col = -1;
  while (map[tab] != NULL)
    {
      while (map[tab][++col] != '\0');
      map[tab][col] = '\n';
      map[tab][++col] = '\0';
      write(1, map[tab], col);
      col = -1;
      tab++;
    }
}
