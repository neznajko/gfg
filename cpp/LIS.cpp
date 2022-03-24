////////////////////////////////////////////////////////////////
// Longest Increasing Subsequence 
// Medium Accuracy: 46.69% Submissions: 66145 Points: 4
//
// Given an array of integers, find the length of the longest
// (strictly) increasing subsequence from the given array.
// 
// Example 1:
// Input:
// N = 16
// A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output: 6
// Explanation:Longest increasing subsequence
// 0 2 6 9 13 15, which has length 6
//
// Example 2:
// Input:
// N = 6
// A[] = {5,8,3,7,9,1}
// Output: 3
// Explanation:Longest increasing subsequence
// 5 7 9, with length 3
//
// Your Task: Complete the function longestSubsequence() which
// takes the input array and its size as input parameters and
// returns the length of the longest increasing subsequence.
// 
// Expected Time Complexity : O(Nlog(N))
// Expected Auxiliary Space: O(N)
// 
// Constraints:
// 1 ≤ N ≤ 10^5
// 0 ≤ A[i] ≤ 10^6
//
// Hint: Create an array of N length where ith value will be the
// last value for a subsequence of length (i+1).
// 
// Iterate over the array, use binary search to find best
// indexes to place new elements in the dp array.
/////////////////////////////////////////////////< Driver Code >
# include <iostream>
# include <vector>
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
private:
    vector<int> seq;
    int binsrch( int y);
public:
    int longestSubsequence( int n, int* a);
};
// Test Cases Passed: 111 / 111
// Total Time Taken:  0.0 / 1.2
////////////////////////////////////////////////////////////////
int main() {
    int t, n;
    cin >> t;
    while( t--) {
        cin >> n;
        int a[ n];
        for( int i = 0; i < n; i++) {
            cin >> a[ i];
        }
        Solution ob;
        cout << ob.longestSubsequence( n, a) << endl;
    }
}
////////////////////////////////////////////////</ Driver code >
// In Dasgupta et al. book, this problem is solved for O(n^2),
// which also requres additional graph to be constructed, again
// for O(n^2). This solution( look at Hint:) is quite amaizing,
// cos it solves the problem for O(nlog(n)).
int Solution::binsrch( int y) {
// return fst j: seq[ j] <= y
    int lo{ 0 };
    int hi = seq.size() - 1;
    while( lo < hi) {
        int mi{( lo + hi) >> 1};
        if( seq[ mi] < y) {
            lo = mi + 1;
        } else if( seq[ mi] == y) {
            return mi;
        } else {
            hi = mi;
        }
    }
    return hi;
}
int Solution::longestSubsequence( int n, int* a) {
    if( n == 0) return 0; // guarantee a[ 0] exists
    seq.push_back( a[ 0]);
    for( int j = 1; j < n; j++) {
        if( a[ j] > seq.back()) {
            seq.push_back( a[ j]); // longer sub seq found
        } else { // update seq if there is no duplicate
            int i{ binsrch( a[ j]) };
            seq[ i] = a[ j];
            // Now the optimal increasing sub seq of length
            // (i + 1) is seq[ 0], ..., seq[ i]
        }
    }
    return seq.size();
}
////////////////////////////////////////////////////////////////
