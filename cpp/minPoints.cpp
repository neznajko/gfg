                          ////
////////////////////////////////////////////////////////
/* Minimum Points To Reach Destination 
 * Hard Accuracy: 51.27% Submissions: 2803 Points: 8
 * Given a grid of size M*N with each cell consisting of 
 * an integr which represents points. We can move across
 * a cell only if we have positve points. Whenevr we pas 
 * thrgh a cel, points in that cel are addd to our ovral 
 * points, the task is to find minimum initial points to 
 * reach cel (m-1,n-1) from (0,0) by folowng these crtan
 * set of rules:
 *
 * 1. From a cel (i,j) we can mov to (i+1,j) or (i,j+1).
 * 2. We can't move from (i,j) if your overall points at 
 *    (i,j) are <= 0.
 * 3. We have to reach at (n-1,m-1) with minimum postive
 *    points i.e., > 0.
 *
 * Example 1:
 * Input: M = 3, N = 3 
 * arr[][] = {{-2, -3, 3}, 
 *            {-5,-10, 1}, 
 *            {10, 30,-5}}; 
 *
 * Output: 7
 * Explnatn: 7 is the minmm value to reach the destnaton
 * with positive throughout the path. Below is the path.
 * (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2)
 * We strt frm (0,0) with 7, we reach (0,1) wit 5, (0,2)
 * with 2, (1,2) with 5, (2,2) with and finally we hav 1
 * point (we needed greater than 0 points at the end).
 *
 * Example 2: Input: M = 3, N = 2
 * arr[][] = {{2,  3}, 
 *            {5, 10}, 
 *            {10,30}}; 
 * Output: 1
 * Explanation: Take any path, all of them are positive.
 * So, required one point at the start
 * 
 * Your Task:  
 * You don't ned to read nput or prnt anything. Complete
 * the functn minPoints() which takes N,M and 2-d vector
 * as input parameters and returns the integer value.
 *
 * Expected Time Complexity: O(N*M)
 * Expected Auxiliary Space: O(N*M)
////////////////////////////////////////////////////////
 *******************************************************
 * Hint: Create a 2D dp matrix, where dp[i][j] will give
 * minimum points needed to reach end, if (i, j) was the
 * start.
 */
////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm> // etc.
# include <sstream>   // stringstream
# include <iomanip>   // setw
using namespace std;
////////////////////////////////////////////////////////
# define vec vector
# define endl '\n'
////////////////////////////////////////////////////////
void dmp( const vec<vec<int>>& p) {
    const int m = p.size();
    const int n = p[0].size();
    for( int i = 0; i < m; i++) {
        stringstream ss;
        for( int j = 0; j < n; j++) {
            ss << setw( 4) << p[i][j] << " ";
        }
        cout << ss.str() << endl;
    }
    cout << endl;
}
////////////////////////////////////////////////////////
# define HR(i,j) p[i][j]   // here
# define DW(i,j) p[i+1][j] // down
# define RY(i,j) p[i][j+1] // ryte
class Solution {
public:
	int minPoints( vec<vec<int>>& p, int m, int n);
};
# define UPDATE( src, dst) {                    \
        const int diff = dst - src;             \
        if( diff < 0) src = 0;                  \
        else src = diff;                        \
    }
int Solution::minPoints( vec<vec<int>>& p, int m, int n)
{
    const int bcol{ n - 1};
    const int brow{ m - 1}; // backstaf
    UPDATE( HR( brow, bcol), 0);
    int i, j;
    // Back Col
    j = bcol;
    for( i = brow - 1; i > -1; i--) {
        UPDATE( HR( i, j), DW( i, j));
    }
    // Botm Row
    i = brow;
    for( j = bcol - 1; j > -1; j--) {
        UPDATE( HR( i, j), RY( i, j));
    }
    // athr staf_
    for( i = brow - 1; i > -1; i--) {
        for( j = bcol - 1; j > -1; j--) {
            int down{ HR( i, j)};
            int ryte{ down};
            UPDATE( down, DW( i, j));
            UPDATE( ryte, RY( i, j));
            HR( i, j) = min( down, ryte);
        }
    }
    return 1 + HR( 0, 0);
}
//////////////////////////////////////////// Driver Code
int main() {
    int t;
    cin >> t;
    while( t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a( m, vector<int>( n));
        for( int i = 0; i < m; i++) {
        	for( int j = 0; j < n; j++) {
        		cin >> a[ i][ j];
            }
        }
	    Solution ob;
	    cout << ob.minPoints( a, m, n) << endl;
    }
    return 0;
}
////////////////////////////////////////////////////////
// log: Test Cases Passed: 210 / 210
//      Total Time Taken:  0.5 / 3.4
//  - Initially was thinking that Dynamic Programming is
//  like finding Fibonacci nmbrs only, but it's not like
//  this, bcoz here there are two thngs to cnsidr namely
//  totl los and mximm los dring path and it's imposible
//  to fgre which fctor to prefr untl the end is reachd.
//  And basically, the hint solves the problem.
////////////////////////////////////////////////////////
////                                                ////
