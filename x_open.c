/*
** x_open.c for  in /u/ept2/jouan_t/code/c/projetx
** 
** Made by thibault jouan
** Login   <jouan_t@epita.fr>
** 
** Started on  Tue May 13 22:22:10 2003 thibault jouan
** Last update Tue May 27 16:41:14 2003 thibault jouan
*/

#include "mn.h"

void		x_open(t_list *list)
{
  XGCValues	xgcv;

  printf(" >> Connexion au serveur X.\n");
  if ((DX->dpy = XOpenDisplay(0)) == NULL)
    {
      printf("%s.\n", "    - Impossible de se connecter au serveur X");
      exit(EXIT_FAILURE);
    }
  DX->im_id = Imlib_init(DX->dpy);
  DX->gc = DX->gcg = DefaultGC(DX->dpy, DefaultScreen(DX->dpy));
  DI->win_x = DI->map_x * UNIT;
  DI->win_y = DI->map_y * UNIT;
  DX->win = XCreateSimpleWindow(DX->dpy, DefaultRootWindow(DX->dpy),
				DI->pos_x, DI->pos_y, DI->win_x, DI->win_y, 1,
				BlackPixel(DX->dpy, DefaultScreen(DX->dpy)),
				WhitePixel(DX->dpy, DefaultScreen(DX->dpy)));
  XSelectInput(DX->dpy, DX->win, ExposureMask|KeyPressMask);
  xgcv.graphics_exposures = False;
  XChangeGC(DX->dpy, DX->gcg,
            GCGraphicsExposures, &xgcv);
  XAutoRepeatOff(DX->dpy);
  XMapWindow(DX->dpy, DX->win);
  XFlush(DX->dpy);
}
