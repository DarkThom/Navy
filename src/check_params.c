/*
** check_params.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 14:06:48 2017 Thomas BLENEAU
** Last update Thu Feb  9 11:34:07 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	check_boat(char **pos)
{
  int	i;

  i = -1;
  pos = find_coordinates(pos);
  while (pos[++i] != NULL)
    {
      if (pos[i][2] == pos[i][5])
	{
	  if (my_getnbr(pos[i]) != (my_atoi(pos[i][6]) - my_atoi(pos[i][3]) + 1))
	    {
	      free_tab_function(pos);
	      return (1);
	    }
	}
      else if (pos[i][3] == pos[i][6])
	{
	  if (my_getnbr(pos[i]) != (my_atoi(pos[i][5]) - my_atoi(pos[i][2]) + 1))
	    {
	      free_tab_function(pos);
	      return (1);
	    }
	}
    }
  free_tab_function(pos);
  return (0);
}

int	check_line(int ac, char **av)
{
  int	i;
  char	**tab;

  i = -1;
  tab = swap_coordinates(parsing_pos(ac, av));
  while (tab[++i] != NULL)
    {
      if (tab[i][2] != tab[i][5] && tab[i][3] != tab[i][6])
	{
	  free_tab_function(tab);
	  return (1);
	}
    }
  if (check_boat(tab))
    return (1);
  else if ((tab = create_tab_game(ac, av)) == NULL)
    {
      free_tab_function(tab);
      return (1);
    }
  return (0);
}

int	check_coordinates(int ac, char **av)
{
  int	i;
  char	**tab;

  i = -1;
  tab = parsing_pos(ac, av);
  while (tab[++i] != NULL)
    if (tab[i][2] == tab[i][5] && tab[i][3] == tab[i][6])
      {
	free_tab_function(tab);
	return (1);
      }
  if (check_same_boat(tab))
    return (1);
  return (0);
}

int	check_file(int ac, char **av)
{
  int	i;
  int	j;
  char	**tab;

  i = -1;
  tab = parsing_pos(ac, av);
  while (tab[++i] != NULL)
    {
      j = 0;
      while (tab[i][++j] != '\0')
	{
	  if ((tab[i][j] < 'A' || tab[i][j] > 'H')
	      && (tab[i][j] < 'a' || tab[i][j] > 'h')
	      && (tab[i][j] < '1' || tab[i][j] > '8')
	      && (tab[i][j] != ':'))
	    {
	      free_tab_function(tab);
	      return (1);
	    }
	}
    }
  free_tab_function(tab);
  return (0);
}

int	check_params(int ac, char **av)
{
  int	i;
  int	fd;
  char	**tab;

  i = -1;
  if (ac == 2 && (fd = open(av[1], O_RDONLY)) == -1
      && my_strcmp(av[1], "-h") != 0)
    return (1);
  else if (ac == 3 && (fd = open(av[2], O_RDONLY)) == -1
	   && my_str_isnum(av[1]) != 0)
    return (1);
  if (check_coordinates(ac, av) || check_file(ac, av))
    return (1);
  else if (check_line(ac, av))
    return (1);
  tab = parsing_pos(ac, av);
  while (tab[++i] != NULL)
    if (my_strlen(tab[i]) != 7)
      {
	free_tab_function(tab);
	return (1);
      }
  free_tab_function(tab);
  return (0);
}
