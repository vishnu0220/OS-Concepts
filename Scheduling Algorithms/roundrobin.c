#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>

int p[100], pid[100], at[100], bt[100], ct[100], tat[100], wt[100], rt[100];
int n, tq;
float avg_tat, avg_wt,t_put, avg_rt;

void RR_data()
{
    int i;
    printf("Enter the No. of processes : ");
    scanf("%d", &n);
    
    printf(" -------- \n");
    printf("| NOTE : | Here we are assuming all the processes have arrived at the Time stamp 0\n");
    printf(" -------- \n");
    printf("Enter the burst times of the process\n");
    for ( i = 0; i < n; i++ )
        scanf("%d", &bt[i]);
    printf("Enter Time Quantum : ");
    scanf("%d", &tq);
}

void RR_computations()
{
    int i, currentTime = 0, completed = 0;
    int remainingTime[100];
    for ( i = 0; i < n; i++ )
        remainingTime[i] = bt[i];
    
    while( completed < n )
    {
        for( i = 0; i < n; i++ )
        {
            if( remainingTime[i] > 0 )
            {
                int exeTime = (remainingTime[i] < tq) ? remainingTime[i] : tq;
                currentTime += exeTime;
                remainingTime[i] -= exeTime;

                if ( remainingTime[i] == 0 )
                {
                    completed++;
                    wt[i] = currentTime - bt[i];
                    tat[i] = currentTime;
                }
            }
        }
    }

    for ( i = 0; i < n; i++ )
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    avg_wt /= n;
    avg_tat /= n;

    // Displaying the Computed data
    printf("Bt\t tat\t wt\n");
    for ( i = 0; i < n; i++ )
    {
        printf("%d\t %d\t %d\n",bt[i], tat[i], wt[i]);
    }

    printf("Average Waiting Time: %f\n", avg_tat);
    printf("Average Turnaround Time: %f\n", avg_wt);
}

void main()
{
    //clrscr();
    printf("ROUND ROBIN CPU SCHEDULING ALGORITHMS\n");     
    RR_data();
    RR_computations();
}