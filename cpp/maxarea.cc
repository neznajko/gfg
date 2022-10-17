////////////////////////////////////////////////////////////////
// Max rectangle
////////////////////////////////////////////////////////////////
// Given a binary maátrix M of size n X m. Find the maximum area
// of a rectangle formed only of 1s in the given matrix.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       n = 4, m = 4
//              M[][] = {{0 1 1 0},
//                       {1 1 1 1},
//                       {1 1 1 1},
//                       {1 1 0 0}}
// Output:      8
// Explanation: [ a very long explanation ]
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n*m)
// Expected Auixiliary Space: O(m)
////////////////////////////////////////////////////////////////
// Constraints:
// 1<=n,m<=1000
// 0<=M[][]<=1
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <algorithm>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
constexpr int MAX=700;
////////////////////////////////////////////////////////////////
class Solution{public:int maxArea(int M[MAX][MAX],int n,int m);};
////////////////////////////////////////////////////////////////
int main(){int T;cin>>T;int M[MAX][MAX];while(T--){int n,m;cin>>
n>>m;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>M[i][j];}}
Solution obj;cout<<obj.maxArea(M,n,m)<<endl;}}
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const vector<T>& v ){
    for( int j = 0; j < v.size(); j++ ){
        os << "[,"[ j > 0] << v[ j];
    }
    return os << "]";
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 175 / 175 This is really difficult problem
// Total Points Scored: 8 / 8   its core is a problem which I've
// Your Total Score: 878        acctually have solved but not in
// Total Time Taken: 1.1        a very efficient way, and had to
// Your Accuracy: 100%          revisit it namley the finding of
// Attempts No.: 1              the maximum square in histogram.
////////////////////////////////////////////////////////////////
typedef int long_t;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// a is n bars histogram, where n is guaranteed to be >= 1. This
// O(n) solution is in my own opinion nice and not very obvious.
// Thanks to a gfg article you can read about it here:
// geeksforgeeks.org/largest-rectangle-under-histogram
// or try finding it by your self the hint is,          [stack].
long_t maxsqr( long_t* a, int n ){
    static const int GRD{ -1 };
    // create a stack, containing guard and the first bin of the
    // histogram
    vector<int> stk({ GRD, 0 });
    // initialize the result
    long_t output{ 0 }; 
    // make a loop 
    for( int j = 1; j < n; j++ ){
        for( int i = stk.back(); i != GRD and a[ i] > a[ j ]; i = stk.back()){
            // pop all bins with greather bars than a[ j] cos in all
            // time the stack is in increasing order with respect of a,
            // and holds bins which bars are the heights of the future
            // squares, if the above for loop condition holds a[ i]
            // can't serve this function any longer, so to speak.
            stk.pop_back();
            // the square with a[ i] as its height extends from j untill
            // prevous bin in the stack, thats why the guard is here.
            output = max( output, a[ i ]*( j - stk.back() - 1 ));
        }
        stk.push_back( j );
    }
    // No more popping!
    for( int i = stk.back(); i != GRD; i = stk.back()){
        stk.pop_back();
        output = max( output, a[ i ]*( n - stk.back() - 1 ));
    }
    return output;
}
////////////////////////////////////////////////////////////////
int* acc( int a[ MAX ][ MAX ], int i, int m ){
    if( i > 0 ){
        for( int j = 0; j < m; j++ ){
            if( a[ i ][ j ] == 0 )continue;
            a[ i ][ j ] += a[ i - 1 ][ j ];
        }
    }
    return a[ i ];
}
int Solution::maxArea( int a[ MAX ][ MAX ], int n, int m ){
    int output{ 0 };
    for( int i = 0; i < n; i++ ){
        int* y = acc( a, i, m );
        output = max( output, maxsqr( y, m ));
    }
    return output;
}
////////////////////////////////////////////////////////////////
// log:
