////////////////////////////////////////////////////////////////
// Edit Distance
////////////////////////////////////////////////////////////////
// Given two strings s and t. Return the minimum number of
// operations required to convert s to t.
////////////////////////////////////////////////////////////////
// The possible operations are permitted:
// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other.
//////////////////////////////////////////////////////////////// 
// Example::::::1
// Input::::::::s = "geek", t = "gesek"
// Output:::::::1
// Explanation::One operation is required inserting 's' between
// two 'e's of str1.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(|s|*|t|)
// Expected Space Complexity: O(|s|*|t|)
///////////////////////////////////////////////[ Driver Code ]//
"use strict";
process.stdin.resume();
process.stdin.setEncoding("utf-8");
let inputString = "";
let currentLine = 0;
process.stdin.on("data", (inputStdin) => { 
    inputString += inputStdin; 
});
process.stdin.on("end", (_) => {
    inputString = inputString.trim().split("\n").map(
        (string) => { return string.trim(); });
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
        let input = readLine().split(" ");
        let s = input[0];
        let t = input[1];
        let obj = new Solution();
        let res = obj.editDistance(s, t);
        console.log(res);
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 80 / 80 There is no betr explanatn of this
// Total Points Scored: 4 / 4 problm from Dasgupta's book, but I
// Your Total Score: 854      couldn't remember the exact solutn
// Total Time Taken: 0.06     which was moving from ground up so
// Your Accuracy: 100%        contiuned with the top-down memory
// Attempts No.: 1            approach here.
////////////////////////////////////////////////////////////////
class Solution {
    // s: 0 1 2 .. m - 1 (i)
    // t: 0 1 2 .. n - 1 (j)
    dp( i, j ){
        // base cases
        if( i >= this.m )return this.n - j;
        if( j >= this.n )return this.m - i;
        // check memory
        if( this.mem[ i][ j] != undefined ){
            return this.mem[ i][ j];
        }
        // compare s[ i], t[ j]
        const comp = !( this.s[ i] == this.t[ j ]) + this.dp( i + 1, j + 1 );
        // continue with same s
        const cont = 1 + this.dp( i, j + 1 );
        // pass moving on t
        const pass = 1 + this.dp( i + 1, j );
        // et voilá
        this.mem[ i][ j] = Math.min( comp, cont, pass );
        return this.mem[ i][ j];
    }
    editDistance( s, t ){ //////////////////////////////////////
        this.s = s;
        this.t = t;
        this.m = s.length;
        this.n = t.length;
        this.mem = Array.from({ length: this.m },
                              () => Array( this.n ));
        return this.dp( 0, 0 );
    }
}
////////////////////////////////////////////////////////////////
// log:
