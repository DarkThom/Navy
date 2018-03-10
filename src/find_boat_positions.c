/*
** find_boat_positions.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Feb  1 21:43:33 2017 Thomas BLENEAU
** Last update Thu Feb  9 22:49:34 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

char		**swap_coordinates(char **pos)
{
  int		i;
  int		j;

  i = -1;
  while (pos[++i] != NULL)
    {
      j = 2;
      if (((pos[i][j] >= '0' && pos[i][j] <= '9')
	   && (isnum_alpha(pos[i][j + 1]) == 0))
	  || ((pos[i][j + 3] >= '0' && pos[i][j + 3] <= '9')
	  && (isnum_alpha(pos[i][j + 5]) == 0)))
	my_swap(&pos[i][j], &pos[i][j + 1]);
    }
  return (pos);
}

char		**swap_position(char **pos)
{
  int		i;
  int		j;

  i = -1;
  while (pos[++i] != NULL)
    {
      j = 2;
      if (pos[i][j] == pos[i][j + 3])
	{
	  if (my_atoi(pos[i][j + 1]) > my_atoi(pos[i][j + 4]))
	    my_swap(&pos[i][j + 1], &pos[i][j + 4]);
	}
      else if (pos[i][j + 1] == pos[i][j + 4])
	if (my_atoi(pos[i][j]) > my_atoi(pos[i][j + 3]))
	  my_swap(&pos[i][j], &pos[i][j + 3]);
    }
  return (pos);
}

char		**find_coordinates(char **pos)
{
  int		i;
  int		j;

  i = -1;
  pos = swap_coordinates(pos);
  while (pos[++i] != NULL)
    {
      j = 0;
      while (pos[i][++j] != '\0')
	{
	  if ((pos[i][j] >= 'A' && pos[i][j] <= 'H')
	      || (pos[i][j] >= 'a' && pos[i][j] <= 'h'))
	    {
	      if (pos[i][j] >= 'A' && pos[i][j] <= 'H')
		pos[i][j] = (pos[i][j] - 65) + 48;
	      else
		pos[i][j] = (pos[i][j] - 97) + 48;
	    }
	  else if (pos[i][j] >= '0' && pos[i][j] <= '9')
	    pos[i][j] = (my_getnbr(&pos[i][j]) - 1) + 48;
	}
    }
  pos = swap_position(pos);
  return (pos);
}

char		**put_boat_position(char **tab, char **pos, t_pos_boat *boat)
{
  if (boat->x == boat->xf)
    {
      while (boat->y <= boat->yf)
	{
	  if (tab[boat->y][boat->x] != '.' && tab[boat->y][boat->x] != '\0')
	    return (NULL);
	  tab[boat->y][boat->x] = (my_atoi(pos[boat->i][0]) + 48);
	  boat->y = boat->y + 1;
	}
    }
  else if (boat->y == boat->yf)
    {
      while (boat->x <= boat->xf)
	{
	  if (tab[boat->y][boat->x] != '.' && tab[boat->y][boat->x] != '\0')
	    return (NULL);
	  tab[boat->y][boat->x] = (my_atoi(pos[boat->i][0]) + 48);
	  boat->x = boat->x + 1;
	}
    }
  return (tab);
}

char		**boat_position(char **tab, char **pos)
{
  t_pos_boat	boat;

  boat.i = -1;
  while (pos[++boat.i] != NULL)
    {
      boat.j = 2;
      if (pos[boat.i][boat.j] >= '0' && pos[boat.i][boat.j] <= '9')
	{
	  boat.x = my_atoi(pos[boat.i][boat.j]);
	  boat.y = my_atoi(pos[boat.i][boat.j + 1]);
	  boat.xf = my_atoi(pos[boat.i][boat.j + 3]);
	  boat.yf = my_atoi(pos[boat.i][boat.j + 4]);
	  if ((tab = put_boat_position(tab, pos, &boat)) == NULL)
	    return (NULL);
	}
    }
  return (tab);
}
