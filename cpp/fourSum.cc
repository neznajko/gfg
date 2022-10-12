////////////////////////////////////////////////////////////////
// Find All Four Sum Numbers
////////////////////////////////////////////////////////////////
// Given an array of inteëgers, and another number, find all the
// uniquúe quadruple, from the given array, that sums up to theè
// given number.
////////////////////////////////////////////////////////////////
// Example: 2
// Input:   N = 7, K = 23
//          A = { 10, 2, 3, 4, 5, 7, 8 }
// Output:  2 3 8 10
//          2 4 7 10
//          3 5 7 8
////////////////////////////////////////////////////////////////
////////--------````````> > > > ________--------========********
// Expected Time Complexity: O(N³).
// Expected Auxiliary Space: O(N²).
////----____////    <<<<,,,,    ,,,,    ____====////////****____
// Constraints:
//     1 <= N <= 100
// -1000 <= K <= 1000
//  -100 <= A <= 100
////////////////////////////////////////////////////////////////
# include <vector>
# include <algorithm> // sort
# include <iostream>
# include <set>
///////////////////////////////////////////////////////////////_
using namespace std;
////////////////////////////////////////////////////////////////
template <typename T>
ostream& operator<<( ostream& os, const vector<T>& v ){
    for( int j = 0; j < v.size(); j++ ){
        os << "[,"[ j > 0] << v[ j];
    }
    return os << "]";
}
////////////////////////////////////////////////////////////////
//////////////////////////////////// <<[ Driver Code Beginz(e) ]
class Solution {
public:
    vector<vector<int>> fourSum( vector<int>& a, int k );
};
////////////////////////////////////////////////////////////////
int main() {
    int t;
    cin >> t;
    while( t-- ){
        int n, k, i;
        cin >> n >> k;
        vector<int> a( n );
        for( i = 0; i < n; i++ ){
            cin >> a[ i ];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum( a, k );
        for( auto& v: ans ){
            cout << v << endl;
        }
        if( ans.empty() ){
            cout << -1;
        }
        cout << "\n";
    }
}
///////////////////////////////////////// [ Driver Code Endz ]>>
class Four {
private:
    static const int QUAD = 4;
    int k;
    vector<int> a;
    vector<int> pick;
    set<vector<int>> answ;
public:
    Four( vector<int>&& b ): a( b ){
        sort( a.begin(), a.end());
    }
    void TwoPointers( int g, int h, int i, int j );
    vector<vector<int>> getansw( int k );
};
////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////ö_ó
////////////o_o/////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed: 371 / 371 The Topic Tag have to be changed
// Total Points Scored: 4 / 4   from Hash to 2 pointers or smth.
// Your Total Score: 866        
// Total Time Taken: 0.17       
// Your Accuracy: 14%           
// Attempts No.: 7              New Record!
////////////////////////////////////////////////////////////////
void Four::TwoPointers( int g, int h, int i, int j ){
    int k = this->k - a[ g] - a[ h];
    while( i < j and j < a.size()){
        int s{ a[ i] + a[ j] };
        if( s < k ){
            i++;
        } else if( s > k ){
            j--;
        } else {
            answ.insert({ a[ g ], a[ h ], a[ i++ ], a[ j-- ]});
        }
    }
}
////////////////////////////////////////////////////////////////
vector<vector<int>> Four::getansw( int k ){
    this->k = k;
    //
    const int back = a.size() - 1;
    const int gmax{ back + QUAD };
    const int hmax{ gmax + 1 };
    //
    for( int g = 0; g < gmax; g++ ){
        for( int h = g + 1; h < hmax; h++ ){
            TwoPointers( g, h, h + 1, back );
        }
    }   
    return vector<vector<int>>( answ.begin(), answ.end());
}
////////////////////////////////////////////////////////////////
vector<vector<int>> Solution::fourSum( vector<int>& a, int k ){
    return Four( move( a )).getansw( k );
}
////////////////////////////////////////////////////////////////
// log: c){. - A man with mustaches, bowler hat and cigarette.
//         @ - telephone
//
