////////////////////////////////////////////////////////////////
// Stickler Thief
////////////////////////////////////////////////////////////////
// Stickler the thief wants to loot money from a society having 
// n houses in a single line. He is a weird person and follows a
// certain rule when looting the houses. According to the rule, 
// he will never loot two consecutive houses. At the same time, 
// he wants to maximize the amount he loots. The thief knows 
// which house has what amount of money but is unable to come up
// with an optimal looting strategy. He asks for your help to 
// find the maximum money he can get if he strictly follows the 
// rule. Each house has a[i] amount of money present in it.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       n = 6
//              a[] = {5,5,10,100,10,5}
// Output:      110
// Explanation: 5+100+5=110
////////////////////////////////////////////////////////////////
// Expected Time Complexity:O(N).
// Expected Space Complexity:O(N).
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤    n ≤ 10^4
// 1 ≤ a[i] ≤ 10^4
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
                int[] arr = new int[N];
                string elements = Console.ReadLine().Trim();
                elements = elements + " " + "0";
                arr = Array.ConvertAll(elements.Split(), int.Parse);
                Solution obj = new Solution();
                int res = obj.FindMaxSum(arr, N);
                Console.Write(res + "\n");
            }
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 304 / 304 Medium problms can be more trcky
// Total Points Scored: 4 / 4   to solve than hard ones, because
// Your Total Score: 850        hard problems usually follow som
// Total Time Taken: 0.4        theoretcl line but they can also
// Your Accuracy: 100%          be very easy, like this one.
// Attempts No.: 1
////////////////////////////////////////////////////////////////
class Solution {
    int n = 0;
    int[] arr = {};
    int[] mem = {};
    int dp( int j ){
        // base case
        if( j >= n) return 0;
        // check memory
        if( mem[ j] > 0 )return mem[ j ];
        // take jth element
        int take = arr[ j] + dp( j + 2 );
        // skip
        int skip = dp( j + 1 );
        mem[ j] = Math.Max( take, skip );
        return mem[ j ];
    }
    public int FindMaxSum( int[] arr, int n)
    {
        this.n = n;
        this.arr = arr;
        this.mem = new int[ n ]; // initialized to 0
        return dp( 0 );
    }
}
////////////////////////////////////////////////////////////////
// log: