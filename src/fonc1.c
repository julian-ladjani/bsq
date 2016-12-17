/*
** fonc1.c for BSQ in /home/julian-ladjani/delivery/CPE/BSQ/CPE_2016_BSQ/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Apr Dec 14 17:01:18 2016 Julian Ladjani
** Last update Jul Dec 17 16:11:42 2016 Julian Ladjani
*/

#include "my.h"

int		check_firstline(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      if (buffer[i] < '0' || buffer[i] > '9')
	return (0);
      i++;
    }
  if (buffer[i] == '\0')
    return (0);
  else if (buffer[i] == '\n')
    return (i);
  return (0);
}

int		my_get_firstline(char *buffer)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      if (buffer[i] >= '0' || buffer[i] <= '9')
	nb = (nb * 10) + (buffer[i] - 48);
      else
	return (0);
      i++;
    }
  return (nb);
}

int		nb_line(char *buffer)
{
  int		nbline;
  int		i;

  if ((i = check_firstline(buffer)) < 1)
    return (0);
  nbline = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n' && buffer[i + 1] != '\0')
	nbline++;
      else if (buffer[i] != 'o' && buffer[i] != '.' && buffer[i + 1] != '\0')
	return (0);
      i++;
    }
  if (nbline == my_get_firstline(buffer))
    return (nbline);
  else
    return (0);
}

int		nb_col(char *buffer)
{
  int		nb1;
  int		i;
  int		nb;

  nb1 = line_char(buffer + line_char(buffer) + 1);
  i = line_char(buffer) + 1;
  while (buffer[i] != '\0')
    {
      nb = line_char(buffer + i);
      if (nb != nb1)
	return (0);
      i += (nb + 1);
    }
  return (nb_col);
}

char		**make_my_map(char *buffer)
{
  int		line;
  int		col;
  char		**map;
  int		tab;
  int		c;

  if (((line = nb_line(buffer)) == 0) || ((col = nb_col(buffer)) == 0))
    return (NULL);
  if ((map = malloc((line + 2) * sizeof(char *))) == NULL)
    return (NULL);
  tab = -1;
  c = -1;
  while (*buffer != '\0')
    {
      if ((map[++tab] = malloc((col + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (*buffer != '\n' && *buffer != '\0')
	map[tab][++c] = *(buffer++);
      c = -1;
      buffer++;
    }
  map[++tab] = NULL;
  return (++map);
}
