////////////////////////////////////////////////////////////////
// Longest consecutive subsequence 
////////////////////////////////////////////////////////////////
// Medium Accuracy: 48.9% Submissions: 100k+ Points: 4
////////////////////////////////////////////////////////////////
// Given an array of positive integers. Find the length of the
// longest sub-sequence such that elements in the subsequence
// are consecutive integers, the consecutive numbers can be in
// any order.
////////////////////////////////////////////////////////////////
// Example 1:
// Input:
// N = 7
// a[] = {2,6,1,9,4,5,3}
// Output:
// 6
// Explanation:
// The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6
// numbers form the longest consecutive subsquence.
//
// Example 2:
// 
// Input:
// N = 7
// a[] = {1,9,3,10,4,20,2}
// Output:
// 4
// Explanation:
// 1, 2, 3, 4 is the longest consecutive subsequence.
////////////////////////////////////////////////////////////////
// Your Task:
// You don't need to read input or print anything. Your task is
// to complete the function findLongestConseqSubseq() which
// takes the array arr[] and the size of the array as inputs and
// returns the length of the longest subsequence of consecutive
// integers.
// 
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
// 
// Constraints:
// 1 <= N <= 10^5
// 0 <= a[i] <= 10^5
// 
////////////////////////////////////////////////////////////////
# include <iostream>
# include <set>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
struct Solution {
    int findLongestConseqSubseq( int arr[], int N );
};
////////////////////////////////////////////////////////////////
int main() {
    int t, n, i, a[ 100001 ]; cin >> t; while( t-- ){
        cin >> n; for( i = 0; i < n; i++ ){ cin >> a[i]; }
        Solution obj;
        cout << obj.findLongestConseqSubseq( a, n ) << endl;
    }
}
////////////////////////////////////////////////////////////////
int Solution::findLongestConseqSubseq( int arr[], int N ){
// Test Cases Passed: 131 / 131
// Total Time Taken: 0.47 / 2.7
    set<int> s( arr, arr + N );
    auto it = s.end();
    --it;
    int maxsubseq = 0;
    do{
        int subseq = 1;
        while( it != s.begin()){
            if( *it - 1 != *(--it)) break;
            subseq++;
        }
        if( subseq > maxsubseq ) maxsubseq = subseq;
    } while( it != s.begin());
    return maxsubseq;
}
////////////////////////////////////////////////////////////////
// log: -I'm drawing only for myself.
