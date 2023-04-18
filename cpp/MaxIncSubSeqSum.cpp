////////////////////////////////////////////////////////////////
// Maximum sum increasing subsequence
////////////////////////////////////////////////////////////////
// Given an array of n positive integers. Find the sum of the 
// maximum sum subsequence of the given array such that the 
// integers in the subsequence are sorted in strictly increasing 
// order i.e. a strictly increasing subsequence!
////////////////////////////////////////////////////////////////
// Example: 1
// Input: N = 5, arr[] = { 1, 101, 2, 3, 100 }
// Output: 106
// Explanation: The maximum sum of a increasing sequence is 
// obtained from { 1, 2, 3, 100 }
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N^2)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  210 / 210
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1086
// Total Time Taken:                                        0.26
// Your Accuracy:                                            50%
// Attempts No.:                                               2
////////////////////////////////////////////////////////////////
class MaxIncSubSeqSum {
    int * a{ nullptr };
    int n{};
    vector<vector<int>> cache;
public:
    MaxIncSubSeqSum( int * a, int n ):
        a{ a },
        n{ n },
        cache{ n, vector<int>( n + 1, 0 )}
    {}
    int dp( int j, int m );
};
////////////////////////////////////////////////////////////////
int MaxIncSubSeqSum::dp( int j, int m ){
    if( j < 0 ) return 0;
    if( cache[ j ][ m ]) return cache[ j ][ m ];
    int skp{ dp( j - 1, m )};
    int taike{};
    if( m == n or a[ j ] < a[ m ]){
        taike = a[ j ] + dp( j - 1, j );
    }
    return cache[ j ][ m ] = max( skp, taike );
}
////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSumIS( int * a, int n ){
        return MaxIncSubSeqSum( a, n ).dp( n - 1, n );
    }
};
////////////////////////////////////////////////////////////////
# define __sizf( a ) sizeof a / sizeof *a
////////////////////////////////////////////////////////////////
int main() {
    int a[]{ 1, 101, 2, 3, 4, 5, 6, 100 };
    cout << Solution().maxSumIS( a, __sizf( a )) << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
