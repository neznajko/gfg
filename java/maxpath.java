////////////////////////////////////////////////////////////////
////    ----,,,,````    ____////''''====____>>>>    ::::    ////
//  4   8   12  16  20  24  28  32  36  40  44  48  52  56  60  64
//  |   |   |   |   |   |   |   |           |   |   |   |   "   |
//  Maximum path|   sum in  matrix          |   |   |   |   |   |
//  |   |   |   |   |   |   |   |           |   |   '   |   |   |
//  Medium  Accuracy:   50.83%  Submissions:|   37200   Points: 4
//  |   |   |   |   |       |   |           |   |   |   |   '   |
//  Given   a   NxN matrix  of  positive    integers.   There   are
//  |   '   |       |           '           |   "   '       |
//  only    three   possible    moves   from|   a   cell    Matrix[r][c].
//  |   |                                   |
//  Matrix[r+1][c]                          |
//      |                                   |
//      Matrix[r+1][c-1]                    |
//                                          |
//                                          Matrix[r+1][c+1]
////____````,,,,>>>>    ````    ,,,,>>>>    ____````,,,,====////
//  4   8   12  16  20  24  28  32  36  40  44  48  52  56  60  64
//  '   '   '   '   "   '   '   "   '   '   '   '       '   '
//  Starting'   from"   any column  in  row 0   return  the largest
//  '   '   '   '   "   "       '   '   "   "
//  sum of  any of  the paths   up  to  row N-1.
////////////////////////////////////////////////////////////////
//
//  Example: Input: N = 2, Matrix = {{348, 391},{618, 193}}
//  Output: 1009, Explaination: The best path is 391 -> 618. 
//  It gives the sum = 1009.
//
////////////////////////////////////////////////////////////////
////----////----////----////----////----////----////----////----
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Your Task:
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_
// You do not need to read input or print anything. Your task is
// =============================================================
// to complete the function maximumPath() which takes the size N
// _____________________________________________________________
// and the Matrix as input parameters and returns the highest 
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// maximum path sum.
////////////////////////////////////////////////////////////////
// 
// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)
// 
////////////////////////////////////////////////////////////////
// Constraints:            /////////////////////////////////////
// 1 ≤ N ≤ 500             /////////////////////////////////////
// 1 ≤ Matrix[i][j] ≤ 1000 /////////////////////////////////////
////////////////////////////////////////////////////////////////
import java.io.*;
import java.util.Arrays;
import java.util.stream.IntStream;
////////////////////////////////////////////////////////////////
class GFG {
    public static void main( String args[]) throws IOException {
        // If you want to impress your colleagues, toss by the
        // way that BufferedReader is a Decorator!!!( Head First )
        BufferedReader in = new BufferedReader
            ( new InputStreamReader( System.in ));
        int t = Integer.parseInt( in.readLine() );
        while( t-- > 0 ){
            int N = Integer.parseInt( in.readLine() );
            String input_line[] = in.readLine().trim().split( "\\s+" );
            int Matrix[][] = new int[N][N];
            for( int i = 0; i < N*N; i++ ){ // multiplication here?!!
                Matrix[i/N][i%N] = Integer.parseInt( input_line[i] );
            }
            Solution ob = new Solution();
            System.out.println( ob.maximumPath( N, Matrix ));
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:   233 / 233
// Total Points Scored: 4 / 4
// Your Total Score:    758
// Total Time Taken:    0.85
// Your Accuracy:       50%
// Attempts No.:        2
////////////////////////////////////////////////////////////////
//     0   1   2   3   j
//   +---+---+---+---+    
// 0 | s | s | s |   |    
//   +---+---+---+---+    
// 1 |   | d |   |   |    
//   +---+---+---+---+    
// 2 |   |   |   |   |    
//   +---+---+---+---+
// 3 |   |   |   |   |
//   +---+---+---+---+
// i
class Solution {
    int n;
    int m[][];
    //
    int getmax( int i, int j ){
        int g   = i - 1; // (g, h) -> (i, j)
        int h   = j - 1; // maximum valued position
        int end = j + 2; // j - 1, j, j + 1
        for(; j < end; j++ ){
            if( m[g][j] > m[g][h] ) h = j;
        }
        return h;
    }
    // 0 1 1 1 1 0
    // 0 1 1 1 1 0 i
    // 0 1 1 1 1 0 i
    // 0 1 1 1 1 0 i
    //   j j j j
    void dp() {
        for( int i = 1; i < n; i++ ){
            int g = i - 1;
            for( int j = 1; j <= n; j++ ){
                int h = getmax( i, j );
                m[i][j] += m[g][h];
            }
        }
    }
    int maximumPath( int n, int mat[][] ){
        // Add two guards per row.
        m = new int[n][n + 2];
        for( int i = 0; i < n; i++ ){
            System.arraycopy( mat[i], 0, m[i], 1, n );
        }
        this.n = n;
        //
        dp();
        return Arrays.stream( m[n - 1] ).max().getAsInt();
    }
}
////////////////////////////////////////////////////////////////
// log: -The answer of the question when the ego is bad and when
// the ego is good is the same with the answer of; when fighting
// is good and when fighting is bad? The ego is good, when it is
// an unique, a contrast, part of the whole, the ego is bad when
// it want the whole to be like itself like in China Russia etc.
// Fighting is good when it tries to preserve the uniqueness the
// identity of the ego, because the whole is stable only when it
// is created by the harmony of the contrasts.
