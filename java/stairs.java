////////////////////////////////////////////////////////////////
// Nambà of ways to reach the nth stair
//////////////////////////////////////////////////////////////// _
// Medium Accuracy: 42.67% Submissions: 63743 Points: 4          _
// There are n stairs, a person standing at the bottom wants to  _
// reach the top. The person can climb either 1 stair or 2 stair Ś
// at a time. Count the number of ways, the person can reach the _
// top (order does matter).                                      _
//////////////////////////////////////////////////////////////// 
// Expected Time Complexity : O(n)
// Expected Auxiliary Space: O(1)
//////////////////////////////////////////////////////////////// -----
// Your Task:                                                    -----
// Complete the function countWays() which takes the top stair n umber
// m as input parameters and returns the answer % 10^9+7.        -----
//////////////////////////////////////////////////////////////// -----
// Constraints:                                     
// 1 ≤ n ≤ 10^4
////////////////////////////////////////////////////////////////
import java.util.Scanner;
////////////////////////////////////////////////////////////////
class GFG {
                        public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
                                           int t = sc.nextInt();
while(t-- > 0) {
                                           int m = sc.nextInt();
Solution obj = new Solution();
                           System.out.println(obj.countWays(m));
}
                                                               }
}
//////////////////////////////////////////////////////////////// ---
// If we are on jth stair than we've might come here either by o ne-
// or two stairs climb, that is from (j-1)th or from (j-2)th sta ir.
// So N(j) = N(j-1) + N(j-2), the famous Fibonacci formula.      ---
class Solution {
    static final int MOD = 1000000007;
    static final int MAXSIZ = 10001;
    static int fib[] = new int [ MAXSIZ ];
    static {
        fib[0] = fib[1] = 1;
    }
    static int fibsiz = 2;

    int countWays( int n )
    {
        if( n < fibsiz ) return fib[n];
        for( int j = fibsiz; j <= n; j++ ){
            fib[j] = fib[j - 1] + fib[j - 2];
            fib[j] %= MOD;
        }
        fibsiz = n + 1;
        return fib[n];
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 997 /997
// Total Time Taken: 0.28
// log: Semantics is comming from sema like in semaphore meaning -----
// sign. When people had no alphabet and language they communica ted--
// with signs, like you do today thinking that this is some very -----
// ästonishing skill but that signaling is very obvious from the -----
// context like the meaning of the words, and I didn't mean that -----
// boring stuff when I told you that we can cominicate without w ords,
// signs, contexts or whatever but only with thoughts regardless -----
// of time and space, a-and because you think of yourselves like -----
// leaders of the World or whatever you think of, and don't want to---
// look stupid, you prefer to fool yourself and act like you kno w----
// what I'm talking about, no you don't, and by the way you look -----
// Stupid!                                                       -----
////////////////////////////////////////////////////////////////
