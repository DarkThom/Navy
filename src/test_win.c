/*
** test_win.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sun Feb  5 12:06:13 2017 Thomas BLENEAU
** Last update Sun Feb 19 11:37:04 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	test_win(char **tab, char **tab_enemy)
{
  int	i;
  int	j;

  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != '\0')
	if (tab[i][j] >= '2' && tab[i][j] <= '5')
	  return (0);
    }
  display_game(tab, tab_enemy);
  enemy_won();
  free_tab(tab, tab_enemy);
  return (1);
}

int	test_map(char **tab_enemy, char **tab)
{
  int	i;
  int	j;
  int	x;

  i = -1;
  x = 0;
  while (tab_enemy != NULL && tab_enemy[++i] != NULL)
    {
      j = -1;
      while (tab_enemy[i][++j] != '\0')
	{
	  if (tab_enemy[i][j] == 'x')
	    x = x + 1;
	}
    }
  if (x >= 14)
    {
      display_game(tab, tab_enemy);
      player_won();
      free_tab(tab, tab_enemy);
      return (0);
    }
  return (1);
}
