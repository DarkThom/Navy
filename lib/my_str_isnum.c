/*
** my_str_isnum.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 22:00:49 2017 Thomas BLENEAU
** Last update Mon Jan 30 22:07:21 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	my_str_isnum(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
      return (1);
  return (0);
}
