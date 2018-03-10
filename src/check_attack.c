/*
** check_attack.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sat Feb  4 10:52:50 2017 Thomas BLENEAU
** Last update Wed Feb  8 20:19:27 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	check_str(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (1);
  else if (str[0] == '\0')
    return (1);
  while (str && str[++i] != '\0')
    if (str[i] != '\0' && (isnum_alpha(str[i]))
	&& (str[i] < '1' || str[i] > '8'))
      return (1);
  return (0);
}

int	check_attack(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (1);
  else if (my_strlen(str) != 2 || str[0] == '\0')
    return (1);
  else if (check_str(str))
    return (1);
  while (str && str[++i + 1] != '\0')
    {
      if (str[i] != '\0' && (str[i] >= '1' && str[i] <= '8'))
	{
	  if (str[i] != '\0' && (isnum_alpha(str[i + 1])))
	    return (1);
	}
      else if ((str[i] != '\0') && ((str[i] >= 'A' && str[i] <= 'H')
				    || (str[i] >= 'a' && str[i] <= 'h')))
	{
	  if (str[i] != '\0' && (str[i + 1] < '1' || str[i + 1] > '8'))
	    return (1);
	}
    }
  return (0);
}

char	*swap_attack(char *str)
{
  int	i;

  i = -1;
  while (str && str[++i + 1] != '\0')
    if ((str[i] >= '1' && str[i] <= '8')
	&& (isnum_alpha(str[i + 1]) == 0))
      my_swap(&str[i], &str[i + 1]);
  return (str);
}

char	*attack_coordinates(char *str)
{
  int	i;

  i = -1;
  while (str && str[++i] != '\0')
    {
      if ((str[i] >= 'A' && str[i] <= 'H')
	  || (str[i] >= 'a' && str[i] <= 'h'))
	{
	  if (str[i] >= 'A' && str[i] <= 'H')
	    str[i] = (str[i] - 65) + 48;
	  else
	    str[i] = (str[i] - 97) + 48;
	}
      else if (str[i] >= '1' && str[i] <= '8')
	str[i] = (my_atoi(str[i]) - 1) + 48;
    }
  return (str);
}
