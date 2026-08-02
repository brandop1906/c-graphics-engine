#include <stdio.h>
#include <stdlib.h>
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
int cols[8];
int rows[8];

vec4 points[8] = {
    {1, 1, 1, 1},   //0
    {1, 1, -1, 1},  //1
    {1, -1, -1, 1}, //2
    {-1, -1, -1, 1},//3
    {-1, -1, 1, 1}, //4
    {-1, 1, -1, 1}, //5
    {-1, 1, 1, 1},  //6
    {1, -1, 1, 1},  //7
};

int edges[12][2] = {
    {0,1}, {0,6}, {0,7},
    {1,2}, {1,5},
    {2,3}, {2,7},
    {3,4}, {3,5}, 
    {4,6}, {4,7},
    {5,6},
};

void draw_line(int col1, int row1, int col2, int row2) {
    int a = abs(col2 - col1);
    int b = abs(row2 - row1);
    int steps = (a > b) ? a : b;

    if (steps == 0) 
    {
        if (col1 >= 0 && col1 < WIDTH && row1 >= 0 && row1 < HEIGHT) {
            grid[row1][col1] = '#';
        }
        return;
    }

    for (int i = 0; i <= steps; i++)
    {
        float t = (float)i / steps;
        int col = col1 + t * (col2 - col1);
        int row = row1 + t * (row2 - row1);
        if (col >= 0 && col < WIDTH && row >= 0 && row < HEIGHT) 
        {
            grid[row][col] = '#';
        }
    }
}

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
            cols[i] = (x - min) / (max - min) * (WIDTH - 1);
            rows[i] = (HEIGHT - 1) - ((y - min) / (max - min) * (HEIGHT - 1));
        }

        for (int e = 0; e < 12; e++)
        {
            int va = edges[e][0];
            int vb = edges[e][1];
            draw_line(cols[va], rows[va], cols[vb], rows[vb]);
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
        angle_y += 0.04;
        angle_x *= 0.07;
        fflush(stdout);
        usleep(50000);
    
    }

    bump_free(&allo);


    return 0;
}