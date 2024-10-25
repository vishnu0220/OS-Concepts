#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>

int processes[20], max[20][20], allocated[20][20], need[20][20], resources[20], available[20];
int n, r, process; // procces is for calling the safety algo for the specific task


void print_data()
{
    int i, j;
    printf("\nPrinting the data\n");
    printf("Process   Max     Allocated    Need\n");
    for ( i = 0; i < n; i++ )
    {
        printf("   %d    ", processes[i]);
        for ( j = 0; j < r; j++ )
        {
            printf("%d  ", max[i][j]);
        }
        printf("  ");
        for ( j = 0; j < r; j++ )
        {
            printf("%d  ", allocated[i][j]);
        }
        printf("  ");

        for ( j = 0; j < r; j++ )
        {
            printf("%d  ", need[i][j]);
        }
        printf("\n");
    }
    printf("The available resources \n");
    for ( i = 0; i < r; i++ )
        printf("%d  ",available[i]);
    printf("\n");
}


void release_algorithm( int process )
{
    int i, j, k = 0; // k will be the iterating variable for available array
    for ( i = 0; i < r; i++ )
    {
        available[k] += allocated[process][i];
        k++;
        allocated[process][i] = 0;
    }
    // updating the need matrix for corressponding procces
    for ( i = process, j = 0; j < r; j++ )
        need[process][j] = max[process][j];
}


void request_algorithm( int process )
{
    int i, j , k = 0, flag = 0, release_procees; // k will be the iterating variable for available array
    for ( i = process, j = 0; j < r; j++ ) // Here r is No. of resources i.e to know Howmany times we need to check for condition
    {
        if( need[i][j] > available[k++] )
        {
            flag = 1;
            break;
        }
    }

    if ( flag == 0)
    {
        printf("Access can be granted to procees %d \n", process);
        printf("Procces %d finished it execution \n", process);
        printf("Now the process %d releasing its resources \n", process);
        release_algorithm(process);
        for ( i = process, j =0; j < r; j++ )
        {
            max[process][j] = 0;
            need[process][j] = 0;
        }
    }
    else
    {
        printf("Access denied to procees %d \n", process);
        printf("To execute the request procces %d, Enter a procces to release it's resouces : ", process);
        scanf("%d", &release_procees);
        printf("On demand process %d releasing it's resources to avoid Deadlock", release_procees);
        release_algorithm(release_procees);
        flag = 0, k = 0;
        for ( i = process, j = 0; j < r; j++ ) // Here r is No. of resources i.e to know Howmany times we need to check for condition
        {
            if( need[i][j] > available[k++] )
            {
                flag = 1;
                break;
            }
        }
        print_data();
        if ( flag == 1 )
            printf("\nAfter procees %d release it's resouces process %d is unable to execute", release_procees, process);
        else
        {
            printf("\nProcess %d finished it's execution", process);
            for ( i = process, j = 0; j < r; j++ )
                max[process][j] = 0;
            release_algorithm(process);
        }
    }
    print_data();
}


void main()
{
    int i, j, k = 0; // k is taken for storing the values in available array
    int sum = 0; // For calulating the sum of individual column sum of allocated matrix to get available array values
    int process;
    //clrscr();
    printf("Enter the No. of procceses and resources : ");
    scanf("%d%d", &n, &r);
    for ( i = 0; i < n; i++ )
        processes[i] = i;
    printf("Enter the No. of resources of each type\n");
    for ( i = 0; i < r; i++ )
        scanf("%d",&resources[i]);
    printf("Enter the max resources needed for each process\n");
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < r; j++ )
        {
            scanf("%d", &max[i][j]);
        }
    printf("Enter the allocated resources for each process\n");
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < r; j++ )
        {
            scanf("%d", &allocated[i][j]);
        } 
    
// calculating the need matrix
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < r; j++ )
        {
            need[i][j] = max[i][j] - allocated[i][j];
        }
  
    for ( i = 0; i < r; i++ )
    {
        sum = 0;
        for ( j = 0; j < n; j++ )
            sum += allocated[j][i];
        available[k++] = resources[i] - sum;
    }
    // print them
    print_data();
    printf("Enter the procces to execute : ");
    scanf("%d", &process);
    request_algorithm(process);
    //getch();
}