////////////////////////////////////////////////////////////////
// Optimal Strategy For A Game
////////////////////////////////////////////////////////////////
// You are given an array arr of size n. The elements of the
// array represent n coin of values v1, v2, ....vn. You play
// against an opponent in an alternating way. In each turn, a
// player selects either the first or last coin from the row,
// removes it from the row permanently, and receives the value
// of the coin. You need to determine the maximum possible
// amount of money you can win if you go first
////////////////////////////////////////////////////////////////
// Input: n = 4, arr[] = {5, 3, 7, 10}
// Output: 15
////////////////////////////////////////////////////////////////
// Input: n = 4, arr[] = {8, 15, 3, 7}
// Output: 22
////////////////////////////////////////////////////////////////
// Expected Time Complexity : O(n*n)
// Expected Auxiliary Space: O(n*n)
////////////////////////////////////////////////////////////////
// 2 <= n <= 10^3
// 1 <= arr[i] <= 10^6
////////////////////////////////////////////////////////////////
# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
typedef long long long_t;
typedef vector <vector <long_t>> mat_t;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
private:
    int* a = NULL;
    mat_t cache_A;
    mat_t cache_B;
public:
    long_t player_A( int i, int j );
    long_t player_B( int i, int j );
    long_t maximumAmount( int n, int* a );
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
long_t Solution::player_A( int i, int j )
{
    if( i == j ) return a[ i ];
    if( cache_A[ i ][ j ]) return cache_A[ i ][ j ];
    long_t x = a[ i ] + player_B( i + 1, j );
    long_t y = a[ j ] + player_B( i, j - 1 );
    return cache_A[ i ][ j ] = max( x, y );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
long_t Solution::player_B( int i, int j )
{
    if( i == j ) return -a[ i ];
    if( cache_B[ i ][ j ]) return cache_B[ i ][ j ];
    long_t x = -a[ i ] + player_A( i + 1, j );
    long_t y = -a[ j ] + player_A( i, j - 1 );
    return cache_B[ i ][ j ] = min( x, y );
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
long_t Solution::maximumAmount( int n, int* a )
{
    this->a = a;
    cache_A = mat_t( n, vector <long_t> ( n ));
    cache_B = mat_t( n, vector <long_t> ( n ));
    return( player_A( 0, n - 1 ) + accumulate( a, a + n, 0 )) / 2;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){int t;cin>>t;while(t--){int n;cin>>n;int a[n];for(int
i=0;i<n;i++)cin>>a[i];Solution ob;cout<<ob.maximumAmount(n,a)<<
endl;}}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1115 / 1115
// Points Scored:                                          4 / 4
// Your Total Score:                                        1838 
// Time Taken:                                              0.17
