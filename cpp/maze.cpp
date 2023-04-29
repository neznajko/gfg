////////////////////////////////////////////////////////////////
// Rat in a Maze Problem - I
////////////////////////////////////////////////////////////////
// Consider a rat placed at (0,0) in a square matrix of order 
// N*N. It has to reach the destination at (N-1,N-1). Find all 
// possible paths that the rat can take to reach from source to 
// destination. The directions in which the rat can move are 
// 'U' (up), 'D' (down), 'L' (left), 'R' (right). Value 0 at a 
// cell in the matrix represents that it is blocked and rat 
// cannot move to it while value 1 at a cell in the matrix 
// represents that rat can be travel through it.
////////////////////////////////////////////////////////////////
// Note: In a path, no cell can be visited more than one time.
// If the source cell is 0, the rat cannot move to any other 
// cell.
////////////////////////////////////////////////////////////////
// Example: 1
////////////////////////////////////////////////////////////////
// Input: N = 4
//        m[][] = {{1, 0, 0, 0},
//                 {1, 1, 0, 1},
//                 {1, 1, 0, 0},
//                 {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR
// Explanation: nop
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L*X), L = length of the path, 
// X = number of paths.
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
    static constexpr int NFDR{ 4 }; // number of directions
    static constexpr int GRD{ 2 }; // guard
    vector<string> pathList; // output
    string path{ "T" }; // dropped from the top initially
    vector<int> maze; // 32-bit flat model( with protection )
    int n{}; // maze's width, height
    vector<int> dr{ NFDR }; // URDL directions displacement
    int goal{}; // target offset
    void Dfs( int src );
    void Debug() const;
    void Flatten( const vector<vector<int>>& m );
public:
    vector<string> findPath( vector<vector<int>>& m, int n );
};
////////////////////////////////////////////////////////////////
void Solution::Flatten( const vector<vector<int>>& m ){
    const vector<int> grd( n, GRD );
    maze.insert( maze.end(), grd.begin(), grd.end());
    for( const auto& row: m ){
        maze.push_back( GRD );
        maze.insert( maze.end(), row.begin(), row.end());
        maze.push_back( GRD );
    }
    maze.insert( maze.end(), grd.begin(), grd.end());
}
vector<string> Solution::findPath
( vector<vector<int>>& m, int n ){
    if( m[ 0 ][ 0 ] == 0 ){
        return {};
    }
//  @Override
    m[ n - 1 ][ n - 1 ] = 1;
    this->n = n + 2; // protection enabled
    // One advantage of using flat array than 2D is that moving
    // up down, etc. requires only one instead of two operations.
    dr = { -this->n, 1, this->n, -1 };
    maze.reserve( this->n * this->n );
    Flatten( m );
    goal = ( int )maze.size() - this->n - 2;
    Debug();
    Dfs( this->n + 1 );
    return pathList;
}
void Solution::Dfs( int src ){
    if( src == goal ){
        pathList.push_back
        ( string( path.begin() + 1, path.end()));
    } else {
        maze[ src ] = GRD;
        for( int j{}; j < NFDR; ++j ){
            int dst{ src + dr[ j ]};
            if( maze[ dst ] == 1 ){
                path.push_back( "URDL"[ j ]);
                Dfs( dst );
            }
        }
        maze[ src ] = 1;
    }
    path.pop_back();
}
void Solution::Debug() const {
    cout << goal << endl;
    for( int j{}; j < maze.size(); ++j ){
        cout << maze[ j ] << " ";
        if(( j + 1 ) % n == 0 ){
            cout << endl;
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 1          6     2/ 1         6    2
// Total Points Scored:                          4/          4
// Your Total Score:       1              0  9              8
// Total Time Taken:               0 . 0               1
//////////////////////////////|///////////////|///////////////|/
// T           h i          s |    i        s |       t   h e |
///////////////|///////////////////|/////////////|//////////////
// n        th |   t  i         me |    I  '   m |  so l  v in g
////////////////////////|//////////////////////////////|////////
// s  i m     i l    ar |  p            r o b   le   m |
////////////////////////////////////////////////////////////////
int main(){
    int n;
    cin >> n;
    vector<vector<int>> m( n, vector<int>( n, 0 ));
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            cin >> m[ i ][ j ];
        }
    }
    Solution obj;
    vector<string> result = obj.findPath( m, n );
    sort( result.begin(), result.end());
    if( result.size() == 0 ){
        cout << -1;
    } else {
        for( int i = 0; i < result.size(); i++ ){ 
            cout << result[i] << " ";
        }
    }
}
////////////////////////////////////////////////////////////////