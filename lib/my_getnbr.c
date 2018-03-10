/*
** my_getnbr.c for  in /home/BLENEA_T/Piscine/CPool_workshoplib
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Oct 21 19:07:11 2016 Thomas BLENEAU
** Last update Fri Feb  3 08:55:12 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	sign;

  i = 0;
  nb = 0;
  sign = 0;
  if (str == NULL)
    return (0);
  while (str[i] == '-')
    {
      sign = sign + 1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      if (nb * 10 + str[i] - 48 < 0 || nb * 10 + str[i] - 48 >= 2147483647)
	return (0);
      nb = nb * 10 + str[i] - 48;
      i = i + 1;
    }
  if (sign % 2 == 1)
    return (nb * -1);
  return (nb);
}

int	my_atoi(char c)
{
  int   nb;

  nb = 0;
  if (c >= '0' && c <= '9')
    {
      if (nb * 10 + c - 48 < 0 || nb * 10 + c - 48 >= 2147483647)
	return (0);
      nb = nb * 10 + c - 48;
    }
  return (nb);
}
