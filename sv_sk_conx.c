/*
** sv_sk_conx.c for  in 
** 
** Made by StarK
** Login   <stark@abris13.org>
** 
** Started on  Tue May 20 18:48:30 2003 StarK
** Last update Mon May 26 00:16:17 2003 thibault jouan
*/

#include "mn.h"

void			sv_sk_conx(t_list *list, int i)
{
  int			sock;
  socklen_t		sock_len;
  struct sockaddr_in	address;

  sock_len = sizeof(struct sockaddr_in);
  if ((sock = accept(i, (struct sockaddr *)&address, &sock_len)) == -1)
    {
      printf("SV> Erreur lors de l'acceptation d'un client.\n");
      perror("accept");
      exit(EXIT_FAILURE); 
    }
  printf("SV> Connexion d'un client depuis : '%s:%u'.\n",
	 inet_ntoa(address.sin_addr), ntohs(address.sin_port));
  if (DI->start)
    sv_sk_refuse(list, sock, i);
  else
    {
      sv_send(sock, "WELCOME");
      DS->sk_tab[sock] = 2;
    }
}
