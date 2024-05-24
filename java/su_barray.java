////////////////////////////////////////////////////////////////
// Maximum Sub Array
////////////////////////////////////////////////////////////////
// Find out the maximum sub-array of non negative numbers from
// an array. The sub-array should be contiguous i.e., a
// sub-array created by choosing the second and fourth element
// and skipping the third element is invalid. Maximum sub-array
// is defined in terms of the sum of the elements in the
// sub-array. Sub-array A is greater than sub-array B if sum(A)
// > sum(B)
////////////////////////////////////////////////////////////////
// a = [1, 2, 5, -7, 2, 3]
// The two sub-arrays are [1, 2, 5] [2, 3].
// The answer is [1, 2, 5] as its sum is larger than [2, 3]
////////////////////////////////////////////////////////////////
// NOTE: If there is a tie, then compare with segment's length
/// and return segment which has maximum length. If there is
// still a tie, then return the segment with minimum starting
// index. If no such subarray is present return "-1"
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// 1 ≤ N ≤ 10^5
// -10^5 ≤ A[i] ≤ 10^5
////////////////////////////////////////////////////////////////
import java.io                                               .*;
import java.util                                             .*;
////////////////////////////////////////////////////////////////
class GFG{public static void main(String[] args)throws Exception 
{ BufferedReader br = new BufferedReader( new InputStreamReader(
System.in)); PrintWriter out=new PrintWriter( System.out);int t=
Integer.parseInt( br.readLine().trim()); while( t--> 0 ){ int n=
Integer.parseInt(br.readLine().trim());String[]str=br.readLine()
.trim().split(" ");int[]a=new int[n];for(int i=0; i<n;i++){a[i]=
Integer.parseInt(str[i]);}ArrayList<Integer> ans=new Solution().
findSubarray(a,n);for(int i:ans){out.print(i+" ");}out.println()
;}out.close();}}////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// コーヒーを飲みます。
// Ich trinke Kaffee.
////////////////////////////////////////////////////////////////
// 音楽を聞きます。
// Ich höre Musik.
////////////////////////////////////////////////////////////////
// テレビを見ます。
// Ich sehe fern.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    ArrayList <Integer> findSubarray( int a[], int n )
    {
        var ma = new ArrayList <Integer> ();
        var ms = -1;
        for( int j = 0; j < n; ){
            for(; j < n && a[ j ] < 0; ++j )
                ;
            var ca = new ArrayList <Integer> ();
            var cs = 0;
            for(; j < n && a[ j ] >= 0; ++j ){
                ca.add( a[ j ]);
                cs += a[ j ];
            }
            if( cs > ms ){
                ma = ca;
                ms = cs;
            } else if( cs == ms ){
                if( ca.size() > ma.size()){
                    ma = ca;  ////      //////   /////////////// よ
                }             //#########             ########## む
            }                 //##      ######   ###############
        }                     //#########             ########## l
        if( ma.size() == 0 ){ //##      ######################## e
            ma.add( -1 );     //#########             ########## s
        }                     //##      #  #########  ########## e
        return ma;            //#########  #  ###  #  ########## n
    }                         //##      ####  ###  #############
}                             //##  ##  ####  ###  ############# 
//////////////////////////////////      ////  ///  /////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  309 / 309
// Points Scored:                                          4 / 4
// Your Total Score:                                        1786 
// Time Taken:                                              1.27
