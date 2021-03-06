#include "mn.h"

void		net_read_analyse(t_list *list, char *m, int sock)
{
  char		**tab;
  t_pl		*pl;

  pl = pl_get_id(list, sock);
  if (pl->nib && ((strncmp(m, "DIR ", strlen("DIR "))) == 0))
    {
      tab = explode(" ", m);
      if (tab[1])
	{
	  if ((strcmp(tab[1], "GAUCHE")) == 0)
	    pl->nib->dir = 'g';
	  if ((strcmp(tab[1], "DROITE")) == 0)
	    pl->nib->dir = 'd';
	  if ((strcmp(tab[1], "BAS")) == 0)
	    pl->nib->dir = 'b';
	  if ((strcmp(tab[1], "HAUT")) == 0)
	    pl->nib->dir = 'h';
	}
      tbl_free(tab);
      free(tab);
    }
}
