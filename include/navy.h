/*
** navy.h for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 30 12:58:44 2017 Thomas BLENEAU
** Last update Sun Feb 19 11:28:41 2017 Thomas BLENEAU
*/

#ifndef NAVY_H_
# define NAVY_H_

# ifndef TAB_SIZE
#  define TAB_SIZE (8)
# endif /* !TAB_SIZE */

# ifndef LINE_SIZE
#  define LINE_SIZE (8)
# endif /* !LINE_SIZE */

# ifndef PACKET_LEN
#  define PACKET_LEN (8)
# endif /* !PACKET_LEN */

# define UNUSED __attribute__((unused))

/*
** Include de la libC
*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <signal.h>
# include <ucontext.h>

/*
** Déclaration de globale
*/

extern int	g_pid;

/*
** Déclaration de la structure pour boat_position
*/

typedef struct	s_pos_boat
{
  int		i;
  int		j;
  int		x;
  int		y;
  int		xf;
  int		yf;
}		t_pos_boat;

/*
** Déclaration de la structure JEU
*/

typedef struct	s_game
{
  int		pid;
  int		res;
  char		**tab;
  char		**tab_enemy;
}		t_game;

/*
** Prototypes de fonctions attack
*/

char	*attack_coordinates(char *);
char	*attack_receive();
char	*swap_attack(char *);
char	result_receive();
int	attack_result(int, char *, char **, int, int);
int	attack_send(int, char *);
int	attack_server_client(int, char **, char **);
int	check_attack(char *);
int	display_attack(int, char **, char **);

/*
** Prototypes de fonctions envoie et réception de signaux
*/

char	convert_packet(char, int);
int	check_connection(int, char **);
int	check_sigaction();
int	check_sigaction_receive();
int	pid_handler(int);
int	receive_packet();
int	send_packet(int, char);

/*
** Prototypes de fonctions propre au jeu
*/

int	client_action(int, char **);
int	server_action(int, char **);
int	help_command();
int	test_win(char **, char **);
int	test_map(char **, char **);
char	**boat_position(char **, char **);
char	**create_tab_game(int, char **);
char	**find_coordinates(char **);
char	**parsing_pos(int, char **);
char	**parsing_map();
char	**swap_coordinates(char **);
char	**swap_position(char **);
void	display_game(char **, char **);
void	display_tab(char **);
void	display_pid();
void	enemy_position(char, char *, char **);
void	handler(int, siginfo_t *, void *);
void	player_won();
void	enemy_won();

#endif /* !NAVY_H_ */
