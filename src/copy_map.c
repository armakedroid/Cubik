#include "../incudes/cube3d.h"

int copy_map(t_mapdata *map)
{
    int i;
    int j;
    int a;
    int rows;

    rows = 0;
    while (map->mapdata[rows])
        rows++;
    map->original_map = (char **)malloc(sizeof(char *) * (rows - 8 + 1));
    if (!map->original_map)
        return (1);
    i = 8;
    j = 0;
    while (map->mapdata[i])
    {
        a = 0;
        while (map->mapdata[i][a])
            a++;
        map->original_map[j] = (char *)malloc(sizeof(char) * (a + 1));
        if (!map->original_map[j])
            return (1);
        a = 0;
        while (map->mapdata[i][a])
        {
            map->original_map[j][a] = map->mapdata[i][a];
            a++;
        }
        map->original_map[j][a] = '\0';
        j++;
        i++;
    }
    map->original_map[j] = NULL;
    return (0);
}
