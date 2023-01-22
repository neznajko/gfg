////////////////////////////////////////////////////////////////
// Split Array Largest Sum -------------------------------------
//  plit  rray  argest  um -------------------------------------
// - lit - ray - rgest - m -------------------------------------
// -- it -- ay -- gest -----------------------------------------
// --- t --- y --- est -----------------------------------------
// ________________ st _________________________________________
// ----------------- t ------------------------------- n -------
// -------------------------------------------------- e a ----- o
// G ----------------------------------------- t --- v   r --- t
//  i --------------------------------------- i t - i     r - n
//   v - n ------- ] ----------------------- l   h g       a i
//    e a a ----- [ o N --------------- r - p     e         y
//     n   r --- r   f e ------------- e K S
//          r - r       l ----------- b   .
//           a a         e --------- m
// K          y           m ------- u
// K subarrays             e --- d n
// K subarrays such         n - n a
// K subarrays such that     t a
// K subarrays such that the  s
// K subarrays such that the maximum 
// K subarrays such that the maximum subarray 
// K subarrays such that the maximum subarray sum 
// K subarrays such that the maximum subarray sum achievable 
// K subarrays such that the maximum subarray sum achievable out
// o
// f K s                             e . F i n d t
///////u                             l///////////h
///////b                             b///////////a
///////a                             i///////////t p o s s i b l e
///////r                             s///////////////////////////s
///////r                             s///////////////////////////u
///////a                             o///////////////////////////b
///////y             s m i n i m u m p///////////////////////////a
///////s f o r m e d i///////////////////////////////////////////r
/////////////////////////////////////////////////////////////////r
/////////////////////////////////////////////////////////////////a
/////////////////////////////////////////////////////////. m u s y
// Example:                                                    1
// Input:                                           N = 4, K = 3
//                                          arr[] = {1, 2, 3, 4}
// Output:                                                     4
// Explanation:   Optimal Split is {1, 2}, {3}, {4}. Maximum sum
// of all subarrays is 4, which is minimum possible for 3 splits.
////////////////////////////////////////////////////////////////
// Example:                                                    2
// Input:                                           N = 3, K = 2
//                                               A[] = {1, 1, 2}
// Output:                                                     2
// Explanation:  Splitting the array as {1,1} and {2} is optimal.
//                   This results in a maximum sum subarray of 2.
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ N ≤ 10^5
// 1 ≤ K ≤ N
// 1 ≤ arr[i] ≤ 10^4
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N*log(sum(arr)))
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
# include <iostream>
# include <algorithm> // max_element
# include <numeric>   // accumulate
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    int splitArray( int a[], int n, int k );
};
////////////////////////////////////////////////////////////////
// max( a[] ) -------------_------------------------- sum( a[] )
//                        mid
// Hint
// 
// To check, if mid is possible?,
// maximum; subarray ..      sum!
//
// Maintain a count! of subarrays"
// include all possible elements in
// subarray,! until              ..
// their sum is less than mid.
//
// After this evaluation,!?; if the
// count, is less than or equal to K?
// then mid is achievable,' else not.,
//
// Find:,! the minimum possible value of,
// mid; which satisfies the condition..
//
////////////////////////////////////////////////////////////////
// - Write a function that takes as input a sorted array a, its
// size n, and a value mid in the range [ max(a[]), sum(a[]) ],
// that conforms to the second couplet of Hint.
// - Who are you talking to?
////////////////////////////////////////////////////////////////
// Basically here, I've misunderstood the problem, becoz is there
// a standard definition of sub array? is [ 5, 7 ] sub array of
// [ 1, 2, 5, 6, 7, 8 ]? I thought yea, and went for a solution
// vith sorting and linked lists:), but here they mean consecutive
// values, vhich doesn't require fancy stuff..
int get_nf_splits( int* a, int n, int m ){
    int nf_splits{ 1 };
    int backup{ m };
    for( int j = n - 1; j >= 0; --j ){
        if( a[ j ] > m ){
            m = backup - a[ j ];
            ++nf_splits;
        } else {
            m -= a[ j ];
        }
    }
    return nf_splits;
}
int Solution::splitArray( int a[], int n, int k ){
    int u{ accumulate( a, a + n, 0 )};
    int l{ *max_element( a, a + n )};
    while( l <= u ){
        int m{( l + u )/ 2 };
        int c{ get_nf_splits( a, n, m )};
        if( c > k ){
            l = m + 1;
        } else {
            u = m - 1;
        }
    }
    return l; 
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  122 / 122
// Total Points Scored:                                    8 / 8
// Your Total Score:                                        1002
// Total Time Taken:                                        0.11
// Your Accuracy:                                            33%
// Attempts No.:                                               3
////////////////////////////////////////////////////////////////
int main() {
    int a[] = { 10, 2, 33, 14, 5, 1, 7, 18 };
    const int n = sizeof a / sizeof *a,
              k = 3;
    cout << Solution().splitArray( a, n, k ) << endl;
}
////////////////////////////////////////////////////////////////
//
//
