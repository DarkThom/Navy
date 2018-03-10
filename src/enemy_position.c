/*
** enemy_position.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Feb  8 15:57:43 2017 Thomas BLENEAU
** Last update Fri Feb 10 08:36:18 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

void	enemy_position(char packet, char *str, char **tab)
{
  int	x;
  int	y;

  str = attack_coordinates(str);
  x = my_atoi(str[1]);
  y = my_atoi(str[0]);
  if (packet == '1')
    tab[x][y] = 'x';
  else if (tab[x][y] != 'x')
    tab[x][y] = 'o';
}
