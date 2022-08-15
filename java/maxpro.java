////////////////////////////////////////////////////////////////
// Maximum Product Subarray
// Medium Accuracy: 29.84% Submissions: 100k+ Points: 4
////////////////////////////////////////////////////////////////
// Given an array Arr[] that contains N integers (may be positive,
// negative or zero). Find the product of the maximum product
// subarray.
//
// Example 1: N = 5, Arr[] = {6, -3, -10, 0, 2}
// Output: 180
// Explanation: Subarray with maximum product is [6, -3, -10] which
// gives product as 180.
//
// You don't need to read input or print anything. Your task is
// to complete the function maxProduct() which takes the array of
// integers arr and n as parameters and returns an integer denoting
// the answer.
// Note: Use 64-bit integer data type to avoid overflow.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// Constraints:
//    1 ≤ N   ≤ 500
// -10² ≤ Arr ≤ 10²
////////////////////////////////////////////////////////////////
import java.io.*;
import java.util.*;
////////////////////////////////////////////////////////////////
class Main {
    public static void main( String[] args ) throws Exception {
        BufferedReader br =
            new BufferedReader( new InputStreamReader(System.in ));
        int tc = Integer.parseInt( br.readLine() );
        while( tc-- > 0 ){
            int n = Integer.parseInt( br.readLine() );
            int[] arr = new int[ n ];
            String[] inputLine = br.readLine().split(" ");
            for( int i = 0; i < n; i++ ){
                arr[i] = Integer.parseInt( inputLine[i] );
            }
            System.out.println( new Solution().maxProduct( arr, n ));
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:   10352 / 10352
// Total Points Scored: 4 / 4
// Your Total Score:    762
// Total Time Taken:    1.36
// Your Accuracy:       100%
// Attempts No.:        1
////////////////////////////////////////////////////////////////
class Solution {
    long[][] pro; // duct
    long[]   neg; //
    long[]   pos; // shortcuts
    int[]    a;
    //
    int sign( int j ){
        return a[j] < 0 ? 0 : 1;
    }
    // This looks unclear, but there is no duplicate code. The
    // idea is that for every j we keep both positive and
    // negative products, and if a[j] is negative we multiply
    // it with the negative to get the positive and vice versa;
    void set_prod( int j ){
        if( a[j] == 0 ) return; // do nofing
        int s = sign( j );
        pro[1 - s][j] = a[j] * neg[j - 1];
        //
        pro[s][j] = a[j];
        if( pos[j - 1] > 0 ) pro[s][j] *= pos[j - 1];
    }
    long maxProduct( int[] a, int n ){
        // discard a possible negative answer
        if( n == 1 ) return a[0];
        // initialize
        this.a = a;
        pro = new long[2][n];
        neg = pro[0];
        pos = pro[1];
        pro[ sign( 0 )][0] = a[0];
        //
        for( int j = 1; j < n; j++ ){
            set_prod( j );
        }
        return Arrays.stream( pro[1] ).max().getAsLong();
    }
}
////////////////////////////////////////////////////////////////
// From: neznajko
// To: TŸT
// Subject: GFY
// Message: None
//
