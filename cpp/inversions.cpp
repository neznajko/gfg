////////////////////////////////////////////////////////////////
// Count Inversions 
// Medium Accuracy: 39.43% Submissions: 100k+ Points: 4
// Given an array of integers. Find the Inversion Count in the
// array.
// Inversion Count: For an array, inversion count indicates how
// far (or close) the array is from being sorted. If array is
// already sorted then the inversion count is 0. If an array is
// sorted in the reverse order then the inversion count is the
// maximum. Formally, two elements a[i] and a[j] form an
// inversion if a[i] > a[j] and i < j.
//
// Example 1:
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).
//
// Example 2:
// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already 
// sorted so there is no inversion count.
//
// Example 3:
// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array 
// are same, so there is no inversion count.
//
// Your Task:
// You don't need to read input or print anything. Your task is
// to complete the function inversionCount() which takes the
// array arr[] and the size of the array as inputs and returns
// the inversion count of the given array.
//
// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).
// 
// Constraints:
// 1 ≤ N ≤ 5*10^5
// 1 ≤ arr[i] ≤ 10^18
////////////////////////////////////////////////////////////////
# include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
# define BUFLEN 500000 // 1 <= N <= 5*10^5
////////////////////////////////////////////////////////////////
typedef long long int i64_t;
////////////////////////////////////////////////////////////////
i64_t cntr{};
i64_t aux[ BUFLEN]; // copy buffer
////////////////////\\//////////////////////////////////////////
// Becoz the time complexity is O(nlog(n)) the first thought was
// to use mergesort but that was the last problem, so I've tried
// with binary search tree but couldn't pass the time test there
// is a fat case arount 100 so I've made a little paste and copy
class Solution {
private:
    i64_t* arr;
    // merges [lo..mi] with [mi + 1..hi]
    void merge( i64_t lo, i64_t mi, i64_t hi);
    void mrgsort( i64_t lo, i64_t hi);
public:
    i64_t inversionCount( i64_t arr[], i64_t n) {
        this->arr = arr;
        cntr = 0;
        mrgsort( 0, n - 1);
        return cntr;
    }
};
void Solution::merge( i64_t lo, i64_t mi, i64_t hi) {
    // avoid using STL if possible, copy arr to aux, simple for
    // loop looks fine
    for( i64_t _ = lo; _ <= hi; _++) {
        aux[ _] = arr[ _];
    }
    i64_t i = lo;     // left aux position (src)
    i64_t j = mi + 1; // ryte aux position
    i64_t k = lo;     // arr position      (dst)
    // Vhen merging and the fyorst lmnt from ryte is bigger than
    // every lmnt left on left there is a corespnding inversion.
    while( true) { // that is not folz
        if( i > mi) { // no more left left
            for( i64_t t = j; t <= hi; t++) {
                arr[ k++] = aux[ t];
            }
            break;
        } else if( j > hi) { // ryte no more
            for( i64_t t = i; t <= mi; t++) {
                arr[ k++] = aux[ t];
            }
            break;
        } else { // ok compare here
            if( aux[ i] <= aux[ j]) { // no inversions
                arr[ k++] = aux[ i++];
            } else {
                cntr += mi - i + 1; // left left lmnts
                arr[ k++] = aux[ j++];
            }                
        }            
    }
}
void Solution::mrgsort( i64_t lo, i64_t hi) {
    // Chck if something to split
    if( lo == hi) return; // nope
    // split to left and ryte
    i64_t mi = ( lo + hi) >> 1; // middle
    mrgsort( lo, mi);
    mrgsort( mi + 1, hi);
    merge( lo, mi, hi);
}
////////////////////////////////////////////////////////////////
int main() {
    i64_t T;
    cin >> T;
    while( T--) {
        i64_t N;
        cin >> N;
        i64_t A[ N];
        for( i64_t i = 0; i < N; i++) {
            cin >> A[ i];
        }
        Solution obj;
        cout << obj.inversionCount( A, N) << endl;
    }    
}
/////////////////////////////////// https://youtu.be/-gsDBuHwqbM
////////////////////////////////////////////////////////////////
// log: -The Evil Nazis are plotting a secret, and nasty plan to
// infect Macron, for his next meeting, with Covid19; watch out!
//
// Test Cases Passed: 117 / 117
// Total Time Taken:  0.2 / 2.2
////////////////////////////////////////////////////////////////
