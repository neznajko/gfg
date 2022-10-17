                            ////////
///////////////////////////////////////////////////////////////=
// Jump Game
////////////////////////////////////////////////////////////////
// Given an positive integer N and a list of N integers A[]. Each
// element in the array denotes the maximum length of jump you can 
// cover. Find out if you can make it to the last index if you start
// at the first index of the list.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       N = 6
//              A[] = {1, 2, 0, 3, 0, 0} 
// Output:      1
// Explanation: Jump 1 step from first index to second index. Then
// jump 2 steps to reach 4th index, and now jump 2 steps to reach
// the end.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 <= N    <= 10^5
// 0 <= A[i] <= 10^5
////////////////////////////////////////////////////////////////
function main() {
    console.log(( new Solution()).canReach(
        [ 1, 2, 0, 0 ], 4
    ));
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 1022 / 1022 That's an easy one.
// Total Points Scored: 4 / 4     I've decided to try
// Your Total Score: 882          not including The Driver Code,
// Total Time Taken: 0.22         only the solution and the test
// Your Accuracy: 100%            input, for those who were secretly
// Attempts No.: 1                running this code, excuse moi.
///////////////////////////////////////////////////////////////_
function check( a, j ){
    if( j == 0 )return true;
    for( let i = j - 1; i >= 0; i-- ){
        if( a[ i ] >= j - i )return check( a, i );
    }
    return false;
}
class Solution {
    canReach( a, n ){
        if( a[ 0 ] == 0 )return false;
        return check( a, n - 1 );
    }
}
////////////////////////////////////////////////////////////////
// log:
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
////                                                        ////
