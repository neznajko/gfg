                            ////////
///////////////////////////////////////////////////////////////=
// Median of 2 Sorted Arrays of Different Sizes
////////////////////////////////////////////////////////////////
// Given two sorted arrays array1 and array2 of size m and n 
// respectively. Find the median of the two sorted arrays.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       m = 3, n = 4
//              array1[] = {1,5,9}
//              array2[] = {2,3,6,7}
// Output:      5
// Explanation: The middle element for {1,2,3,5,6,7,9} is 5
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(min(log n, log m)).
// Expected Auxiliary Space: O((n+m)/2).
////////////////////////////////////////////////////////////////
// Constraints: 
// 0 ≤ m,n ≤ 10^4
// 1 ≤ array1[i], array2[i] ≤ 10^5
////////////////////////////////////////////////////////////////
function main() {
    console.log(( new Solution()).MedianOfArrays(
        [1,2,5,7],
        [3,6,8,9]
    ));
} // 1 2 3 5 6 7 8 9
////////////////////////////////////////////////////////////____
////////////////////////////////////////////////////////////////
// Test Cases Passed: 333 / 333 Median is statistics term and if
// Total Points Scored: 8 / 8   we fire the ends of sorted array
// Your Total Score: 894        they'll meet vhere the median is
// Total Time Taken: 0.17       so by using the Two Pointers, we 
// Your Accuracy: 100%          can solve that one quite easily,
// Attempts No.: 1              despite it's labeled hard.
////////////////////////////////////////////////////////////////
function median( a, i, j ){
    for(; i < j; i++, j--){
    }
    return ( a[i] + a[j] )/2;
}
////////////////////////////////////////////////////////////////
class Solution {
    // s(i,u) t(j,v)
    MedianOfArrays( s, t ){
        let i = 0, u = s.length - 1;
        let j = 0, v = t.length - 1;
        while( true ){
            if( i == u && j == v ) return( s[i] + t[j] )/2;
            if( i > u ) return median( t, j, v );
            if( j > v ) return median( s, i, u );
            if( s[i] < t[j] ) i++;
            else              j++;
            if( s[u] > t[v] ) u--;
            else              v--;
        }
    }
}
////////////////////////////////////////////////////////////////
// log:
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
////                                                        ////
