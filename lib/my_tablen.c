/*
** my_tablen.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 20:08:43 2017 Thomas BLENEAU
** Last update Mon Jan 30 20:09:22 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	my_tablen(const char *str)
{
  int	i;
  int	fd;
  char	*buffer;

  i = 0;
  fd = open(str, O_RDONLY);
  while ((buffer = get_next_line(fd)))
    {
      if (buffer != NULL)
	free(buffer);
      i = i + 1;
    }
  return (i);
}
