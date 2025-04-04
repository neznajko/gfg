////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 昼 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> der Mittag >>>>>>>>
//8888                                                  88888888
//8888    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    88888888 
//>>>>    @@@@@@                             @@@@@@@    >>>>>>>> ひる
//8888    \\\\\\    \\\\\\\\\\\\\\\\\\\\\    \\\\\\\    88888888
//8888    \\\\\\                             \\\\\\\    88888888
//8888    \\\\\\    \\\\\\\\\\\\\\\\\\\    \\\\\\\\\    88888888
//>>>>    @@@@@@    @                  @    @@@@@@@@    >>>>>>>>
//>>>>    @@@@@@    @    @@@@@@@@@@    @@    @@@@@@@    >>>>>>>>
//>>>>    @@@@@@    @                  @@@    @@@@@@    >>>>>>>>
//8888    \\\\\    \\    \\\\\\\\\\    \\\\    \\\\\    88888888
//8888    \\\    \\\\                  \\\\\\\\\\\\\    88888888
//8888    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    88888888
//8888    \\\\\\                             \\\\\\\    88888888
//8888    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    88888888
//8888                                                  88888888
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> lE Midi >>>>>>>>
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Count Palindromic Subsequences
////////////////////////////////////////////////////////////////
// Given a string str o f length N, you have t o find number o f 
// palindromic subsequence (n e e d not necessarily be distinct) 
// present in the string str.
////////////////////////////////////////////////////////////////
// Note: You have to return the answer module 10^9+7
////////////////////////////////////////////////////////////////
// Input: Str = "aab" Output: 4 Explanation: palindromic
// subsequence are :"a", "a", "b", "aa"
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)
////////////////////////////////////////////////////////////////
// 1 <= length of string <= 1000
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import java.util                                             .*;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class GFG{public static void main( String args[]){Scanner sc=new 
Scanner(System.in);int t= sc.nextInt();sc.nextLine();while(t>0){
String str=sc.nextLine(); Solution ob=new Solution();System.out.
println(ob.countPS(str));t--;}}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    static final long MOD = 1000000007;
    String s;
    long cache[][];
    //
    long dp( int i, int j ){
        if( j  < i ) return 0;
        if( i == j ) return 1;
        if( cache[ i ][ j ] == 0 ){
            long a = dp( i + 1, j - 1 );
            long b = dp( i + 1, j );
            long c = dp( i, j - 1 );
            long d = 0;
            if( s.charAt( i ) == s.charAt( j )){
                d = a + 1;
            }
            cache[ i ][ j ] = ( b + c - a + d ) % MOD;
            if( cache[ i ][ j ] < 0 ){
                cache[ i ][ j ] += MOD;
            }
        }
        return cache[ i ][ j ];
    }
    long countPS( String s ){
        int n = s.length();
        cache = new long[ n ][ n ];
        this.s = s;
        return dp( 0, n - 1 );
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  105 / 105
// Points Scored:                                          4 / 4
// Your Total Score:                                        1710 
// Time Taken:                                              0.37
