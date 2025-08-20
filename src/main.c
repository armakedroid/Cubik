#include "../incudes/cube3d.h"

int main(int argc, char **argv)
{
    int i;
    t_mapdata arg;

    if (argc != 2)
       return(ft_putstr_fd("wrong argument number", 2), 1);
    i = validation(argv[1], &arg);
    if (i == -1)
        return (ft_putstr_fd("error\n",2), 1);
    
}