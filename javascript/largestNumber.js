////////////////////////////////////////////////////////////////
// Largest Number formed from an Array
////////////////////////////////////////////////////////////////
// Given a list of non negative integers, arrange them in such a
// manner that they form the largest number possible.The result
// is going to be very large, hence return the result in the
// form of a string.
////////////////////////////////////////////////////////////////
// Example 1:
// Input: 
// N = 5
// Arr[] = {3, 30, 34, 5, 9}
// Output: 9534330
// Explanation: Given numbers are {3, 30, 34, 5, 9}, the
// arrangement 9534330 gives the largest value.  Example 2:
// 
// Example 2:
// Input: 
// N = 4
// Arr[] = {54, 546, 548, 60}
// Output: 6054854654
// Explanation: Given numbers are {54, 546, 548, 60}, the
// arrangement 6054854654 gives the largest value.
// 
// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(1)
//
// Constraints:
// 1 ≤ N ≤ 10^5
// 0 ≤ Arr[i] ≤ 10^18
// Sum of all the elements of the array is greater than 0.
// 
////////////////////////////////////////////////////////////////
"use strict";
////////////////////////////////////////////////////////////////
process.stdin.resume();
process.stdin.setEncoding( "utf-8" );
////////////////////////////////////////////////////////////////
let inputString = "";
let currentLine = 0;
process.stdin.on( "data", inputStdin => {
    inputString += inputStdin;
});
process.stdin.on( "end", _ => {
    inputString = inputString
        .trim()
        .split( "\n" )
        .map( string => {
            return string.trim();
        });
    main();
});
function readLine() {
    return inputString[ currentLine++ ];
}
function main() {
    let t = parseInt( readLine());
    let i = 0;
    for(; i < t; i++ ){
        let n = parseInt( readLine());
        let arr = new Array( n );
        let input_ar1 = readLine().split( " " );
        for( let i = 0; i < n; i++ ) arr[i] = input_ar1[i];
        let obj = new Solution();
        let res = obj.printLargest( arr );
        console.log( res );
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 182 / 182
// Total Points Scored: 4 / 4
// Your Total Score: 790
// Total Time Taken: 0.51
// Your Accuracy: 100%
// Attempts No.: 1
//
// By looking at Example 2, was thinking this is just
// lexicographic sorting, that is "6" > "50", but Example 1
// shows that it's not exaclty that becoz "30" > "3", but
// "303" < "330", so it is lexicographic comparison on the
// concatenation!
class Solution{
    printLargest( a ){
        // Trying desperately to look cool, by chaining methods,
        // without big success!
        return a.map( y => y.toString())
                .sort(( a, b ) => {
                    if( a == b ) return 0;
                    if( a + b < b + a ) return 1;
                    return -1;
                })
                .join( '' );
    }
}
////////////////////////////////////////////////////////////////
