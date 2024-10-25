#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>

int m_size, n, pf = 0;
int mm[10], search_array[25], Index_arr[10]; // Index_arr array stores the Index the value that not have been used for longer time
float phr,pfr;

int pagehit(int key)
{
    int i;
    for ( i = 0; i < m_size; i++ )
    {
        if ( mm[i] == key )
            return 1;
    }
    return 0;
}

void intializeIndex()
{
    int i;
    for ( i = 0; i < m_size; i++ )
        Index_arr[i] = 999;
}

int opt_replace(int startIndex)
{
    int i, j = 0, k = 0, index; // we didn't know which index to be replaced
    intializeIndex();
    for ( k = 0; k < m_size; k++ )
    {    
        for( i = startIndex+1; i < n; i++ )
        {
            if(mm[j] ==  search_array[i] )
            {
                Index_arr[j] = i;
                j++;
                break;
            }
        } 
    }
    index = 0; // assuming that 0th index page is not used for longest time period
    for ( i = 0; i < m_size; i++ )
    {
        if(Index_arr[i] > Index_arr[index])
        {
            index = i;
        }
    }
    return index;
}

void page_replace(int index , int value)
{
    mm[index] = value;
}

void displayData()
{
    int i;
    for ( i = 0; i < m_size; i++ )
        printf("%d    ", mm[i]);
    printf("\n");
}

int main()
{
    int i, j = 0, index;
    //clrscr();
    printf("Enter the main memory size : ");
    scanf("%d", &m_size);
    printf("Enter the search array size : ");
    scanf("%d", &n);
    printf("Enter the search array : ");
    for ( i = 0; i < n; i++ )
        scanf("%d", &search_array[i]);
    for ( i = 0; i < m_size; i++ )
        mm[i] = -1;

    printf("Intially Manimemory is empty\n");
    printf("Printing the intial data in memory\n");
    displayData();
    printf("Printing the Mainmemory data during the OPT page replace process\n");

    for ( i = 0; i < n; i++ )
    {
        if( pagehit(search_array[i]) == 0 )
        {
            pf++;
            if( j < m_size )
                mm[j++] = search_array[i];
            else
            {
                index = opt_replace(i);
                page_replace(index, search_array[i]);
            }
            displayData();
        }
    }  

    printf("\nNo. of page faults : %d \n", pf);
    if ( pf == n )
    {
        pfr = 1;
        phr = 0;
    }
    else 
    {
        phr = (float) (n-pf)/n;
        pfr = (float) pf/n;    
    }    
    printf("page hit ratio : %f \n", phr);
    printf("page fault ratio : %f \n", pfr);
    //getch();
    return 0;
}