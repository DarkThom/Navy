/*
** display_game.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 20:16:53 2017 Thomas BLENEAU
** Last update Fri Feb 10 08:32:22 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

void	display_tab(char **tab)
{
  int	i;
  int	j;
  int	l;

  i = -1;
  j = 1;
  write(1, "\n |A B C D E F G H\n", 19);
  write(1, "-+---------------\n", 18);
  while (tab[++i] != NULL)
    {
      l = -1;
      my_put_nbr(j++);
      write(1, "|", 1);
      while (tab[i][++l] != '\0')
	{
	  write(1, &tab[i][l], 1);
	  if (l < 7)
	    write(1, " ", 1);
	}
      write(1, "\n", 1);
    }
  write(1, "\n", 1);
}

void	display_game(char **tab, char **tab_enemy)
{
  write(1, "my positions:", 14);
  display_tab(tab);
  write(1, "enemy's positions:", 18);
  display_tab(tab_enemy);
}

int	display_attack(int pid, char **tab, char **tab_enemy)
{
  char	*str;
  char	packet;
  char	*string;

  write(1, "attack: ", 8);
  while (check_attack(str = get_next_line(0)))
    {
      if (str == NULL)
	{
	  free_tab(tab, tab_enemy);
	  return (1);
	}
      write(1, "wrong position\n", 15);
      free(str);
      write(1, "attack: ", 8);
    }
  string = my_strdup(str);
  str = swap_attack(str);
  attack_send(pid, str);
  write(1, string, my_strlen(string));
  packet = result_receive();
  enemy_position(packet, str, tab_enemy);
  free(str);
  free(string);
  return (0);
}
