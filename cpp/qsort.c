/* Quick Sort **************************************************
 * [ Medium ]   Accuracy: 46.8% / Submissions: 80535 / Points: 4
 * #############################################################
 * QUICK SORT IS A DIVIDE AND                            CONQUER
 * #############################################################
 * ALGORITHM. IT PICKS AN ELEMENT                             AS
 * #############################################################
 * PIVOT AND PARTITIONS THE GIVEN                          ARRAY
 * #############################################################
 * AROUND THE PICKED PIVOT. GIVEN AN                       ARRAY
 * #############################################################
 * ARR[], ITS STARTING POSITION LOW                          AND
 * #############################################################
 * ITS ENDING POSITION HIGH.                           IMPLEMENT
 * #############################################################
 * THE PARTITION() AND QUICKSORT()                     FUNCTIONS
 * #############################################################
 * TO SORT THE                                            ARRAY.
 * #############################################################
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *        Your Task                 inpt parametrs and parttions
 *                                  the array. Consider the last
 * You don't need to read input     lment as the pivot such that
 * or print anything. Your task     all the lments less than (or
 * is to complete the functions     eql to) the pivot lie before
 * quickSort(), which takes the     it, and the elements greater
 * array arr[], low and high as     than it lie after the pivot.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Expected Time Complexity: O(N*logN)
 * Expected Auxiliary Space: O(1)
 =============================================================== 
 * Constraints:
 * 1 <= N <= 10^3
 * 1 <= arr[i] <= 10^4
 **************************************************************/
////////////////////////////////////////////////////////////////
# include <stdio.h>
////////////////////////////////////////////////////////////////
void quickSort( int *y, int lo, int hi );
////////////////////////////////////////////////////////////////
// Test Cases Passed: 67 \ 67
// Total Time Taken: 0.01 \ 1.24
/////////////////////////////////////////////// >>>> Driver Code
void printArray( int arr[], int size ){
        for( int i = 0; i < size; i++ ){
                printf( "%d ", arr[ i ]);
        }
        printf( "\n" );
}
////////////////////////////////////////////////////////////////
int main() {
        int arr[ 1000 ], n, T;
        scanf( "%d", &T );
        while( T-- ){
                scanf( "%d", &n );
                for( int i = 0; i < n; i++ ){
                        scanf( "%d", &arr[ i ]);
                }
                quickSort( arr, 0, n - 1 );
                printArray( arr, n );
        }
}
/////////////////////////////////////////////// Driver Code <<<<
# define push( J ){                             \
                ++sp;                           \
                int tmp = y[ sp ];              \
                y[ sp ] = y[ J ];               \
                y[ J ] = tmp;                   \
        }
////////////////////////////////////////////////////////////////
int partitn( int *y, int lo, int hi ){
        int sp = lo - 1; // stack pointer
        for( int j = lo; j <= hi; j++ ){
                if( y[ j ] <= y[ hi ] ){
                        push( j );
                }
        }
        return sp;
}
////////////////////////////////////////////////////////////////
void quickSort( int *y, int lo, int hi ){
        if( lo >= hi ) return; // and chill
        int j = partitn( y, lo, hi );
        quickSort( y, lo, j - 1 );
        quickSort( y, j + 1, hi );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
