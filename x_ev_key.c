#include "mn.h"

void		x_ev_key(t_list *list, XEvent xev)
{
  char		buf[256];
  KeySym	k;
  int		len;

  /* printf(" >> Evénement 'Clavier'\n"); */
  len = XLookupString((XKeyEvent *)&xev, buf, sizeof(buf), &k, NULL);
  buf[len] = 0;
  if (k == XK_Escape || k == XK_q)
    x_quit(list);
  else if (k == XK_Left)
    cl_send(list, "DIR GAUCHE");
  else if (k == XK_Right)
    cl_send(list, "DIR DROITE");
  else if (k == XK_Down)
    cl_send(list, "DIR BAS");
  else if (k == XK_Up)
    cl_send(list,"DIR HAUT");
}
