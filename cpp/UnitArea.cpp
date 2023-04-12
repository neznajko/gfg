////////////////////////////////////////////////////////////////
// Unit               of                           region of 1's
// :::: A   r   e   a :: l   a   r   g   e   s   t :::::: :: :::
// .... -   -   -   - .. _   _   _   _   _   _   _ ...... .. ...
// Given a grid     dimension nxm containing 0s and 1s. Find the
// ::::: : :::: o f ::::::::: ::: :::::::::: :: ::: ::: :::: :::
// ..... . .... - - ......... ... .......... .. ... ... .... ...
// unit            of       largest                       of 1s.
// :::: a  r  e  a :: t h e ::::::: r   e   g   i   o   n :: :::
// .... _  _  _  _ .. - - - ....... _   _   _   _   _   _ .. ...
// Region of 1's is a           of 1's connected 8-directionally 
// :::::: :: ::: :: : g r o u p :: ::: ::::::::: ::::::::::::::: 
// ...... .. ... .. . - - - - - .. ... ......... ...............
// (                                  , vertically, diagonally).
// :h  o  r  i  z  o  n  t  a  l  l  y: ::::::::::: ::::::::::::
// .-  -  -  -  -  -  -  -  -  -  -  -. ........... ............
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input: grid = {{         1,         1,         1,         0},
//                {         0,         0,         1,         0},
//                {         0,         0,         0,         1}}
// Output:                                                     5
// Explanation:                                             nope
////////////////////////////////////////////////////////////////
// E  x  p  e  c  t  e  d Time Complexity: O   (   n   *   m   )
// Expected A   u   x   i   l   i   a   r   y Space: O ( n * m )
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
    int n{};
    int m{};
    int unitArea{};
    vector<vector<int>> grid;
    void dfs( int i, int j );
public:
    int findMaxArea( vector<vector<int>>& grid );
};
////////////////////////////////////////////////////////////////
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid( n, vector<int>( m, -1 ));
    for( int i{}; i < n; i++ ){
        for( int j{}; j < m; j++ ){
            cin >> grid[ i ][ j ];
        }
    }
    cout << Solution().findMaxArea( grid ) << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    97 / 97
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1074
// Total Time Taken:                                        0.32
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
void Solution::dfs( int i, int j ){
    this->grid[ i ][ j ] = -1;
    this->unitArea++;
    for( int di{ -1 }; di <= 1; di++ ){
        for( int dj{ -1 }; dj <= 1; dj++ ){
            int u{ i + di };
            int v{ j + dj };
            if( u < 0 or u >= n or
                v < 0 or v >= m ){
                continue;
            }
            if( this->grid[ u ][ v ] == 1 ){
                dfs( u, v );
            }
        }
    }
}
////////////////////////////////////////////////////////////////
int Solution::findMaxArea( vector<vector<int>>& grid ){
    n = (int) grid.size();
    m = (int) grid[ 0 ].size();
    this->grid = move( grid );
    int maxUnitArea{};
    for( int i{}; i < n; i++ ){
        for( int j{}; j < m; j++ ){
            if( this->grid[ i ][ j ] == 1 ){
                unitArea = 0;
                dfs( i, j );
                maxUnitArea = max( maxUnitArea, unitArea );
            }
        }
    }
    return maxUnitArea;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
