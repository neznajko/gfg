////////////////////////////////////////////////////////////////////////
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                           Matrix Chain Multiplication 
 *                [ Hard ] Accuracy: 59.72% Submissions: 28591 Points: 8
 *
 *mp Geeks Summer Carnival is LIVE NOW        Lamp Geeks Summer Carnival
 *
 * Given a sequence of matrices, find the most efficient way to multiply
 * these matrics togethr. The efficient way is the one that involves the
 * least number of multiplications.
 = = = = =   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
 * The dimensions of the matrices are given in an array; arr[] of size N
 * (such that N = number of matrices + 1), where the i-th matrix has the
 * dimensions (arr[i-1] x arr[i]).
 , , , . , . , , , . , . , , , . . , . . . . . , . , . , , . . , . , . ,
 = Example 1; Input: N = 5, arr = {40, 20, 30, 10, 30}
 +            Output: 26000
 > Explanatn: There are 4 matrices of dmensn 40x20, 20x30, 30x10, 10x30.
 _ Say the matrices are namd as A, B, C, D. Out of all posble combnatns,
 * the most efficient way is (A*(B*C))*D. The number of operations are -
 ` 20*30*10 + 40*20*10 + 40*10*30 = 26000.
 . * o . * o . * o . * o . * o . * o . * o . * o . * o . * o . * o . * o
 - Example 2; Input: N = 4, arr = {10, 30, 5, 60}
 ?            Output: 4500
 * Explaination: The matrices have dimensions 10*30, 30*5, 5*60. Say the
 % matrices are A, B and C. Out of all possible combos, the most efficnt
 * way is (A*B)*C. The number of multiplications are - 10*30*5 + 10*5*60
 = 4500.
 . Your Task: You do not need to take input or print anything. Your task
 * is to complte the functn matrixMultiplication() which takes the value
 - N and the array arr[] as input parametrs and returns the mnmum number 
 * of multiplication operations needed to be performed.
 =======================================================================
 , Expected Time Complexity: O(N^3)
 * Expected Auxiliary Space: O(N^2)
 -----------------------------------------------------------------------
 > Constraints: 2 ≤      N ≤ 100
                1 ≤ arr[i] ≤ 500
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
////////////////////////////////////////////////////////// > Driver Code
'use strict';
process.stdin.resume();
process.stdin.setEncoding( 'utf-8' );

let inputString = '';
let currentLine = 0;

process.stdin.on( 'data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on( 'end', _ => {
    inputString = inputString.trim().split('\n').map( string => {
        return string.trim();
    });
    main();    
});

function readLine() {
    return inputString[ currentLine++ ];
}

function main() {
    let t = parseInt( readLine() );
    let i = 0;
    for(; i < t; i++ ){
        let n = parseInt( readLine() );
        let arr = new Array( n );
        let input_ar1 = readLine().split(' ').map( x => parseInt( x ));
        for(let i = 0; i < n; i++ ){
            arr[ i ] = input_ar1[ i ];
        }
        let obj = new Solution();
        console.log( obj.matrixMultiplication( arr, n ));
    }
}
////////////////////////////////////////////////////////// < Driver Code
// -Becoz multiplication is binary operation, we eventually, that is for
// sure, will end up with a binary tree. The main question in DP is what
// are the sub-problems!? Here, if we look at the last operation it will
// split the matrices in two, in Exmple 1 the most efficient sequence is
// (A*(B*C))*D, that will correspond to the split (ABC) and D. So we can
// run through all possible splits and for each one we have two problems
// of the same type, but with reduced sizes. Than after solving all sub-
// problems for all splits, we can pick the one with minimum operations.
//
function cons( n ){
    return Array.from({ length: n }, y => Array.from({ length: n }));
}
// Test Cases Passed: 127 / 127
// Total Time Taken: 0.19/ 1
class Solution {    
    matrixMultiplication( arr, n ){
        this.cache = cons( n );            
        ////////////////////////////////////////////////////////////////
        this.d = arr; //                                      dimentions
        return this.dp( 1, n - 1 );
    }
    dp( i, j ){
        if( i == j ) return 0;
        if( this.cache[ i ][ j ] != undefined ){
            return this.cache[ i ][ j ];
        }
        ////////////////////////////////////////////////////////////////
        const d = this.d; //                                    shortcut
        let min = Infinity;
        for( let k = i; k < j; k++ ){
            const f = this.dp( i, k );
            const s = this.dp( k + 1, j );
            const c = f + s + d[ i - 1 ]*d[ k ]*d[ j ];
            if( c < min ) min = c;
        }
        this.cache[ i ][ j ] = min;
        return min;
    }
}
////////////////////////////////////////////////////////////////////////
//  3 4 5       - dp( i, j ), dp( 1, n - 1 )
//  (3,4)(4,5)  - d: 2 5 6 3 4
//   0 1  1 2   - A: (2,5)(5,6)(6,3)(3,4)
//                    0 1  1 2  2 3  3 4
//                      i         k    j
// d[i-1]*d[j]*d[k]
