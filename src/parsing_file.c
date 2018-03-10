/*
** parsing_file.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 14:33:25 2017 Thomas BLENEAU
** Last update Sun Feb  5 10:11:10 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

char	**my_first_condition(int ac, char **av, char **tab, int *fd)
{
  if (ac == 2)
    {
      *fd = open(av[1], O_RDONLY);
      if ((tab = malloc(sizeof(char *) * (my_tablen(av[1]) + 1))) == NULL)
	return (NULL);
    }
  else
    {
      *fd = open(av[2], O_RDONLY);
      if ((tab = malloc(sizeof(char *) * (my_tablen(av[2]) + 1))) == NULL)
	return (NULL);
    }
  return (tab);
}

char	**parsing_pos(int ac, char **av)
{
  int	i;
  int	fd;
  char	*str;
  char	**tab;

  i = 0;
  tab = NULL;
  if ((tab = my_first_condition(ac, av, tab, &fd)) == NULL)
    return (NULL);
  while ((str = get_next_line(fd)))
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      tab[i] = str;
      i = i + 1;
    }
  if (str != NULL)
    free(str);
  tab[i] = NULL;
  return (tab);
}

char	**parsing_map()
{
  int	i;
  int	j;
  char	**tab;

  i = -1;
  if ((tab = malloc(sizeof(char *) * (TAB_SIZE + 1))) == NULL)
    return (NULL);
  while (++i < TAB_SIZE)
    {
      j = -1;
      if ((tab[i] = malloc(sizeof(char) * (LINE_SIZE + 1))) == NULL)
	return (NULL);
      while (++j < LINE_SIZE)
	tab[i][j] = '.';
      tab[i][j] = '\0';
    }
  tab[i] = NULL;
  return (tab);
}
