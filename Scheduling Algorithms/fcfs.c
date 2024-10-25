#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>

int p[100], pid[100], at[100], bt[100], ct[100], tat[100], wt[100];
int n, cpu_idle, Temp_ct;
float avg_tat, avg_wt, t_put;

void fcfs_data()
{
    int i;
    printf("Enter the no. of processes : ");
    scanf("%d",&n);
    printf("\nEnter the process id's, arrival time and burst times of each process\n");
    for ( i = 1; i <= n; i++ )
        scanf("%d%d%d",&pid[i], &at[i], &bt[i]);
}

void fcfs_Sort()
{
    int i,j,temp;
    for ( i = 0; i <= n-1; i++ )
    {
        int flag = 0;
        for ( j = 0; j <= n-1-i; j++ )
        {
            if ( at[j] > at[j+1] )
            {
                flag = 1;
                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;

                temp = at[j+1];
                at[j+1] = at[j];
                at[j] = temp;

                temp = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = temp;
            }
        }
        if ( flag == 0 )
            break;
    }
}


void fcfs_computations()
{
    int i;
    for ( i = 1; i <= n; i++)
    {
        if( at[i] > ct[i-1] )
        {
            cpu_idle = at[i] - ct[i-1];
            ct[i] = Temp_ct + bt[i] + cpu_idle;
        }
        else
        {
            ct[i] = Temp_ct + bt[i];
        }
        Temp_ct = ct[i];
        tat[i] = ct[i] - at[i];
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
    printf("\nPid\tAt\tBt\tCt\tTat\tWt\n");
    for ( i = 1; i <= n; i++ )
    {
	    printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}

void main()
{
    //clrscr();
    printf("First Come First Serve CPU SCHEDULING ALGORITHM\n");
    fcfs_data();
    display();
    fcfs_Sort();
    fcfs_computations();
    display();
    final_res();
   //getch();
}