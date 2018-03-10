/*
** create_tab_game.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sun Feb  5 09:54:52 2017 Thomas BLENEAU
** Last update Mon Feb  6 13:39:35 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

char	**create_tab_game(int ac, char **av)
{
  char	**tab;
  char	**pos;

  tab = parsing_map();
  pos = parsing_pos(ac, av);
  pos = find_coordinates(pos);
  if ((tab = boat_position(tab, pos)) == NULL)
    {
      free_tab_function(pos);
      free_tab_function(tab);
      return (NULL);
    }
  free_tab_function(pos);
  return (tab);
}
