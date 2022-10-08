////////////////////////////////////////////////////////////////
// Interleaved Strings
////////////////////////////////////////////////////////////////
// Given strings A, B, and C, find whether C is formed by an
// interleaving of A and B.
////////////////////////////////////////////////////////////////
// An interleaving of two strings S and T is a configuration
// such that it creates a new string Y from the concatenation
// substrings of A and B and |Y| = |A + B| = |C|
// 
// For example:
// 
// A = "XYZ"
// 
// B = "ABC"
// 
// so we can make multiple interleaving string Y like, XYZABC,
// XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to
// check whether you can create a string Y which can be equal to
// C.
// 
// Specifically, you just need to create substrings of string A
// and create substrings B and concatenate them and check
// whether it is equal to C or not.
// 
// Note: a + b is the concatenation of strings a and b.
// 
// Return true if C is formed by an interleaving of A and B,
// else return false.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       A = YX, B = X, C = XXY
// Output:      0
// Explanation: XXY is not interleaving of YX and X
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N * M)
// Expected Auxiliary Space: O(N * M)
// here, N = length of A, and M = length of B
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ length of A, B ≤ 100
// 1 ≤ length of C ≤ 200
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////[ Driver Code ]//
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
function printArray(res, n) {
    for(let i=0;i<n;i++){
        console.log(res[i]);
    }
}
function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let s = readLine().split(' ');
        let A = s[0];
        let B = s[1];
        let C = s[2];
        let obj = new Solution();
        let res = obj.isInterleave(A, B, C);
        if(res === true){
            console.log(1);
        }
        else{
            console.log(0);
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 403 / 403                              o_o
// Total Points Scored: 4 / 4
// Your Total Score: 858
// Total Time Taken: 0.05
// Your Accuracy: 50%
// Attempts No.: 2
////////////////////////////////////////////////////////////////
class Solution {
    // a: 0 1 2 .. m - 1 ( i)
    // b: 0 1 2 .. n - 1 ( j)
    dp( i, j ){
        // c's offset
        const k = i + j;
        // base cases
        if( i >= this.m ){
            return this.c.substr( k) == this.b.substr( j);
        }
        if( j >= this.n ){
            return this.c.substr( k) == this.a.substr( i);
        }
        // check memory
        if( this.mem[ i][ j] != undefined )return this.mem[ i][ j];
        // what is this?
        let answ = false;
        // a) a[ i] = b[ j] = c[ k]
        if( this.a[ i] == this.b[ j] && this.b[ j] == this.c[ k] ){
            // take a[ i ]
            if( this.dp( i + 1, j )){
                answ = true;
            } else { // take b[ j ]
                answ = this.dp( i, j + 1 );
            }
        }
        // b) a[ i] = c[ k]
        else if( this.a[ i] == this.c[ k ]){
            answ = this.dp( i + 1, j );
        }
        // c) b[ j] = c[ k]
        else if( this.b[ j] == this.c[ k ]){
            answ = this.dp( i, j + 1 );
        }
        this.mem[ i][ j] = answ;
        return answ;
    }
    isInterleave( a, b, c ){
        this.a = a;
        this.b = b;
        this.c = c;
        this.m = a.length;
        this.n = b.length;
        // This is the 4th dp problem in a row, I didn't expect
        // it and went for a dfs solution, and couldn't get out
        // from the fyorst test case, vhich was something like:
        // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        // AAAAAAAAAAAB AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAC AAAAAA
        // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAAA
        // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB.
        this.mem = Array.from({ length: this.m },
                              () => Array( this.n ));
        return this.dp( 0, 0 );
    }
}
////////////////////////////////////////////////////////////////
// log:
