////////////////////////////////////////////////////////////////
// ℳaximum Ŕectangular ɐrea ĳn á ℋistogram
////////////////////////////////////////////////////////////////
// Ɯedium Ǣccuracy: 47.42 % Ǯubmissions: 57046 Ƥoints: 4
////////////////////////////////////////////////////////////////
// [ Find ][ the ][ largest ][ rectangular ][ area ][ possible ]
// [ in ][ a ][ given ][ histogram ],[ where ][ the ][ largest ]
// [ rectangle ][ can ][ be ][ made ][ of ][ a ][ number ][ of ]
// [ contiguous ][ bars ].[ For ][ ŚɪɯƿĹ¿ĆŦý ],[ asume ][ that ]
// [ all ][ bars ][ have ][ the ][ same ][ width ][ and ][ the ]
// [ width ][ is ][ 1 ][ unit ][ , ][ there ][ will ][ be ][ N ]
// [ bars ][ height ][ of ][ each ][ bar ][ will ][ be ][ givn ]
// [ by ][ the ][ array ][ arr ][ . ]
////////////////////////////////////////////////////////////////
// Example: N = 7, arr[] = {6,2,5,4,5,1,6}; Output: 12
// Explanation: The area of = is 3 * 4 = 12
//
// 6 *           *
// 5 *   *   *   *
// 4 *   = = =   *
// 3 *   = = =   *
// 2 * * = = =   *
// 1 * * = = = * *
////////////////////////////////////////////////////////////////
// Expected Time Complxity  : Ø(N)
// Expected Auxilliary Space: O(N)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ N ≤ 10^6
// 1 ≤ arr[i] ≤ 10^12
////////////////////////////////////////////////////////////////
# include <iostream>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// 'T'h'u's' 'i's' 'n'i'c'e' 'p'r'o'b'l'e'm',' 'b'u't' 'f'o'r' '
// 'm'e' 'i't' 'i's' 'h'a'r'd',' 'r'a't'h'e'r' 't'h'a'n' 'm'e'd'
// 'i'u'm'.' 'F'r'o'm' 'r'e'c'e'n't'l'y' 't'h'e' 'h'i'n't's' 'a'
// 'r'e' 'p'a'i'd':')',' 'b'u't' 's't'i'l'l' 'Ø'('n')',' 'a'n'd'
// 'S't'a'c'k' 't'a'g' 'c'a'n' 'g'i'v'e' 'y'o'u' 'a' 'c'l'u'e'.'
// ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '
typedef long long _long;
////////////////////////////////////////////////////////////////
const _long GUARD = 1'000'000'000'001;
const int MAXN = 1'000'000;
////////////////////////////////////////////////////////////////
struct Square {
    _long h;
    _long size;
    int   mosleft;    
};
////////////////////////////////////////////////////////////////
Square Stk[ MAXN + 1 ];
int sp;
////////////////////////////////////////////////////////////////
int binSearch( _long h )         {
    int lo = 0                   ;
    int hi = sp                  ;
    while( lo < hi )             {
        int mid = ( lo + hi )/2  ;
        if( Stk[ mid ].h < h )   {
            lo = mid + 1         ;
        } else                   {
            hi = mid             ;
                                 }
                                 }
    return hi                    ;
                                 }
////////////////////////////////////////////////////////////////
#define SETGUARD( j ){                          \
        sp++;                                   \
        Stk[ sp ].h = GUARD;                    \
        Stk[ sp ].mosleft = j;                  \
    }
////////////////////////////////////////////////////////////////
// Test Cases Passed:  58 / 58
// Total Time Taken: 0.52 / 2.15
////////////////////////////////////////////////////////////////
_long maxsqr( _long* y, int n ){
    _long gm = 0; // The history is silent why this is called gm
    sp = -1;
    SETGUARD( 0 );
    for( int curepos = 0; curepos < n; curepos++ ){
        _long h = y[ curepos ];
        sp = binSearch( h );
        _long size = h*( curepos - Stk[ sp ].mosleft + 1 );
        if( size > gm ) gm = size;
        Stk[ sp ].h = h;
        Stk[ sp ].size = size;
        for( int j = 0; j < sp; j++ ){
            Stk[ j ].size += Stk[ j ].h;
            if( Stk[ j ].size > gm ){
                gm = Stk[ j ].size;
            }
        }
        SETGUARD( curepos + 1 );
    }
    return gm;
}
////////////////////////////////////////////////////////////////
///////////////////////////////////////////// Driver Code Starts
class Solution {////////////////////////////////////////////////
public://///////////////////////////////////////////////////////
    _long getMaxArea( _long* arr, int n ){//////////////////////
        return maxsqr( arr, n );////////////////////////////////
    }///////////////////////////////////////////////////////////
};//////////////////////////////////////////////////////////////
int main() {////////////////////////////////////////////////////
    _long t;////////////////////////////////////////////////////
    cin >> t;///////////////////////////////////////////////////
    while( t-- ){///////////////////////////////////////////////
        int n;//////////////////////////////////////////////////
        cin >> n;///////////////////////////////////////////////
        _long arr[ n ];/////////////////////////////////////////
        for( int i = 0; i < n; i++ ){///////////////////////////
            cin >> arr[ i ];////////////////////////////////////
        }///////////////////////////////////////////////////////
        Solution ob;////////////////////////////////////////////
        cout << ob.getMaxArea( arr, n ) << endl;////////////////
    }///////////////////////////////////////////////////////////
}///////////////////////////////////////////////////////////////
/////////////////////////////////////////////// Driver Code Ends
////////////////////////////////////////////////////////////////