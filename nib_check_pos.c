#include "mn.h"

int		nib_check_pos(t_list *list, int x, int y)
{
  int		d;
  int		cy;
  t_map		*map;
  t_nib		*nib;

  for (cy = (y + 1); cy <= (y + 6); cy++)
    {
      for (map = DM; map; map = map->next)
	{
	  if ((map->type == 'w') || (map->type == ' '))
	    {
	      d = (int)sqrt(((double)pow((map->x - x), 2) +
			     (double)pow((map->y - cy), 2)));
	      if (d < 5)
		return (0);
	    }
	}
      if (DW)
	for (nib = DW; nib; nib = nib->next)
	  {
	    d = (int)sqrt(((double)pow((nib->x - x), 2) +
			   (double)pow((nib->y - cy), 2)));
	    if (d < 5)
	      return (0);
	  }
    }
  return (1);
}
