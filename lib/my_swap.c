/*
** my_swap.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Feb  2 07:58:48 2017 Thomas BLENEAU
** Last update Thu Feb  2 08:02:19 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

void	my_swap(char *a, char *b)
{
  char	c;

  c = *a;
  *a = *b;
  *b = c;
}
