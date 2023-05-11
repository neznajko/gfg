////////////////////////////////////////////////////////////////
// K-th element of two sorted Arrays
////////////////////////////////////////////////////////////////
// Given two sorted arrays arr1 and arr2 of size N and M 
// respectively and an element K. The task is to find the 
// element that would be at the kth position of the final sorted
// array.
////////////////////////////////////////////////////////////////
// Example: 1
////////////////////////////////////////////////////////////////
// Input: arr1[] = {2, 3, 6, 7, 9}
//        arr2[] = {1, 4, 8, 10}
//             k = 5
////////////////////////////////////////////////////////////////
// Output: 6
////////////////////////////////////////////////////////////////
// Explanation: The final sorted array would be:
// 1, 2, 3, 4, 6, 7, 8, 9, 10
// The 5th element of this array is 6.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(Log(N) + Log(M))
// Expected Auxiliary Space: O(Log (N))
////////////////////////////////////////////////////////////////
# include <iostream> 
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution{
public:
    int kthElement
    ( int const * a, int const * b, int n, int m, int k );
};
////////////////////////////////////////////////////////////////
# define siz( A ) ( sizeof A/ sizeof *A )
////////////////////////////////////////////////////////////////
int main(){
    int a[]{ 2, 3, 6, 7, 9 };
    int b[]{ 1, 4, 8, 10 };
    int n{ siz( a )};
    int m{ siz( b )};
    int k{ 5 };
    cout << Solution().kthElement( a, b, n, m, k ) << endl;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  160 / 160
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1106
// Total Time Taken:                                        0.19
////////////////////////////////////////////////////////////////
int Solution::kthElement
( int const * a, int const * b, int n, int m, int k ){
    if( !n ){              //    0 1 2 3 4 5 6 7 8 9 a b c d e f
        return b[ k - 1 ]; // a= 1 2 3, n= 3
    }                      // b= 4,     m= 1
    if( !m ){              // k= 4
        return a[ k - 1 ];
    }
    int i{( n - 1 )/ 2 };
    int j{( m - 1 )/ 2 };
    int nfl{( i + 1 ) + ( j + 1 )}; // number of elements
    if( a[ i ] > b[ j ]){
        swap( a, b ); // ..
        swap( n, m ); // **
        swap( i, j ); // oo
    }
    if( k < nfl ){ 
        m = j; 
    } else {
        a += i + 1;
        n -= i + 1;
        k -= i + 1;
    } 
    return kthElement( a, b, n, m, k );
}
////////////////////////////////////////////////////////////////
