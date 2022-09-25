////////////////////////////////////////////////////////////////
// The Celebrity Problem
////////////////////////////////////////////////////////////////
// A celebrity is a person who is known to all but does not know
// anyone at a party. If you go to a party of N people, find if 
// there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the
// party such that if an element of row i and column j is set to
// 1 it means ith person knows jth person. Here M[i][i] will 
// always be 0.
// 
// Follow Up: Can you optimize it to O(N)
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       N = 3
//              M[][] = {{0 1 0},
//                       {0 0 0}, 
//                       {0 1 0}}
// Output:      1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is 
// the celebrity. 
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N^2)
// Expected Auxiliary Space: O(1)
////////////////////////////////////////////////////////////////
// Constraints:
// 2 <= N <= 3000
// 0 <= M[][] <= 1
////////////////////////////////////////////////////////////////
namespace DriverCode
{
    class GFG
    {
        static void Main(string[] args)
        {
            int testcases;
            testcases = Convert.ToInt32(Console.ReadLine());
            while (testcases-- > 0)
            {
                int N = Convert.ToInt32(Console.ReadLine());
                int[] arr = new int[N*N];
                int[,] M = new int[N,N];
                string elements = Console.ReadLine().Trim();
                elements = elements + " " + "0";
                arr = Array.ConvertAll(elements.Split(), int.Parse);
                int k = 0;
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        M[i,j] = arr[k++];
                    }
                }
                Solution obj = new Solution();
                int res = obj.celebrity(M, N);
                Console.Write(res + "\n");
            }
        }
    }
}
////////////////////////////////////////////////////////////////
// "A celebrity is a person who is known to all but does not know
// anyone at a party."; I agree, here we have to switch to Tricky
// Trickster mode again, but it's a nice problem nontheless. The 
// idea for the O(N) solution is that, if everyone knows the celeb 
// than we don't need to make full scan, we can only proceed with
// the first branch of the dfs tree.
class Celeb_Candidate: Exception 
{
    public int name;
    public Celeb_Candidate( int name )
    {
        this.name = name;
    }
}
////////////////////////////////////////////////////////////////
class Solution
{
    int[,] m = {};
    int n;
    void Are_You_Celeb( int i )
    {
        for( int j = i + 1; j < n; j++ ){
            if( m[i,j] == 1 ) Are_You_Celeb(j);
        }
        throw new Celeb_Candidate(i);
    }
    bool Check_Check( int k ){
        // row check
        for( int j = 0; j < n; j++ ){
            if( m[k,j] == 1 ) return false;
        }
        // col check, By the way how is Colchester doing?,
        // I wonder, have to check! last time we lost from
        // Cambridge:(,..
        m[k,k] = 1;
        for( int i = 0; i < n; i++ ){
            if( m[i,k] == 0 ) return false;
        }
        return true;
    }
    public int celebrity(int[,] m, int n)
    {
        this.m = m;
        this.n = n;
        try { Are_You_Celeb(0);
        } catch( Celeb_Candidate cc ){
            if( Check_Check( cc.name )){
                return cc.name;
            }
        }
        return -1;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 66 / 66
// Total Points Scored: 4 / 4
// Your Total Score: 826
// Total Time Taken: 1.09
// Your Accuracy: 100%
// Attempts No.: 1
// log: 
//
