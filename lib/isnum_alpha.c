/*
** isnum_alpha.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Feb  2 08:12:29 2017 Thomas BLENEAU
** Last update Wed Feb  8 20:16:08 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	isnum_alpha(char c)
{
  if (!((c >= 'A' && c <= 'H')
	|| (c >= 'a' && c <= 'h')))
    return (1);
  return (0);
}
