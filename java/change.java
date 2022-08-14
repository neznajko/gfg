//////////////////////////////////////////////////////////////// 
// Coin Change                                                   
// Medium Accuracy: 47.19% Submissions: 96029 Points: 4          
// _____________________________________________________________ ----
// Given a value N, find the number of ways to make change for N ----
// cents, if we have infinite supply of each of S = { S1, S2, .. SM }
// valued coins.                                                 ----
// =============================================================
// Input:  n = 4 , m = 3, S[] = {1,2,3}
// Output: 4({1,1,1,1},{1,1,2},{2,2},{1,3})
// .·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.
// Your Task:
//                         You don't need to read input or print 
// anything. Your task is to complete the function count() which
//      accepts an array S[] its size m and n as input parameter
//    and returns the number of ways to make change for N cents.
// -------------------------------------------------------------
// Expected Time Complexity: O(m*n).
// Expected Auxiliary Space: O(n).
// =============================================================
// Constraints:
// 1 <= n,m <= 10³
////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.util.Arrays;
////////////////////////////////////////////////////////////////
import static java.lang.System.out;
////////////////////////////////////////////////////////////////
// Test Cases Passed:   20 / 20
// Total Points Scored: 4 / 4
// Your Total Score:    754
// Total Time Taken:    0.47
// Your Accuracy:       50%
// Attempts No.:        2
////////////////////////////////////////////////////////////////
class GfG {
    public static void main( String args[] ){
        Scanner sc = new Scanner( System.in );
        int t = sc.nextInt();
        while( t-- > 0 ){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int Arr[] = new int[m];
            for( int i = 0; i < m; i++ ) Arr[i] = sc.nextInt();
            Solution ob = new Solution();
            System.out.println( ob.count( Arr, m, n ));
        }
    }
}
////////////////////////////////////////////////////////////////
class Solution {
    int[]    s;
    long[][] memory;
    long dp( int n, int j ){
        // [1] check j
        if( j >= s.length ) return 0;
        // [2] voilá
        if( n == 0 ) return 1;
        // [3] get the corresponding coin value
        int coin = s[j];
        // [4] check coin
        if( coin > n ) return 0;
        // [5] check if we didn't cache the query already
        if( memory[n][j] == 0 ){
            // [6] take and skip
            memory[n][j] = dp( n - coin, j ) + dp( n, j + 1 );
        }
        // [7] au revoir
        return memory[n][j];
    }
    public long count( int s[], int o_ò, int n ){
        Arrays.sort( s );
        this.s = s;
        memory = new long[n + 1][s.length];
        return dp( n, 0 );
    }
}
////////////////////////////////////////////////////////////////
// `·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`·.·`
// log:
