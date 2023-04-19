////////////////////////////////////////////////////////////////
// nCr
////////////////////////////////////////////////////////////////
// Given two integers n and r, find nCr. Since the answer may be 
// very large, calculate the answer modulo 10^9 + 7.
////////////////////////////////////////////////////////////////
// Example: 2
// Input: n = 2, r = 4
// Output: 0
// Explaination: r is greater than n.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n * r)
// Expected Auxiliary Space: O(r)
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    int nCr( int n, int r );
};
////////////////////////////////////////////////////////////////
int main() {
    cout << Solution().nCr( 15, 4 ) << endl;
}
////////////////////////////////////////////////////////////////
int Solution::nCr( int n, int r ){
    if( r > n ){ return 0; }
    vector<vector<int>> C( n + 1, vector<int>( n + 1 , 0 ));
    for( int i{}; i <= n; ++i ){
        C[ i ][ 0 ] = 1;
    }
    // 1 0 0 0 0    1 0 0 0 0
    // 1 0 0 0 0    1 1 0 0 0
    // 1 0 0 0 0 -> 1 2 1 0 0
    // 1 0 0 0 0    1 3 3 1 0
    // 1 0 0 0 0    1 4 6 4 1
    for( int i{ 1 }; i <= n; ++i ){
        for( int j{ 1 }; j <= n; ++j ){
            C[ i ][ j ] = C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ];
            C[ i ][ j ] %= 1000000007;
        }
    }
    return C[ n ][ r ];
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    40 / 40
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1090
// Total Time Taken:                                        0.15
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
