//` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` `/////////////////////////
///`Z`e`r`o` `S`u`m` `S`u`b`a`r`r`a`y`s`////////////////////////
////` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` `///////////////////////
/////` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` `//////////////////////
//////` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` `/////////////////////
// You are given an array arr[] of siz n. Find the totl count of
// sub-arrays having their sum equal to 0.
////////////////////////////////////////////////////////////////
// Example 1:
// Input: n = 6, arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are
// [0], [0], [0], [0], [0,0], and [0,0].
// 
// Example 2:
// Input: n = 10, arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4
// Explanation: The 4 subarrays are [-1 -3 4], [-2 2], 
// [2 4 6 -12], and [-1 -3 4 -2 2]
// 
// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)
// 
// Constraints:    
// 1<= n <= 10^7
// -10^10 <= arr[i] <= 10^10
////////////////////////////////////////////////////////////////
'use strict';
process.stdin.resume();
process.stdin.setEncoding('utf-8');
let inputString = '';
let currentLine = 0;
process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});
process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    main();    
});
function readLine() {
    return inputString[currentLine++];
}
////////////////////////////////////////////////////////////////
// t
// n
// a1 a2 .. an
function main() {
    let t = parseInt(readLine());
    for( let i = 0; i < t; i++ ){
        let input_line = readLine().split(' ');
        let n = parseInt(input_line[0]);
        let arr = new Array(n);
        input_line = readLine().split(' ');
        for( let i = 0; i < n; i++ ){
            arr[i] = parseInt(input_line[i]);
        }        
        let obj = new Solution();
        let ans = obj.findSubarray(arr, n)
        console.log(ans);
    }
}
////////////////////////////////////////////////////////////////
// I remember a similar problem, and there was a trick including
// a hash table so first we are going through the array and pick
// all sums and put them into table and than look again the sums
// and check if there is a corresponding entry in the hash table
// to cancel the current sum. Actually it turns out we can do it
// only with one pass.
class Solution {
    findSubarray( A, n ){
        let C = {}; // hash counter table
        let s = 0; // sum
        n = 0; // number of zero sub-arrays
        for( const y of A ){
            s += y;
            if( s in C ){
                // I had to do this trick here otherwise was
                // failing on the time limit.
                n += C[ s ]++;
            } else {
                C[ s ] = 1;
            }
            if( s == 0 ) n++;
        }
        return n;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 302 / 302
// Total Points Scored: 4 / 4
// Your Total Score: 794
// Total Time Taken: 0.98
// Your Accuracy: 33%
// Attempts No.: 3
////////////////////////////////////////////////////////////////
// log: -If you are self-respecting introvert, you must have, at
// least one; in-reserve vintovert!
//
// At job interview ..
// - Backend or Frontend???
// - Backend!!?
// - Why??!
// - Cos I'm introvert!!!
