////////////////////////////////////////////////////////////////
// Next Greater Element
////////////////////////////////////////////////////////////////
// Given an array arr[] of size N having distinct elements, the
// task is to find the next greater element for each element of
// the array in order of their appearance in the array.
////////////////////////////////////////////////////////////////
// Next greater element of an element in the array is the nearest
// element on the right which is greater than the current element.
////////////////////////////////////////////////////////////////
// If there does not exist next greater of current element, then
// next greater element for current element is -1.
////////////////////////////////////////////////////////////////
// For example, next greater of the last element is always -1.
////////////////////////////////////////////////////////////////
// Example 1:
// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element to 1 is 3, 3 is 4, 2 is
// 4 and for 4? Since it doesn't exist, it is -1.
////////////////////////////////////////////////////////////////
// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(N)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ N ≤ 10^6
// 1 ≤ Ai ≤ 10^18
////////////////////////////////////////////////////////////////
import java.io.*;
////////////////////////////////////////////////////////////////
class GFG {    
    public static void main( String[] args ) throws IOException {
        BufferedReader br = new BufferedReader
            ( new InputStreamReader( System.in ));
        int t = Integer.parseInt( br.readLine().trim());
        while( t-- > 0 ){
            int n = Integer.parseInt( br.readLine().trim());
            String inputLine[] = br.readLine().trim().split( " " );
            long[] arr = new long[ n ];
            for( int i = 0; i < n; i++ ){
                arr[ i ] = Long.parseLong( inputLine[ i ]);
            }
            long[] res = new Solution().nextLargerElement( arr, n );
            for( int i = 0; i < n; i++ ){ 
                System.out.print( res[ i ] + " " );
            }
            System.out.println();
        }
    }
}
////////////////////////////////////////////////////////////////
// [O]k, so we have an array a with n elements, lets say we are
// given 0 <= j < n, and ask what is the first element on the
// right of j, that is a[i]: j < i < n, such that a[j] < a[i]?
// With only that info we can start loofing from i in [j+1, n)
// range until the a[j] < a[i] condition is false. If at the
// end, i is equal to n than such element doesn't exist.
// [T]hat will take O(n), and for all elements we will have
// O(n^2) runing time but the expectecd time complexity is
// O(n).
// [T]hat means we need additional info. Let's say we've made
// the scan for j, and found the element i: a[j] < a[i]. Now
// what can we say about (j - 1)th element?
// [I]f a[j - 1] < a[j], that we have the answer, otherwise
// we know that all elements from [j to i) are less than
// a[j - 1], so we need to scan only in the [i, n) range.
class Solution {
    public static long[] nextLargerElement( long[] a, int n ){
        final int back = n - 1;
        long[] g = new long[ n ]; // next greater element
        int[] p = new int[ n ]; // next greater position
        g[ back ] = -1;
        p[ back ] = n;
        for( int j = back - 1; j > -1; j-- ){
            int i = p[ j + 1 ];
            if( a[ j ] < a[ j + 1 ] ){ 
                i = j + 1;
            } else {
                for(; i < n && a[ i ] < a[ j ]; i++ )
                    ;
            }
            p[ j ] = i;
            g[ j ] = ( i < n ) ? a[ i ] : g[ back ];
        }
        return g;
    } 
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 304 / 304
// Total Points Scored: 4 / 4
// Your Total Score: 782
// Total Time Taken: 2.42
// Your Accuracy: 100%
// Attempts No.: 1
// log: -Apparently this has passed the tests, but the principle
// solution, as pointed by the site, is by using a stack.
////////////////////////////////////////////////////////////////
