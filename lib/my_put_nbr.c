/*
** my_put_nbr.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 20:20:27 2017 Thomas BLENEAU
** Last update Mon Jan 30 20:32:02 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	check_sign(int nb)
{
  if (nb < 0)
    {
      write(1, "-", 1);
      nb = nb * -1;
      return (nb);
    }
  return (nb);
}

int	find_div(int nb)
{
  int	div;

  div = 1;
  while (nb > 9)
    {
      nb = nb / div;
      div = div * 10;
    }
  return (div);
}

void	my_put_nbr(int nb)
{
  int	div;
  char	c;

  nb = check_sign(nb);
  div = find_div(nb);
  while (div != 0)
    {
      c = ((nb / div) + 48);
      write(1, &c, 1);
      nb = nb % div;
      div = div / 10;
    }
}
