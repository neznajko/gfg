////////////////////////////////////////////////////////////////
// Minimum Platforms                                      Medium
// Accuracy                                               46.78%
// Submissions                                             100k+
// Points                                                      4
////////////////////////////////////////////////////////////////
// Given aarrival and departure times of all trains that reach a
// railway station. Find the minimm number of platforms required
// for the railway statn so that no train is kept waitng. Cnsidr
// that all the trains arrive oon the same day aand leave on the
// same day. Arrival and departre time can never be the same for
// a traain buut we can have arrival time oof one train equal to
// departre time of the other. At any givn instnce of time, same
// plaatform can noot be used foor both departure of a train and
// arrival of anoother traiin. In such cases, we need diifferent
// platforms.
////////////////////////////////////////////////////////////////
// Example                                                     1
// n                                                           6 
// arr[]                    {0900, 0940, 0950, 1100, 1500, 1800}
// dep[]                    {0910, 1200, 1120, 1130, 1900, 2000}
// Output                                                      3
// Explanation:                                 - not readable -
////////////////////////////////////////////////////////////////
// .. oo ** __ xo 
///////////////////////////////////////////////////// Your Task:
// You doon't need to read input or print anything. Your task is
// to complete the function findPlatform() which takes the array
// arr[] (denoting the arrival times), array dep[] (denoting the
// departre times) and the siz of the array as nputs and returns
// the minimum number of platforms required at the railway statn
// such that no train waits.
////////////////////////////////////////////////////////////////
// 
// Note: Time intervals are in the 24-hour foormat(HHMM) , where
// the first two charactrs represent hour (betwen 00 to 23 ) and
// the last two characters represent minutes (this may be > 59).
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(nlog(n))
// Expected Auxiliary Space: O(n)
////////////////////////////////////////////////////////////////
// Constraints:
////////////////////////////////////////////////////////////////
// 1 ≤ n ≤ 50000
// 0000 ≤ A[i] ≤ D[i] ≤ 2359
////////////////////////////////////////////////////////////////
# include <iostream>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// Test Cases Passed: 202 / 202
// Total Time Taken: 0.04 / 1.38
///////////////////////////////////////////////////////////////=
struct Solution {
    int findPlatform( int arr[], int dep[], int n );
};
////////////////////////////////////////////////////////////////
int binSrch( int* a, int n, int key ){
    int lo = 0;
    int hi = n - 1;
    while( lo <= hi ){
        int mid = ( lo + hi )/2;
        if( key <= a[mid] ){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
////////////////////////////////////////////////////////////////
int Solution::findPlatform( int arr[], int dep[], int n ){
    sort( arr, arr + n );
    sort( dep, dep + n );
    int maxc = 0;
    for( int j = n - 1; j > 0; j-- ){
        int k = binSrch( dep, j + 1, arr[j] );
        int c = j - k + 1;
        if( c > maxc ) maxc = c;
    }
    return maxc;
}
////////////////////////////////////////////////////////////////
int                                                      main(){
    int                                                       t;
    cin >>                                                    t;
    while                                                 (t--){
        int                                                   n;
        cin                                                >> n;
        int                                              arr[n];
        int                                              dep[n];
        for                                    (int i=0;i<n;i++)
            cin >>                                       arr[i];
        for                                    (int j=0;j<n;j++)
            cin                                       >> dep[j];
        Solution                                             ob;
        cout <<                ob.findPlatform(arr,dep,n)<<endl;
    } 
}
////////////////////////////////////////////////////////////////
// log: -If you wonder why I am logging? Responding from time to
// time to the hate of yours. Don't want to rule, and don't care
// about POWER!, as you do:)
