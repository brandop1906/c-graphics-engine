#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int choice;
    bool running = true;

    do
    {
        printf("1 : Addition, 2 : Subtraction, 3 : Multiplication, 4 : Division, 5 : Factorial, 6 : Close Program\n");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Error: not a number\n");
            continue;
        }
        switch (choice)
        {
        case 1: {
            int x,y,result;
            printf("Enter a value for x: \n");
            if (scanf("%d", &x) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number\n");
                continue;
            }
            printf("Enter a value for y: \n");
            if (scanf("%d", &y) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number\n");
                continue;
            }
            result = x + y;
            printf("%d + %d = %d\n", x, y, result);
            break;
        }
        case 2: {
            int x, y, result;
            printf("Enter a value for x: \n");
            if (scanf("%d", &x) != 1)
            {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number\n");
                continue;
            }
            printf("Enter a value for y: \n");
            if (scanf("%d", &y) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number\n");
                continue;
            }
            result = x - y;
            printf("%d - %d = %d\n", x, y, result);
            break;
            
        }

        case 3: {
            int x, y, result;
            printf("Enter a value for x: \n");
            if (scanf("%d", &x) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number\n");
                continue;
            }
            printf("Enter a value for y: \n");
            if (scanf("%d", &y) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number\n");
                continue;
            }
            result = x * y;
            printf("%d * %d = %d\n", x, y, result);
            break;
        }
        case 4: {
            float x, y;
            float result;
            printf("Enter a value for x: \n");
            if (scanf("%f", &x) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                printf("Error: not a number");
                continue;
            }
            printf("Enter a value for y: \n");
            if (scanf("%f", &y) != 1) {
                int ch;
                while ((ch =  getchar()) != '\n' && ch != EOF) 
                    ;
                printf("Error: Enter a non zero number\n");
                continue;
            }
            if (y == 0) {
                printf("Error: Enter a non zero number for y\n");
                break;
            }
            result = x / y;
            printf("%.1f / %.1f = %.2f\n", x, y, result);
            break;
        }

        case 5: {
            int x, i, result = 1;
            printf("Enter a value for x: ");
            if (scanf("%d", &x) != 1) {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                continue;
            }
            if ( x < 0) {
                printf("Error: factorial is undefined for negative numbers\n");
                break;
            }
            if (x == 0) {
                printf("The Factorial of %d is: %d\n", x, result);
                break;
            }
            for (i = 1; i <= x; i++)
            {
                result *= i;
            }
            printf("The Factorial of %d is: %d\n", x, result);
            break;
        }

        case 6:
            printf("Closing Program!\n");
            running = false;
            break;
        
        default:
            printf("Error: That is not a supported option\n");
            break;
        }
    } while (running);

    return 0;
    
}


