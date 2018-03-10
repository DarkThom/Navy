/*
** result_attack.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sun Feb  5 10:45:43 2017 Thomas BLENEAU
** Last update Thu Feb  9 09:16:58 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	attack_result(int pid, char *string,
		      char **tab, int x, int y)
{
  if (tab[x][y] >= '2' && tab[x][y] <= '5')
    {
      write(1, string, my_strlen(string));
      write(1, ": hit\n\n", 7);
      send_packet(pid, '1');
    }
  else if (tab[x][y] == 'o' ||  tab[x][y] == '.'
	   || tab[x][y] == 'x')
    {
      write(1, string, my_strlen(string));
      write(1, ": missed\n\n", 10);
      send_packet(pid, '0');
    }
  free_str(string);
  return (0);
}
