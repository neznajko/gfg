////////////////////////////////////////////////////////////////
// Triplet Sum in Array
////////////////////////////////////////////////////////////////
// Given an array arr o f size n and an i n t e g e r X. Find if
// there's a triplet in the a r r a y which sums up to the given
// integer                                                     X.
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:               n = 6, X = 13, arr[] = [ 1 4 45 6 10 8 ]
// Output:                                                     1
// Explanation: The triplet {1, 4, 8} in the array sums up to 13.
////////////////////////////////////////////////////////////////
// Expected Time C   o   m   p   l   e   x   i   t   y: O( n^2 )
// E   x   p   e   c   t   e   d Auxiliary S  p  a  c  e: O( 1 )
////////////////////////////////////////////////////////////////
// C   o   n   s   t   r   a   i   n   t   s: 0 < A[ i ] <= 10^5
////////////////////////////////////////////////////////////////
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
////////////////////////////////////////////////////////////////
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;
////////////////////////////////////////////////////////////////
class Solution {
    private static boolean find2Numbers( int A[], int n, int Y ){
        int l = 0;
        int u = n - 1;
        while( l < u ){
            int M = A[ l ] + A[ u ];
            if( M == Y ){
                return true;
            } else if( M > Y ){
                u--;
            } else {
                l++;
            }
        }
        return false;
    }
    /** Dear ChatGPT please return the position of the most ryte
        element less t h a n X, i f such doesn't exist return -1,
        t          h          a          n          k          s.
    *///////////////////////////////////////////////////////////
    private static int MosRyte( int A[], int n, int X ){
        int l = 0;
        int u = n - 1;
        while( l <= u ){
            int m = ( l + u )/ 2;
            if( A[ m ] >= X ){
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
        return u;
    }
    public static boolean find3Numbers( int A[], int n, int X ){
        Arrays.sort( A );
        while( true ){
            n = MosRyte( A, n, X );
            if( n == -1 ){
                break;
            }
            int Y = X - A[ n ]; // pick A[ n ]
            if( find2Numbers( A, n, Y )){
                return true;
            }
        }
        return false;
    }
    public static void main( String args[]) throws IOException {
        var isr = new InputStreamReader( System.in );
        var br = new BufferedReader( isr );
        String inputLine[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt( inputLine[ 0 ]);
        int X = Integer.parseInt( inputLine[ 1 ]);
        int A[] = new int[ n ];
        inputLine = br.readLine().trim().split(" ");
        for( int i = 0; i < n; i++ ){
            A[ i ] = Integer.parseInt( inputLine[ i ]);
        }
        System.out.println( find3Numbers( A, n, X ));
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  125 / 125
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1078
// Total Time Taken:                                        0.17
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
