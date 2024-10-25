#include<stdio.h>

int p[50], at[50], bt[50], ct[50], tat[50], wt[50], rmg[50];
int n;
float avg_tat, avg_wt, t_put;

void srtf_sort()
{
    int i, j, temp, flag;
    for ( i = 0; i < n-1; i++ )
    {
        flag = 0;
        for ( j = 0; j < n-1-i; j++ )
        {
            if ( at[j] > at[j+1] )
            {
                flag = 1;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;  
            }
        }
        if ( flag == 0 )
            break;
    }
}

void srtf_computations()
{
    int i, j, completed = 0;
    /*
    while( completed < n )
    {
        
    }
    */
   printf("Not implemented !!");
}

void display()
{
    int i;
    printf("Printing the data\n\n");
    printf("process     arrivaltime     bursttime     completiontime     turnaroundtime     waitingtime\n\n");
    for ( i = 0; i < n; i++ )
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
}

void main()
{
    int i;
    printf("SRTF cpu sheduling algorithm\n");
    printf("Enter the no. of process : ");
    scanf("%d", &n);
    printf("Enter the process no, arrival time and burst time of each process\n");
    for ( i = 0; i < n; i++ )
    {
        scanf("%d%d%d",&p[i], &at[i], &bt[i]);
        rmg[i] = bt[i];  // copying the burst times of each process
    }
    //display();
    srtf_sort();
    display();  // printing the data after sorting
    srtf_computations();
}