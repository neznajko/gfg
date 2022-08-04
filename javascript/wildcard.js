                              ////
////////////////////////////////////////////////////////////////
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
 ** Wildcard Pattern Matching
 ** Given two strings 'str' and a wildcard pattern 'pattern' of
 ** length N and M respectively, You have to print '1' if the
 ** wildcard pattern is matched with str else print '0'.
 ** The wildcard pattern can include the characters ‘?’ and ‘*’
 ** ‘?’ – matches any single character
 ** ‘*’ – Matches any sequence of characters (including the
 **       empty sequence)
 ** Note: The matching should cover the entire str (not partial
 ** str).
 ** Example 1:
 ** Input:
 ** pattern = "ba*a?"
 ** str = "baaabab"
 ** Output: 1
 ** Explanation: replace '*' with "aab" and 
 ** '?' with 'b'. 
 ** Example 2:
 ** Input:
 ** pattern = "a*ab"
 ** str = "baaabab"
 ** Output: 0
 ** Explanation: Because of'a' at first position,
 ** pattern and str can't be matched. 
 ** 
////////////////////////////////////////////////////////////////
 ** Your Task:
 ** You don't need to read input or print anything. Your task is
 ** to complete the function wildCard() which takes the two
 ** strings 'pattern' and 'str' as input parameters and returns
 ** the answer.
Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)
***************************************************************/
"use strict";
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
function readLine() {
    return inputString[currentLine++];
}
function printArray(arr, size) {
    let i;
    let s = "";
    for (i = 0; i < size; i++) {
        s += arr[i] + " ";
    }
    console.log(s);
}
function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let pattern = readLine();
        let str = readLine();
        let obj = new Solution();
        let res = obj.wildCard(pattern,str);
        console.log(res);
    }
}
////////////////////////////////////////////////////////////////
var n;    // =|
var m;    // ='
var tab;  // >o
var pat;  // ;@
var stng; // :/

function wcard( i, j) {
    if( i == n + 1) {                 //        out
        return ( j == m + 1) ? 1 : 0; //         of
    } else if( j == m + 1) return 0;  // boundaries
    if( tab[ i][ j] != undefined) return tab[ i][ j];
    var rezlt;
    switch( pat[ i]) {
    case '?':
        rezlt = wcard( i + 1, j + 1);
        break;
    case '*':
        if( wcard( i + 1, j)) rezlt = 1;
        else rezlt = wcard( i, j + 1); 
        break;
    default:
        if( pat[ i] == stng[ j]){
            rezlt = wcard( i + 1, j + 1);
        } else rezlt = 0;
        break;
    }
    tab[ i][ j] = rezlt;
    return rezlt;
}
////////////////////////////////////////////////////////////////
class Solution {
    wildCard( pattern, str ){
        n = pattern.length;
        m = str.length;
        pat = pattern + '?';
        stng = str + '?'; /** guards */
        tab = Array.from({ length: n + 1},
                         x => Array.from({ length: m + 1}));
        return wcard( 0, 0 );
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 181 /181
// Total Time Taken: 0.12
////////////////////////////////////////////////////////////////
// log: -My life is already ruined, and don't know what you want
// to achieve more, I guess you want to finish me off with joke?
// After more than 8 years of non stop hate, you can hardly make
// me a scratch. I really don't care about you, and if you don't
// mind continue without me I will pretend you are not existing.
