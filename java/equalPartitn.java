// 8888||||88|||||||888888||||||888888888|||||||8|||||||888888||
// 8888||||88|||||||888888||||||888888888|||||||8|||||||888888||
// 8888||||88|||||||888888|||     8888888|||||||8|||||||888888||
// 8888||||88|||||                           |||8|||||||888888||
// 8888||||88|||||||888888|||     888888     |||8|||||||888888||
// 8888||||88|||                               |8|||||||888888||
// 8888||||88|||||||888888|||     888888     |||8|||||||888888||
// 8888||||88|||||                           |||8|||||||888888||
// 8888||||88|||||||888888|||     8888888|||||||8|||||||888888||
// 8888||||88||||                             ||8|||||||888888||
// 8888||||88|||||||888888|||     8888888|||||||8|||||||888888||
// 8888||||88|||                               |8|||||||888888||
// 8888||||88|||||||888888||||||888888888|||||||8|||||||888888||
// 8888||||88|||||                           |||8|||||||888888||
// 8888||||88|||||     888||||||88888888     |||8|||||||888888||
// 8888||||88|||||                           |||8|||||||888888||
// 8888||||88|||||     888||||||88888888     |||8|||||||888888||
// 8888||||88|||||                           |||8|||||||888888||
// 8888||||88|||||||888888||||||888888888|||||||8|||||||888888||
// 8888||||88|||||||888888||||||888888888|||||||8|||||||888888||
// 書 ショ write sho
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Partition Equal Subset Sum
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Givn an array arr[] of size N, check if it can be partitioned
// into two parts such that the sum of elements in both parts is
// the same.                                                   
//////////////////////////////////////////////////////////  
/////////////////////////////////////////////////////////   ////
////////////////////////////////////////////////////////   /////
///////////////////////////////////////////////////////   //////
// Input: N = 4, arr = {1, 5, 11, 5}                 /   /
// Output: YES                                      /   /
// Explanation: The two parts are {1, 5, 5} and {11}   /
///////////////////////////////////////////////////   //////////
//////////////////////////////////////////////////   ///////////
/////////////////////////////////////////////////   ////////////
////////////////////////////////////////////////   /////////////
// Expected Time Complexity: O(N*sum_of_elements) /
// Expected Auxiliary Space: O(sum_of_elements)  /
/////////////////////////////////////////////   ////////////////
////////////////////////////////////////////   /////////////////
///////////////////////////////////////////   /////////////////
//////////////////////////////////////////   /////////////////  
// 1 ≤ N ≤ 100                              /////////////////   
// 1 ≤ arr[i] ≤ 1000
// N*sum_of_elements ≤ 5*10^6
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
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import java.io.*;
import java.util.*;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//// たけし：そうですか......。じゃあ、土曜日に映画を見ませんか。
//// メアリー： 土曜日はちょっと......。
//// たけし： じゃあ、日曜日はどうですか。
//// メアリー： いいですね。
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//// えいが 映画 ｍおｖいえ( movie )
//// 映 えい 
//// 88888888##  ####  画 が
//// 8     88##  ####  88888888########
//// 8  8  8        #                  
//// 8     8  #  #  #  8888888  #######
//// \  \                8          #  
//// \     \\@@  @@@@    8  88  ##  #  
//// \\\\  \\@    @@@    8          #
//// \\\\\\\  @@@@  @    \  \\  @@  @  
////                     \          @  
////       projection    \\\\\\@@@@@@  
////
////                   \\\\\\\\@@@@@@@@
////                            picture
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//// おんがく 音楽 ｍうｓいｃ( music )
////////////////////////////////////////////////////////////////
//// 音 おん
//// 8888888  ///////  楽 ガク
//// 88            //  ## ####  ---- --
//// 8888  88//  ////  #   #      -   -
////                   ## ##  #-  -- --
//// 88888888////////  #####      -----
//// \\            @@  ## ##  #-  -- --
//// \\  \\\\@@@@  @@  0   0      >   >
//// \\            @@  00 0000  >>>> >>
//// \\  \\\\@@@@  @@                  
//// \\            @@  000  00  >>  >>>
////            sound  0  0000  >>>>  >
////                            comfort
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////// .. das quadratähnliche - the square like
////// Brustkorbrechteck, - chest rectangel
////// die Zwischenform - the in between form
////// des Bauches, - of the belly
////// das Trapezoid - the trapezoid
////// des Oberschenkels - upper legs
////// die quadratnahe - near the square
////// Zwischenform - in between form
////// des Knies - of the knee
////// usw. [ und so weiter ] - etc.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class GFG{public static void main(String args[])throws
IOException{BufferedReader in=new BufferedReader(new 
InputStreamReader(System.in));int t=Integer.parseInt(in.readLine
());while(t-->0){int N=Integer.parseInt(in.readLine());String 
input_line[]=in.readLine().trim().split("\\s+");int arr[]=new 
int[N];for(int i=0;i<N;i++)arr[i]=Integer.parseInt(input_line[i]
);Solution ob=new Solution();int x=ob.equalPartition(N,arr);if(x
==1)System.out.println("YES");else System.out.println("NO");}}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// So we are given an array a and we are asked can it be split
// in two parts having equal sums? If total sum is odd obviously
// not, otherwise it's equivalent to the question can we find a
// subset of a having sum equal to (totalsum / 2) which can be
// solved using dp. Let dp(s,j) gives T or F depending whether 
// we can find a subset of a[j..-1] having sum s, then
// dp(s,j) = dp(s-a[j],j+1) || dp(s,j+1)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    int n;
    int a[];
    boolean [][] dp;
    void debug() {
        System.out.println( Arrays.toString( a ));
        // stackoverflow
        System.out.println( Arrays.deepToString( dp )
                                  .replace( "], ", "]\n " ));
    }
    int checkthus( int halfsum ){
        // initialize
        dp = new boolean[ halfsum + 1 ][ n ];
        for( int j = n - 1; j >= 0; --j ){
            if( a[j] <= halfsum ){
                dp[ a[j] ][j] = true;
            }
        }
        // reverse engineering
        for( int j = n - 2; j >= 0; --j ){
            for( int s = 1; s <= halfsum; ++s ){
                int r = s - a[j];
                boolean taike = r > 0 ? dp[r][j + 1] : false;
                boolean skp = dp[s][j + 1];
                dp[s][j] = taike || skp;
            }
        }
        return dp[ halfsum ][0] ? 1 : 0;
    }
    int equalPartition( int n, int a[] ){
        int s = Arrays.stream( a ).sum();
        // check if sum is odd or n is one
        if(( s & 1 ) == 1 || n < 2 ){ return 0; }
        this.n = n;
        this.a = a;
        return checkthus( s / 2 );
    }
}
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
// Test Cases Passed:                                1120 / 1120
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1666
// Total Time Taken:                                        0.25
// prev:  github.com/neznajko/gfg/blob/main/dotnet/PerfectSum.cs
// foreword:                 the punctuation is completly random
// logbook:      We can't rely our experience and imagination to
//     describe God as man with beard who is responsible for the
//  lightning bolts, the only way we can describe and understand 
//   God is in the form of low, rule of thumb, or principle, for
//     that matter; not formulated in the language of physics or
//    math, cos truth must cross all boundaries, but rather with
// some not very sophisticated and hard to understand words. I'm
//   not a preacher, neither want to lead a rebelion against the
//  empire but for me the above mentioned principle( IJ ) is the
//   truth, althought in reality it's just a spring for a theory
