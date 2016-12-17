/*
** main.c for BSQ in /home/julian-ladjani/delivery/CPE/BSQ/CPE_2016_BSQ/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Dec 14 15:11:18 2016 julian ladjani
** Last update Jul Dec 17 16:10:49 2016 Julian Ladjani
*/

#include "my.h"

int		main(int ac, char **av)
{
  char		*buffer;
  struct stat	fstat;
  int		fd;
  int		len;
  char		**map;

  if (ac < 2)
    return (84);
  if ((stat(av[1], &fstat)) < 0)
    return (84);
  if ((fd = open(av[1], O_RDONLY)) < 0)
     return (84);
  if ((buffer = malloc(fstat.st_size + 1)) == NULL)
    return (84);
  if (len = read(fd, buffer, fstat.st_size) != fstat.st_size)
    return (84);
  buffer[fstat.st_size] = '\0';
  if ((map = make_my_map(buffer)) == NULL)
    return (84);
  map = make_square(map);
  write_it(map);
  return (0);
}
