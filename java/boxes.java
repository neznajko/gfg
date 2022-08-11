////////////////////////////////////////////////////////////////
// Box Stacking
// Medium Accuracy: 48.37% Submissions: 27134 Points: 4
////////////////////////////////////////////////////////////////
// You are given a set of N types of rectangular 3-D boxes, where
// the ith box has height h, width w and length l. You task is to
// create a stack of boxes which is as tall as possible, but you
// can only stack a box on top of another box if the dimensions
// of the 2-D base of the lower box are each strictly larger than
// those of the 2-D base of the higher box. Of course, you can rotate
// a box so that any side functions as its base. It is also allowable
// to use multiple instances of the same type of box. You task is
// to complete the function maxHeight which returns the height of
// the highest possible stack so formed.
////////////////////////////////////////////////////////////////
// Note: 
// Base of the lower box should be strictly larger than that of
// the new box we're going to place. This is in terms of both length
// and width, not just in terms of area. So, two boxes with same
// base cannot be placed one over the other.
////////////////////////////////////////////////////////////////
// Example 1:
// Infut:
// n = 4
// height[] = {4,1,4,10}
// width[] = {6,2,5,12}
// length[] = {7,3,6,32}
// Output: 60
// Explanation: One way of placing the boxes is as follows in the
// bottom to top manner: (Denoting the boxes in (l, w, h) manner)
// (12, 32, 10) (10, 12, 32) (6, 7, 4) (5, 6, 4) (4, 5, 6) (2, 3, 1)
// (1, 2, 3) Hence, the total height of this stack is
// 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
// No other combination of boxes produces a height greater than
// this.
////////////////////////////////////////////////////////////////
// Your Task:
// You don't need to read input or print anything. Your task is
// to complete the function maxHeight() which takes three arrays
// height[], width[], length[], and N as a number of boxes and
// returns the highest possible stack height which could be formed.
//
// Expected Time Complexity : O(N*N)
// Expected Auxiliary Space: O(N)
// 
// Constraints:
// 1 <= N <= 100
// 1 <= l,w,h <= 100
////////////////////////////////////////////////////////////////
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
////////////////////////////////////////////////////////////////
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
////////////////////////////////////////////////////////////////
import static java.lang.System.out;
////////////////////////////////////////////////////////////////
//                   d | r | i | v | e ' r |   | c | o : d | e 
////////////////////////////////////////////////////////////////
class GFG {
public static void main(String[] args) throws IOException {
    var br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine().trim());
    while(T-- > 0){
        int n = Integer.parseInt(br.readLine().trim());
        String[] s1 = br.readLine().trim().split(" ");
        int[] height = new int[n];
        for( int i = 0; i < n; i++ ){
            height[i] = Integer.parseInt(s1[i]);
}
        String[] s2 = br.readLine().trim().split(" ");
        int[] width = new int[n];
        for(int i = 0; i < n; i++){
            width[i] = Integer.parseInt(s2[i]);
}
        String[] s3 = br.readLine().trim().split(" ");
        int[] length = new int[n];
        for(int i = 0; i < n; i++){
            length[i] = Integer.parseInt(s3[i]);
}
        Solution obj = new Solution();
        System.out.println(obj.maxHeight(height, width, length, n));
}}}
////////////////////////////////////////////////////////////////
class Box implements Comparable<Box> { // for sorting
    static final int _3 = 3;
    static final int MAXSIZ = 101;
    int d[]; // another dmnsn
    //
    Box( int h, int w, int l ){
    ////////////////////////////////////////////////////////////
        d = new int[]{ h, w, l };
    }
    int height() {
        return d[0];
    }
    int width() {
        return d[1];
    }
    int length() {
        return d[2];
    }
    Integer area() {
        return width()*length();
    }
    Box rotate() { // 0, 1, 2 -> 2, 0, 1
        return new Box( d[2], d[0], d[1] );
    }
    void normalize() {
        if( width() < length() ){
            int t = d[1]; d[1] = d[2]; d[2] = t;
        }
    }
    boolean AceOfBase( final Box box ){ // make the check
        return( width( ) > box.width( ) &&
                length() > box.length());
    }
    @Override
    public int compareTo( Box box ) {
        return box.area().compareTo( area() ); // reverse
    }
    @Override
    public String toString() {
        return String.format( "[%d %d %d]",
                              height(),
                              width(),
                              length() );
    }
    public static void main( String[] args ){
        Box box = new Box( 3, 2, 5 );
        out.println( box );
        box.normalize();
        out.println( box );
    }
}
////////////////////////////////////////////////////////////////
class Solution {
    static final Box base = new Box( 0, Box.MAXSIZ, Box.MAXSIZ );
    //
    int n;
    ArrayList<Box> boxs = new ArrayList<>();
    int memory[][];
    //
    void sort() {
        Collections.sort( boxs );
        boxs.forEach( box -> box.normalize() );
    }
    Solution() {};
    Solution( int[] height, int[] width, int[] length, int n ){
        boxs.add( base );
        for( int j = 0; j < n; j++ ){
            Box box = new Box( height[j], width[j], length[j] );
            for( int k = 0; k < Box._3; k++ ){
                box = box.rotate();
                boxs.add( box );
            }
        }
        this.n = boxs.size();
        memory = new int[ this.n ][ this.n ];
        sort();
    }
    int f( int i, int j ){ // the dp function( Dynamic Programming )
        if( j == n ) return 0;
        if( memory[i][j] == 0 ){
            Box bot = boxs.get( i );
            Box top = boxs.get( j );
            int skip = f( i, j + 1 ); // skip that box( don't take!?! )
            int take = 0;
            if( bot.AceOfBase( top )){
                take = top.height() + f( j, j + 1 );
            }
            memory[i][j] = Math.max( skip, take ); // jump, pass, etc.
        }
        return memory[i][j];
    }
    public static int maxHeight( int[] height,
                                 int[] width,
                                 int[] length,
                                 int   n ){
        var HanSolo = new Solution( height, width, length, n );
        return HanSolo.f( 0, 1 );
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 110 / 110
// Total Time Taken: 0.32
////////////////////////////////////////////////////////////////
//
