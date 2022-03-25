////////////////////////////////////////////////////////////////
// Minimum operations to convert array A to B 
// Hard Accuracy: 60.91% Submissions: 8173 Points: 8
//
// Given two Arrays A[] and B[] of length N and M
// respectively. Find the minimum number of insertions and
// deletions on the array A[], required to make both the arrays
// identical.  Note: Array B[] is sorted and all its elements
// are distinct, operations can be performed at any index not
// necessarily at end.
// 
// Example 1:
// Input:
// N = 5, M = 3
// A[] = {1, 2, 5, 3, 1}
// B[] = {1, 3, 5}
// Output:
// 4
// Explanation:
// We need to delete 2 and replace it with 3.
// This costs 2 steps. Further, we will have to
// delete the last two elements from A to
// obtain an identical array to B. Overall, it
// results in 4 steps.
// 
// Example 2:
// Input:
// N = 2, M = 2
// A[] = {1, 4}
// B[] = {1, 4}
// Output :
// 0
// Explanation:
// Both the Arrays are already identical.
// 
// Your Task: You don't need to read input or print
// anything. Your task is to complete the function
// minInsAndDel() which takes two integers N and M, and two
// arrays A of size N and B of size M respectively as input and
// returns the minimum insertions and deletions required.
// 
// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)
// 
// Constraints:
// 1 ≤ N ≤ 10^5
// 1 ≤ A[i], B[i] ≤ 10^5
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
  public:
    int minInsAndDel( int A[], int B[], int N, int M);
};
// Test Cases Passed: 123 / 123
// Total Time Taken:  0.4 / 2.1
///////////////////////////////////////////// Driver Code Starts
int main() {
    int t;
    cin >> t;
    while( t--) {
        int N, M;
        cin >> N >> M;
        int A[ N], B[ M];
        for( int i = 0; i < N; i++) {
            cin >> A[ i];
        }
        for( int i = 0; i < M; i++) {
            cin >> B[ i];
        }
        Solution ob;
        cout << ob.minInsAndDel( A, B, N, M) << endl;
    }
}
/////////////////////////////////////////////// Driver Code Ends
////////////////////////////////////////////////////////////////
// Copy and paste from LIS.cpp, and renaming the class from
// Solution to lis.
class lis {
private:
    vector<int> seq;
    int binsrch( int y);
public:
    int longestSubsequence( int n, int* a);
};
int lis::binsrch( int y) {
// return fst j: seq[ j] <= y
    int lo{ 0 };
    int hi = seq.size() - 1;
    while( lo < hi) {
        int mi{( lo + hi) >> 1};
        if( seq[ mi] < y) {
            lo = mi + 1;
        } else if( seq[ mi] == y) {
            return mi;
        } else {
            hi = mi;
        }
    }
    return hi;
}
int lis::longestSubsequence( int n, int* a) {
    if( n == 0) return 0; // guarantee a[ 0] exists
    seq.push_back( a[ 0]);
    for( int j = 1; j < n; j++) {
        if( a[ j] > seq.back()) {
            seq.push_back( a[ j]); // longer sub seq found
        } else { // update seq if there is no duplicate
            int i{ binsrch( a[ j]) };
            seq[ i] = a[ j];
            // Now the optimal increasing sub seq of length
            // (i + 1) is seq[ 0], ..., seq[ i]
        }
    }
    return seq.size();
}
////////////////////////////////////////////////////////////////
// This problem is hard, becoz it uses another problem namely,
// lis: longest increasing sub-sequence. It actually doesn't
// require additional space, but that's not very important. The
// idea is the following:
// Iterate over A and discard each element not present in B
// using binary search, that will take O(nlog(n)), than use lis
// on the modified A, which will give the size of unmovable, so
// to speak elements, let's say L. Than the number of deletions
// will be N - L, and number of insertions M - L, with total
// number of editions, N + M - 2L.
//
# define NEGATIVE -1
int binsrch( int y, int* arr, int n) {
// Search for exact match of :y within the array :arr
    int lo = 0;
    int hi = n - 1;
    if( y < arr[ lo] or y > arr[ hi]) return NEGATIVE;
    while( lo <= hi) {
        int mi = (lo + hi) >> 1;
        if( arr[ mi] < y) {
            lo = mi + 1;
        } else if( arr[ mi] == y) {
            return mi;
        } else {
            hi = mi - 1;
        }
    }
    return NEGATIVE;
}
int Solution::minInsAndDel( int A[], int B[], int N, int M) {
    int sp = 0; // stack pointer
    for( int j = 0; j < N; j++) {
        if( binsrch( A[ j], B, M) != NEGATIVE) {
            A[ sp++] = A[ j]; // in-place stack push
        }
    }
    int L = lis().longestSubsequence( sp, A);
    int del = N - L;
    int ins = M - L;
    return del + ins;
}
////////////////////////////////////////////////////////////////
