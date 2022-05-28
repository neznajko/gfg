#! /usr/bin/env                                             node
// #############################################################
// Minimum number of jumps
// -------------------------------------------------------------
// Medium Accuracy: 32.96% Submissions: 100k+ Points: 4
// =============================================================
// Given an array of N integers arr[] where each element
// represents the max number of steps that can be made forward
// from that element. Find the minimum number of jumps to reach
// the end of the array (starting from the first element). If an
// element is 0, then you cannot move through that element.
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Note: Return -1 if you can't reach the end of the array. 
// .............................................................
// Example: 1
// Input: N = 11, arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: First jump from 1st element to 2nd element with
// value 3. Now, from here we jump to 5th element with value 9, 
// and from here we will jump to last. 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Your task:
// You don't need to read input or print anything. Your task is
// to complete function minJumps() which takes the array arr and
// it's size N as input parameters and returns the minimum
// number of jumps. If not possible returns -1.
// ,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,`,
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)
//////////////////////////////////////////////////// Driver Code
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
        let n = parseInt(readLine()); 
        let arr = new Array(n);
        let inputArr2 = readLine().split(" ").map((x) => parseInt(x));
        for(let j = 0;j < n;j++){
            arr[j] = inputArr2[j];
        }
        let obj = new Solution();
        let res = obj.minJumps(arr,n);
        console.log(res);
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 141 / 141
// Total Time Taken: 0.27 / 19.14
////////////////////////////////////////////////////////////////
// Looking at the Total Time Taken one can say, what a fantastic
// algorithm, but the problem has a tag Dynamic Programming, and
// usually these algorithms have O(N^2) complexity or something.
// Surprisingly this one can be solved for O(N), but I could not
// found it and came with thus algorithm which practically looks
// Ok( fantastic ) but in worst case scenario should behave like
// O(N^2). It does not use additional space, but it modifies the
// jump array, so the O(1) doesn't count as well:)
// By the way if you are walking on a rope and suddenly wind has
// blown up you lost your balance and fall, what was the reason?
// What is true for people is true for countries as well, if you
// put yourself in an unstable situation sooner or later you are
// going to fall.
class Solution {
    minJumps( a, n){
        if( a[0] == 0 ){
            if( n == 1 ) return 0;
            return -1;
        }
        const goal = n - 1;
        const nil = -1;
        a[goal] = nil;
        for( let j = goal - 1; j > -1; j-- ){
            if( a[j] == 0 ) continue;
            const range = j + a[j];
            let target = goal;
            for(;;) { // Ok
                if( range >= target ){
                    a[target] = j;
                    a[j] = nil;
                    break;
                } else {
                    if( a[target] == nil ){
                        break;
                    } else {
                        target = a[target];
                    }
                }
            }
        }
        if( a[0] != nil ) return nil;
        n = 0;
        for( let j = goal; a[j] > -1; j = a[j] ){
            n++;
        }
        if( n == 0 ) n = -1;
        return n;
    }
}
////////////////////////////////////////////////////////////////
