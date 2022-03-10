////////////////////////////////////////////////////////////////
/* Find the number of islands 
 * Medium Accuracy: 38.66% Submissions: 100k+ Points: 4
 * Given a grid of size n*m (n is number of rows and m is number
 * of columns grid has) consisting of '0's (Water) and
 * '1's (Land). Find the number of islands.
 * Note: An island is surrounded by water and is formed by
 * connecting adjacent lands horizontally or vertically or
 * diagonally i.e., in all 8 directions.
 * 
 * Example 1:
 * Input:
 * grid = {{0,1},{1,0},{1,1},{1,0}}
 * Output:
 * 1
 * Explanation:
 * The grid is
 * 0 1
 * 1 0
 * 1 1
 * 1 0
 * All lands are connected.
 * Example 2:
 * 
 * Input:
 * grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
 * Output:
 * 2
 * Expanation:
 * The grid is
 * 0 1 1 1 0 0 0
 * 0 0 1 1 0 1 0 
 * There are two islands one is colored in blue 
 * and other in orange.
 * 
 * Your Task:
 * You don't need to read or print anything. Your task is to
 * complete the function numIslands() which takes grid as input
 * parameter and returns the total number of islands.
 * 
 * Expected Time Compelxity: O(n*m)
 * Expected Space Compelxity: O(n*m)
 * 
 * Constraints:
 * 1 ≤ n, m ≤ 500
 *//////////////////////////////////////////////////////////////
# include <stdio.h>
////////////////////////////////////////////////////////////////
# define COL 501
////////////////////////////////////////////////////////////////
int( *map)[ COL];
int _n;
int _m;
enum{ WATER, LAND, VISITED};
////////////////////////////////////////////////////////////////
int explore( int i, int j) {
    map[ i][ j] = VISITED;
    for( int di = -1; di < 2; di++) {
        for( int dj = -1; dj < 2; dj++) {
            int i1 = i + di;
            int j1 = j + dj;
            if( i1 < 0 || i1 == _n) continue;
            if( j1 < 0 || j1 == _m) continue;
            if( map[ i1][ j1] == LAND) {
                explore( i1, j1);
            }
        }
    }
}
////////////////////////////////////////////////////////////////
int countIslands( int M[][ COL], int n, int m) {
    map = M;
    _n = n;
    _m = m;
    int cc = 0;
    for( int i = 0; i < n; i++) {
        for( int j = 0; j < m; j++) {
            if( map[ i][ j] == LAND) {
                explore( i, j);
                cc++;
            }
        }
    }
    return cc;
}
////////////////////////////////////////////////////////////////
int main() {
    int t;
    scanf( "%d", &t);
    while( t--) {
        int n, m;
        scanf( "%d %d", &n, &m);
        int M[ n][ COL];
        for( int i = 0; i < n; i++) {
            for( int j = 0; j < m; j++) {
                scanf( "%d", &M[ i][ j]);
            }
        }
        int ans = countIslands( M, n, m);
        printf( "%d\n", ans);
    }
}
////////////////////////////////////////////////////////////////
// log: To the President of the Russian Federation:
// -Look pal I know you've been following my log:, yesterday you
// have bombarded a hospital with moms and newborn babies, you
// have destroyed not only the homes, but the lives of millions
// innocent people, you have isolated Russia from the West and
// put at risk your partnership with China, there is no way
// getting victorious from that situation. I know what is to be
// hated from The Whole World, and the path for you getting out
// of that situation is very narrow, but still exist; if the
// plan is to multiply that hell in every town until all Ukraine
// is in flames, and you acknowledge your mistakes here and stop
// the World and the History might still forgive you. Enough is
// enough, take Crimea and the two Republics and leave Ukraine
// alone, they have proved themselves as the bravest nation the
// World has ever witness and deserve their sovereign.
//
// To the leaders of the West and NATO:
// -You are no good even for 4en 3a 3e7e.
//
// Test Cases Passed: 26 / 26
// Total Time Taken: 0.0 / 1.1
////////////////////////////////////////////////////////////////
