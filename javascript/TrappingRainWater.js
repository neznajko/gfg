#!/usr/bin/env                                              node
////////////////////////////////////////////////////////////////
/* Trapping _ Rain - Water ` * * * * * * * * * * * * * * * * * *
 * Medium, Accuracy: 49.62[%]; Submissions: 100k+, Points: 4
 * Lamp{ This problem is part of GFG SDE Sheet. }
 *       Click « here » to view more.  
****************************************************************
 * Givn an array a[] of N non negative integers representing the
 * heght of blocks. If width of each blck is 1, compute how much
 * water can be trapped between the blcks durng the rainy season. 
 * 
 * Example: 1
 * Input: N = 6, a[] = {3,0,0,2,0,4}
 * Output: 10
 * Explanation: 
 *           |
 * |~~~~~~~~~|
 * |~~~~~|~~~|
 * |~~~~~|~~~|
 * ` ` ` ` ` `
 * 3 0 0 2 0 4
****************************************************************
 * Your Task: You don't need to read input or print anythng. The
 * tsk is to cmplete the function trappingWater() wich takes a[]
 * and N as input parametrs and retrns the total amount of water
 * that can be trapped.
****************************************************************
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(N)
================================================================
 - Constraints:
 - 3 < N < 10^6
 - 0 < A[i] < 10^8
***************************************************************/
// > /////////////////////////////////////////////// Driver Code
'use strict';process.stdin.resume();process.stdin.setEncoding('utf-8');
let inputString='';let currentLine=0;process.stdin.on('data',
inputStdin=>{inputString+=inputStdin;});process.stdin.on('end',
_=>{inputString=inputString.trim().split('\n').map(string=>{
return string.trim();});main();});function readLine(){
return inputString[currentLine++];}function main(){let t=
parseInt(readLine());let i=0;for(;i<t;i++){let n=parseInt(readLine());
let arr=new Array(n);let input_ar1=readLine().split(' ').map(x=>parseInt(x));
for(let i=0;i<n;i++)arr[i]=input_ar1[i];let obj=new Solution();
console.log(obj.trappingWater(arr,n));}}
////////////////////////////////////////////////////////////////
function Gateway( left, ryte=-1 ){
    this.left = left;
    this.ryte = ryte;
}
function getGateways( a, n ){
// l 1) pop left gates
// o
// o 2) push left gates
// p
    // [0] Prepare for the journey
    let j = 1;
    let stk = []; // left gates stack
    let gateway = [];
    label:
    while( true ){ // The loop
        // popping
        // fst can't be ryte, last can be
        for(;;++j ){
            // compare j - 1 and j
            if( j == n )break label;
            if( a[j - 1] > a[ j ]){
                // j - 1 is a left gate
                j--;
                break;
            } else if( a[j - 1] == a[ j ]){
                continue; // do nofing
            } else {
                // j is a ryte gate
                let lastGate;
                while( stk.length > 0 ){
                    lastGate = stk[ stk.length - 1 ];
                    if( a[ lastGate.left ] < a[j] ){
                        stk.pop();
                    } else {
                        break;
                    }
                }
                if( lastGate != undefined ){
                    lastGate.ryte = j;
                    if( stk.length == 0 ){
                        gateway.push( lastGate );
                    }
                }
            }
        }
        // pushing
        for(;;++j){
            // compare j and j + 1
            if( j == n - 1 )break label;
            if( a[j] >= a[j + 1] ){
                stk.push( new Gateway( j ));
            } else {
                // j + 1 is a ryte gate
                j += 1;
                break;
            }
        }
    }
    gateway.push( ...stk );
    return gateway;    
}
function getWater( a, left, ryte ){
    const h = Math.min( a[ left ], a[ ryte ]);
    let sum = 0;
    for( let j = left + 1; j < ryte; j++ ){
        sum += a[j];
    }
    return h*(ryte - left - 1) - sum;
}
function rainWater( a, n ){
    let water = 0;
    for( const gateway of getGateways( a, n )){
        if( gateway.ryte != -1 ){
            water += getWater( a, gateway.left, gateway.ryte );
        }
    }
    return water;
}
class Solution {
    trappingWater( a, n ){
        return rainWater( a, n );
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 152 / 152
// Total Time Taken: 0.29 / 1.43
//
// 6189279543 This problm is nice, but the code is messy and not
//            the very best posbl:) The lgic is the same as with
//    |~~|    similar problems for example are strings of parens 
//   ||~~|    balanced etc. and it uses stacks as auxiliary data 
//   ||~||    structres. If a[j] > a[j + 1], then a[j] is called
// |~||~||    left gate, cos it can hold water from the lft side,
// |~||~|||   and if a[j - 1] < a[j], a[j] is the ryte gate.
// |~||~||||  {SPOILER} So basicly ve loop over a[], and push to
// |~||~||||| the stk left gates, and pop them vhen reachng ryte
// |~|||||||| gate, etc.
// ||||||||||
// ( )(  )
////////////////////////////////////////////////////////////////
