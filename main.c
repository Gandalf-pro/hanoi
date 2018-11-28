#include "hanoi.h"
//done
bool iseven(int n)
{
    if (n % 2 == 0)
        return true;
    else
        return false;
}
//done
int minturn(int n)
{
    return pow(2, n) - 1;
}
//done
void settowerzero()
{
    int j;
    for (j = 0; j < lent; j++)
    {
        tower1[j] = 0;
        tower2[j] = 0;
        tower3[j] = 0;
    }
}
//done
int gettopindex(int n)
{
    int i, j;
    switch (n)
    {
    case 1:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower1[i] == 0)
            {
                if (i == 0)
                    return i;
                else
                    return i - 1;
            }
        }

    case 2:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower2[i] == 0)
            {
                if (i == 0)
                    return i;
                else
                    return i - 1;
            }
        }

    case 3:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower3[i] == 0)
            {
                if (i == 0)
                    return i;
                else
                    return i - 1;
            }
        }
    }
}

int gettopindexfor(int n)
{
    int i, j;
    switch (n)
    {
    case 1:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower1[i] == 0)
            {
                if (i == 0)
                    return i-1;
                else
                    return i - 1;
            }
        }

    case 2:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower2[i] == 0)
            {
                if (i == 0)
                    return i-1;
                else
                    return i - 1;
            }
        }

    case 3:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower3[i] == 0)
            {
                if (i == 0)
                    return i-1;
                else
                    return i - 1;
            }
        }
    }
}

int gettop(int n)
{
    int i, j;
    switch (n)
    {
    case 1:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower1[i] == 0)
            {
                if (i == 0)
                    return tower1[i];
                else
                    return tower1[i - 1];
            }
        }

    case 2:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower2[i] == 0)
            {
                if (i == 0)
                    return tower2[i];
                else
                    return tower2[i - 1];
            }
        }

    case 3:
        for (i = 0; i < disknum + 2; i++)
        {
            if (tower3[i] == 0)
            {
                if (i == 0)
                    return tower3[i];
                else
                    return tower3[i - 1];
            }
        }
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
//needs to print the pole for zeros
void printit()
{
    int i, j;
    for (i = lent - 1; i >= 0; i--)
    {
        if (tower1[i] == 0 & tower2[i] == 0 & tower3[i] == 0)
            continue;
        if (tower1[i] != 0)
            printf("   %d", tower1[i]);
        else
            printf("   %c", 186);

        printf("     ");

        if (tower2[i] != 0)
            printf("%d     ", tower2[i]);
        else
            printf("%c     ", 186);

        if (tower3[i] != 0)
            printf("%d", tower3[i]);
        else
            printf("%c", 186);

        printf("\n");
    }
    printf("  %c%c%c   %c%c%c   %c%c%c", 205, 202, 205, 205, 202, 205, 205, 202, 205);
    printf("\n");
}
//ok
void moveab()
{
    //a to b
    if(gettop(1)==0&gettop(2)==0)
    return;
    else if(gettop(1)==0)
    {
        tower1[0]=gettop(2);
        tower2[gettopindex(2)]=0;
    }
    else if(gettop(2)==0)
    {
        tower2[0]=gettop(1);
        tower1[gettopindex(1)]=0;
    }
    else if (gettop(1) > gettop(2))
    {
        tower1[gettopindex(1) + 1] = gettop(2);
        tower2[gettopindex(2)] = 0;
    }
    else if (gettop(1) < gettop(2))
    {
        tower2[gettopindex(2) + 1] = gettop(1);
        tower1[gettopindex(1)] = 0;
    }
    return;
}

void moveac()
{
    //a to c
    if(gettop(1)==0&gettop(3)==0)
    return;
    else if(gettop(1)==0)
    {
        tower1[0]=gettop(3);
        tower3[gettopindex(3)]=0;
    }
    else if(gettop(3)==0)
    {
        tower3[0]=gettop(1);
        tower1[gettopindex(1)]=0;
    }
    else if (gettop(1) > gettop(3))
    {
        tower1[gettopindex(1) + 1] = gettop(3);
        tower3[gettopindex(3)] = 0;
    }
    else
    {
        tower3[gettopindex(3) + 1] = gettop(1);
        tower1[gettopindex(1)] = 0;
    }
    return;
}

void movebc()
{
    //b to c
    if(gettop(2)==0&gettop(3)==0)
    return;
    else if(gettop(2)==0)
    {
        tower2[0]=gettop(3);
        tower3[gettopindex(3)]=0;
    }
    else if(gettop(3)==0)
    {
        tower3[0]=gettop(2);
        tower2[gettopindex(2)]=0;
    }
    else if (gettop(2) > gettop(3))
    {
        tower2[gettopindex(2) + 1] = gettop(3);
        tower3[gettopindex(3)] = 0;
    }
    else
    {
        tower3[gettopindex(3) + 1] = gettop(2);
        tower2[gettopindex(2)] = 0;
    }
    return;
}

void moveeven()
{
    int i=0;
    start:
    moveac();
    printit();
    i++;
    if(i>=minimumturn)
    return;
    moveab();
    printit();
    i++;
    if(i>=minimumturn)
    return;
    movebc();
    printit();
    i++;
    if(i>=minimumturn)
    return;
    goto start;
}

void moveodd()
{
    int i=0;
    start:
    moveab();
    printit();
    i++;
    if(i>=minimumturn)
    return;
    moveac();
    printit();
    i++;
    if(i>=minimumturn)
    return;
    movebc();
    printit();
    i++;
    if(i>=minimumturn)
    return;
    goto start;
}

void move()
{
    if (even)
        moveeven();
    else
        moveodd();
}

void startsteps()
{
    printit();
    move();
}

void startvisual()
{
    int i;
    even = iseven(disknum);
    settowerzero();
    settower(disknum);
    startsteps(minimumturn);
}

void main()
{
    int i,num;
    start:
    printf("Enter 1 if you want to start enter 2 if you want to quit\n");
    scanf("%d,\n",&num);
    if(num==1)
    {
    printf("Enter the total amountof disks:");
    scanf("%d", &disknum);
    minimumturn = minturn(disknum);
    printf("This is the min amount of actions needed:%d\n", minimumturn);
    startvisual();
    goto start;
    }else if(num==2)
    exit(1);
    else
    {
        printf("Enter a valid number");
        goto start;
    }
}
