/*
** attack_client.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Feb  8 14:21:16 2017 Thomas BLENEAU
** Last update Wed Feb  8 15:23:33 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	attack_server_client(int pid, char **tab, char **tab_ennemy)
{
  int   x;
  int   y;
  char	*str;
  char  *string;

  str = attack_receive();
  string = my_strdup(str);
  str = swap_attack(str);
  str = attack_coordinates(str);
  x = my_atoi(str[1]);
  y = my_atoi(str[0]);
  attack_result(pid, string, tab, x, y);
  if (tab[x][y] >= '2' && tab[x][y] <= '5')
    tab[x][y] = 'x';
  else if (tab[x][y] == '.')
    tab[x][y] = 'o';
  free_str(str);
  return (0);
}
