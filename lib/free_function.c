/*
** free_function.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 18:46:13 2017 Thomas BLENEAU
** Last update Wed Feb  8 16:53:28 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	free_tab_function(char **tab)
{
  int	i;

  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    free(tab[i]);
  if (tab != NULL)
    free(tab);
  return (0);
}

int	free_str(char *str)
{
  if (str != NULL)
    free(str);
  return (0);
}

void	free_tab(char **tab, char **tab_enemy)
{
  free_tab_function(tab);
  free_tab_function(tab_enemy);
}
