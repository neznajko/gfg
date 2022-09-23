////////////////////////////////////////////////////////////////
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Heap Sort
 * Given an array of size N. The task is to sort the array elements
 * by completing functions heapify() and buildHeap() which are used
 * to implement Heap Sort.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Expected Time Complexity: O(N * Log(N)).
 * Expected Auxiliary Space: O(1).
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Constraints:
 * 1 ≤ N ≤ 10^6
 * 1 ≤ arr[i] ≤ 10^6
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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
                obj.heapSort(arr, N);
                for (int i = 0; i < N; i++)
                {
                    Console.Write(arr[i] + " ");
                }
                Console.Write("\n");
            }
        }
    }
}
////////////////////////////////////////////////////////////////
class Solution
{
    int[] a = Array.Empty<int>();
    int n;
    int s; // size of the currently sorted array(are in Indian)
    void Swap(int i, int j)
    {
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    }
    // There is hidden element at n equal to nil. The idea is to
    // flip the heap upside down and use the reversed array from
    // n-1 to 0 as 1-based heap array. Then after finish popping
    // the array will be sorted.
    ////////////////////////////////////////////////////////////
    void Bubble_Up(int j)
    {
        // n - 1 is the top of the heap
        while (j < n - 1)
        {
            int i = n - ((n - j) >> 1); // parent index
            if (a[i] > a[j]) Swap(i, j);
            j = i; // bubble up
        }
    }
    int Get_Smaller_Child(int j)
    {
        int i = n - ((n - j) << 1);
        // s is the index of last sorted element
        if( i - 1 > s) // Ok
        {
            return a[i] <= a[i - 1] ? i : i - 1;
        }
        else if (i - 1 == s)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
    void Sink()
    {
        int j = n - 1;
        while (true)
        {
            int i = Get_Smaller_Child(j);
            if (i == -1 || a[i] >= a[j]) break;
            Swap(i, j);
            j = i;
        }
    }
    void Sort_Heap()
    {
        s = 0;
        for (int j = 0; j < n - 1; j++)
        {
            Swap(j, n - 1);
            Sink();
            s++;
        }
    }
    void Build_Heap()
    {
        for (int j = n - 2; j >= 0; j--) Bubble_Up(j);
    }
    public void heapSort(int[] a, int n)
    {
        this.a = a;
        this.n = n;
        Build_Heap();
        Sort_Heap();
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 102 / 102
// Total Points Scored: 4 / 4
// Your Total Score: 822
// Total Time Taken: 1.95
// Your Accuracy: 100 %
// Attempts No.: 1
// log:
//