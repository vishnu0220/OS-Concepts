#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>

int pid[100], at[100], bt[100], ct[100], tat[100], wt[100], n;
float avg_tat, avg_wt,t_put, avg_rt;

void sjf_data()
{
    int i;
    printf("Enter the no. of processes : ");
    scanf("%d",&n);
    printf("Here we assume that all processes have arrived at 0\n");
    printf("Enter the process id's and burst times of each process\n");
    for ( i = 1; i <= n; i++ )
    {
	scanf("%d",&pid[i]);
	scanf("%d",&bt[i]);
    }
}

void sjf_sort()
{
    int i,j,temp;
    for ( i = 0; i <= n-1; i++ )
    {
        int flag = 0;
        for ( j = 0; j <= n-1-i; j++ )
        {
            if ( bt[j] > bt[j+1] )
            {
                flag = 1;
                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;

                temp = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = temp;
            }
        }
        if ( flag == 0 )
            break;
    }
}

void sjf_computations()
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
    avg_rt /= n;
    t_put = ct[n];
    t_put = n/t_put;

}

void final_res()
{
    printf("\n\nThe average Turn around time : %f ",avg_tat);
    printf("\nThe average Waiting time : %f ",avg_wt);                
    printf("\nThe average response time : %f",avg_rt);
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
    printf("Shortest Job First CPU SCHEDULING ALGORITHMS\n");
    sjf_data();
    display();
    sjf_sort();
    sjf_computations();
    display();
    final_res();
}