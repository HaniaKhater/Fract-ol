#ifndef FRACTOL_H
# define FRACTOL_H

// redefine path at 42
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mlx
{
    char    *name;
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *addr;
    int     line_len;
    int     bpp;
    int     endian;
}

int     ft_strcmp(char *s1, char*s2);
void    print_av_list(void);

#endif