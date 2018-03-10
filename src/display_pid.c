/*
** display_pid.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Feb  3 17:36:15 2017 Thomas BLENEAU
** Last update Thu Feb  9 15:09:30 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

void	display_pid()
{
  write(1, "my_pid: ", 8);
  my_put_nbr(getpid());
  write(1, "\n", 1);
}
