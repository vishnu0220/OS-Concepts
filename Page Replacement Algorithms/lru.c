#include<stdio.h>
// Remove comments if you execute in Turbo C compiler
//#include<conio.h>
int m_size, n, pf = 0;
int mm[20], search_array[25], values [20];
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

int pagehitvalues(int key)
{
    int i;
    for ( i = 0; i < m_size; i++ )
    {
        if ( values[i] == key )
            return 1;
    }
    return 0;
}

void valuesIntialize()
{
    int i;
    for ( i = 0; i < m_size; i++ )
        values[i] = -1;
}

int lru_index(int lastindex)
{
    int i, j, k = 0, index = 0, data;
    valuesIntialize();
    for ( i = lastindex - 1; i >= 0; i-- )
    {
        if ( pagehit(search_array[i]) )
        {
            if( pagehitvalues(search_array[i]) == 0) 
            {
                values[k] = search_array[i];
                k++;
            }
        }
    }
    
    index = m_size-1;
    data = values[index];  
    for( i = 0; i < m_size; i++ )
    {
        if( mm[i] == data )
        {
            index = i;
            break;
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
    int i, j = 0, index, k = 0;
    //clrscr();
    printf("Enter the main memory size : ");
    scanf("%d", &m_size);
    printf("Enter the search array size : ");
    scanf("%d", &n);
    printf("Enter the search array : ");
    for ( i = 0; i < n; i++ )
        scanf("%d", &search_array[i]);
    for ( i = 0; i < m_size; i++ )
    {
        mm[i] = -1;
        values [i] = -1;
    }
    printf("Intially Manimemory is empty\n");
    printf("Printing the intial data in memory\n");
    displayData();
    printf("Printing the Mainmemory data during the LRU page replace process\n");
    for ( i = 0; i < n; i++ )
    {
        if ( pagehit(search_array[i]) )
            continue;
        else
        {
            pf++;
            if ( j < m_size )
            {
                mm[j] = search_array[i];
                j++;
            }
            else
            {
                index = lru_index(i);
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