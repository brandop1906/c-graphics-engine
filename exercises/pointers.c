#include <stdio.h>
#include <ctype.h>
 int getch(void);
int ungetch(int);
 /* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, nextc;
 while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);    /* it′s not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        nextc = getch();
        if (!isdigit(nextc)) {
            ungetch(nextc);
            return 0;
        }
        c = nextc;
    }
        
        
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}