/*
** check_same_boat.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Feb  9 11:29:57 2017 Thomas BLENEAU
** Last update Thu Feb  9 11:34:03 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	check_same_boat(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    if (tab[i][0] < '2' || tab[i][0] > '5')
      {
	free_tab_function(tab);
	return (1);
      }
  if (i != 4)
    {
      free_tab_function(tab);
      return (1);
    }
  i = -1;
  while (tab[++i + 1] != NULL)
    {
      if (tab[i][0] == tab[i + 1][0])
	{
	  free_tab_function(tab);
	  return (1);
	}
    }
  return (0);
}
