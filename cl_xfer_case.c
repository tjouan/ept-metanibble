#include "mn.h"

void		cl_xfer_case(t_list *list, char *m)
{
  if (DI->auth_ok == 0)
    {
      cl_auth(list, m);
      DI->auth_ok = 1;
    }
  else if (DI->map_ok == 1)
    {
      if ((strncmp(m, "MAPSTART", strlen("MAPSTART"))) == 0)
	{
	  cl_xfer_map(list, m);
	  DI->map_ok = 2;
	}
    }
  else if (DI->map_ok == 2)
    {
      if ((strncmp(m, "MAPEL", strlen("MAPEL"))) == 0)
	cl_xfer_map_all(list, m);
      else if ((strncmp(m, "MAPEND", strlen("MAPEND"))) == 0)
	DI->map_ok = 3;
    }
  else if ((strncmp(m, "START", strlen("START"))) == 0)
    DI->start = 1;
}
