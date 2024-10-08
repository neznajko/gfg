//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 起
//@@@@@@@@@@@@@@########@@@@@@@#################@@@@@@@@@@@@@@@@
//@@@@@@@@#######======#######@#===============#@@@@@@@@@@@@@@@@ お( o )
//@@@@@@@@#=======    =======#@#=             =#@@@@@@@@@@@@@@@@ き( ki )
//@@@@@@@@#=                =#@#=             =#@@@@@@@@@@@@@@@@ る( ru )
//@@@@@@###=                =###==========    =#@@@@@@@@@@@@@@@@
//@@@@@@#=========    =========#==========    =#@@@@@@@@@@@@@@@@ 
//@@@@@@#=                    =#=             =#@@@@@@@@@@@@@@@@ 
//@@@@@@#=========    =========#=    ==========#@@@@@@@@@@@@@@@@ 
//@@@@@@#======##=          =###=    ==========#@@@@@@@@@@@@@@@@
//@@@@@@#=    =##=          =#@#=             =#@@@@@@ despertar s
//@######=    =##=    =======###=             =#@@@ se réveiller f
//@#======    =================================#@@@@@@@@ wake up e
//@#=                                         =#@@@@@@@@@ wecken g
//@#=     ====                                =#@@@@@@@@@ будити u
//@#=======##==================================#@@@@@@@@@ veglia i
//@#############################################@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// Rod Cutting
////////////////////////////////////////////////////////////////
// Given a rod of length N inches and an array of prices, price[],
// denoting the value of a piece of length i. Determine the maximum
// value obtainable by cutting up the rod and selling the pieces
////////////////////////////////////////////////////////////////
// Note: Consider 1-based indexing
////////////////////////////////////////////////////////////////
// Input: N = 8 Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output: 22 Explanation: The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N^2)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
// 1 ≤ N ≤ 1000
// 1 ≤ Ai ≤ 10^5
////////////////////////////////////////////////////////////////
import java.io                                               .*;
import java.util                                             .*;
////////////////////////////////////////////////////////////////
class RodCutting{public static void main(String args[])throws 
IOException{BufferedReader in=new BufferedReader(new 
InputStreamReader(System.in));PrintWriter out=new PrintWriter(
System.out);int t=Integer.parseInt(in.readLine().trim());while(t
-->0){int n=Integer.parseInt(in.readLine().trim());String s[]=in
.readLine().trim().split(" ");int[] arr=new int[n];for(int i=0;i
<n;i++)arr[i]=Integer.parseInt(s[i]);Solution ob=new Solution();
out.println(ob.cutRod(arr,n));}out.close();}}
////////////////////////////////////////////////////////////////
//  1  5  8  9 10 17 17 20
//  0  1  2  3  4  5  6  7  0 - based
//  j:       ^
//  m: 9
//  k: 0
// > j
// m = price[ j ]
// for k = 0; k < ceil( j/2 ); ++k
//   p = price[ k ] + price[ j - k - 1 ]
//   m = max( m, p )
// price[ j ] <- m
////////////////////////////////////////////////////////////////
class Solution
{
    public int cutRod( int price[], int n )
    {
        for( int j = 1; j < n; ++j ){
            int m = price[ j ];
            int half = ( j + 1 ) / 2;
            for( int k = 0; k < half; ++k ){
                int p = price[ k ] + price[ j - k - 1 ];
                m = Math.max( m, p );
            }
            price[ j ] = m;
        }
        return price[ n - 1 ];
    }
}
//888888/////////////////////////////////////////////////8888888
//888888// . . . . . . . . . . . . . . . . . . . . . . //8888888
//888888// ^.^.^.^.^.^.^.^.^.^.^.^   ^.^.^.^.^.^.^.^.^ //8888888 寝
//888888// |^|^|^|                                   | //8888888
//888888// %|%|%|%   %|%|%|%|%|%|%|%|%|%|%|%|%|%|%   % //8888888 
//888888// ,%,%,%,%,%,   ,%,%,                   ,%,%, //8888888 ね( ne )
//888888// `,`,`,`,`,`   `,`,`,`,`,`,`,`,`,`,`   `,`,` //8888888 る( ru )
//888888// -`-`-`-`-`-   -`-`-                   -`-`- //8888888
//888888// /-/-/         /-/-/-/-/-/-/-/-/-/-/   /-/-/ //888888f dormir
//888888// _/_/_/_/_/_   _/_/_                   _/_/_ //8888888
//888888// :_:_:_:_:_:   :_:_:_:_:_:_:_:_:_:_:_:_:_:_: //888888i sonno
//888888// @:@:@:@:@:@   @                           @ //8888888
//888888// #@#@#         #   #@#@#@#@#@#@#@#@#@#@#   # //888888u сон
//888888// 8#8#8#8#8#8   8#8#8                   8#8#8 //8888888
//888888//         ;8;   ;8;8;8;     ;8;8;     ;8;8;8; //888888s dormir
//888888////////// ';'   ';';';';';'       ';';';';';' //8888888
//88888888888888// "'"   "'"'"       "'"'"       "'"'" //888888g schlafen
//88888888888888// *"*"*"*"*"*"*"*"*"*"*"*"*"*"*"*"*"* //8888888
//88888888888888/////////////////////////////////////////888888e sleep
//88888888888888/////////////////////////////////////////8888888
// log:
// Test Cases Passed:                                1265 / 1265
// Points Scored:                                          4 / 4
// Your Total Score:                                        1758 
// Time Taken:                                               0.2
