                                  ////
////////////////////////////////////////////////////////////////////////
/* Unique BST's
 Medium Accuracy: 44.17% Submissions: 30476 Points: 4
 Given an integer. Find how many structurally unique binary search trees
 are there that stores the values from 1 to that integer (inclusive). 
 Example 1:
 Input:
 N = 2
 Output: 2
 Explanation: for N = 2, there are 2 unique
 BSTs
     1               2  
      \            /
       2         1
 Example 2:
 Input:
 N = 3
 Output: 5
 Explanation: for N = 3, there are 5
 possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3
 Your Task:
 You don't need to read input or print anything. Your task is to
 complete the function numTrees() which takes the integer N as input and
 returns the total number of Binary Search Trees possible with keys 
 [1.....N] inclusive. Since the answer can be very large, return the
 answer modulo 1000000007.
 Expected Time Complexity: O(N^2).
 Expected Auxiliary Space: O(N).
*/
////////////////////////////////////////////////////////////////////////
// Test Cases Passed: 21 / 21
// Total Time Taken: 0.2/1.41
import java.util.*;
import java.io.*;
import java.lang.*;
class Solution {
    static long numTrees( int n) {
        long[] uniq = new long[ n + 1];
        uniq[ 1] = uniq[ 0] = 1;
        for( int j = 2; j <= n; j++) {
            for( int i = 1; i <= j; i++) {
                uniq[ j] += uniq[ i - 1] * uniq[ j - i];
                uniq[ j] %= 1000000007;
            }
        }
        return uniq[ n];
    }
}
class GFG {
    public static void main( String args[]) {
        Scanner sc = new Scanner( System.in);
        int t = sc.nextInt();
        while( t--> 0) {
            int n = sc.nextInt();
            Solution ob = new Solution();
            System.out.println( ob.numTrees( n));
        }
    }
}
////////////////////////////////////////////////////////////////////////
// chill: The Cranberries - You and Me( https://youtu.be/84zVbHX7lVw )
