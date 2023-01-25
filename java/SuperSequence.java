////////////////////////////////////////////////////////////////
//                                 Shortest Common Supersequence
////////////////////////////////////////////////////////////////
//                                                              
//          Given t                      g w       an          
//          e      w                     n  h     X d
//          h       o   nd Y o           i  i        
//          t          a      f          r  c    ,  Y
//                  s                    t   h   h   
//          f      t  X         leng     s      t   a
//          o     r                 t        h  o   s
//                i  s               h   t   a  b    
//          h      ng                s   s    s     i
//          t                            e          t
//          g                         m  l          s
//          n                            l           
//          e         ,               a  a          s
//          l       f  y              n  m          u
//           eht dni    levi         d   s          b
//                          t                        
//                           c      n                
//                            epser                  
//
//          S    E    Q    U    E    N    C    E    S.
//
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:                                     X = abcd, Y = xycd
// Output:                                                     6
// Explanation: Shortest Common Supersequence would be abxycd which
// is of length 6 and has both the strings as its subsequences.
////////////////////////////////////////////////////////////////
// Example:                                                    2
// Input:                                     X = efgh, Y = jghi
// Output:                                                     6
// Explanation: Shortest Common Supersequence would be ejfghi which
// is of length 6 and has both the strings as its subsequences.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O( Length( X ) * Length( Y ))
// Expected Auxiliary Space: O( Length( X ) * Length( Y ))
////////////////////////////////////////////////////////////////
// Constraints:
// 1 <= |X|,|Y| <= 100
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  200 / 200
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1006
// Total Time Taken:                                        0.26
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
import static java.lang.System.out;
////////////////////////////////////////////////////////////////
class Solution {
    private int[][] momory;
    private String X;
    private String Y;
    private int dp( int i, int j ){
        if( i < 0 ) return j + 1;
        if( j < 0 ) return i + 1;
        if( momory[ i ][ j ] > 0 ) return momory[ i ][ j ];
        if( X.charAt( i ) == Y.charAt( j )){
            momory[ i ][ j ] = 1 + dp( i - 1, j - 1 );
        } else {
            momory[ i ][ j ] = 1 + Math.min( dp( i - 1, j ),
                                             dp( i, j - 1 ));
        }
        return momory[ i ][ j ];
    }
    public int
        shortestCommonSupersequence( String X, String Y, int m, int n ){
        momory = new int[ m ][ n ];
        this.X = X;
        this.Y = Y;
        return dp( m - 1, n - 1 );
    }
    public static void main( String[] args ){
        String X = "efgh";
        String Y = "jghi";
        int m = X.length();
        int n = Y.length();
        
        out.println( new Solution().shortestCommonSupersequence( X, Y, m, n ));
    }
}
////////////////////////////////////////////////////////////////
