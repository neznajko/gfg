////////////////////////////////////////////////////////////////
/* Next Permutation 
 * Medium Accuracy: 54.7% Submissions: 34997 Points: 4
 *
 * Implement the next permutation, which rearranges the list of
 * numbers into Lexicographically next greater permutation of
 * list of numbers. If such arrangement is not possible, it must
 * be rearranged to the lowest possible order i.e. sorted in an
 * ascending order. You are given an list of numbers arr[ ] of
 * size N.
 * 
 * Example 1:
 * Input: N = 6
 * arr = {1, 2, 3, 6, 5, 4}
 * Output: {1, 2, 4, 3, 5, 6}
 * Explaination: The next permutation of the 
 * given array is {1, 2, 4, 3, 5, 6}.
 *
 * Example 2:
 * Input: N = 3
 * arr = {3, 2, 1}
 * Output: {1, 2, 3}
 * Explaination: As arr[] is the last 
 * permutation. So, the next permutation 
 * is the lowest one.
 *
 * Your Task: You do not need to read input or print
 * anything. Your task is to complete the function
 * nextPermutation() which takes N and arr[ ] as input
 * parameters and returns a list of numbers containing the next
 * permutation.
 * 
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(1)
 * 
 * Constraints:
 * 1 ≤ N ≤ 10000
 *//////////////////////////////////////////////////////////////
# include <vector>
# include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
// Ok, I know one slow Lexicographic algorithm from Knuth books,
// but it should be O( n).
typedef vector<int> vint;
struct Solution {
    vint nextPermutation( int n, vint& arr);
};
vint Solution::nextPermutation( int n, vint& arr) {
    // find j        inc            reverse
    //         *             *                *
    //         * *         * *          *     *
    //     * * * *       * * * *      * *   * *
    //   * * * * * *,  * * * * * *, * * * * * *
    //         j             j k          voilà
    // { find j}
    int j{ n - 1};
    for(; j > 0; j--) {
        if( arr[ j - 1] < arr[ j]) break;
    }
    // { inc }
    if( j > 0) {
        int k{ n - 1};
        for(;; k--) {
            if( arr[ k] > arr[ j - 1]) break;
        }
        swap( arr[ k], arr[ j - 1]);
    }
    // { reverse }
    for( int k = n - 1; j < k; j++, k--) {
        swap( arr[ k], arr[ j]);
    }
    return arr;
}
// Test Cases Passed:  44 / 44
// Total Time Taken:  0.0 / 1.1
//////////////////////////////////////////////////// Driver Code
int main() {
    int t;
    cin >> t;
    while( t--) {
        int N;
        cin >> N;
        vector<int> arr( N);
        for( int i = 0; i < N; i++) {
            cin >> arr[ i];
        }
        Solution ob;
        vector<int> ans = ob.nextPermutation( N, arr);
        for( int u: ans) {
            cout << u << " ";
        }
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////
