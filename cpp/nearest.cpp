////////////////////////////////////////////////////////////////
// Distance of nearest cell having 1
////////////////////////////////////////////////////////////////
// Givn a binary grid of n*m. Find the distance of the nearest 1
// in the grid for each cell.
// The distance is calculated as |i1 - i2| + |j1 - j2|, where i1,
// j1 are the row number and column number of the current cell, and
// i2, j2 are the row number and column number of the nearest cell
// having value 1.
////////////////////////////////////////////////////////////////
// Example:                                                    2
// Input:                       grid = {{1,0,1},{1,1,0},{1,0,0}}
// Output:                             {{0,1,0},{0,0,1},{0,1,2}}
// Explanation:                                      The grid is
//                                                         1 0 1
//                                                         1 1 0
//                                                         1 0 0
//     0's at (0,1), (1,2), (2,1) and (2,2) are at a distance of
//       1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1)
//                                                 respectively.
////////////////////////////////////////////////////////////////
// Yout Task: Have fun!
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ n, m ≤ 500
////////////////////////////////////////////////////////////////
//  
// 8 . . . . . . . . b1, b4, d4, g6
// 7 . . . . . . . .
// 6 . . . . . . 1 .
// 5 . . . . . . . .
// 4 . 1 . 1 . . . .
// 3 . . . . . . . .
// 2 . . . . . . . .
// 1 . 1 . . . . . .
//   a b c d e f g h
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <utility> // pair
# include <deque>
////////////////////////////////////////////////////////////////
using namespace std;
///////////////////////////////////////////////////////////////_
typedef vector <vector <int>> Grid;
typedef pair <int, int>       Pixel;
////////////////////////////////////////////////////////////////
class Solution {
public:
    Grid nearest( Grid& grid );
};
////////////////////////////////////////////////////////////////
# define LEFT( j ) ( j - 1 )
# define UP(   i ) ( i - 1 )
# define RYTE( j ) ( j + 1 )
# define DOWN( i ) ( i + 1 )
////////////////////////////////////////////////////////////////
Grid Solution::nearest( Grid& grid ){
    // 0 0 0 0 0
    // 0 0 1 0 1
    // 0 0 1 0 0
    // 0 1 0 0 1
    deque <Pixel> deq;
    const int n = grid.size();
    const int m = grid.front().size();
    for( int i = 0; i < n; ++i ){
        for( int j = 0; j < m; ++j ){
            if( grid[ i ][ j ]){
                deq.push_back({ i, j });
            }
            --grid[ i ][ j ];
        }
    }
    // -1 -1 -1 -1 -1
    // -1 -1  0 -1  0
    // -1 -1  0 -1 -1
    // -1  0 -1 -1  0
    while(! deq.empty()){
        auto [ i, j ] = deq.front();
        deq.pop_front();
        if( LEFT( j ) >= 0 and grid[ i ][ LEFT( j )] < 0 ){
            grid[ i ][ LEFT( j )] = grid[ i ][ j ] + 1;
            deq.push_back({ i, LEFT( j )});
        }
        if( UP( i ) >= 0 and grid[ UP( i )][ j ] < 0 ){
            grid[ UP( i )][ j ] = grid[ i ][ j ] + 1;
            deq.push_back({ UP( i ), j });
        }
        if( RYTE( j ) < m and grid[ i ][ RYTE( j )] < 0 ){
            grid[ i ][ RYTE( j )] = grid[ i ][ j ] + 1;
            deq.push_back({ i, RYTE( j )});
        }
        if( DOWN( i ) < n and grid[ DOWN( i )][ j ] < 0 ){
            grid[ DOWN( i )][ j ] = grid[ i ][ j ] + 1;
            deq.push_back({ DOWN( i ), j });
        }
    }
    return grid;
}
////////////////////////////////////////////////////////////////
int main() {
    Grid grid = {{ 0, 0, 0, 0, 0 },
                 { 0, 0, 1, 0, 1 },
                 { 0, 0, 1, 0, 0 },
                 { 0, 1, 0, 0, 1 }};
    auto answ = Solution().nearest( grid );
    for( const auto& row: answ ){
        for( int bit: row ){
            cout << bit << " ";
        }
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    90 / 90
// Total Points Scored:                                    4 / 4
// Your Total Score:                                         990
// Total Time Taken:                                        0.56
// Your Accuracy:                                            50%
// Attempts No.:                                               2
////////////////////////////////////////////////////////////////
