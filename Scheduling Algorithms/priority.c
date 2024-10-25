#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>

int p[100], pid[100], at[100], bt[100], ct[100], tat[100], wt[100], n;
float avg_tat, avg_wt,t_put;

void priority_data()
{
    int i;
    printf("Enter the no. of processes : ");
    scanf("%d",&n);
    printf("Here we assume that all processes have arrived at 0\n");
    printf("Lower the number higher the priority\n");
    printf("Enter the priority, process id's and burst times of each process\n");
    for ( i = 1; i <= n; i++ )
    {
        scanf("%d",&p[i]);
        scanf("%d",&pid[i]);
        scanf("%d",&bt[i]);
    }
}

void priority_sort()
{
    int i,j,temp;
    for ( i = 0; i <= n-1; i++ )
    {
        int flag = 0;
        for ( j = 0; j <= n-1-i; j++ )
        {
            if ( p[j] > p[j+1] )
            {
                flag = 1;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;

                temp = pid[j+1];
                pid[j+1] = pid[j];
                pid[j] = temp;

                temp = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = temp;
            }
        }
        if ( flag == 0 )
            break;
    }
}

void priority_computations()
{
    int i;
    for ( i = 1; i <= n; i++)
    {    
        ct[i] = bt[i] + tat[i-1];
        tat[i] = ct[i] ; // + at[i] ==> all processes arrived at 0
        wt[i] = tat[i] - bt[i];
    }

    for ( i = 1; i <= n; i++ )
    {
	    avg_tat += tat[i];
	    avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;
    t_put = ct[n];
    t_put = n/t_put;
}

void final_res()
{
    printf("\n\nThe average Turn around time : %f ",avg_tat);
    printf("\nThe average Waiting time : %f ",avg_wt);
    printf("\nThe through put : %f ",t_put);
}

void display()
{
    int i;
    printf("\nprty\tPid\tAt\tBt\tCt\tTat\tWtn");
    for ( i = 1; i <= n; i++ )
    {
	    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}

void main()
{
    //clrscr();
    printf("PRIORITY CPU SCHEDULING ALGORITHMS\n");
    priority_data();
    display();
    priority_sort();
    priority_computations();
    display();
    final_res();
}