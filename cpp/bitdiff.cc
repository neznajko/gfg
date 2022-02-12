////////////////////////////////////////////////////////////////
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Bit Difference 
 * Hard Accuracy: 46.07% Submissions: 12124 Points: 8
 * We define f(X,Y) as number of different corresponding bits in
 * binary representation of X and Y. For example, f(2,7) = 2,
 * since binary representation of 2 and 7 are 010 and 111,
 * respectively. The first and the third bit differ, so f(2,7)=2.
 *
 * You are given an array A of N integers, A_1,A_2,..,A_N. Find
 * sum of f(A_i,A_j) for all ordered pairs (i,j) such that
 * 1 <= i, j <= N. Return the answer modulo 10**9+7.(!)
 *
 * Example 1:
 * 
 * Input: N = 2
 * A = {2, 4}
 * Output: 4
 * Explaintion: We return 
 * f(2, 2) + f(2, 4) + 
 * f(4, 2) + f(4, 4) = 
 * 0 + 2 + 
 * 2 + 0 = 4.
 *
 * Example 2:
 * 
 * Input: N = 3
 * A = {1, 3, 5}
 * Output: 8
 * Explaination: We return 
 * f(1, 1) + f(1, 3) + f(1, 5) + 
 * f(3, 1) + f(3, 3) + f(3, 5) + 
 * f(5, 1) + f(5, 3) + f(5, 5) = 
 * 0 + 1 + 1 + 
 * 1 + 0 + 2 + 
 * 1 + 2 + 0 = 8.
 * Your Task:
 * You do not need to read input or print anything. Your task is
 * to complete the function countBits() which takes the value N
 * and the array A as input parameters and returns the desired
 * count modulo 10**9+7.
 * Expected Time Complexity: O(N*log2(Max(A_i)))
 * Expected Auxiliary Space: O(1)
 * 
 * Constraints:
 * 1 ≤ N ≤ 10**5
 * 2**0 ≤ A[i] < 2**31
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
////////////////////////////////////////////////////////////////
# include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    int countBits( int N, long long int A[]);
};
////////////////////////////////////////////////////////////////
# define GETBIT( j) ((A[j] & mask) > 0)
int Solution::countBits( int N, long long int A[]) {
    static const int NBITS{ 32};
    static const int MODULO{ 1000000007};
    long long cntr{};
    for( int off = 0; off < NBITS; off++) {
        const long long mask = 1 << off;
        int ones = 0;        
        for( int j = 0; j < N; j++) {
            ones += GETBIT( j);
        }
        cntr += 2*ones*( N - ones);
    }
    return( cntr % MODULO);
}
////////////////////////////////////////////////////////////////
int main () {
    int t;
    cin >> t;
    while( t--) {
        int N;
        cin >> N;
        long long int A[N];
        for( int i = 0; i < N; i++) {
            cin >> A[i];
        }        
        Solution ob;
        cout << ob.countBits( N, A) << "\n";
    }
}
////////////////////////////////////////////////////////////////
// log: -Yeah;[Ok], art is horseshit you buy tacos and I'll stop
// posting pixes.
//
// Test Cases Passed: 184 / 184
// Total Time Taken: 0.1/2.3
