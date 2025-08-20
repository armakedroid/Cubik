#include "../incudes/cube3d.h"

void    copy_map(t_mapdata *map)
{
    int i;
    int j;

    i = 8;
    j = 0;
    while (map->mapdata[i])
    {
        map->original_map[j] = map->mapdata[i];
        j++;
        i++;
    }
    
}