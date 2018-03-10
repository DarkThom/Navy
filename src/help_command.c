/*
** help_command.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 13:36:17 2017 Thomas BLENEAU
** Last update Tue Feb  7 13:10:26 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	help_command()
{
  write(1, "USAGE\n", 6);
  write(1, "           ./navy [first_player_pid] navy_positions\n", 52);
  write(1, "DESCRIPTION\n", 12);
  write(1, "           first_player_pid", 27);
  write(1, "  ", 2);
  write(1, "only for the 2nd player.  ", 26);
  write(1, "pid of the first player,\n", 25);
  write(1, "           navy_positions    ", 29);
  write(1, "file representing the positions of the ships.\n", 46);
  return (0);
}
