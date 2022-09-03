////////////////////////////////////////////////////////////////
// Number of Coins
////////////////////////////////////////////////////////////////
// Given a value V and array coins[] of size M, the task is to m-
// the change for V cents, given that you have an infinite   eka-
// supply of each of coins { coins1, coins2, .., coinsm } valued
// coins. Find the minimum number of coins to make the change. I=
// not possible to make change then return -1.                 f=
////////////////////////////////////////////////////////////////
// Example 1:
// Input: V = 30, M = 3, coins[] = {25, 10, 5}
// Output: 2
// Explanation: Use one 25 cent coin, and one 5 cent coin
////////////////////////////////////////////////////////////////
// Your Task:  
// You don't need to read input or print anything. Complete the
// function minCoins() which takes V, M and array coins as input
// parameters and returns the answer.
// 
// Expected Time Complexity: O(V*M)
// Expected Auxiliary Space: O(V)
// 
// Constraints:
// 1 ≤ V*M ≤ 10^6
// All array elements are distinct
////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.util.Arrays;
////////////////////////////////////////////////////////////////
// t
// v m
// c1 c2 .. cm
////////////////////////////////////////////////////////////////====
class GfG {                                                   // dc  
    public static void main( String args[] ) {                //
        Scanner sc = new Scanner( System.in );                // dc
        int t = sc.nextInt();                                 //
        while( t-- > 0 ) {                                    // dc
            int v = sc.nextInt();                             // 
            int m = sc.nextInt();                             // dc
            int coins[] = new int[ m ];                       //
            for( int i = 0; i < m; i++ ){                     // dc
                coins[ i ] = sc.nextInt();                    //
            }                                                 // dc
            Solution ob = new Solution();                     //
            System.out.println( ob.minCoins( coins, m, v ));  // dc
        }                                                     //
    }                                                         // dc
}                                                             //
////////////////////////////////////////////////////////////////====
// Test Cases Passed: 212 / 212
// Total Points Scored: 4 / 4
// Your Total Score: 778
// Total Time Taken: 0.31
// Your Accuracy: 50%
// Attempts No.: 2
class Solution{
    static final int MAXVAL = 1000001;
    int[]   coins;
    int[][] memory;
    int minCoins( int coins[], int m, int v ){
        Arrays.sort( coins );
        this.coins = coins;
        memory = new int[ m ][ v + 1 ]; // set to nil
        int j = m - 1;
        for(; j > -1 && coins[ j ] > v; --j )
            ;
        if( j == - 1 ) return -1;
        if( coins[ j ] == v ) return 1;
        int n = dp( j, v ); 
        return n == MAXVAL ? -1 : n;
    }
    int dp( int j, int y ){ // dynamic programming
        if( j < 0 || y < 0 ) return MAXVAL;
        if( y == 0 ) return 0;
        if( memory[ j ][ y ] == 0 ){
            int c = coins[ j ];
            int take = 1 + dp( j, y - c );
            int skip = dp( j - 1, y );
            memory[ j ][ y ] = Math.min( skip, take );
        }
        return memory[ j ][ y ];
    }
}
////////////////////////////////////////////////////////////////
// log:
