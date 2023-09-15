#include <stdio.h>
struct process
{
    char name;
    int at, bt, wt, ft, tt;
} P[10];

void main()
{
    float awt, aft, att;
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Process name, Arrival Time, Burst Time: ");
        scanf("\n %c %d %d", &P[i].name, &P[i].at, &P[i].bt);
    }
    printf("\n");
    P[0].wt = 0;
    P[0].ft = P[0].bt;
    P[0].tt = P[0].ft - P[0].at;

    for (int i = 1; i < n; i++)
    {
        P[i].ft = P[i - 1].ft + P[i].bt;
        P[i].wt = P[i].ft - P[i].at - P[i].bt;
        P[i].tt = P[i].ft - P[i].at;
    }
    printf("Process    AT   BT   WT   FT   TT \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %c         %d    %d    %d    %d    %d", P[i].name, P[i].at, P[i].bt, P[i].wt, P[i].ft, P[i].tt);
        printf("\n");
    }
}