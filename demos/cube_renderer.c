#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>
#include "vec.h"
#include "mat.h"
#include "bump.h"
#include "math_alloc.h"

#define M_PI 3.14159265358979323846
#define WIDTH 40
#define HEIGHT 20

float min = -2.0;
float max = 2.0;
bool running = true;
float angle_z = (M_PI/4);
float angle_y = (M_PI/4);
float angle_x = (M_PI/4);
char grid[HEIGHT][WIDTH];

vec4 points[8] = {
    {1, 1, 1, 1},
    {1, 1, -1, 1},
    {1, -1, -1, 1},
    {-1, -1, -1, 1},
    {-1, -1, 1, 1},
    {-1, 1, -1, 1},
    {-1, 1, 1, 1},
    {1, -1, 1, 1},
};

int main(void) {
    BumpAllocator allo = bump_init(1024);
    vec4 *verts = vec4_alloc_array(&allo, 8);

    if (verts == NULL) {
        printf("Memory NOT allocated!");
        return 0;
    }

    verts[0] = (vec4){1, 1, 1, 1};
    verts[1] = (vec4){1, 1, -1, 1};
    verts[2] = (vec4){1, -1, -1, 1};
    verts[3] = (vec4){-1, -1, -1, 1};
    verts[4] = (vec4){-1, -1, 1, 1};
    verts[5] = (vec4){-1, 1, 1, 1};
    verts[6] = (vec4){-1, 1, -1, 1};
    verts[7] = (vec4){1, -1, 1, 1};

    while (running)
    {
        printf("\033[2J\033[H");

        mat4 zrot = mat4_rotate_z(angle_z);
        mat4 yrot = mat4_rotate_y(angle_y);
        mat4 xrot = mat4_rotate_x(angle_x);

        mat4 combined = mat4_mul(mat4_mul(xrot, yrot), zrot);

        for (int i = 0; i < 8; i++)
        {
            verts[i] = mat4_mul_vec4(combined, points[i]);
        }

        for (int row = 0; row < HEIGHT; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                grid[row][col] = ' ';
            }
            
        }

        for (int i = 0; i < 8; i++)
        {
            float x = verts[i].x;
            float y = verts[i].y;
            int col = (x - min) / (max - min) * (WIDTH - 1);
            int row = (HEIGHT - 1) - ((y - min) / (max - min) * (HEIGHT - 1));
            if (col >= 0 && col < WIDTH && row >= 0 && row < HEIGHT)
            {
                grid[row][col] = '#';
            }
        }

        for (int row = 0; row < HEIGHT; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                printf("%c", grid[row][col]);
            }
            printf("\n");
        }

        angle_z += 0.05;
        angle_y += 0.07;
        angle_x += 0.10;
        fflush(stdout);
        usleep(50000);
    
    }

    bump_free(&allo);


    return 0;
}