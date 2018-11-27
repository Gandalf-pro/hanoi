#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int tower1[100];
int tower2[100];
int tower3[100];

int minturn(int n)
{
    return pow(2, n) - 1;
}

void settowerzero()
{
    int j;
    for (j = 0; j < 100; j++)
    {
        tower1[j] = 0;
        tower2[j] = 0;
        tower3[j] = 0;
    }
}

void settower(int n)
{
    int i, j;
    settowerzero();
    j = 0;
    for (i = n; i >= 1; i--, j++)
    {
        tower1[j] = i;
    }
}

void printit()
{
    int i, j;
}

void startgame()
{
       
}


void startvisual()
{
}

void main()
{
    int i, disknum = 0;
    char some[10];
    printf("Enter the total amountof disks:");
    scanf("%d", &disknum);
    printf("This is the min amount of actions needed:%d\n", minturn(disknum));
    printf("Enter go if you want to see how to do it enter quit if you dont\n");
    gets(some);
    if (strcmp(some, "go") == 0)
        startvisual();
    else if (strcmp(some, "quit") == 0)
        exit(1);
}
