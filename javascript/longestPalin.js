////////////////////////////////////////////////////////////////
// Longest Palindrome in a String
////////////////////////////////////////////////////////////////
// Given a string S, find the longst palindromic substring in S.
// Substring of string S: S[ i ... j ] where 0 ≤ i ≤ j < len(S).
// Palindrme string: A strng which reads the same backwrds. More
// frmally, S is palndrome if revrse(S) = S. Incase of conflict,
// return the substrng which occrs first (with the least startng
// index).
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(|S|^2)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ |S| ≤ 10^3
////////////////////////////////////////////////////////////////
"use strict";
////////////////////////////////////////////////////////////////
process.stdin.resume();
process.stdin.setEncoding("utf-8");
let inputString = "";
let currentLine = 0;
process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});
process.stdin.on("end", (_) => {
    inputString = inputString
        .trim()
        .split("\n")
        .map((string) => {
            return string.trim();
        });
    main();
});
////////////////////////////////////////////////////////////////
function readLine() {
    return inputString[currentLine++];
}
////////////////////////////////////////////////////////////////
function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let S = readLine().trim();    
        let obj = new Solution();
        let res = obj.longestPalin(S);
        console.log(res);
    }
}
////////////////////////////////////////////////////////////////
// [0] - palin position
// [1] - its length
// return the one with larger length, if are same return the one
// with lower position
const LEN = 1;
const POS = 0;
function maxpalin( a, b ){
    if( a[LEN] == b[LEN] ){
        return a[POS] < b[POS] ? a : b;
    }
    return a[LEN] > b[LEN] ? a : b;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 173 / 173 I even didn't bothr trying figre
// Total Points Scored: 4 / 4   what the trick's here, just went
// Your Total Score: 846        for the classical dp approach.
// Total Time Taken: 0.68
// Your Accuracy: 100%
// Attempts No.: 1
////////////////////////////////////////////////////////////////
class Solution {
    // return [starting position, lenght] of longest palin,
    // vithin [i, j] range
    dp( i, j) {
        // base cases
        if( i == j ) return [ i, 1];
        if( i >  j ) return [-1, 0];
        // check if it's in the memory
        if( this.memory[i][j] != undefined ){
            return this.memory[i][j];
        }
        // A) s[i] = s[j]?
        let A = [ -1, 0 ]; // use it as a return result
        if( this.s[i] == this.s[j]) {
            A = this.dp( i + 1, j - 1);
            // check if s[i..j] is palindrome
            if( A[LEN] == j - i - 1 ){
                this.memory[i][j] = [ i, j - i + 1 ];
                return this.memory[i][j];
            }
        }
        // B) Discard ith element
        let B = this.dp( i + 1, j);
        // update A
        A = maxpalin( A, B );
        // C) Discard jth element
        let C = this.dp( i, j - 1 );
        // update A one last time
        A = maxpalin( A, C );
        // save to memory and gerout
        this.memory[i][j] = A;
        return A;
    }
    longestPalin( s) {
        // n - length of the input string ::s
        const n = s.length;
        // save input string as field
        this.s = s;
        // keep soleved sub-problems here:
        this.memory = Array.from({ length: n }, () => Array( n));
        // get longest palin starting position and length
        const [ j, len] = this.dp( 0, n - 1);
        // et voilá
        return s.substring( j, j + len);
    }
}
////////////////////////////////////////////////////////////////
// log:
