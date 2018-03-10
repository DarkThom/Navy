/*
** convert_packet.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Feb  7 15:33:48 2017 Thomas BLENEAU
** Last update Thu Feb  9 11:41:44 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

char	convert_packet(char packet, int boolean)
{
  if (boolean == 0)
    {
      if (packet >= 'A' && packet <= 'H')
	packet = packet - 65;
      else if (packet >= 'a' && packet <= 'h')
	packet = packet - 97;
      else if (packet >= '1' && packet <= '9')
	packet = packet - 49;
    }
  else if (boolean == 1)
    packet = packet + 65;
  else if (boolean == 2)
    packet = packet + 49;
  return (packet);
}
