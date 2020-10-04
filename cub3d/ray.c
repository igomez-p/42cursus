/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:32:01 by kali              #+#    #+#             */
/*   Updated: 2020/10/04 16:17:40 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define CUB_SIZE                64
#define FOV                     60
#define HEIGHT                  (CUB_SIZE / 2)
#define PLANE_X                 320             // plano proyección horiz
#define PLANE_Y                 200             // plano proyección vertical
#define PROJECT_PLANE_DISTANCE  (PLANE_Y / (2 * (tan(30) * 180 / M_PI)))
#define BACK_COL_ANGLE          (FOV / PLANE_X)

int     g_point_of_view_y; // COORDENADA VERTICAL JUGADOR
int     g_point_of_view_x; // COORDENADA HORIZONTAL JUGADOR

// coordenadas en unidad: (g_point_of_view * (CUB_SIZE - 1) + (CUB_SIZE / 2))
// plano de proyección == resolución ?

void    point_of_view(t_cub *info)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
            {
                g_point_of_view_x = x;
                g_point_of_view_y = y;
                break;
            }
            x++;
        }
        y++;
    }
}

void    throw_lightning(t_cub *info, int x, int y) // la coord y se encargará de buscar si ha chocado con alguna pared o no
{
    // ECUACIÓN DE UNA RECTA: y = m*x + n, m = (y-y0) / (x-x0), n = 0
    int m;

    m = (y - g_point_of_view_y) / (x - g_point_of_view_x);
    if (m < 0)
        m *= -1;
    // trazar rayo ? en funcion de y ?
}

// Paso 3: Lanzamiento de rayos. Encontrar muros
void    find_walls(t_cub *info)
{
    int vision_angle;
    int x;

    vision_angle = FOV / 2;
    x = 0;
    while (x < g_plane_x)
    {
        // lanzar rayo
        // trazar rayo
        vision_angle += BACK_COL_ANGLE;
        x++;
    }
}