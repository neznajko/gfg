#!/usr/bin/env                                              node
////////////////////////////////////////////////////////////////
/* Minimize the Heights I
 * Medium; Accuracy: 44%, Submissions: 34715, Points: 4
 *
 * Given an array arr[] denoting heights of N towers and a
 * positive integer K, you have to modify the height of each
 * tower either by increasing or decreasing them by K only once.
 * Find out what could be the possible minimum difference of the
 * height of shortest and longest towers after you have modified
 * each tower.
 *
 * Note: Assume that height of a tower can be negative.
 *
 * == Example 1 ==
 * Input:  K = 2, N = 4, Arr[] = {1, 5, 8, 10}
 * Output: 5
 * Explanation: The array can be modified as {3, 3, 6, 8}. The
 * difference between the largest and the smallest is 8-3 = 5.
 *
 * == Example 2 ==
 * Input: K = 3, N = 5, Arr[] = {3, 9, 12, 16, 20}
 * Output: 11
 * Explanation: The array can be modified as {6, 12, 9, 13,
 * 17}. The difference between the largest and the smallest is
 * 17-6 = 11.
 *
 * Your Task: You don't need to read input or print
 * anything. Your task is to complete the function getMinDiff()
 * which takes the arr[], n and k as input parameters and
 * returns an integer denoting the minimum difference.
 *
 * Expected Time Complexity: O(N*logN)
 * Expected Auxiliary Space: O(N)
 *////////////////////////////////////////////////// Driver Code
'use strict';
//
process.stdin.resume();
process.stdin.setEncoding( 'utf-8' );
//
let inputString = '';
let currentLine = 0;
//
process.stdin.on( 'data', inputStdin => { inputString += inputStdin; });
process.stdin.on( 'end', _ => {
    inputString = inputString.trim().split( '\n' ).map(
        string => { return string.trim(); });
    main();
});
function readLine() {
    return inputString[ currentLine++ ];
}
function main() {
    let t = parseInt( readLine());
    for( let i = 0; i < t; i++ ){
        let K = parseInt( readLine());
        let N = parseInt( readLine());
        let arr = new Array( N );
        let input_ar1 = readLine().split(' ').map( x => parseInt( x ));
        for( let i = 0; i < N; i++) arr[i] = input_ar1[i];
        let obj = new Solution();
        let res = obj.getMinDiff( arr, N, K );
        console.log( res );
    }
}
//////////////////////////////////////////////////// Driver Code
class Solution {
    getMinDiff( a, n, k ){
        if( n == 1) return 0;
        // sort the array
        a.sort(( x, y ) => {
            return( x - y );
        });
        // initialize the actors
        let i = 0;
        let j = n - 1;
        const basDif = a[j] - a[i];
        a[i] += k;
        a[j] -= k;
        // p,(q range):
        let p = Math.min( a[i], a[j]);
        let q = Math.max( a[i], a[j]);
        // Not possible to improve basDif:
        if( q - p >= basDif) return basDif;
        // do the loop
        i++, j--;
        while( i <= j ){
            // consider which i or j to take
            const leftPlus = a[i] + k;
            const leftMins = a[i] - k;
            if( leftPlus <= q || leftMins >= p ){ // take i
                i++;
                continue;
            }
            const rytePlus = a[j] + k;
            const ryteMins = a[j] - k;
            if( rytePlus <= q || ryteMins >= p ){ // take j
                j--;
                continue;
            }
            const leftDif = Math.min( leftPlus - q, p - leftMins );
            const ryteDif = Math.min( rytePlus - q, p - ryteMins );
            if( leftDif < ryteDif ){ // take i
                if( leftPlus - q < p - leftMins ){ // take plus
                    q = leftPlus;
                } else { // take minus
                    p = leftMins;
                }
            } else { // take j
                if( rytePlus - q < p - ryteMins ){ // take plus
                    q = rytePlus;
                } else { // take minus
                    p = ryteMins;
                }                
            }
        }
        return q - p < basDif ? q - p : basDif;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 34718 / 34718
// Total Time Taken:   0.74 / 2.58
////////////////////////////////////////////////////////////////
//
