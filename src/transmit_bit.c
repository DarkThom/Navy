/*
** transmit_bit.c for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Feb  1 09:33:19 2017 Thomas BLENEAU
** Last update Tue Feb  7 17:37:55 2017 Thomas BLENEAU
*/

#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int		pid_handler(int	nbr)
{
  static int	pid = 0;

  if (nbr == 0)
    return (pid);
  else
    pid = nbr;
  return (pid);
}

void		handler_pid(UNUSED int signal, siginfo_t *info,
			    UNUSED void *data)
{
  pid_handler(info->si_pid);
  g_pid = info->si_pid;
}

void		handler(int signal, UNUSED siginfo_t *info,
			UNUSED void *data)
{
  g_pid = signal;
}

int		check_sigaction()
{
  struct sigaction	action;

  action.sa_sigaction = handler_pid;
  action.sa_flags = SA_SIGINFO;
  sigemptyset(&action.sa_mask);
  if (sigaction(SIGUSR1, &action, NULL) < 0)
    return (1);
  else if (sigaction(SIGUSR2, &action, NULL) < 0)
    return (1);
  return (0);
}

int		check_sigaction_receive()
{
  struct sigaction	action;

  action.sa_sigaction = handler;
  action.sa_flags = SA_RESTART;
  sigemptyset(&action.sa_mask);
  if (sigaction(SIGUSR1, &action, NULL) < 0)
    return (1);
  else if (sigaction(SIGUSR2, &action, NULL) < 0)
    return (1);
  return (0);
}
