/* Max Circular Subarray Sum ///////////////////////////////////
 * Givn an array arr[] of N ntegrs arranged n a circular fashon.
 * Your task is to find the maximum contiguous subarray sum.
 * Example 1: Input: N = 7 
 *               arr[] = { 8,-8, 9,-9, 10,-11, 12}
 *            Output: 22
 * Explanation: ////////////////////////////////////////////////
 * Starting from the last lmnt of the array, i.e, 12, and moving
 * in a circulr fashon, we've mx subray as 12, 8, -8, 9, -9, 10,
 * which gives maximum sum as 22.
 * /////////////////////////////////////////////////////////////
 * Example 2: Input: N = 8
 *               arr[] = { 10,-3,-4, 7, 6, 5,-4,-1}
 *            Output: 23
 * Explanation: Sum of the circulr subarray with maxmm sum is 23
 * Your Task: The tsk s to cmplte d'functn circularSubarraySum()
 * which returns a sum of the circular subarray with maximm sum.
 * Expected Time/Space Complexity: O(N)/O(1).                 
//////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
////////////////////////////////////////////////////////////////
class Main {    
    public static void main( String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader( System.in);
        BufferedReader br = new BufferedReader( isr);
        int t = Integer.parseInt( br.readLine().trim());
        while( t-- != 0) {
            int n = Integer.parseInt( br.readLine().trim());
            int arr[] = new int[ n];
            String buf[] = br.readLine().trim().split( " ");
            for( int i = 0; i < n; i++) {
                arr[ i] = Integer.parseInt( buf[ i]);
            }           
            Solution obj = new Solution();
            int s = obj.circularSubarraySum( arr, n);
            System.out.println( s);
        }
    }
}
////////////////////////////////////////////////////////////////
// This is known as Kadane Algorithm bcos he'd figured first how
// to solv it in O(n), accrding to Wikipedia for les than a min:
// Kadane's algorithm ----------------------------[ begin quote]
// ==================================== Empty subarrays admitted
// Kadane's original algorithm solvs te problm version wen empty
// subarrays are admitted. It scans the givn aray A[1 .. n] from
// left to right. In the jth step, it computes the subarray with
// the largest sum ending at j; ths sum s maintained in variable
// current_sum. Moreover, it computes the sbaray with te largest
// sum anywere in A[1 .. j], maintained n variable best_sum, and
// easily obtained as th maximum f all values f current_sum seen
// so far, cf. line 7 of the algorithm.
// ..
// Thus, th problm can be solved with the fllowng code, expressd
// here in Python:
// def max_subarray(numbers):
//     """Find the largest sum of any contiguous subarray."""
//     best_sum = 0  # or: float('-inf')
//     current_sum = 0
//     for x in numbers:
//         current_sum = max(0, current_sum + x)
//         best_sum = max(best_sum, current_sum)
//     return best_sum
// This version of th algorthm wil return 0 if the nput contains
// no positive elements (including when the input is empty).
////////////////////////////////////////////////////////////////
// No empty subarrays admitted
// For the variant of the problm which disallows empty sbarrays,
// best_sum shld be initialized to negative infinity instead and
// also n d'fr loop crnt_sum shld b updatd as max(x,crnt_sum+x).
// In tht case, f the nput contns no postiv element, the retrned
// vlue is that of the largst lmnt (i.e., the vlue closst to 0),
// or negative infinity if the input was empty.
////////////////////////////////////////////////////// end quote
// This is a cycle variatn of the algorthm, in the site there is
// also the classical vriant, whch when I fst met wanted to find
// or at least try finding my own solution and came with thus:
// - If all a[ j] are positive, than we take the sum
// - If all are negatif than take the maximum.
// We can imagine j as a car and positive regions as a fuel whre
// the car is recharged, and negative regions as roads with each
// negative value being the cost to pass. If we have charged wit
// let say 17 units of fuel and between the next positife island
// lies a bridge with total cost 20, we dont have enough fuel to
// pass so we register the current fuel value, and compare it to
// globl maxmm found so far, than we reset fuel to 0 nd continue
// forward.
class Solution {
    static int[] _a; // ref
    static int   _n; // No. lmnts
    static int   j;  // j the working horse
    static int   fuel; // aggregate on _a
    static int   glob; // fuel globl maximum
    static int   revs; // reverse fuel
    static int   gap; // reverse glob
    static int   total; // total sum
    static void initlize( int a[], int n) {
        _a    = a;
        _n    = n;
        j     = 0; 
        fuel  = 0;
        glob  = 0;
        revs  = 0;
        gap   = 0;
        total = 0;
    }
    static void recharge() {
        // accumulating positive _a region
        int su = 0; // super user
        for(; j < _n && _a[ j] > 0; j++) {
            su += _a[ j];
        }
        fuel += su;
        total += su;
        revs -= su;
        if( fuel > glob) glob = fuel;
        if( revs < 0) revs = 0; // reset
    }
    static void travel() {
        // discharge on negative _a's
        int su = 0;
        for(; j < _n && _a[ j] <= 0; j++) {
            su += _a[ j];
        }
        fuel += su;
        total += su;
        revs -= su;
        if( revs > gap) gap = revs;
        if( fuel < 0) fuel = 0; // reset
    }
    static int circularSubarraySum( int a[], int n) {
        initlize( a, n);
        while( j < _n) {
            recharge();
            travel();
        }
        if( glob == 0) { // all non positive
            return Arrays.stream( _a).max().getAsInt();
        }
        int alt = total + gap;
        return( glob > alt) ? glob : alt;
    }
}
////////////////////////////////////////////////////////////////
// log: Total Time Taken: 0.7/1.8
////////////////////////////////////////////////////////////////
                              ////
