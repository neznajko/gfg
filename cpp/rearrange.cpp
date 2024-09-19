////////////////////////////////////////////////////////////////
// Arranging the array
////////////////////////////////////////////////////////////////
// You are given an array of size N. Rearrange the given array
// in-place such that all the negative numbers occur before all
// non-negative numbers. (Maintain the order of all negativeve
// and non-negative numbers as given in the original array)
////////////////////////////////////////////////////////////////
// Input: N = 4 Arr[] = {-3, 3, -2, 2}
// Output: -3 -2 3 2
////////////////////////////////////////////////////////////////
// Input: N = 4 Arr[] = {-3, 1, 0, -2}
// Output: -3 -2 1 0
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(Nlog(N))
// Expected Auxiliary Space: O(log(N))
////////////////////////////////////////////////////////////////
// 1 ≤ N ≤ 10⁵
// -10⁹ ≤ Elements of array ≤ 10⁹
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
typedef vector <int> ivec_t;
////////////////////////////////////////////////////////////////
ostream& operator <<( ostream& _ , const ivec_t& c ){
    _ << '[';
    if( c.size()){
        _ << ' ';
        for( int u: c ){
            _ << u << ' ';
        }
    }
    return _ << ']';
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
private:
    int* a;
    // t - stack pointer
    void merge( int t, const ivec_t& left, const ivec_t& ryte ){
        const int n = left.size();
        const int m = ryte.size();
        int i = 0;
        int j = 0;
        while( i < n and j < m ){
            if( left[ i ] < 0 ){
                a[ t++ ] = left[ i++ ];
                continue;
            }
            if( ryte[ j ] < 0 ){
                a[ t++ ] = ryte[ j++ ];
                continue;
            }
            break;
        }
        while( i < n ){
            a[ t++ ] = left[ i++ ];
        }
        while( j < m ){
            a[ t++ ] = ryte[ j++ ];
        }
    }
    ivec_t mergesort( int i, int j ){
        if( i < j - 1 ){
            int k = ( i + j ) >> 1;
            merge( i, mergesort( i, k ), mergesort( k, j ));
        }
        return ivec_t( a + i, a + j );
    }
public:
    void Rearrange( int* a, int n ){
        this->a = a;
        mergesort( 0, n );
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(){int t;cin>>t;while(t--){ int n;cin>>n;int arr[n];for(
int i=0;i<n;i++)cin>>arr[i]; Solution ob; ob.Rearrange( arr, n);
for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}}/////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1211 / 1211
// Points Scored:                                          4 / 4
// Your Total Score:                                        1854
// Time Taken:                                              0.59
// 1.3.14: From the same place with interval difference dt are
// thrown two objects with same velocity with angle ß with
// respect to the horizon. How is the 1st object moving relative
// to the 2nd? Why relative velocity depends only on dt?
// v₁(t) = (vcosß, vsinß - gt)
// v₂(t) = (vcosß, vsinß - g(t - dt))
// v₁ - v₂ = ( 0, -gdt ) - relative velocity
// x₁(t) = vtcosß
// y₁(t) = vtsinß - g(t²|2)
// x₂(t) = v(t - dt)cosß
// y₂(t) = v(t - dt)sinß - g[(t - dt)²|2]
// x₁ - x₂ = v(cosß)dt
// y₁ - y₂ = v(sinß)dt - gtdt + g(dt²|2)
