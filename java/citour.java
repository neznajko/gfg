////////////////////////////////////////////////////////////////
// Circular tour
////////////////////////////////////////////////////////////////
// Suppose there is a circle. There are N petrol pumps on that
// circle. You will be given two sets of data.
////////////////////////////////////////////////////////////////
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
////////////////////////////////////////////////////////////////
// Find a starting point where the truck can start to get
// through the complete circle without exhausting its petrol in
// between.
////////////////////////////////////////////////////////////////
// Note: Assume for 1 litre petrol, the truck can go 1 unit of
// distance.
////////////////////////////////////////////////////////////////
// Example :    1
// Input:       N = 4
//              Petrol = 4 6 7 4
//              Distance = 6 5 3 5
// Output:      1
// Explanation: There are 4 petrol pumps with amount of petrol
// and distance to next petrol pump value pairs as {4, 6}, {6,
// 5}, {7, 3} and {4, 5}. The first point from where truck can
// make a circular tour is 2nd petrol pump. Output in this case
// is 1 (index of 2nd petrol pump).
////////////////////////////////////////////////////////////////
// Your Task: Your task is to complete the function tour() which
// takes the required data as inputs and returns an integer
// denoting a point from where a truck will be able to complete
// the circle (The truck will stop at each petrol pump and it
// has infinite capacity). If there exists multiple such
// starting points, then the function must return the first one
// out of those. (return -1 otherwise)
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space : O(1)
////////////////////////////////////////////////////////////////
// Constraints:
// 2 ≤ N ≤ 10000
// 1 ≤ petrol, distance ≤ 1000
////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.util.Arrays;
////////////////////////////////////////////////////////////////
import static java.lang.System.out;
////////////////////////////////////////////////////////////////
class First_Circular_tour
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0)
        {
            int n = sc.nextInt();
            sc.nextLine();
            String str = sc.nextLine();
            String arr[] = str.split(" ");
            int p[] = new int[n];
            int d[] = new int[n];
            int j = 0;
            int k = 0;
            for(int i = 0; i < 2*n; i++)
            {
                if(i%2 == 0)
                {
                    p[j] = Integer.parseInt(arr[i]);
                    j++;
                }
                else
                {
                    d[k] = Integer.parseInt(arr[i]);
                    k++;
                }
            }           
            System.out.println(new Solution().tour(p, d));
            t--;
        }
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 498 / 498
// Total Points Scored: 4 / 4
// Your Total Score: 834
// Total Time Taken: 1.05
// Your Accuracy: 50%
// Attempts No.: 2
////////////////////////////////////////////////////////////////
class Solution
{
    int tour( int benzine[], int distance[] )
    {
        int deficit = 0;
        int start = 0;
        int total = 0;
        final int n = benzine.length;
        for( int j = 0; j < n; j++ ){
            total += benzine[j] - distance[j];
            if( total < 0 ){
                deficit += total;
                start = j + 1;
                total = 0;
            }
        }
        total += deficit;
        if( total < 0 ) return -1;
        return start;
    }
}
///////////////////////////////////////////////////////////////_
// log: No fox no news, waving the hammer every day doesn't seem
// like very intelligent job although its understandable because
// after all you want to rule peoples mind and their choices but
// I don't know I guess you don't want to be in contrast to your
// target group.

