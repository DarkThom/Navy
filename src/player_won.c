/*
** player_won.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sun Feb  5 15:45:12 2017 Thomas BLENEAU
** Last update Wed Feb  8 19:24:06 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

void	player_won()
{
  write(1, "I won\n", 6);
}

void	enemy_won()
{
  write(1, "Enemy won\n", 10);
}
