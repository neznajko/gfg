////////////////////////////////////////////////////////////////
// W     o     r     d S       e       a       r       c       h
////////////////////////////////////////////////////////////////
// Given a 2D b o a r d of letters and a word. Check if the word 
// exists in the board. The word can be constructed from letters 
// of adjacent cells only, i.e. horizontal or vertical neighbors.
// The same l e t t e r cell can n o t be used more t h a n once.
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:          board = {{ a,g,b,c },{ q,e,e,l },{ g,b,k,s }},
//                                                word = "geeks"
// Output:                                                     1
// Explanation: The board is a g b c
//                           q e e l
//                           g b k s. The letters which are used
// to m   a   k   e the "g  e  e  k  s" are c o l o r e d.( Ok )
// Example:                                                    2
// Input:          board = {{ a,b,c,e },{ s,f,c,s },{ a,d,e,e }},
//                                                word = "sabfs"
// Output:                                                     0
// Explanation: The board is a b c e
//                           s f c s
//                           a d e e. S a m e letter can not b e 
// u    s    e    d twice h     e     n     c     e ans i    s 0.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O( N * M * len( word ))
// Expected Space Compelxity: O( len( word ))
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    int n{};
    int m{};
    int level{};
    int lastLevel{};
    string word;
    vector<vector<char>> board;
////////////////////////////////////////////////////////////////
    // m a r k/unmark b o a r d letter( v e r t e x ) as visited
    void check( int i, int j ){
        board[ i ][ j ] = -board[ i ][ j ];
    }
    void enter( int i, int j ){
        check( i, j );
        level++;
    }
    void exit( int i, int j ){
        check( i, j );
        level--;
    }
    void dfs( int i, int j );
public:
    bool isWordExist( vector<vector<char>>& board,
                      string& word );
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board( n, vector<char>( m ));
    for( int i{}; i < n; i++ ){
        for( int j{}; j < m; j++ ){
            cin >> board[ i ][ j ];
        }
    }
    string word;
    cin >> word;
    bool ans{ Solution().isWordExist( board, word )};
    cout << ans << endl;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
bool Solution::isWordExist( vector<vector<char>>& board,
                            string& word ){
    n = ( int )board.size();
    m = ( int )board[ 0 ].size();
    level = -1;
    lastLevel = ( int )word.length() - 1;
    this->word = move( word );
    this->board = move( board );
    for( int i{}; i < n; i++ ){
        for( int j{}; j < m; j++ ){
            if( this->board[ i ][ j ] == this->word[ 0 ]){
                try {
                    dfs( i, j );
                } catch( ... ){
                    return true;
                }
            }
        }
    }
    return false;
}
////////////////////////////////////////////////////////////////
void Solution::dfs( int i, int j ){
    enter( i, j );
    if( level == lastLevel ){
        throw( "check this out..." );
    }
    char key{ word[ level + 1 ]};
    // NORTH
    if( i > 0 ){
        if( board[ i - 1 ][ j ] == key ){
            dfs( i - 1, j );
        }
    }
    // EAST
    if( j < m - 1 ){
        if( board[ i ][ j + 1 ] == key ){
            dfs( i, j + 1 );
        }
    }
    // SOUTH
    if( i < n - 1 ){
        if( board[ i + 1 ][ j ] == key ){
            dfs( i + 1, j );
        }
    }
    // WEST
    if( j > 0 ){
        if( board[ i ][ j - 1 ] == key ){
            dfs( i, j - 1 );
        }
    }
    exit( i, j );
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  412 / 412
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1070
// Total Time Taken:                                        0.04
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
