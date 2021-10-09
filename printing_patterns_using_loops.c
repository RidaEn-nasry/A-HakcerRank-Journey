#include <stdio.h>

//I splitted the box into two halves for easiness sake
void Print_Patterns(int n, int n_unchanged, int flag)
{
    //If the first half ends update the flag.
    if (n == 1)
        flag = 1;
    //If the second half ends terminate.
    if ((flag == 1) && (n == (n_unchanged + 1)))
        return;

    //How many times to print in each row;
    int HowMany = n + (n - 1);
    const int HowMany_unchanged = n_unchanged + (n_unchanged - 1);
    
    //Print the first non-repeating numbers to the left.
    for (int i = HowMany_unchanged - HowMany, k = 0, j = n_unchanged; k < (i / 2); k++, j--)
        printf("%i ", j);

    //Print repeating numbers in the first half (flag = 0), or the second half (flag = 1).
    if (flag == 0)
        for (int i = 0; i < HowMany; i++)
            printf("%i ", n);
    else if (flag == 1)
        for (int i = HowMany; i > 0; i--)
            printf("%i ", n);

    //Print lhe last non-repeating numbers to the right
    for ( int i = HowMany_unchanged - HowMany, k=0, j = (n + 1); k < (i / 2); k++, j++)
        printf("%i ", j);

    printf("\n");

    //Recursively recall the function ascendingly in the first half
    //And descendingly in the second half.recursively recall the function 
    if (flag == 1)
        Print_Patterns(++n, n_unchanged, 1);
    else
        Print_Patterns(--n, n_unchanged, 0);
    

};


int main() 
{
    int n;
    scanf("%d", &n);
    //Start The flag argument with zero;
    Print_Patterns(n, n, 0);
    return 0;
};