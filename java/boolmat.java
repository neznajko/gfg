////////////////////////////////////////////////////////////////
// Boolean Matrix                                               ////////
////////////////////////////////////////////////////////////////////////
// Medium Accuracy: 50.0% Submissions: 24186 Points: 4
////////////////////////////////////////////////////////////////////////
// Given a boolean matrix of size RxC, where each cell contains either 0
// or 1, modify it such that if a matrix cell [ i][ j] is 1 then all the
// cells in its ith row and jth column will become 1.
////////////////////////////////////////////////////////////////////////
// Example: Input: R = 4, C = 3 matrix[][] = {{ 1, 0, 0 }, Output: 1 1 1
// -,-,-,-, `````` ============ ************* { 1, 0, 0 }, ,.,.,., 1 1 1
// ,-,-,-,- `````` P = A = R = I * S ******** { 1, 0, 0 }, .,.,.,. 1 1 1
// -,-,-,-, `````` ============ ************* { 0, 0, 0 }} ,.,.,., 1 0 0 
// ,-,-,-,- `````` ============ ************************** .,.,.,.,.,.,.
////////////////////////////////////////////////////////////////////////
// Your Task:::: You dont need to read input or print anything. Complete
// the function booleanMatrix() that takes the matrix as input parameter
// and modifies it in-place.
////////////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(R * C) //////////////////////////////////
// Expected Auxiliary Space: O(R + C) //////////////////////////////////
////////////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ R, C ≤ 1000                                                 /////
// 0 ≤ matrix[ i ][ j ] ≤ 1                                        /////
import java.io.*; ////////////////////////////////////////////////////
class GFG {                                                        /// D
    public static void main( String[] args ) throws IOException {  /// R
        BufferedReader read = new BufferedReader(                  /// I
            new InputStreamReader( System.in ));                   /// V
        int t = Integer.parseInt( read.readLine() );               /// E
        while( t--> 0 ){                                           /// R
            String str[] = read.readLine().trim().split( "\\s+" ); ///
            int r = Integer.parseInt( str[ 0 ]);                   /////
            int c = Integer.parseInt( str[ 1 ]);                   /////
            int matrix[][] = new int[ r ][ c ];                    /////
            for( int i = 0; i < r; i++ ){                          /////
                int k = 0;                                         /////
                str = read.readLine().trim().split( "\\s+" );      /////
                for( int j = 0; j < c; j++ ){                      /////
                    matrix[ i ][ j ] = Integer.parseInt(str[ k ]); /////
                    k++;                                           /////
                }                                                  /////
            }                                                      /////
            new Solution().booleanMatrix( matrix );                /////
            StringBuilder sb = new StringBuilder();                /////
            for( int i = 0; i < r; i++ ){                          /////
                for( int j = 0; j < c; j++ ){                      /////
                    sb.append( matrix[ i ][ j ] + " " );           /////
                }                                                  /////
                sb.append( "\n" );                                 //   
            }                                                      // C 
            System.out.print( sb );                                //   
        }                                                          // O 
    }                                                              //   
}                                                                  // D 
/////////////////////////////////////////////////////////////////////   
// Test Cases Passed: 107 / 107                                       E
// Total Time Taken: 1.49 / 2.5
class Solution { ///////////////////////////////////////////////////////
    void booleanMatrix( int mat[][] ){      
        // Let's try brute force               ========
        int n = mat.length;      // rows       ===  ===
        int m = mat[ 0 ].length; // cols       ===oo===
        ///////////////////////////////////////===- ===/////////////////
        boolean[] proj_n = new boolean[ n ];   ///  ///          that[s]
        boolean[] proj_m = new boolean[ m ];                     
        ////////////////////////////////////////////////////////////////
        for( int i = 0; i < n; i++ ){ //////
            for( int j = 0; j < m; j++ ){ //
                if( mat[ i ][ j ] == 1 ){ //
                    proj_n[ i ] = true; ////
                    proj_m[ j ] = true; //// 
                    continue; //////////////    t h e   t  r  i  c  k
                }}} ////////////////////////////////////////////////////
        for( int i = 0; i < n; i++ ){                ///////////////////
            if( proj_n[ i ]) {                       ///////////////////
                for( int j = 0; j < m; j++ ){        ///////////////////
                    mat[ i ][ j ] = 1;               ///////////////////
                }}} ////////////////////////////////////////////////////
        for( int j = 0; j < m; j++ ){ //////////////// That[ s ]
            if( proj_m[ j ]) { ///////////////////////
                for( int i = 0; i < n; i++ ){ ////////
                    mat[ i ][ j ] = 1; ///////////////
                }}}}} ////////////////////////////////           The End
